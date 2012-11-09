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
#ifndef _PY_TUPLE_
#define _PY_TUPLE_

#include "object.hh"

namespace python { namespace objects {
    
class Tuple : public Object
{
    PY_OBJECT("tuple")
    
public:
    Tuple(long n);
    virtual ~Tuple(void);
    
    void set(long i, Object* object);
    Object* get(long i);
    

private:
    long m_n;
    Object** m_objects;
};
    
}} // namespace python::objects
#endif // _PY_TUPLE_
