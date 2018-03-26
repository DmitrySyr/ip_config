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
std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}


bool filter(const std::vector<std::string>& OrigVec
            , const std::vector<std::string>& CondVec
            ) {

    if(OrigVec.size() != CondVec.size()) {
            std::cout << "There is inconsistence in vectors size.\n";
            return false;
        }


    auto OrigIt = OrigVec.cbegin(); auto CondIt = CondVec.cbegin();

    for(
        ;
        OrigIt != OrigVec.cend();
        ++OrigIt, ++CondIt
        ) {

            if((*CondIt != "") && (*OrigIt != *CondIt)) {
                return false;
            }
        }

    return true;
}


bool filter_any(const std::vector<std::string>& OrigVec
            , std::string Cond
            ) {


    if(Cond == "") { return true;}

    for(
        auto OrigIt = OrigVec.cbegin();
        OrigIt != OrigVec.cend();
        ++OrigIt
        ) {

            if((*OrigIt != "") && (*OrigIt == Cond)) {

                return true;
            }
        }

    return false;
}

bool TaskLessHelper(const std::string& lp, const std::string& rp) {

    if(lp.size() < rp.size()) {return true;}
    else if(lp.size() > rp.size()) {return false;}
    else { return lp < rp;}
}

bool TaskLess(const std::vector<std::string>& LeftVec, const std::vector<std::string>& RightVec) {

    auto LeftIt = LeftVec.begin();
    auto RigthIt = RightVec.begin();

    for(; LeftIt != LeftVec.end(); ++LeftIt, ++RigthIt){
        if(*LeftIt != *RigthIt) {
            return TaskLessHelper(*LeftIt, *RigthIt);
        }
    }

    return false;
}

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

        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first byte and output
        // ip = filter(1)


        auto f1 = std::bind(filter, std::placeholders::_1, std::vector<std::string>{"1", "", "", ""});

        std::vector<std::vector<std::string> > tmp(ip_pool.size());

        tmp.clear();

        std::copy_if(ip_pool.cbegin(), ip_pool.cend(), std::back_inserter(tmp), f1);

        std::cout << tmp;

        tmp.clear();


        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first and second bytes and output
        // ip = filter(46, 70)


        auto f2 = std::bind(filter, std::placeholders::_1, std::vector<std::string>{"46", "70", "", ""});

        std::copy_if(ip_pool.cbegin(), ip_pool.cend(), std::back_inserter(tmp), f2);

        std::cout << tmp;

        tmp.clear();

        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // TODO filter by any byte and output
        // ip = filter_any(46)

        std::copy_if(
                        ip_pool.cbegin()
                        , ip_pool.cend()
                        , std::back_inserter(tmp)
                        , std::bind(filter_any, std::placeholders::_1, "46")
                    );


        std::cout << tmp;

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
