#pragma once
#include <string>
#include <array>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <set>
#include <iomanip>
#define TABLESIZE 13871 // original 13871

// hash map class
class HashMap {
private:
    // data class to store zip code information
    struct Container {
        const int zipCode;
        const std::string abbreviation;
        const std::array<int, 6> incomes;
        Container() : zipCode(-1), abbreviation("N/A"), incomes({ -1, -1, -1, -1, -1, -1 }) {};
        Container(int zipCode, std::string abbreviation, std::array<int, 6> incomes) : zipCode(zipCode), abbreviation(abbreviation), incomes(incomes) {};
    };
    std::array<std::vector<Container>, TABLESIZE> table;
    int filledBuckets = 0;
    const int tableSize = TABLESIZE;
    const int hash(const int zipCode) const;
public:
    HashMap() {};
    void createTableFromFile(std::fstream& file);
    const std::pair<bool, const Container> retrieve(const int zipCode) const;
    void printRandomZipCodes(const int seed) const;
    const float getLoadFactor() const;
    void printLoadFactor() const;
    void printZipCodeData(const int zipCode) const;
};