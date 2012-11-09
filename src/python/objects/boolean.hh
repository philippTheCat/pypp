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
#ifndef _PY_BOOLEAN_
#define _PY_BOOLEAN_

#include "object.hh"

namespace python { namespace objects {

class Boolean : public Object
{
    PY_OBJECT("boolean")
public:
    Boolean(void);
    ~Boolean(void);
    
};


}} // namespace python::objects;
#endif // _PY_BOOLEAN_
