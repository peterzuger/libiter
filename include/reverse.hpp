/**
 * @file   libiter/include/reverse.hpp
 * @author Peter Züger
 * @date   04.04.2019
 * @brief  reverse iterators
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
#ifndef LIBITER_REVERSE_HPP
#define LIBITER_REVERSE_HPP

namespace libiter{
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

            reverse(const T& other):val{other}{}

            constexpr iterator begin() noexcept{
                return val.rbegin();
            }
            constexpr const_iterator begin() const noexcept{
                return val.rbegin();
            }
            constexpr iterator end() noexcept{
                return val.rend();
            }
            constexpr const_iterator end() const noexcept{
                return val.rend();
            }

            // reverse iterators
            constexpr reverse_iterator rbegin() noexcept{
                return val.begin();
            }
            constexpr const_reverse_iterator rbegin() const noexcept{
                return val.begin();
            }
            constexpr reverse_iterator rend() noexcept{
                return val.end();
            }
            constexpr const_reverse_iterator rend() const noexcept{
                return val.end();
            }

            // const iterators
            constexpr const_iterator cbegin() const noexcept{
                return crbegin();
            }
            constexpr const_iterator cend() const noexcept{
                return crend();
            }
            constexpr const_reverse_iterator crbegin() const noexcept{
                return cbegin();
            }
            constexpr const_reverse_iterator crend() const noexcept{
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
