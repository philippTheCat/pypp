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
#include "tuple.hh"

namespace python { namespace objects {

Tuple::Tuple(long n)
    : m_n(n)
{
    m_objects = new Object*[n];
}


Tuple::~Tuple(void)
{
    delete m_objects;
}

void Tuple::set(long int i, Object* object)
{
    m_objects[i] = object;
}

Object* Tuple::get(long i)
{
    return m_objects[i];
}

    
}} // namespace python::objects
    