/**********************
 * 
 * Bracket Completion
 * (Exercise 1.3.31)
 * 
 **********************/

#include <iostream>
#include <string>
#include <vector>
#include "Stack.hpp"

class BracketCompletion
{
public:
    std::string getCompResult(const std::string &str)
    {
        if (str.length() == 0)
        {
            std::cout << "input string length is zero !!!" << std::endl;
            return std::string();
        }

        Stack<std::string> ops;
        Stack<std::string> vls;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '(')
            {
                std::cout << "input error !!!" << std::endl;
                return std::string();
            }
            if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            {
                ops.push(str.substr(i, 1));
            }
            else if (str[i] == ')')
            {
                std::string vl = vls.pop();
                std::string op = ops.pop();
                std::string new_vl = "(" + vls.pop() + op + vl + ")";
                vls.push(new_vl);
            }
            else
            {
                vls.push(str.substr(i, 1));
            }
        }

        return vls.pop();
    }
};

int main(int argc, char **argv)
{
    BracketCompletion bc;

    std::string data = "1+2)*3-4)*5-6)))";
    std::string result = bc.getCompResult(data);

    std::cout << "data is " << data << std::endl;
    std::cout << "complete is " << result << std::endl;

    return 0;
}