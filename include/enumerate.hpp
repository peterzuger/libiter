/**
 * @file   libiter/include/enumerate.hpp
 * @author Peter Züger
 * @date   17.4.2019
 * @brief  enumerate iterators
 */
#ifndef LIBITER_ENUMERATE_HPP
#define LIBITER_ENUMERATE_HPP

#include "enumerate_iterator.hpp"
#include <iterator>

namespace libiter{
    namespace impl{
        template<typename T>
        class enumerator{
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
            using iterator               = enumerate_iterator<typename type::iterator>;
            using const_iterator         = const iterator;
            using reverse_iterator       = enumerate_iterator<typename type::reverse_iterator>;
            using const_reverse_iterator = const reverse_iterator;

            enumerator(const T& other):val{other}{}

            constexpr iterator begin() noexcept{
                return iterator(val.begin(), 0);
            }
            constexpr const_iterator begin() const noexcept{
                return const_iterator(val.begin(), 0);
            }
            constexpr iterator end() noexcept{
                return iterator(val.end(), std::distance(val.begin(), val.end()));
            }
            constexpr const_iterator end() const noexcept{
                return const_iterator(val.end(), std::distance(val.begin(), val.end()));
            }

            // reverse iterators
            constexpr reverse_iterator rbegin() noexcept{
                return reverse_iterator(val.rbegin(), std::distance(val.begin(), val.end()));
            }
            constexpr const_reverse_iterator rbegin() const noexcept{
                return const_reverse_iterator(val.rbegin(), std::distance(val.begin(), val.end()));
            }
            constexpr reverse_iterator rend() noexcept{
                return reverse_iterator(val.rend(), 0);
            }
            constexpr const_reverse_iterator rend() const noexcept{
                return const_reverse_iterator(val.rend(), 0);
            }

            // const iterators
            constexpr const_iterator cbegin() const noexcept{
                return cbegin();
            }
            constexpr const_iterator cend() const noexcept{
                return cend();
            }
            constexpr const_reverse_iterator crbegin() const noexcept{
                return crbegin();
            }
            constexpr const_reverse_iterator crend() const noexcept{
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