#include <iostream>
#include "Queue.hpp"

int main(int argc, char **argv)
{
    int data[10] = {1, 2, 3, 4, 5, 5, 7, 8, 9, 10};

    Queue<int> queue;
    std::cout << "push : ";
    for (int i = 0; i < 10; i++)
    {
        queue.enqueue(data[i]);
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "size : " << queue.size() << std::endl;

    std::cout << "pop : ";
    while (!queue.isEmpty())
    {
        int item = queue.dequeue();
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}