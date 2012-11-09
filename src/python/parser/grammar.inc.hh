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
#ifndef _PY_PARSER_GRAMMAR_
#define _PY_PARSER_GRAMMAR_

#include <boost/spirit/include/qi.hpp>

namespace python { namespace parser { namespace internal {

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

template<typename Iterator>
struct grammar : public qi::grammar<Iterator, qi::space_type>
{
    grammar(void) : grammar::base_type(script_file)
    {
        using ascii::char_;
        using ascii::alpha;
        using ascii::alnum;
        
        // Primitives
        NAME = qi::lexeme[alpha >> +(alnum | char_('_'))];
        
        script_file = +NAME;
        
        
    }
    
    
    qi::rule<Iterator, qi::space_type> NAME;
    
    
    
    qi::rule<Iterator, qi::space_type> script_file;
};
    
    
    

}}} // namespace python::parser::internal
#endif // _PY_PARSER_GRAMMAR_
