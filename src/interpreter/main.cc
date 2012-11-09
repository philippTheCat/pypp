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
#include <iostream>
#include <fstream>

#include <python/vm/marshal.hh>
#include <python/vm/interpreter.hh>
#include <python/objects/code.hh>

using python::objects::Code;
using python::objects::Object;
using python::objects::Frame;
using python::object_cast;
using python::vm::Interpreter;

int main(int argc, char** argv)
{
    std::ifstream in;
    in.open("/home/klemens/tmp/test.pyc", std::ios::in);
    if(!in.good())
    {
        std::cerr << "Error opening file..." << std::endl;
        return 1;
    }
    
    python::vm::Marshal m(in);

    
    long magic = m.readLong();
    long timestamp = m.readLong();   

    Frame* frame = new Frame;
    frame->setCode(object_cast<Code*>(m.readObject()));


    std::cout << frame << std::endl;
    
    Interpreter* p = new Interpreter();
    
    p->exec(frame);
    

    
    
    return 0;
};
