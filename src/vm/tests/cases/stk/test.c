#include <stdio.h>

#include "stk.h"
#include "var.h"


void printstk(stk_t* stk)
{
	var_cont* test0 = stk_at(stk, 0);
	var_cont* test1 = stk_at(stk, 1);
	var_cont* test2 = stk_at(stk, 2);
	var_cont* test3 = stk_at(stk, 3);
	printf("%i, %i, %i, %i\n",
	       test0->type, test1->type, test2->type, test3->type);
}

int main(int argc, char* argv[])
{
	stk_t* new = stk_new();

	stk_push(new, var_new(TEMPORARY, VOID));
	stk_push(new, var_new(TEMPORARY, G_INT));
	stk_push(new, var_new(TEMPORARY, G_FLOAT));
	stk_push(new, var_new(TEMPORARY, G_CHAR));
	stk_push(new, var_new(TEMPORARY, G_STR));

	printf("init: \n");
	printstk(new);

	stk_pop(new);

	printf("stk_pop: \n");
	printstk(new);

	stk_rot_top(new);

	printf("stk_rot_top: \n");
	printstk(new);

	stk_rot_top(new);

	stk_rot_three(new);

	printf("stk_rot_top + stk_rot_three: \n");
	printstk(new);

	stk_rot_three(new);

	printf("stk_rot_three: \n");
	printstk(new);

	stk_del(new);

	return 0;
}
