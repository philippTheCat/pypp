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
#include "object.hh"

namespace python { namespace objects {

Object::Object(void)
{
    m_refcount = 1;
}

Object::~Object(void)
{
}

    
void Object::incref(void)
{
    ++m_refcount;
}
    
void Object::decref(void)
{
    --m_refcount;
}




}} // namespace python::objects

std::ostream& operator<<(std::ostream& stream, const python::objects::Object* obj)
{
    stream << "<object type='" << python::object_type(obj) << "' at='0x" << std::hex << long(obj) << "' >";
    return stream;   
}

