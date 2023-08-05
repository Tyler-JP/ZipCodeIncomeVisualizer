#pragma once

#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <set>
#include <sstream>
#include <utility>

#include "tax_info.h"

// Helper methods rely on insert() and retrieve() in data structures:
// Prints specified zip code data
template <typename D>
void printZipCodeData(const int zipCode, const D& dataStructure) {
    std::pair<bool, TaxInfo> p = dataStructure.retrieve(zipCode);
    // zip code exists
    if (p.first) {
        p.second.print();
    }
    else {
        std::cout << "Zip code " << zipCode << " does not exist!" << std::endl;
    }
}

// prints a random selection of 10 zip codes, good for debugging
template <typename D>
void printRandomZipCodes(const int seed, const D& dataStructure) {
    std::set<int> s;
    srand(seed);
    int randNum = rand() % 89999 + 10000;
    for (int i = 0; i < 10; i++) {
        randNum = rand() % 89999 + 10000;
        if (s.count(randNum) == 1) { // randNum has been generated before
            continue;
        }
        printZipCodeData(randNum, dataStructure);
        s.insert(randNum);
    }
}

// Creates data structure from csv file
template <typename D>
void createTaxTableFromFile(std::fstream& file, D& dataStructure) {
    std::string line;
    std::getline(file, line); // reads filler header line
    int counter = 0;
    std::array<int, 6> incomes = { 0, 0, 0, 0, 0, 0 };

    while (std::getline(file, line)) {
        std::stringstream s(line);

        std::string uselessStateNum;
        std::string zipCode;
        std::string abbreviation;
        std::string incomeLevel;
        std::string income;

        std::getline(s, uselessStateNum, ',');
        std::getline(s, abbreviation, ',');
        std::getline(s, zipCode, ',');
        std::getline(s, incomeLevel, ',');
        std::getline(s, income);

        incomes[std::stoi(incomeLevel) - 1] = std::stoi(income);
        counter++;
        if (counter == 6) { // all data from 1 zip code collected
            counter = 0;
            if ((zipCode != "0") && (zipCode != "99999")) { // not actual zip codes
                TaxInfo container(std::stoi(zipCode), abbreviation, incomes);
                dataStructure.insert(std::stoi(zipCode), container);
            }
            incomes = { 0, 0, 0, 0, 0, 0 };
        }
    }
}
