/* `ns` Namespace implementation
 */

#ifndef NS_H
#define NS_H

#include <stdlib.h>

#include "var.h"
#include "helper.h"

typedef struct ns_cont {
	int size;
	var_cont** names;
	struct ns_cont* next;
} ns_cont;

typedef struct ns_t {
	ns_cont* root;
	ns_cont* last;
} ns_t;

/* Initializes namespace of size
 */
ns_t* ns_init(int);

ns_cont* ns_cont_init(int);

/* Cleans up memory
 */
void ns_del(ns_t*);

void ns_cont_del(ns_cont*);

/* Pushes namespace of size
 */
void ns_push(ns_t*, int);

/* Pops last namespace level
 */
void ns_pop(ns_t*);

/* Declares a variable, at root or last namespace
 */
void ns_dec(ns_t*, b_type, int, int);

/* Sets variable to value, at root or last namespace
 */
void ns_set(ns_t*, int, int, var_cont*);

#endif // NS_H