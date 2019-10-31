/**
 * @file   libiter/include/range_iterator.hpp
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
#ifndef LIBITER_RANGE_ITERATOR_HPP
#define LIBITER_RANGE_ITERATOR_HPP

#include <iterator>

namespace libiter{
    template<int start, int stop, int step>
    class range_iterator{
        int current;

    public:
        using value_type        = int;
        using pointer           = value_type*;
        using reference         = value_type&;
        using difference_type   = std::size_t;
        using iterator_category = std::random_access_iterator_tag;

        static_assert(start < stop,
                      "libiter::range_iterator: range must be positive ( start < stop )");
        static_assert(!(( stop - start ) % step),
                      "libiter::range_iterator: range must terminate (( stop - start ) % step)");

        constexpr range_iterator():current{0}{}
        constexpr range_iterator(value_type x):current{x}{}
        constexpr range_iterator(const range_iterator<start, stop, step>& x):current{x.base()}{}

        constexpr range_iterator& operator=(const range_iterator& u){
            current = u.base();
            return *this;
        }

        constexpr value_type base() const{
            return current;
        }
        constexpr reference operator*(){
            return current;
        }

        constexpr range_iterator& operator++(){
            current += step;
            return *this;
        }
        constexpr range_iterator operator++(int){
            range_iterator tmp = *this;
            current += step;
            return tmp;
        }
        constexpr range_iterator& operator--(){
            current -= step;
            return *this;
        }
        constexpr range_iterator operator--(int){
            range_iterator tmp = *this;
            current -= step;
            return tmp;
        }

        constexpr range_iterator operator+ (difference_type n) const{
            return range_iterator(current + ( n * step ));
        }
        constexpr range_iterator& operator+=(difference_type n){
            current += (n * step);
            return *this;
        }

        constexpr range_iterator operator- (difference_type n) const{
            return range_iterator(current - (n * step));
        }
        constexpr range_iterator& operator-=(difference_type n){
            current -= (n * step);
            return *this;
        }

        constexpr value_type operator[](difference_type n) const{
            return n * step;
        }
    };

    template<int start1, int stop1, int step1,
             int start2, int stop2, int step2>
    constexpr bool operator==(
        const range_iterator<start1, stop1, step1>& x,
        const range_iterator<start2, stop2, step2>& y){
        return x.base() == y.base();
    }

    template<int start1, int stop1, int step1,
             int start2, int stop2, int step2>
    constexpr bool operator!=(
        const range_iterator<start1, stop1, step1>& x,
        const range_iterator<start2, stop2, step2>& y){
        return x.base() != y.base();
    }

    template<int start1, int stop1, int step1,
             int start2, int stop2, int step2>
    constexpr bool operator<(
        const range_iterator<start1, stop1, step1>& x,
        const range_iterator<start2, stop2, step2>& y){
        return x.base() < y.base();
    }

    template<int start1, int stop1, int step1,
             int start2, int stop2, int step2>
    constexpr bool operator>(
        const range_iterator<start1, stop1, step1>& x,
        const range_iterator<start2, stop2, step2>& y){
        return x.base() > y.base();
    }

    template<int start1, int stop1, int step1,
             int start2, int stop2, int step2>
    constexpr bool operator>=(
        const range_iterator<start1, stop1, step1>& x,
        const range_iterator<start2, stop2, step2>& y){
        return x.base() >= y.base();
    }

    template<int start1, int stop1, int step1,
             int start2, int stop2, int step2>
    constexpr bool operator<=(
        const range_iterator<start1, stop1, step1>& x,
        const range_iterator<start2, stop2, step2>& y){
        return x.base() <= y.base();
    }
}

#endif /* LIBITER_RANGE_ITERATOR_HPP */
