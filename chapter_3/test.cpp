#include <iostream>
#include <sstream>
#include <fstream>
#include <istream>
#include <time.h>
#include <map>
#include <unordered_map>

#include "SequentialSearchST.h"
#include "BinarySearchST.h"
#include "BST.h"

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
    clock_t bsst_start = clock();
    // 填充符号表
    binary_search::BinarySearchST bsst;
    std::vector<std::string> bsst_datas = strings;
    for (int i = 0; i < bsst_datas.size(); i++)
    {
        int value = 0;
        if (bsst.get(bsst_datas[i], value))
            bsst.put(bsst_datas[i], value + 1);
        else
            bsst.put(bsst_datas[i], 1);
    }
    // 获取数量最大的键值
    int bsst_max_times = 0;
    std::string bsst_max_string = strings[0];
    std::vector<std::string> bsst_keys(0);
    bsst.getKeys(bsst_keys);
    for (int i = 0; i < bsst_keys.size(); i++)
    {
        int value = 0;
        if (bsst.get(bsst_keys[i], value))
        {
            if (value > bsst_max_times)
            {
                bsst_max_times = value;
                bsst_max_string = bsst_keys[i];
            }
        }
        else
            return -1;
    }
    clock_t bsst_end = clock();
    std::cout << "binary_search algo find \"" << bsst_max_string << "\" with largest times "
              << bsst_max_times << " and cost time " << double(bsst_end - bsst_start) / CLOCKS_PER_SEC << "[sec] " << std::endl;

    /////////////////////////////////// 二叉树查找 //////////////////////////////////////////
    clock_t bst_start = clock();
    // 填充符号表
    binary_search::BinarySearchST bst;
    std::vector<std::string> bst_datas = strings;
    for (int i = 0; i < bst_datas.size(); i++)
    {
        int value = 0;
        if (bst.get(bst_datas[i], value))
            bst.put(bst_datas[i], value + 1);
        else
            bst.put(bst_datas[i], 1);
    }
    // 获取数量最大的键值
    int bst_max_times = 0;
    std::string bst_max_string = strings[0];
    std::vector<std::string> bst_keys(0);
    bst.getKeys(bst_keys);
    for (int i = 0; i < bst_keys.size(); i++)
    {
        int value = 0;
        if (bst.get(bst_keys[i], value))
        {
            if (value > bst_max_times)
            {
                bst_max_times = value;
                bst_max_string = bst_keys[i];
            }
        }
        else
            return -1;
    }
    clock_t bst_end = clock();
    std::cout << "bst_search algo find \"" << bst_max_string << "\" with largest times "
              << bst_max_times << " and cost time " << double(bst_end - bst_start) / CLOCKS_PER_SEC << "[sec] " << std::endl;

    //////////////////////////////// 红黑树(直接使用系统函数) /////////////////////////////////////
    clock_t rbt_start = clock();
    // 填充符号表
    std::map<std::string, int> rbt;
    std::vector<std::string> rbt_datas = strings;
    for (int i = 0; i < rbt_datas.size(); i++)
    {
        std::map<std::string, int>::iterator it = rbt.find(rbt_datas[i]);
        if (it == rbt.end())
            rbt.insert(std::pair<std::string, int>(rbt_datas[i], 1));
        else
        {
            // rbt.insert(std::pair<std::string, int>(rbt_datas[i], it->second + 1));//map在第二次插入同样键值的键值对时，不更新值
            rbt[rbt_datas[i]] = it->second + 1;
        }
    }
    // 获取数量最大的键值
    int rbt_max_times = 0;
    std::string rbt_max_string = rbt_datas[0];
    for (std::map<std::string, int>::iterator it = rbt.begin(); it != rbt.end(); it++)
    {
        if (it->second > rbt_max_times)
        {
            rbt_max_times = it->second;
            rbt_max_string = it->first;
        }
    }
    clock_t rbt_end = clock();
    std::cout << "rbt_search algo find \"" << rbt_max_string << "\" with largest times "
              << rbt_max_times << " and cost time " << double(rbt_end - rbt_start) / CLOCKS_PER_SEC << "[sec] " << std::endl;

    //////////////////////////////// 散列表(直接使用系统函数) /////////////////////////////////////
    clock_t ht_start = clock();
    // 填充符号表
    std::unordered_map<std::string, int> ht;
    std::vector<std::string> ht_datas = strings;
    for (int i = 0; i < ht_datas.size(); i++)
    {
        std::unordered_map<std::string, int>::iterator it = ht.find(ht_datas[i]);
        if (it == ht.end())
            ht.insert(std::pair<std::string, int>(ht_datas[i], 1));
        else
        {
            ht[rbt_datas[i]] = it->second + 1;
        }
    }
    // 获取数量最大的键值
    int ht_max_times = 0;
    std::string ht_max_string = ht_datas[0];
    for (std::unordered_map<std::string, int>::iterator it = ht.begin(); it != ht.end(); it++)
    {
        if (it->second > ht_max_times)
        {
            ht_max_times = it->second;
            ht_max_string = it->first;
        }
    }
    clock_t ht_end = clock();
    std::cout << "ht_search algo find \"" << ht_max_string << "\" with largest times "
              << ht_max_times << " and cost time " << double(ht_end - ht_start) / CLOCKS_PER_SEC << "[sec] " << std::endl;

    return 0;
}