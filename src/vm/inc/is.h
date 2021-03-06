/*
 `is` holds the instruction set specification.

 Anything having to do with getting information about a given instruction will
 be handled by this file.
*/

#ifndef IS_H
#define IS_H

#include "ins_mdata.h"
#include "fh.h"
#include "bc.h"

// This array is populated by inc/ins_mdata.h
byte_t INS_MDATA[0x100];

// This array is populated by inc/ins_adata.h
byte_t INS_ADATA[0x100];

/* Takes an opcode, fills metadata about that opcode (given that it exists) in
 * the `bc_cont` structure
 *  byte_t   - opcode
 *  bc_cont* - Bytecode instruction
 */
void get_opcode_mdata(byte_t, bc_cont*);

/* Fills in metadata in @param byte_t.
 * byte_t - un-expanded metadata
 * int*   - is number of params          [0]
 * int*   - int[3] detailing param types [1]
 *
 * For example, given a byte 11011011, it would break down into the following:
 * @param[1] = 3,
 * @param[2] = { 01, 10, 11 }
 */
void unencode(byte_t, int*, int*);

/* Sets up INS_MDATA datastructure to quickly queue for data.
 *  Instruction arguement type metadata
 */
void init_mdata(void);

/* Sets up INS_ADATA datastructure to quickly queue for data.
 *  Instruction arguement abstract-type metadata
 */
void init_adata(void);

#endif // IS_H
