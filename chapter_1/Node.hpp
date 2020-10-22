#pragma once

template <typename T>
class Node
{
public:
    Node() : next(NULL) {}
    T item;
    Node *next;
};