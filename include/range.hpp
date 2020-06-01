/**
 * @file   libiter/include/range.hpp
 * @author Peter Züger
 * @date   04.04.2019
 * @brief  python range(start, stop, step) for C++
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
#ifndef LIBITER_RANGE_HPP
#define LIBITER_RANGE_HPP

#include <cstddef>
#include <iterator>

#include "range_iterator.hpp"

namespace iter{
    template<int start, int stop, int step = 1>
    class range{
    public:
        using value_type             = int;
        using pointer                = value_type*;
        using const_pointer          = const pointer;
        using reference              = value_type&;
        using const_reference        = const reference;
        using size_type              = std::size_t;
        using difference_type        = std::ptrdiff_t;
        using iterator               = range_iterator<start, stop, step>;
        using const_iterator         = const iterator;
        using reverse_iterator       = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;

        constexpr iterator begin()noexcept{
            return iterator(start);
        }
        constexpr const_iterator begin()const noexcept{
            return const_iterator(start);
        }
        constexpr iterator end()noexcept{
            return iterator(stop);
        }
        constexpr const_iterator end()const noexcept{
            return const_iterator(stop);
        }

        // reverse iterators
        constexpr reverse_iterator rbegin()noexcept{
            return reverse_iterator(stop);
        }
        constexpr const_reverse_iterator rbegin()const noexcept{
            return const_reverse_iterator(stop);
        }
        constexpr reverse_iterator rend()noexcept{
            return reverse_iterator(start);
        }
        constexpr const_reverse_iterator rend()const noexcept{
            return const_reverse_iterator(start);
        }

        // const iterators
        constexpr const_iterator cbegin()const noexcept{
            return begin();
        }
        constexpr const_iterator cend()const noexcept{
            return end();
        }
        constexpr const_reverse_iterator crbegin()const noexcept{
            return rbegin();
        }
        constexpr const_reverse_iterator crend()const noexcept{
            return rend();
        }
    };
}

#endif /* LIBITER_RANGE_HPP */
