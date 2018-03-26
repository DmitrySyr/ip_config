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

