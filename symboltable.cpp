//
// Created by Rus Ilie Daniel on 20/10/2023.
//

#include "hashtable.cpp"

class SymbolTable {
private:
    HashTable hashTable;

public:
    SymbolTable(int size) : hashTable(size) {}

    std::string findByPos(std::pair<int, int> pos) {
        return hashTable.findByPos(pos);
    }

    HashTable& getHashTable() {
        return hashTable;
    }

    int getSize() const {
        return hashTable.getSize();
    }

    std::pair<int, int> findPositionOfTerm(const std::string& term) {
        return hashTable.findPositionOfTerm(term);
    }

    bool containsTerm(const std::string& term) {
        return hashTable.containsTerm(term);
    }

    bool add(const std::string& term) {
        return hashTable.add(term);
    }
};
