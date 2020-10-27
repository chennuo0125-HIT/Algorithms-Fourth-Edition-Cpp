/* algorithm 1.2 */

#pragma once

#include "Node.hpp"

template <typename T>
class Stack
{
public:
    Stack() : first(NULL), N(0) {}
    ~Stack()
    {
        while (first)
        {
            Node<T> *next = first->next;
            delete first;
            first = NULL;
            first = next;
        }
    }

    bool isEmpty() { return NULL == first; }

    int size() { return N; }

    void push(T item)
    {
        Node<T> *old_first = first;
        Node<T> *node(new Node<T>());
        node->item = item;
        node->next = old_first;
        first = node;
        N++;
    }

    T pop()
    {
        if (isEmpty())
            return T();

        Node<T> *pop_first = first;
        first = first->next;
        N--;

        T result = pop_first->item;
        delete pop_first;
        pop_first = NULL;

        return result;
    }

private:
    Node<T> *first;
    int N;
};