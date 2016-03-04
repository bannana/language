#include <stdlib.h>
#include <stdio.h>

#include "proc.h"

#include "rt.h"
#include "ins_def.h"
#include "bc.h"
#include "stk.h"
#include "var.h"
#include "ns.h"
#include "pc.h"
#include "helper.h"

/* Initializes process, returns runtime context.
 *  char* - Filename of valid bytecode
 */
rt_t* proc_init(char* fname)
{
	N_ASSERT(fname);
	rt_t* ctx = rt_ctx_new(fname, stk_new());

	return ctx;
}

/* Starts execution loop for a runtime context
 * rt_t* - Runtime context
 */
void proc_run(rt_t* ctx)
{
	N_ASSERT(ctx);

	int n;
	
	for (n = 0; ctx->pc->line->next != NULL; pc_update(ctx->pc))
	{
		printf("%i - %i: %x\n", n, ctx->pc->stk->address, ctx->pc->line->op);

		INS_DEF[ctx->pc->line->op](ctx, ctx->pc->line);

		n++;
	}
}

/* Calls runtime context elements to free memory and terminate
 *  rt_t* - Runtime context
 */
void proc_clean(rt_t* ctx)
{
	N_ASSERT(ctx);
	rt_ctx_del(ctx);
}

/* Function call subroutine.
 *  rt_t*     - Runtime context
 *  var_cont* - Variable in type of function
 *
 *  This function is used to support an interface to multithreaded instances
 */
var_cont* proc_callfun(rt_t* ctx, var_cont* func)
{
	N_ASSERT(ctx);
	return 0;
}

/* Set a variable subroutine
 *  rt_t*     - Runtime context
 *  b_type    - Type
 *  int       - Scope
 *  ns_addr   - Name of variable
 *
 *  This function is used to support an interface to multithreaded instances
 */
void proc_decvar(rt_t* ctx, b_type type, int scope, ns_addr name)
{
	ns_dec(ctx->vars, type, scope, name);
}

/* Set a variable subroutine
 *  rt_t*     - Runtime context
 *  int       - Scope
 *  ns_addr   - Name of variable
 *  var_cont* - Variable container
 *
 *  This function is used to support an interface to multithreaded instances
 */
void proc_setvar(rt_t* ctx, int scope, ns_addr name, var_cont* var)
{
	ns_set(ctx->vars, scope, name, var);
}

/* Get a variable subroutine
 *  rt_t*   - Runtime context
 *  int     - Scope
 *  ns_addr - Name of variable
 */
var_cont* proc_getvar(rt_t* ctx, int scope, ns_addr name)
{
	var_cont* rv;
	
	rv = ns_get(ctx->vars, scope, name);

	return rv;
}
