/**
 * @file   libiter/include/enumerate.hpp
 * @author Peter Züger
 * @date   17.04.2019
 * @brief  enumerate iterators
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
#ifndef LIBITER_ENUMERATE_HPP
#define LIBITER_ENUMERATE_HPP

#include <iterator>

#include "enumerate_iterator.hpp"

namespace iter{
    namespace impl{
        template<typename T>
        class enumerator{
            using type = T;
            type val;

        public:
            using value_type             = std::pair<std::size_t, typename type::value_type>;
            using pointer                = value_type*;
            using const_pointer          = const pointer;
            using reference              = value_type&;
            using const_reference        = const reference;
            using size_type              = typename type::size_type;
            using difference_type        = typename type::difference_type;
            using iterator               = enumerate_iterator<typename type::iterator>;
            using const_iterator         = const iterator;
            using reverse_iterator       = std::reverse_iterator<iterator>;
            using const_reverse_iterator = const reverse_iterator;

            enumerator(const T& other):
                val{other}{}

            constexpr iterator begin()noexcept{
                return iterator(val.begin(), 0);
            }
            constexpr const_iterator begin()const noexcept{
                return const_iterator(val.begin(), 0);
            }
            constexpr iterator end()noexcept{
                return iterator(val.end(), std::distance(val.begin(), val.end()));
            }
            constexpr const_iterator end()const noexcept{
                return const_iterator(val.end(), std::distance(val.begin(), val.end()));
            }

            // reverse iterators
            constexpr reverse_iterator rbegin()noexcept{
                return reverse_iterator(end());
            }
            constexpr const_reverse_iterator rbegin()const noexcept{
                return const_reverse_iterator(end());
            }
            constexpr reverse_iterator rend()noexcept{
                return reverse_iterator(begin());
            }
            constexpr const_reverse_iterator rend()const noexcept{
                return const_reverse_iterator(begin());
            }

            // const iterators
            constexpr const_iterator cbegin()const noexcept{
                return cbegin();
            }
            constexpr const_iterator cend()const noexcept{
                return cend();
            }
            constexpr const_reverse_iterator crbegin()const noexcept{
                return crbegin();
            }
            constexpr const_reverse_iterator crend()const noexcept{
                return crend();
            }
        };
    }

    template<typename T>
    impl::enumerator<T> enumerate(const T& d){
        return impl::enumerator<T>(d);
    }
}

#endif /* LIBITER_REVERSE_HPP */
