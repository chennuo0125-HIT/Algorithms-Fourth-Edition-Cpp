#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>

// 产生随机数
std::vector<int> genRandNum(int num)
{
    std::vector<int> rand_nums(num);
    rand_nums.reserve(num);
    for (int i = 0; i < num; i++)
    {
        rand_nums[i] = rand() % num;
    }

    return rand_nums;
}

// 检查排序是否成功
template <typename type>
bool isSorted(std::vector<type> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] - nums[i - 1] < 0)
        {
            return false;
        }
    }

    return true;
}

// 检查区间排序是否成功
template <typename type>
bool isSorted(std::vector<type> &nums, int si, int ei)
{
    if (si < 0 || si >= nums.size() || ei < 0 || ei >= nums.size())
    {
        std::cout << "si->" << si << " ei->" << ei << " is out of border [0," << nums.size() << "]" << std::endl;
        return false;
    }

    for (int i = si; i < ei; i++)
    {
        if (nums[i + 1] - nums[i] < 0)
        {
            return false;
        }
    }

    return true;
}

// 输出数据
template <typename type>
void printDatas(const std::vector<type> &datas)
{
    std::cout << "datas: ";
    for (int i = 0; i < datas.size(); i++)
    {
        std::cout << datas[i] << " ";
    }
    std::cout << std::endl;
}