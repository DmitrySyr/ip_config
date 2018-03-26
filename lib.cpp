#include "lib.h"

int version()
{
	return PROJECT_VERSION_PATCH;
}

std::ostream& operator <<(std::ostream& out, const ip_t& vec) {

    for(auto v = vec.cbegin(); v != vec.cend(); ++v) {
        if(v != vec.cbegin()) {
            out << ".";
        }

        out << *v;
    }
    //out << "\n";

    return out;
}

std::ostream& operator <<(std::ostream& out, const std::vector<std::string>& vec) {

    for(auto v = vec.cbegin(); v != vec.cend(); ++v) {
        if(v != vec.cbegin()) {
            out << ".";
        }

        out << *v;
    }
    //out << "\n";


    return out;
}

//=======================================================================================

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


bool filter_any(const ip_t& OrigVec, const int Cond) {


    if(Cond < 0) { return true;}

    for(const auto& vec : OrigVec) {

            if(vec == Cond) {

                return true;
            }
        }

    return false;
}



//===========================================================================================

bool MyComp(const std::vector<unsigned int>& LV, const std::vector<unsigned int>& RV) {

    std::cout << "Compare two objects with size " << LV.size() << " and " << RV.size() << "\n";

    if(LV.size() != RV.size()) {

        std::cout << typeid(LV).name() <<"\n";
        std::cout << "========================================\n";
        std::cout << typeid(RV).name() << "\n";

        std::stringstream ss;
        ss << "Trying to compare vectors of different sizes. Which are " << LV.size() << " and " << RV.size() << "\n";

         throw std::runtime_error(ss.str());
    }

    for(size_t i = 0; i != RV.size(); ++i) {
        if(LV[i] > RV[i]) {return true;}
    }

    return false;
}
