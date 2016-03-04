/*  var.h -> Provide implemenation of types
 */

#ifndef VAR_H
#define VAR_H

#include <stdlib.h>
#include <stdio.h>

#include "helper.h"

typedef unsigned int bc_addr;
typedef unsigned int ns_addr;

typedef enum {
	VOID,
	ADDR,
	TYPE,
	PLIST,
	FUNC,
	OBJECT,
	G_INT,
	G_FLOAT,
	G_CHAR,
	G_STR,
	S_ARRAY,
	D_ARRAY,
	K_ARRAY,
	G_FIFO
} b_type;

typedef struct var_cont {
	b_type type;
	void*  data;
} var_cont;

typedef struct var_data_type {
	b_type v;
} var_data_type;

typedef struct var_data_func {
	bc_addr loc;
	bc_addr end;
	b_type  type;
	ns_addr size;
	b_type* param;
} var_data_func;

typedef struct var_data_int {
	int v;
} var_data_int;

typedef struct var_data_float {
	double v;
} var_data_float;

typedef struct var_data_char {
	char v;
} var_data_char;

typedef struct var_data_str {
	char* v;
} var_data_str;

typedef struct var_data_plist {
	b_type* v;
} var_data_plist;

#include "bc.h"

/* Initialze variable with type
 */
var_cont* var_new(b_type);

void* var_data_alloc_TYPE(b_type);
void* var_data_alloc_FUNC(b_type);
void* var_data_alloc_G_INT(int);
void* var_data_alloc_G_FLOAT(double);
void* var_data_alloc_G_CHAR(char);
void* var_data_alloc_G_STR(size_t);
void* var_data_alloc_PLIST(size_t);

/* Frees variable
 */
void var_del(var_cont*);
void var_data_free(void*, b_type);

void var_data_free_FUNC(void*);
void var_data_free_G_STR(void*);
void var_data_free_PLIST(void*);

/* Sets variable
 * void* -> pointer to allocated space of memory that agrees with b_type
 */
void var_set(var_cont*, void*, b_type);

b_type         var_data_get_TYPE(var_cont*);
var_data_func* var_data_get_FUNC(var_cont*);
int            var_data_get_G_INT(var_cont*);
double         var_data_get_G_FLOAT(var_cont*);
char           var_data_get_G_CHAR(var_cont*);
char*          var_data_get_G_STR(var_cont*);
b_type*        var_data_get_PLIST(var_cont*);

void bytes_to_int(var_cont**, int, byte_t*);

void byte_to_type(var_cont**, byte_t);

void raw_to_plist(var_cont**, int, byte_t*);

void raw_to_var(var_cont**, int, byte_t*);

#endif // var_H
