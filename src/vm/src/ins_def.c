#include <stdlib.h>
#include <stdio.h>

#include "ins_def.h"

#include "proc.h"
#include "rt.h"
#include "bc.h"
#include "stk.h"
#include "var.h"
#include "pc.h"
#include "helper.h"

/* Initializes INS_DEF with pointers to each instructions function
 * Populates INS_DEF
 */
void init_ins_def( void )
{
	INS_DEF[0x00] = _ins_def_NULL;
	INS_DEF[0x01] = _ins_def_SYNC;
	INS_DEF[0x02] = _ins_def_ARGB;
	INS_DEF[0x0F] = _ins_def_LIBC;

	INS_DEF[0x10] = _ins_def_POP;
	INS_DEF[0x11] = _ins_def_ROT;
	INS_DEF[0x12] = _ins_def_DUP;
	INS_DEF[0x13] = _ins_def_ROT_THREE;

	INS_DEF[0x20] = _ins_def_DEC;
	INS_DEF[0x21] = _ins_def_LOV;
	INS_DEF[0x22] = _ins_def_STV;
	INS_DEF[0x23] = _ins_def_LOC;
	INS_DEF[0x24] = _ins_def_CTS;

	INS_DEF[0x30] = _ins_def_TYPEOF;
	INS_DEF[0x31] = _ins_def_CAST;

	INS_DEF[0x40] = _ins_def_ADD;
	INS_DEF[0x41] = _ins_def_SUB;
	INS_DEF[0x42] = _ins_def_MULT;
	INS_DEF[0x43] = _ins_def_DIV;
	INS_DEF[0x44] = _ins_def_POW;
	INS_DEF[0x45] = _ins_def_BRT;
	INS_DEF[0x46] = _ins_def_SIN;
	INS_DEF[0x47] = _ins_def_COS;
	INS_DEF[0x48] = _ins_def_TAN;
	INS_DEF[0x49] = _ins_def_ISIN;
	INS_DEF[0x4A] = _ins_def_ICOS;
	INS_DEF[0x4B] = _ins_def_ITAN;
	INS_DEF[0x4C] = _ins_def_MOD;
	INS_DEF[0x4D] = _ins_def_OR;
	INS_DEF[0x4E] = _ins_def_XOR;
	INS_DEF[0x4F] = _ins_def_NAND;

	INS_DEF[0x50] = _ins_def_GTHAN;
	INS_DEF[0x51] = _ins_def_LTHAN;
	INS_DEF[0x52] = _ins_def_EQ;
	INS_DEF[0x53] = _ins_def_NOT;

	INS_DEF[0x60] = _ins_def_STARTL;
	INS_DEF[0x61] = _ins_def_CLOOP;
	INS_DEF[0x6E] = _ins_def_BREAK;
	INS_DEF[0x6F] = _ins_def_DONE;

	INS_DEF[0x70] = _ins_def_GOTO;
	INS_DEF[0x71] = _ins_def_JUMPF;
	INS_DEF[0x7F] = _ins_def_CALL;

	INS_DEF[0x80] = _ins_def_PUSH;
	INS_DEF[0x81] = _ins_def_DEL;
	INS_DEF[0x82] = _ins_def_GET;
	INS_DEF[0x83] = _ins_def_GETP;
	INS_DEF[0x84] = _ins_def_CALLM;

	INS_DEF[0xF0] = _ins_def_RETURN;
	INS_DEF[0xF1] = _ins_def_NEW;
	INS_DEF[0xFE] = _ins_def_DECLASS;
	INS_DEF[0xFF] = _ins_def_DEFUN;
}

int ins_def_is_valid(bc_cont* line)
{
	int rv = 0;

	if(INS_DEF[line->op] != NULL)
	{
		rv = 1;
	}
	return rv;
}

void _ins_def_NULL     (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_SYNC     (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_ARGB     (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_LIBC     (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}

void _ins_def_POP      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_ROT      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_DUP      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_ROT_THREE(rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}

void _ins_def_DEC      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_LOV      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_STV      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_LOC      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_CTS      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}

void _ins_def_TYPEOF   (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_CAST     (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}

void _ins_def_ADD      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_SUB      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_MULT     (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_DIV      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_POW      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_BRT      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_SIN      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_COS      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_TAN      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_ISIN     (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_ICOS     (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_ITAN     (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_MOD      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_OR       (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_XOR      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_NAND     (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}

void _ins_def_GTHAN    (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_LTHAN    (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_EQ       (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_NOT      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}

void _ins_def_STARTL   (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_CLOOP    (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_BREAK    (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_DONE     (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}

void _ins_def_GOTO     (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_JUMPF    (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_CALL     (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}

void _ins_def_PUSH     (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_DEL      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_GET      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_GETP     (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_CALLM    (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}

void _ins_def_RETURN   (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_NEW      (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_DECLASS  (rt_t* ctx, bc_cont* line)
{
	pc_inc(ctx->pc, 1);
}
void _ins_def_DEFUN    (rt_t* ctx, bc_cont* line)
{
	int     name = var_data_get_G_INT(line->varg[0]);
	b_type  type = var_data_get_TYPE(line->varg[1]);
	b_type* args = var_data_get_PLIST(line->varg[2]);

	var_data_func* data = var_data_alloc_FUNC(type);

	data->loc = line->real_addr + 1;

	int nsize;

	for (nsize = 0; ctx->pc->line->next != NULL; pc_update(ctx->pc))
	{
		pc_inc(ctx->pc, 1);
		if (ctx->pc->line->op == 0xF0)
		{
			break;
		} else
		if (ctx->pc->line->op == 0x20)
		{
			nsize++;
		}
	}
	
	data->size = nsize;
	data->type = type;
	data->param = args;

	proc_decvar(ctx, 1, name, FUNC);

	var_cont* var = proc_getvar(ctx, 1, name);
	var_set(var, data, FUNC);
}