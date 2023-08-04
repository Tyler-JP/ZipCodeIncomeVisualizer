#pragma once

#include <utility>

#include "key_val.h"

template <typename T>
class AssociationList
{
private:
    Node<T>* headNode;

    unsigned int listSize;

public:
    AssociationList();
    ~AssociationList();

    AssociationList(const AssociationList&) = delete;
    AssociationList& operator= (const AssociationList&) = delete;

    void insert(int key, T value);
    const std::pair<bool, T> retrieve(const int key) const;

    const unsigned int getListSize() const { return listSize; }
};

template <typename T>
AssociationList<T>::AssociationList() {
    headNode = nullptr;
    listSize = 0;
}

template <typename T>
AssociationList<T>::~AssociationList() {
    Node<T>* previous = nullptr;
    Node<T>* iterator = headNode;
    while (iterator != nullptr)
    {
        previous = iterator;
        iterator = iterator->nextNode;
        delete previous;
    };
}

template <typename T>
void AssociationList<T>::insert(int key, T value) {
    Node<T>* temp = headNode;
    headNode = new Node<T>(key, value, temp);
    listSize += 1;
};

template <typename T>
const std::pair<bool, T> AssociationList<T>::retrieve(const int key) const {
    Node<T>* iterator = headNode;
    while (iterator != nullptr)
    {
        if (iterator->key == key)
            return std::make_pair(true, iterator->value);
        else
            iterator = iterator->nextNode;
    }
    return std::make_pair(false, T());
};
