#pragma once

#include <type_traits>
#include <string>


namespace Helpers{


template <typename T>
struct is_cont {
  static const bool value = false;
};

template <typename T,typename Alloc>
struct is_cont<std::vector<T,Alloc> > {
  static const bool value = true;
};

//========================
template<typename InValue>
void PrintVec(const std::vector<InValue>& vec);

//========================

template<typename V, bool Choose>
struct ImPrintVec{};


template<typename V>
struct ImPrintVec<V, true>{

    static inline void ImPrintVec_(const std::vector<V>& vec){

        for(const auto& v : vec) {
            PrintVec(v);
        }
    }
};

template<typename V>
struct ImPrintVec<V, false>{

    static inline void ImPrintVec_(const std::vector<V>& vec){

         for(auto it = vec.cbegin(); it != vec.cend(); ++it) {

            if(it != vec.cbegin()){
                std::cout << ".";
            }
            std::cout << *it;
        }
        std::cout << "\n";
    }
};

template<typename InValue>
void PrintVec(const std::vector<InValue>& vec){

    ImPrintVec<InValue, is_cont<InValue>::value>::ImPrintVec_(vec);
}

}
