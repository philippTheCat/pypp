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
#ifndef _PY_PARSER_
#define _PY_PARSER_

#include <string>
#include <istream>

namespace python { namespace parser {

class Parser
{
public:
    Parser(void);
    ~Parser(void);
    
    void parse(const std::string& code);
    void parse(std::istream& in);
    
}; // class Parser
}} // namespace python::parser
#endif // _PY_PARSER_
