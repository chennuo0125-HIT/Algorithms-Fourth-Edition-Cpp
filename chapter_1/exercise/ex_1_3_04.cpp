/**********************
 * 
 * Judge whether is balanced of string with bracket
 * (Exercise 1.3.4)
 * 
 **********************/

#include <iostream>
#include <string>
#include "Stack.hpp"

bool isBalanced(const std::string &str)
{
    int len = str.length();
    Stack<char> residual;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
            residual.push(str[i]);
        else if (!(str[i] == '}' && residual.pop() == '{') && !(str[i] == ']' && (residual.pop() == '[')) && !(str[i] == ')' && (residual.pop() == '(')))
        {
            return false;
        }
    }

    if (residual.size() != 0)
        return false;

    return true;
}

int main(int argc, char **argv)
{
    std::string str1 = "[()]{}{[()()]()}";
    std::string str2 = "[(])";

    std::cout << str1 << " is " << isBalanced(str1) << " balanesed" << std::endl;
    std::cout << str2 << " is " << isBalanced(str2) << " balanesed" << std::endl;

    return 0;
}