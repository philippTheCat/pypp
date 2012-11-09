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
#ifndef _PYTHON_MARSHAL_
#define _PYTHON_MARSHAL_

#include <istream>

#include <python/objects/object.hh>

namespace python { namespace vm {

using objects::Object;
    
class Marshal
{
public:    
    Marshal(std::istream& stream);
    ~Marshal(void);
    
    

    void writeByte(char x);
    void writeShort(int x);
    void writeLong(long x);
    
    char readByte(void);
    int  readShort(void);
    long readLong(void);
    Object* readObject(void);
    Object* readLastObject(void);
    Object* readPyLong(void);
    
private:
    std::istream& m_stream;
    int m_depth;
    
    
};

}} // namespace python::vm
#endif // _PYTHON_MARSHAL_
