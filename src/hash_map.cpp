#include "../include/hash_map.h"

// hash function
const int HashMap::hash(const int zipCode) const {
    return zipCode % tableSize;
}

// creates hash table from csv file
void HashMap::createTableFromFile(std::fstream& file) {
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
            if ((zipCode != "0") && (zipCode != "99999")) { // not actual zip codesS
                Container c(std::stoi(zipCode), abbreviation, incomes);
                table[hash(std::stoi(zipCode))].push_back(c);
                if (table[hash(std::stoi(zipCode))].size() == 1) { // checks if new bucket was filled
                    filledBuckets++;
                }
            }
            incomes = { 0, 0, 0, 0, 0, 0 };
        }
    }
}

// returns data stored with corresponding zip code, pair.first is true if it exists
const std::pair<bool, const HashMap::Container> HashMap::retrieve(const int zipCode) const {
    for (const Container c : table[hash(zipCode)]) {
        if (c.zipCode == zipCode) { // zip code found
            return std::make_pair(true, c);
        }
    }
    Container empty; // zip code does not exist
    return std::make_pair(false, empty);
}

// prints a random selection of 10 zip codes, good for debugging
void HashMap::printRandomZipCodes(const int seed) const {
    std::set<int> s;
    srand(seed);
    int randNum = rand() % 89999 + 10000;
    std::vector<Container> zipCodes;
    while (zipCodes.size() < 10) {
        randNum = rand() % 89999 + 10000;
        if (s.count(randNum) == 1) { // randNum has been generated before
            continue;
        }
        std::pair<bool, const Container> p = retrieve(randNum);
        s.insert(randNum);
        if (!p.first) { // zip code does not exist
            continue;
        }
        zipCodes.push_back(p.second);
    }
    for (Container c : zipCodes) {
        std::cout << c.abbreviation << ", " << c.zipCode << std::endl;
        for (int i : c.incomes) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    printLoadFactor();
}

// returns load factor, only considers filled buckets, not total number of items in table
const float HashMap::getLoadFactor() const {
    return float(filledBuckets) / float(tableSize);
}

// prints load factor with precision 8
void HashMap::printLoadFactor() const {
    std::cout << "Load Factor: " << std::setprecision(8) << getLoadFactor() << std::endl;
}

// prints specified zip code data
void HashMap::printZipCodeData(const int zipCode) const {
    std::pair<bool, Container> p = retrieve(zipCode);
    if (p.first) { // zip code exists
        std::cout << "State: " << p.second.abbreviation << std::endl;
        std::cout << "Zip Code: " << p.second.zipCode << std::endl;
        std::cout << "Income Distribution: ";
        for (int i : p.second.incomes) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Zip code " << zipCode << " does not exist!" << std::endl;
    }
}