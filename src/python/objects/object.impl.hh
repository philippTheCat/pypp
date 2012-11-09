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
namespace python {

template<typename T>
inline std::string object_type(void)
{
    return T::__type_static__();
}

inline std::string object_type(const objects::Object* obj)
{
    return obj->__type__();
}

template<typename T>
T object_cast(objects::Object* obj)
{
    return static_cast<T>(obj);
}



template<typename T>
bool object_is_type(objects::Object* obj)
{
    return object_type<T>() == object_type(obj);
}

template<typename T>
struct object_hash
{
    uint64_t operator()(T* obj)
    {
        return 0;
    }
};    
    
    
} // namespace python
