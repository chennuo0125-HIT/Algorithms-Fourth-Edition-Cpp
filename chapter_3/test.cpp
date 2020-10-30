#include <iostream>
#include <sstream>
#include <fstream>
#include <istream>
#include <time.h>

#include "SequentialSearchST.h"

void readData(std::ifstream &in_file, std::vector<std::string> &strings)
{
    strings.clear();
    std::string line;
    while (std::getline(in_file, line))
    {
        std::string key;
        std::stringstream ss(line);
        while (ss >> key)
            strings.push_back(key);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "please input test_file !!!" << std::endl;
        return -1;
    }

    // 读取本地待进行查找的数据集
    std::ifstream in_file(argv[1]);
    if (!in_file.is_open())
    {
        std::cout << "cant read datas from " << argv[1] << std::endl;
        return -1;
    }
    std::vector<std::string> strings;
    readData(in_file, strings);
    if (strings.size() == 0)
    {
        std::cout << "no data in file " << argv[1] << std::endl;
        return -1;
    }

    ///////////////////////////////////// 顺序查找 //////////////////////////////////////
    clock_t ss_start = clock();
    // 填充符号表
    SequentialSearchST ssst;
    std::vector<std::string> ss_datas = strings;
    for (int i = 0; i < ss_datas.size(); i++)
    {
        int value = 0;
        if (ssst.get(ss_datas[i], value))
            ssst.put(ss_datas[i], value + 1);
        else
            ssst.put(ss_datas[i], 1);
    }
    // 获取数量最大的键值
    int max_times = 0;
    std::string max_string = strings[0];
    std::vector<std::string> keys(0);
    ssst.getKeys(keys);
    for (int i = 0; i < keys.size(); i++)
    {
        int value = 0;
        if (ssst.get(keys[i], value))
        {
            if (value > max_times)
            {
                max_times = value;
                max_string = keys[i];
            }
        }
        else
            return -1;
    }
    clock_t ss_end = clock();
    std::cout << "sequential_search algo find \"" << max_string << "\" with largest times " << max_times << " and cost time " << double(ss_end - ss_start) / CLOCKS_PER_SEC << "[sec] " << std::endl;

    return 0;
}