/**
 * @file   libiter/include/enumerate_iterator.hpp
 * @author Peter Züger
 * @date   17.04.2019
 * @brief  enumerate iterators
 *
 * This file is part of libiter (https://gitlab.com/peterzuger/libcrypt).
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
