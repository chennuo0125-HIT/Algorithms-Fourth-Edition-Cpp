#include <iostream>
#include "Stack.hpp"

int main(int argc, char **argv)
{
    int data[10] = {1, 2, 3, 4, 5, 5, 7, 8, 9, 10};

    Stack<int> stack;
    std::cout << "push : ";
    for (int i = 0; i < 10; i++)
    {
        stack.push(data[i]);
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "size : " << stack.size() << std::endl;

    std::cout << "pop : ";
    while (!stack.isEmpty())
    {
        int item = stack.pop();
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}