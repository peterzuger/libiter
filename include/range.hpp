/**
 * @file   libiter/include/range.hpp
 * @author Peter Züger
 * @date   04.04.2019
 * @brief  python range(start, stop, step) for C++
 *
 * This file is part of libiter (https://gitlab.com/peterzuger/libiter).
 * Copyright (c) 2019 Peter Züger.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBITER_RANGE_HPP
#define LIBITER_RANGE_HPP

#include <cstddef>
#include <iterator>

#include "range_iterator.hpp"

namespace libiter{
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

        constexpr iterator begin() noexcept{
            return iterator(start);
        }
        constexpr const_iterator begin() const noexcept{
            return const_iterator(start);
        }
        constexpr iterator end() noexcept{
            return iterator(stop);
        }
        constexpr const_iterator end() const noexcept{
            return const_iterator(stop);
        }

        // reverse iterators
        constexpr reverse_iterator rbegin() noexcept{
            return reverse_iterator(stop);
        }
        constexpr const_reverse_iterator rbegin() const noexcept{
            return const_reverse_iterator(stop);
        }
        constexpr reverse_iterator rend() noexcept{
            return reverse_iterator(start);
        }
        constexpr const_reverse_iterator rend() const noexcept{
            return const_reverse_iterator(start);
        }

        // const iterators
        constexpr const_iterator cbegin() const noexcept{
            return begin();
        }
        constexpr const_iterator cend() const noexcept{
            return end();
        }
        constexpr const_reverse_iterator crbegin() const noexcept{
            return rbegin();
        }
        constexpr const_reverse_iterator crend() const noexcept{
            return rend();
        }
    };
}

#endif /* LIBITER_RANGE_HPP */
