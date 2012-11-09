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
#include "string.hh"

namespace python { namespace objects {

String::String(std::istream& in, long length)
    : Object(), m_length(length)
{
    m_data = new char[length + 1];
    in.read(m_data, length);
    m_data[length] = '\0';
}

String::~String(void)
{
    delete m_data;
}

long int String::length(void) const
{
    return m_length;
}


char String::at(long pos)
{
    return m_data[pos];
}
    
    
}} // namespace python::objects
    