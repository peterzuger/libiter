/**
 * @file   libiter/include/reverse.hpp
 * @author Peter Züger
 * @date   04.04.2019
 * @brief  reverse iterators
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Peter Züger
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef LIBITER_REVERSE_HPP
#define LIBITER_REVERSE_HPP

namespace iter{
    namespace impl{
        template<typename T>
        class reverse{
            using type = T;
            type val;

        public:
            using value_type             = typename type::value_type;
            using pointer                = typename type::pointer;
            using const_pointer          = typename type::const_pointer;
            using reference              = typename type::reference;
            using const_reference        = typename type::const_reference;
            using size_type              = typename type::size_type;
            using difference_type        = typename type::difference_type;
            using iterator               = typename type::reverse_iterator;
            using const_iterator         = typename type::const_reverse_iterator;
            using reverse_iterator       = typename type::iterator;
            using const_reverse_iterator = typename type::const_iterator;

            reverse(const type& other):
                val{other}{}

            constexpr iterator begin()noexcept{
                return val.rbegin();
            }
            constexpr const_iterator begin()const noexcept{
                return val.rbegin();
            }
            constexpr iterator end()noexcept{
                return val.rend();
            }
            constexpr const_iterator end()const noexcept{
                return val.rend();
            }

            // reverse iterators
            constexpr reverse_iterator rbegin()noexcept{
                return val.begin();
            }
            constexpr const_reverse_iterator rbegin()const noexcept{
                return val.begin();
            }
            constexpr reverse_iterator rend()noexcept{
                return val.end();
            }
            constexpr const_reverse_iterator rend()const noexcept{
                return val.end();
            }

            // const iterators
            constexpr const_iterator cbegin()const noexcept{
                return crbegin();
            }
            constexpr const_iterator cend()const noexcept{
                return crend();
            }
            constexpr const_reverse_iterator crbegin()const noexcept{
                return cbegin();
            }
            constexpr const_reverse_iterator crend()const noexcept{
                return cend();
            }
        };
    }

    template<typename T>
    impl::reverse<T> reverse(const T& d){
        return impl::reverse<T>(d);
    }
}

#endif /* LIBITER_REVERSE_HPP */
