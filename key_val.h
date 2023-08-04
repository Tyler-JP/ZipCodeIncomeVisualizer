#pragma once

template <typename T>
struct Node
{
    Node(int key, T value) : key(key), value(value), nextNode(nullptr) {}
    Node(int key, T value, Node<T>* next) : key(key), value(value), nextNode(next) {}

    const unsigned int key;
    const T value;

    Node<T>* nextNode;
};