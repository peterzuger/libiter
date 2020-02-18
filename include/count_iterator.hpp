/**
 * @file   libiter/include/count_iterator.hpp
 * @author Peter Züger
 * @date   18.02.2020
 * @brief  count iterators
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
#ifndef LIBITER_COUNT_ITERATOR_HPP
#define LIBITER_COUNT_ITERATOR_HPP

#include <iterator>
#include <utility>

namespace iter{
    namespace impl{
        template<typename T>
        class count_iterator{
            T value;

        public:
            using iterator_category = std::random_access_iterator_tag;
            using value_type        = T;
            using difference_type   = T;

            static_assert(std::is_integral_v<T>, "iter::count_iterator<T> must be of integral type");

            constexpr count_iterator(const value_type& v): value{v}{}

            constexpr value_type base() const{
                return value;
            }

            template <class U>
            constexpr count_iterator& operator=(const count_iterator<U>& u){
                value = u.value;
                return *this;
            }

            constexpr auto operator*() const{
                return value;
            }

            constexpr count_iterator& operator++(){
                ++value;
                return *this;
            }
            constexpr count_iterator operator++(int){
                count_iterator tmp(*this);
                ++value;
                return tmp;
            }
            constexpr count_iterator& operator--(){
                --value;
                return *this;
            }
            constexpr count_iterator operator--(int){
                count_iterator tmp(*this);
                --value;
                return tmp;
            }

            constexpr count_iterator operator+ (difference_type n) const{
                return count_iterator(value + n);
            }
            constexpr count_iterator& operator+=(difference_type n){
                value += n;
                return *this;
            }

            constexpr count_iterator operator- (difference_type n) const{
                return count_iterator(value - n);
            }
            constexpr count_iterator& operator-=(difference_type n){
                value -= n;
                return *this;
            }

            constexpr value_type operator[](difference_type n) const{
                return *(*this + n);
            }
        };

        template<class V1, class V2>
        constexpr bool operator==(
            const count_iterator<V1>& x,
            const count_iterator<V2>& y){
            return x.base() == y.base();
        }

        template<class V1, class V2>
        constexpr bool operator!=(
            const count_iterator<V1>& x,
            const count_iterator<V2>& y){
            return x.base() != y.base();
        }

        template<class V1, class V2>
        constexpr bool operator<(
            const count_iterator<V1>& x,
            const count_iterator<V2>& y){
            return x.base() < y.base();
        }

        template<class V1, class V2>
        constexpr bool operator>(
            const count_iterator<V1>& x,
            const count_iterator<V2>& y){
            return x.base() > y.base();
        }

        template<class V1, class V2>
        constexpr bool operator>=(
            const count_iterator<V1>& x,
            const count_iterator<V2>& y){
            return x.base() >= y.base();
        }

        template<class V1, class V2>
        constexpr bool operator<=(
            const count_iterator<V1>& x,
            const count_iterator<V2>& y){
            return x.base() <= y.base();
        }
    }
}

#endif /* LIBITER_COUNT_ITERATOR_HPP */
