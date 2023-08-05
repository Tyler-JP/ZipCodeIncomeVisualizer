#include "../include/key_val.h"

AssociationList::AssociationList()
{
    headNode = nullptr;
}

AssociationList::~AssociationList()
{
    Node* previous = nullptr;
    Node* iterator = headNode;
    while (iterator != nullptr) // deletes all nodes
    {
        previous = iterator;
        iterator = iterator->nextNode;
        delete previous;
    };
}

void AssociationList::push(int zip, TaxInfo info)
{
    Node* temp = headNode;
    headNode = new Node(zip, info);
    headNode->nextNode = temp;
};

std::pair<bool, TaxInfo> AssociationList::retrieve(const int key)
{
    Node* iterator = headNode;
    while (iterator != nullptr) // searches for key
    {
        if (iterator->key == key) // key found
            return std::make_pair(true, iterator->container);
        else
            iterator = iterator->nextNode; // continue search if key not found
    }
    return std::make_pair(false, TaxInfo()); // key does not exist
};

void AssociationList::print()
{
    Node* iterator = headNode;
    while (iterator != nullptr)
    {
        std::cout << "State: " << iterator->container.state << " | ";
        std::cout << "Zip Code: " << iterator->container.zipCode << " | ";
        std::cout << "Income Distribution: ";
        for (int i : iterator->container.incomes) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        iterator = iterator->nextNode;
    }
}

// creates list from csv file
void AssociationList::createFromFile(std::fstream& file)
{
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
                TaxInfo container(std::stoi(zipCode), abbreviation, incomes);
                push(std::stoi(zipCode), container);
            }
            incomes = { 0, 0, 0, 0, 0, 0 };
        }
    }
}