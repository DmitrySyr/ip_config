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
    out << "\n";

    return out;
}

std::ostream& operator <<(std::ostream& out, const std::vector<std::string>& vec) {

    for(auto v = vec.cbegin(); v != vec.cend(); ++v) {
        if(v != vec.cbegin()) {
            out << ".";
        }

        out << *v;
    }
    out << "\n";


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
