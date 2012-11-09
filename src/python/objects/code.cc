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
#include "code.hh"
#include <iostream>

namespace python { namespace objects {
    
Code::Code(int argcount, int nlocals, int stacksize, int flags, Object* code, Tuple* consts, 
                              Object* names, Object* varnames, Object* freevars, Object* cellvars, Object* filename, 
                              Object* name, int firstlineno, Object* lnotab)
    : Object()
{
    m_argcount = argcount;
    m_nlocals = nlocals;
    m_stacksize = stacksize;
    m_flags = flags;
    m_code = code;
    m_consts = consts;
    m_name = names;
    m_varnames = varnames;
    m_freevars = freevars;
    m_cellvars = cellvars;
    m_filename = filename;
    m_name = name;
    m_firstlineno = firstlineno;
    m_lnotab = lnotab;
}

Code::~Code(void )
{

}

Tuple* Code::constants(void)
{
    return m_consts;
}

Object* Code::code(void)
{
    return m_code;
}


uint8_t Code::type(void ) const
{
    return 4;
}


    
}} // namespace python::objects
