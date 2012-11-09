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
#include "marshal.hh"
#include <iostream>
#include <python/objects/none.hh>
#include <python/objects/boolean.hh>
#include <python/objects/integer.hh>
#include <python/objects/string.hh>
#include <python/objects/tuple.hh>
#include <python/objects/list.hh>
#include <python/objects/dict.hh>
#include <python/objects/set.hh>
#include <python/objects/code.hh>
#include <python/objects/tuple.hh>

namespace python { namespace vm {
namespace Type {
    enum Type
    {
        Null        = '0',
        None        = 'N',
        False       = 'F',
        True        = 'T',
        Stopiter    = 'S',
        Ellipsis    = '.',
        Int         = 'i',
        Int64       = 'I',
        Float       = 'f',
        BinaryFloat = 'g',
        Complex     = 'x',
        BinaryComplex = 'y',
        Long        = 'l',
        String      = 's',
        Interned    = 't',
        StringRef   = 'R',
        Tuple       = '(',
        List        = '[',
        Dict        = '{',
        Code        = 'c',
        Unicode     = 'u',
        Unknown     = '?',
        Set         = '<',
        FrozenSet   = '>',
    };
} // namespace type


Marshal::Marshal(std::istream& stream)
    : m_stream(stream)
{
    m_depth = 0;
}

Marshal::~Marshal(void)
{
}

Object* Marshal::readObject(void)
{
    ++m_depth;    
    Object* returnVal = 0;
    
    char type = this->readByte();
    switch(type)
    {
        case Type::Null:
            returnVal = 0;
            break;
        
        case Type::None:
            returnVal = &python::objects::NONE;
            break;
            
        //TODO: add Stopiter & Ellipsis
            
        case Type::False:
            returnVal = 0; //&objects::FALSE;
            break;
        
        case Type::True:
            returnVal = 0; // TODO: real boolean 
            break;
            
        case Type::Int:
            returnVal = new objects::Integer(this->readLong());
            break;
            
        //TODO: INT64
            
        case Type::Long:
            returnVal = this->readPyLong();
            break;
            
        //TODO: Float
        case Type::BinaryFloat:
        {
            char buffer[8];
            m_stream.read(buffer, 8);
        }break;
        //TODO: Complex
        //TODO: Type::BinaryComplex
        
            
        case Type::Interned:
            returnVal = new objects::String(m_stream, this->readLong());
            break;

        
        case Type::String:
            returnVal = new objects::String(m_stream, this->readLong());
            break;
           
        case Type::StringRef:
        {
            long n = this->readLong();
            
        }break;
            
        case Type::Unicode:
        {
            long length = this->readLong();
            objects::String* s = new objects::String(m_stream, length);
            break;
        }
        
        case Type::Tuple:
        {
            int n = this->readLong();
            objects::Tuple* tuple = new objects::Tuple(n);
            for(int i = 0;  i < n; ++i)
            {
                tuple->set(i, this->readObject());
            }
            returnVal = tuple;
        }break;
         
        case Type::List:
        {
            int n = this->readLong();
            objects::List* list = new objects::List(n);
            for(int i = 0; i < n; ++i)
            {
                list->set(i, this->readObject());
            }
            returnVal = list;
        }break;
        
        case Type::Dict:
        {
            objects::Dict* dict = new objects::Dict();
            for(;;)
            {
                Object* key = this->readObject();
                if(key == NULL)
                    break;
                Object* value = this->readObject();
                if(value != NULL)
                    dict->set(key, value);
            }
            returnVal = dict;
        }break;
        
        case Type::Set:
        {
            long n = this->readLong();
            objects::Set* set = new objects::Set();
            for(long i = 0; i < n; ++i)
            {
                set->add(this->readObject());
            }
            returnVal = set;
        }break;
        
        case Type::Code:
        {
            int argcount;
            int nlocals;
            int stacksize;
            int flags;
            
            Object* code = 0;
            objects::Tuple* consts = 0;
            Object* names = 0;
            Object* varnames = 0;
            Object* freevars = 0;
            Object* cellvars = 0;
            Object* filename = 0;
            Object* name = 0;
            int firstlineno;
            Object* lnotab = 0;
            
            argcount = this->readLong();
            nlocals = this->readLong();
            stacksize = this->readLong();
            flags = this->readLong();
            
            code = this->readObject();
            if(!code)
                std::cout << "error: code" << std::endl;   
            
            consts = object_cast<objects::Tuple*>(this->readObject());
            if(!consts)
                std::cout << "error: consts" << std::endl;
            
            names = this->readObject();
            if(!names)
                std::cout << "error: names" << std::endl;
            
            varnames = this->readObject();
            if(!varnames)
                std::cout << "error: varnames" << std::endl;
            
            freevars = this->readObject();
            if(!freevars)
                std::cout << "error: freevars" << std::endl;
            
            cellvars = this->readObject();
            if(!cellvars)
                std::cout << "error: cellvars" << std::endl;
            
            filename = this->readObject();
            if(!filename)
                std::cout << "error: filename" << std::endl;
            
            name = this->readObject();
            if(!name)
                std::cout << "error: name" << std::endl;
            firstlineno = this->readLong();
            
            lnotab = this->readObject();    
            if(!lnotab)
                std::cout << "error: lnotab" << std::endl;
                       
            returnVal = new objects::Code(
                argcount,
                nlocals,
                stacksize,
                flags,
                code,
                consts,
                names,
                varnames,
                freevars,
                cellvars,
                filename,
                name,
                firstlineno,
                lnotab
            );
        }break;
        
        default:
        {
            std::cout << "Unknown Marshal Code: 0x" << std::hex << (int) type  << "(" << type << ")" << std::endl;
            returnVal = 0;
            break;
        }
    };
    m_depth--;
    return returnVal;
}



    
    
    
void Marshal::writeByte(char x)
{

}


void Marshal::writeShort(int x)
{
    this->writeByte(static_cast<char>(x & 0xff));
    this->writeByte(static_cast<char>((x >> 8) & 0xff));
}

void Marshal::writeLong(long x)
{
    this->writeByte(static_cast<char>(x & 0xff));
    this->writeByte(static_cast<char>((x >> 8) & 0xff));
    this->writeByte(static_cast<char>((x >> 16) & 0xff));
    this->writeByte(static_cast<char>((x >> 24) & 0xff));
}

char Marshal::readByte(void)
{
    return m_stream.get();
}

long int Marshal::readLong(void)
{
    long x;
    x  = this->readByte();
    x |= (long)this->readByte() << 8;
    x |= (long)this->readByte() << 16;
    x |= (long)this->readByte() << 24;

    /* Sign extension for 64-bit machines */
    x |= -(x & 0x80000000L);
    
    return x;
}

int Marshal::readShort(void)
{
    short x;
    x = this->readByte();
    x |= this->readByte() << 8;
    x |= -(x & 0x8000);
    return x;
}


Object* Marshal::readPyLong(void)
{
    long n = this->readLong();
    
    return 0;
}
    
    
    
}} // namespace python::vm
