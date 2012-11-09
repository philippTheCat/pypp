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
#include <boost/python.hpp>
#include "uuid.hh"

namespace uuid = python::module::uuid;
namespace bpy = boost::python;

BOOST_PYTHON_MODULE(uuid)
{
    bpy::class_<uuid::Uuid>("UUID")
        .add_property("version", &uuid::Uuid::version)
    ;
    bpy::def("uuid4", uuid::uuid4);
}

