/**
 * @file   libiter/test/reverse_test.cpp
 * @author Peter Züger
 * @date   05.04.2019
 * @brief  libiter::reverse tests
 */
#include <reverse.hpp>
#include <iostream>
#include <string>
#include <array>
#include <list>
#include <deque>
#include <sstream>

int main(){
    {
        std::string txt{"abcdefghijklmnopqrstuvwxyz"};
        std::string output{"zyxwvutsrqponmlkjihgfedcba"};

        std::stringstream str;
        for(const auto& i : libiter::reverse(txt))
            str << i;
        std::cout << str.str() << "\n" << output << "\n";
        if(str.str() != output){
            std::cerr << "failed\n";
            return 1;
        }
    }
    {
        std::array<char,26> txt{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        std::string output{"zyxwvutsrqponmlkjihgfedcba"};

        std::stringstream str;
        for(const auto& i : libiter::reverse(txt))
            str << i;
        std::cout << str.str() << "\n" << output << "\n";
        if(str.str() != output){
            std::cerr << "failed\n";
            return 1;
        }
    }
    {
        std::list<char> txt{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        std::string output{"zyxwvutsrqponmlkjihgfedcba"};

        std::stringstream str;
        for(const auto& i : libiter::reverse(txt))
            str << i;
        std::cout << str.str() << "\n" << output << "\n";
        if(str.str() != output){
            std::cerr << "failed\n";
            return 1;
        }
    }
    {
        std::deque<char> txt{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        std::string output{"zyxwvutsrqponmlkjihgfedcba"};

        std::stringstream str;
        for(const auto& i : libiter::reverse(txt))
            str << i;
        std::cout << str.str() << "\n" << output << "\n";
        if(str.str() != output){
            std::cerr << "failed\n";
            return 1;
        }
    }
}
