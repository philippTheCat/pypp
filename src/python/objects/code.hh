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
#ifndef _PY_CODE_
#define _PY_CODE_

#include "object.hh"
#include "tuple.hh"

namespace python { namespace objects {
   
    
class Code : public Object
{
    PY_OBJECT("code")
public:
    Code(int argcount, int nlocals, int stacksize, int flags,
        Object* code, Tuple* consts, Object* names, Object* varnames,
         Object* freevars, Object* cellvars, Object* filename, Object* name,
         int firstlineno, Object* lnotab
    );
    
    virtual ~Code(void);
    
    Object* code(void);
    Tuple* constants(void);
    
    
    // Object
    virtual uint8_t type(void) const;
    
private:
    int m_argcount;
    int m_nlocals;
    int m_stacksize;
    int m_flags;
    Object* m_code;
    Tuple* m_consts; // Tuple
    Object* m_names;
    Object* m_varnames;
    Object* m_freevars;
    Object* m_cellvars;
    Object* m_filename;
    Object* m_name;
    int m_firstlineno;
    Object* m_lnotab;
};  
}} // namespace python::objects
#endif // _PY_CODE_
