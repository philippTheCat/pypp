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
#ifndef _PY_INTERPRETER_
#define _PY_INTERPRETER_

#include <stack>

#include <python/objects/frame.hh>

namespace python { namespace vm {

class Interpreter 
{
public:
    Interpreter(void);
    ~Interpreter(void);
    
    void exec(objects::Frame* code);
    
private:
    std::stack<objects::Object*> m_stack;
    
}; // class Interpreter

}} // namespace python::vm
#endif // _PY_INTERPRETER_
