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
#include "os.hh"

namespace os = python::module::os;
namespace bpy = boost::python;

BOOST_PYTHON_MODULE(os)
{
    // Variables
    bpy::def_readonly("name", os::name);
    
    
    // Process Parameters
    bpy::def("ctermid", os::ctermid);
    bpy::def("chdir", os::chdir);
    bpy::def("fchdir", os::fchdir);
    bpy::def("getcwd", os::getcwd);
    
    bpy::def("system", os::system);
}
