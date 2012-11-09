/*
 * This file is part of PyPP.
 *
 * PyPP is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PyPP is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PyPP.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _PY_OPCODE_
#define _PY_OPCODE_

namespace python { namespace vm {

enum Opcode 
{
    STOP_CODE       = 0,
    POP_TOP         = 1,
    ROT_TWO         = 2,
    ROT_THREE       = 3,
    DUP_TOP         = 4,
    ROT_FOUR        = 5,
    NOP             = 9,
    
    UNARY_POSITIVE  = 10,
    UNARY_NEGATIVE  = 11,
    UNARY_NOT       = 12,
    UNARY_CONVERT   = 13,
    
    UNARY_INVERT    = 15,
    
    BINARY_POWER    = 19,
    
    BINARY_MULTIPLY = 20,
    BINARY_DIVIDE   = 21,
    BINARY_MODULO   = 22,
    BINARY_ADD      = 23,
    BINARY_SUBTRACT = 24,
    BINARY_SUBSCR   = 25,
    BINARY_FLOOR_DIVIDE = 26,
    BINARY_TRUE_DIVIDE = 27,
    INPLACE_FLOOR_DIVIDE = 28,
    INPLACE_TRUE_DIVIDE = 29,
    
    SLICE   = 30,
    /* Also uses 31-33 */
    
    STORE_SLICE = 40,
    /* Also uses 41-43 */
    
    DELETE_SLICE = 50,
    /* Also uses 51-53 */
    
    STORE_MAP = 54,
    INPLACE_ADD = 55,
    INPLACE_SUBTRACT = 56,
    INPLACE_MULTIPLY = 57,
    INPLACE_DIVIDE = 58,
    INPLACE_MODULO = 59,
    STORE_SUBSCR = 60,
    DELETE_SUBSCR = 61,
    
    BINARY_LSHIFT   = 62,
    BINARY_RSHIFT   = 63,
    BINARY_AND      = 64,
    BINARY_XOR      = 65,
    BINARY_OR       = 66,
    INPLACE_POWER   = 67,
    GET_ITER        = 68,
    
    PRINT_EXPR      = 70,
    PRINT_ITEM      = 71,
    PRINT_NEWLINE   = 72,
    PRINT_ITEM_TO   = 73,
    PRINT_NEWLINE_TO = 74,
    INPLACE_LSHIFT = 75,
    INPLACE_RSHIFT = 76,
    INPLACE_AND = 77,
    INPLACE_XOR = 78,
    INPLACE_OR = 79,
    BREAK_LOOP = 80,
    WITH_CLEANUP = 81,
    LOAD_LOCALS = 82,
    RETURN_VALUE = 83,
    IMPORT_STAR = 84,
    EXEC_STMT = 85,
    YIELD_VALUE = 86,
    POP_BLOCK = 87,
    END_FINALLY = 88,
    BUILD_CLASS = 89,
    
    HAVE_ARGUMENT = 90, /* Opcodes from here have an argument: */
    
    STORE_NAME = 90,
    DELETE_NAME = 91,
    UNPACK_SEQUENCE = 92,
    FOR_ITER = 93,
    LIST_APPEND = 94,
    
    STORE_ATTR = 95,
    DELETE_ATTR = 96,
    STORE_GLOBAL = 97,
    DELETE_GLOBAL = 98,
    DUP_TOPX = 99,
    LOAD_CONST = 100,
    LOAD_NAME = 101,
    BUILD_TUPLE = 102,
    BUILD_LIST = 103,
    BUILD_SET = 104,
    BUILD_MAP = 105,
    LOAD_ATTR = 106,
    COMPARE_OP = 107,
    IMPORT_NAME = 108,
    IMPORT_FROM = 109,
    JUMP_FORWARD = 110,
    
    JUMP_IF_FALSE_OR_POP = 111,
    JUMP_IF_TRUE_OR_POP = 112,
    JUMP_ABSOLUTE = 113,
    POP_JUMP_IF_FALSE = 114,
    POP_JUMP_IF_TRUE = 115,
    
    LOAD_GLOBAL = 116,
    
    CONTINUE_LOOP = 119,
    SETUP_LOOP = 120,
    SETUP_EXCEPT = 121,
    SETUP_FINALLY = 122,
    
    LOAD_FAST = 124,
    STORE_FAST = 125,
    DELETE_FAST = 126,
    
    RAISE_VARARGS = 130,
    CALL_FUNCTION = 131,
    MAKE_FUNCTION = 132,
    BUILD_SLICE = 133,
    
    MAKE_CLOSURE = 134,
    LOAD_CLOSURE = 135,
    LOAD_DEREF = 136,
    STORE_DEREF = 137,
    
    CALL_FUNCTION_VAR       = 140, // #args + (#kwargs << 8) 
    CALL_FUNCTION_KW        = 141, // #args + (#kwargs << 8) 
    CALL_FUNCTION_VAR_KW    = 142, // #args + (#kwargs << 8) 
    
    SETUP_WITH              = 143,
    
    EXTENDED_ARG            = 145,
    
    SET_ADD                 = 146,
    MAP_ADD                 = 147,
}; // enum Opcode   
    

template<typename T>
inline bool has_arg(T op)
{
    return (static_cast<Opcode>(op)) >= HAVE_ARGUMENT;
}
    
    
}} // namespace python::vm
#endif // _PY_OPCODE_
