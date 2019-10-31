/**
 * @file   libiter/include/enumerate_iterator.hpp
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
#ifndef LIBITER_ENUMERATE_ITERATOR_HPP
#define LIBITER_ENUMERATE_ITERATOR_HPP

#include <iterator>
#include <utility>

namespace libiter{
    namespace impl{
        template<class Iterator>
        class enumerate_iterator{
        protected:
            Iterator current;
            std::size_t index;

        public:
            using iterator_type     = Iterator;
            using iterator_category = typename std::iterator_traits<Iterator>::iterator_category;
            using value_type        = std::pair<std::size_t, typename std::iterator_traits<Iterator>::value_type>;
            using difference_type   = typename std::iterator_traits<Iterator>::difference_type;
            using pointer           = std::pair<std::size_t, typename std::iterator_traits<Iterator>::pointer>;
            using reference         = std::pair<std::size_t, typename std::iterator_traits<Iterator>::reference>;

            constexpr enumerate_iterator():current{}, index{}{}

            constexpr enumerate_iterator(Iterator x, std::size_t i):current{x}, index{i}{}

            template <class U>
            constexpr enumerate_iterator(const enumerate_iterator<U>& u):current{u.current}, index{u.index}{}

            template <class U>
            constexpr enumerate_iterator& operator=(const enumerate_iterator<U>& u){
                current = u.current;
                index = u.index;
                return *this;
            }

            constexpr iterator_type base() const{
                return current;
            }

            constexpr auto operator*() const{
                return std::make_pair(index, *current);
            }

            constexpr enumerate_iterator& operator++(){
                ++current;
                ++index;
                return *this;
            }
            constexpr enumerate_iterator operator++(int){
                enumerate_iterator tmp(*this);
                ++current;
                ++index;
                return tmp;
            }
            constexpr enumerate_iterator& operator--(){
                --current;
                --index;
                return *this;
            }
            constexpr enumerate_iterator operator--(int){
                enumerate_iterator tmp(*this);
                --current;
                --index;
                return tmp;
            }

            constexpr enumerate_iterator operator+ (difference_type n) const{
                return enumerate_iterator(current + n, index + n);
            }
            constexpr enumerate_iterator& operator+=(difference_type n){
                current += n;
                index += n;
                return *this;
            }

            constexpr enumerate_iterator operator- (difference_type n) const{
                return enumerate_iterator(current - n, index - n);
            }
            constexpr enumerate_iterator& operator-=(difference_type n){
                current -= n;
                index -= n;
                return *this;
            }

            constexpr reference operator[](difference_type n) const{
                return *(*this + n);
            }
        };

        template<class Iterator1, class Iterator2>
        constexpr bool operator==(
            const enumerate_iterator<Iterator1>& x,
            const enumerate_iterator<Iterator2>& y){
            return x.base() == y.base();
        }

        template<class Iterator1, class Iterator2>
        constexpr bool operator!=(
            const enumerate_iterator<Iterator1>& x,
            const enumerate_iterator<Iterator2>& y){
            return x.base() != y.base();
        }

        template<class Iterator1, class Iterator2>
        constexpr bool operator<(
            const enumerate_iterator<Iterator1>& x,
            const enumerate_iterator<Iterator2>& y){
            return x.base() < y.base();
        }

        template<class Iterator1, class Iterator2>
        constexpr bool operator>(
            const enumerate_iterator<Iterator1>& x,
            const enumerate_iterator<Iterator2>& y){
            return x.base() > y.base();
        }

        template<class Iterator1, class Iterator2>
        constexpr bool operator>=(
            const enumerate_iterator<Iterator1>& x,
            const enumerate_iterator<Iterator2>& y){
            return x.base() >= y.base();
        }

        template<class Iterator1, class Iterator2>
        constexpr bool operator<=(
            const enumerate_iterator<Iterator1>& x,
            const enumerate_iterator<Iterator2>& y){
            return x.base() <= y.base();
        }
    }
}

#endif /* LIBITER_ENUMERATE_ITERATOR_HPP */
