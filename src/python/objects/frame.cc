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
#include "frame.hh"

namespace python { namespace objects {
    
Frame::Frame(void)
    : Object()
{   
    m_back = 0;
    m_code = 0;
    m_builtins = new Dict();
    m_globals = new Dict();
    m_locals = new Dict();
}

Frame::~Frame(void)
{
    delete m_builtins;
    delete m_globals;
    delete m_locals;
}

void Frame::setCode(Code* code)
{
    if(m_code)
        m_code->decref();
    m_code = code;
    code->incref();
}

    
    
}} // namespace python::objects
