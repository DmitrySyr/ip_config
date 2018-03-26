#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

//#include "PrintCont.h"
#include "lib.h"


// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]

int main(int argc, char const *argv[])
{
    try
    {
        std::vector<std::vector<std::string> > ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }

        // TODO reverse lexicographically sort

        std::sort(ip_pool.rbegin(), ip_pool.rend(), TaskLess);

        std::cout << ip_pool;


        for(const auto& vec : ip_pool) {

            if(filter(vec, std::vector<std::string>{"1", "", "", ""})) {
                std::cout << vec << "\n";
            }
        }

        //=========================

        for(const auto& vec : ip_pool) {

            if(filter(vec, std::vector<std::string>{"46", "70", "", ""})) {
                std::cout << vec << "\n";
            }
        }

        //=========================

        for(const auto& vec : ip_pool) {

            if(filter_any(vec, "46")) {
                std::cout << vec << "\n";
            }
        }

        //=========================




    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
