#pragma once

#include <array>
#include <memory>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

#include "container.h"

class AssociationList
{
private:
    struct Node
    {
        Node(int key, TaxInfo container) : key(key), container(container), nextNode(nullptr) {}

        const int key;
        const TaxInfo container;
           
        Node* nextNode;
    };

    Node* headNode;

public:
    typedef TaxInfo Container;

    AssociationList();
    ~AssociationList();

    AssociationList(const AssociationList&) = delete;
    AssociationList& operator= (const AssociationList&) = delete;

    void print();

    void push(int key, TaxInfo info);
    std::pair<bool, TaxInfo> retrieve(const int key);

    void createFromFile(std::fstream& file);
};
