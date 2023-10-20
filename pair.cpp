//
// Created by Rus Ilie Daniel on 20/10/2023.
//

#include <string>

class Pair {
private:
    int first;
    int second;

public:
    Pair(int first, int second) : first(first), second(second) {}

    int getFirst() const {
        return this->first;
    }

    int getSecond() const {
        return this->second;
    }

    std::string toString() const {
        return "Pair{" + std::to_string(first) + ", " + std::to_string(second) + '}';
    }
};


