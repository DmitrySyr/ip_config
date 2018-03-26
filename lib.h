#pragma once

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <sstream>
#include <cstdint>

#include "version.h"

using ip_t = std::vector<unsigned int>;

bool MyComp(const ip_t& LV, const ip_t& RV);


//получение версии файла
int version();


// Переопределяем потоки вывода для вектора интов и вектора векторов
template <typename T>
std::ostream& operator <<(std::ostream& out, const std::vector<T>& vec) {
    for(const auto& v : vec) {
        out << v;
    }

    return out;
}


std::ostream& operator <<(std::ostream&, const ip_t&);
std::ostream& operator <<(std::ostream&, const std::vector<std::string>&);
