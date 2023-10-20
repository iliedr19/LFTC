#include "symboltable.cpp" // Include the header file for SymbolTable (assuming it's in a separate file)
#include <cassert> // Include the header for assert
#include <iostream>

int main() {
    SymbolTable symbolTable(5);

    symbolTable.add("1");
    assert(symbolTable.containsTerm("1"));
    std::pair<int, int> position1 = symbolTable.findPositionOfTerm("1");
    assert(position1.first == 1 && position1.second == 0);

    symbolTable.add("6");
    assert(symbolTable.containsTerm("6"));
    std::pair<int, int> position6 = symbolTable.findPositionOfTerm("6");
    assert(position6.first == 1 && position6.second == 1);

    symbolTable.add("5");
    assert(symbolTable.containsTerm("5"));
    std::pair<int, int> position5 = symbolTable.findPositionOfTerm("5");
    assert(position5.first == 2 && position5.second == 0);

    std::string hashTableString = symbolTable.getHashTable().toString();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
