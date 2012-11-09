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
#ifndef _PY_OBJECT_
#define _PY_OBJECT_

#include <string>
#include <ostream>
#include <boost/cstdint.hpp>

namespace python { namespace objects {

#define PY_OBJECT(type_name)                                \
public:                                                    \
    static std::string __type_static__(void) { return std::string(type_name); } \
    virtual std::string __type__(void) const { return std::string(type_name); }
        
struct Object
{
public:
    Object(void);
    virtual ~Object(void);
    
    virtual std::string __type__(void) const = 0;
        
    virtual void incref(void);
    virtual void decref(void);
    
private:
    int m_refcount;
};  
} // namespace objects


std::string object_type(const objects::Object* obj);
template<typename T> std::string object_type(void);


} // namespace python


std::ostream& operator<<(std::ostream& out, const python::objects::Object* obj);

#include "object.impl.hh"

#endif // _PY_OBJECT_
