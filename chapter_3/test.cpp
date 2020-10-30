#include <iostream>
#include <sstream>
#include <fstream>
#include <istream>
#include <time.h>

#include "SequentialSearchST.h"
#include "BinarySearchST.h"

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
    sequential_search::SequentialSearchST ssst;
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
    int ss_max_times = 0;
    std::string ss_max_string = strings[0];
    std::vector<std::string> ss_keys(0);
    ssst.getKeys(ss_keys);
    for (int i = 0; i < ss_keys.size(); i++)
    {
        int value = 0;
        if (ssst.get(ss_keys[i], value))
        {
            if (value > ss_max_times)
            {
                ss_max_times = value;
                ss_max_string = ss_keys[i];
            }
        }
        else
            return -1;
    }
    clock_t ss_end = clock();
    std::cout << "sequential_search algo find \"" << ss_max_string << "\" with largest times "
              << ss_max_times << " and cost time " << double(ss_end - ss_start) / CLOCKS_PER_SEC << "[sec] " << std::endl;

    /////////////////////////////////// 二分查找 //////////////////////////////////////////
    clock_t bs_start = clock();
    // 填充符号表
    binary_search::BinarySearchST bst;
    std::vector<std::string> bs_datas = strings;
    for (int i = 0; i < bs_datas.size(); i++)
    {
        int value = 0;
        if (bst.get(bs_datas[i], value))
            bst.put(bs_datas[i], value + 1);
        else
            bst.put(bs_datas[i], 1);
    }
    // 获取数量最大的键值
    int bs_max_times = 0;
    std::string bs_max_string = strings[0];
    std::vector<std::string> bs_keys(0);
    bst.getKeys(bs_keys);
    for (int i = 0; i < bs_keys.size(); i++)
    {
        int value = 0;
        if (bst.get(bs_keys[i], value))
        {
            if (value > bs_max_times)
            {
                bs_max_times = value;
                bs_max_string = bs_keys[i];
            }
        }
        else
            return -1;
    }
    clock_t bs_end = clock();
    std::cout << "binary_search algo find \"" << bs_max_string << "\" with largest times "
              << bs_max_times << " and cost time " << double(bs_end - bs_start) / CLOCKS_PER_SEC << "[sec] " << std::endl;

    return 0;
}