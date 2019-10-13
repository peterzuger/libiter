/**
 * @file   libiter/test/range_test.cpp
 * @author Peter Züger
 * @date   05.04.2019
 * @brief  libiter::range<start, stop, step> tests
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
#include <iostream>
#include <sstream>

#include <range.hpp>

int main(){
    {
        std::string output{"0123456789"};

        std::stringstream str;
        for(const auto& i : libiter::range<0, 10>{})
            str << i;
        std::cout << str.str() << "\n" << output << "\n";
        if(str.str() != output){
            std::cerr << "failed\n";
            return 1;
        }
    }
    {
        std::string output{"0246810"};

        std::stringstream str;
        for(const auto& i : libiter::range<0, 12, 2>{})
            str << i;
        std::cout << str.str() << "\n" << output << "\n";
        if(str.str() != output){
            std::cerr << "failed\n";
            return 1;
        }
    }
}
