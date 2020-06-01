/**
 * @file   libiter/include/count.hpp
 * @author Peter Züger
 * @date   16.02.2020
 * @brief  python count(start, [step]) for C++
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2020 Peter Züger
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
#ifndef LIBITER_COUNT_HPP
#define LIBITER_COUNT_HPP

#include <iterator>
#include <limits>

#include "count_iterator.hpp"

namespace iter{
    namespace impl{
        template<typename T>
        class counter{
            T start;
            T step;

        public:
            using value_type             = T;
            using iterator               = count_iterator<T>;
            using const_iterator         = const iterator;
            using reverse_iterator       = std::reverse_iterator<iterator>;
            using const_reverse_iterator = const reverse_iterator;

            static_assert(std::is_integral_v<T>, "iter::counter<T> must be of integral type");

            counter(const value_type& _start, const value_type& _step):
                start{_start},
                step{_step}{}

            constexpr iterator begin()noexcept{
                return iterator(start, step);
            }
            constexpr const_iterator begin()const noexcept{
                return const_iterator(start, step);
            }
            constexpr iterator end()noexcept{
                return iterator(std::numeric_limits<value_type>::max(), step);
            }
            constexpr const_iterator end()const noexcept{
                return iterator(std::numeric_limits<value_type>::max(), step);
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
    impl::counter<T> count(const T& start, const T& step = 1){
        return impl::counter<T>(start, step);
    }
}

#endif /* LIBITER_COUNT_HPP */
