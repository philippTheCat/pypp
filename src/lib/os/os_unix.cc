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
#include "os.hh"

#include <stdio.h>
#include <unistd.h>

namespace python { namespace module { namespace os {

std::string name = "unix";

std::string ctermid(void)
{
    return std::string(::ctermid());
}

void chdir(std::string path)
{
    ::chdir(path.c_str());
}

void fchdir(int fd)
{
    ::fchdir(fd);
}

std::string getcwd(void)
{
    return std::string(::getcwd());
}

int system(std::string cmd)
{
    return ::system(cmd.c_str());
}


}}} // namespace python::module::os