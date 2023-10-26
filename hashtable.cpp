//
// Created by Rus Ilie Daniel on 20/10/2023.
//

#include <vector>
#include <string>
#include <stdexcept>

class HashTable {
private:
    int size;
    std::vector<std::vector<std::string>> table;

public:
    HashTable(int size) : size(size), table(size) {}

    std::string findByPos(std::pair<int, int> pos) {
        if (pos.first >= size || pos.second >= table[pos.first].size()) {
            throw std::out_of_range("Invalid position");
        }
        return table[pos.first][pos.second];
    }

    int getSize() const {
        return size;
    }

    std::pair<int, int> findPositionOfTerm(const std::string& term) {
        int pos = hash(term);

        if (!table[pos].empty()) {
            const std::vector<std::string>& elems = table[pos];
            for (int i = 0; i < elems.size(); i++) {
                if (elems[i] == term) {
                    return std::make_pair(pos, i);
                }
            }
        }

        return std::make_pair(-1, -1); // Not found
    }

    bool containsTerm(const std::string& term) {
        return findPositionOfTerm(term) != std::make_pair(-1, -1);
    }

    bool add(const std::string& term) {
        if (containsTerm(term)) {
            return false;
        }

        int pos = hash(term);
        table[pos].push_back(term);

        return true;
    }

    std::string toString() const {
        return "SymbolTable { elements=" + std::to_string(table.size()) + ", size = " + std::to_string(size) + " }";
    }

private:
    int hash(const std::string& key) const {
        int sum_characters = 0;
        for (char c : key) {
            sum_characters += c;
        }
        return sum_characters % size;
    }
};

