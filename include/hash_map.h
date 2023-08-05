#pragma once

#include <assert.h>
#include <utility>

#include "key_val.h"

template <typename T>
class HashMap {
private:
    Node<T>** table;

    unsigned int filledBuckets = 0;
    unsigned int tableSize = 2;
    const float maxLoadFactor = 1.0f;

    // Hashes a key based on the given table size
    const unsigned int hash(const unsigned int key, const unsigned int size) const {
        return key % size;
    }

    // Dynamically creates a table of a given size
    Node<T>** createTable(const unsigned int size);

    // Deletes a table of a given size
    void deleteTable(Node<T>** table, const unsigned int size);

public:
    HashMap();
    ~HashMap();

    HashMap(const HashMap&) = delete;
    HashMap& operator= (const HashMap&) = delete;

    void insert(const unsigned int key, T value);
    const std::pair<bool, const T> retrieve(const unsigned int key) const;

    const float getLoadFactor() const { return float(filledBuckets) / float(tableSize); }
    const unsigned int getBucketCount() const { return filledBuckets; }
    const unsigned int getTableSize() const { return tableSize; }
};

template <typename T>
Node<T>** HashMap<T>::createTable(const unsigned int size)
{
    Node<T>** newTable = new Node<T>*[size];
    for (int i = 0; i < size; i++)
        newTable[i] = nullptr;
    return newTable;
}

template <typename T>
void HashMap<T>::deleteTable(Node<T>** table, const unsigned int size)
{
    for (int i = 0; i < size; i++) // remove all nodes in table 
    {
        Node<T>* previous = nullptr;
        Node<T>* iterator = table[i];
        while (iterator != nullptr)
        {
            previous = iterator;
            iterator = iterator->nextNode;
            delete previous;
        };
    }
    delete[] table;
}

template <typename T>
HashMap<T>::HashMap() {
    filledBuckets = 0;
    tableSize = 2;
    table = createTable(tableSize);
}

template <typename T>
HashMap<T>::~HashMap()
{
    deleteTable(table, tableSize);
}

// pushes key and value onto data structure
template <typename T>
void HashMap<T>::insert(const unsigned int key, T value) {
    Node<T>* bucket = table[hash(key, tableSize)];
    if (bucket == nullptr)
        table[hash(key, tableSize)] = new Node<T>(key, value);
    else
        table[hash(key, tableSize)] = new Node<T>(key, value, bucket);
    filledBuckets += 1;

    // rehash if over load factor
    if (getLoadFactor() > maxLoadFactor)
    {
        // initialize new table
        const unsigned int newTableSize = tableSize * 2;
        Node<T>** newTable = createTable(newTableSize);

        // rehash old table into new
        int newFilledBuckets = 0;
        for (int i = 0; i < tableSize; i++)
        {
            Node<T>* iterator = table[i];
            while (iterator != nullptr)
            {
                Node<T>* newBucket = newTable[hash(iterator->key, newTableSize)];
                if (newBucket == nullptr) {
                    newTable[hash(iterator->key, newTableSize)] = new Node<T>(iterator->key, iterator->value);
                }
                else {
                    newTable[hash(iterator->key, newTableSize)] = new Node<T>(iterator->key, iterator->value, newBucket);
                }
                newFilledBuckets += 1;
                iterator = iterator->nextNode;
            };
        }
        assert(newFilledBuckets == filledBuckets);

        // delete old table and set to new table
        deleteTable(table, tableSize);

        tableSize = newTableSize;
        table = newTable;
    }
}

// returns stored container to respective key
template <typename T>
const std::pair<bool, const T> HashMap<T>::retrieve(const unsigned int key) const {
    Node<T>* current = table[hash(key, tableSize)]; // get bucket
    while (current != nullptr) { // iterate through bucket
        if (current->key == key)
            return std::make_pair(true, current->value); // return val if we match key
        current = current->nextNode;
    }
    return std::make_pair(false, T());
}