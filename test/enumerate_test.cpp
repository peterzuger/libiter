/**
 * @file   libiter/test/enumerate_test.cpp
 * @author Peter Züger
 * @date   17.04.2019
 * @brief  libiter::enumerate tests
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
#include <enumerate.hpp>
#include <iostream>
#include <string>
#include <array>
#include <list>
#include <deque>
#include <sstream>

int main(){
    {
        std::string txt{"abcdefghijklmnopqrstuvwxyz"};
        std::string output{"0a1b2c3d4e5f6g7h8i9j10k11l12m13n14o15p16q17r18s19t20u21v22w23x24y25z"};

        std::stringstream str;
        for(auto&& [i, elem] : libiter::enumerate(txt))
            str << i << elem;
        std::cout << str.str() << "\n" << output << "\n";
        if(str.str() != output){
            std::cerr << "failed\n";
            return 1;
        }
    }
    {
        std::array<char,26> txt{'a','b','c','d','e','f','g','h','i','j','k','l','m',
                                'n','o','p','q','r','s','t','u','v','w','x','y','z'};
        std::string output{"0a1b2c3d4e5f6g7h8i9j10k11l12m13n14o15p16q17r18s19t20u21v22w23x24y25z"};

        std::stringstream str;
        for(auto&& [i, elem] : libiter::enumerate(txt))
            str << i << elem;
        std::cout << str.str() << "\n" << output << "\n";
        if(str.str() != output){
            std::cerr << "failed\n";
            return 1;
        }
    }
    {
        std::list<char> txt{'a','b','c','d','e','f','g','h','i','j','k','l','m',
                            'n','o','p','q','r','s','t','u','v','w','x','y','z'};
        std::string output{"0a1b2c3d4e5f6g7h8i9j10k11l12m13n14o15p16q17r18s19t20u21v22w23x24y25z"};

        std::stringstream str;
        for(auto&& [i, elem] : libiter::enumerate(txt))
            str << i << elem;
        std::cout << str.str() << "\n" << output << "\n";
        if(str.str() != output){
            std::cerr << "failed\n";
            return 1;
        }
    }
    {
        std::deque<char> txt{'a','b','c','d','e','f','g','h','i','j','k','l','m',
                             'n','o','p','q','r','s','t','u','v','w','x','y','z'};
        std::string output{"0a1b2c3d4e5f6g7h8i9j10k11l12m13n14o15p16q17r18s19t20u21v22w23x24y25z"};

        std::stringstream str;
        for(auto&& [i, elem] : libiter::enumerate(txt))
            str << i << elem;
        std::cout << str.str() << "\n" << output << "\n";
        if(str.str() != output){
            std::cerr << "failed\n";
            return 1;
        }
    }
}
