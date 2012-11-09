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
#ifndef _PY_FRAME_
#define _PY_FRAME_

#include <stack>

#include "object.hh"
#include "code.hh"
#include "dict.hh"
#include "file.hh"


namespace python { namespace objects {

class Frame : public Object
{
    PY_OBJECT("frame")
public:
    Frame(void);
    ~Frame(void);
    
    void setCode(Code* code);
    
private:
    Frame* m_back; // previous frame or 0
    Code* m_code;
    
    Dict* m_builtins;
    Dict* m_globals;
    Dict* m_locals;
    
    int m_lasti; // last instruction
    int m_lineno; // current line number
}; // class Frame
}} // namespace python::objects
#endif // _PY_FRAME_
