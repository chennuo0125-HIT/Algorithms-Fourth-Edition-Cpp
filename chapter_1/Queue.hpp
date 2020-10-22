/* algorithm 1.3 */

#pragma once

#include "Node.hpp"

template <typename T>
class Queue
{
public:
    Queue() : first(NULL), last(NULL), N(0) {}
    ~Queue()
    {
        while (first)
        {
            Node<T> *next = first->next;
            delete first;
            first = NULL;
            first = next;
        }
    }

    bool isEmpty() { return 0 == N; }

    int size() { return N; }

    void enqueue(T item)
    {
        Node<T> *node(new Node<T>());
        node->item = item;
        if (NULL == first && NULL == last)
        {
            first = node;
            last = node;
            N++;
            return;
        }
        Node<T> *last_last = last;
        last = node;
        last_last->next = last;
        N++;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            last == NULL;
            return T();
        }

        Node<T> *last_first = first;
        first = first->next;
        N--;

        T result = last_first->item;
        delete last_first;
        last_first = NULL;

        return result;
    }

private:
    Node<T> *first;
    Node<T> *last;
    int N;
};