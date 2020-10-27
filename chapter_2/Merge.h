#pragma once

#include <iostream>
#include <vector>
#include "utility.h"

template <typename type>
class Merge
{
public:
    void merge(std::vector<type> &datas, int lo, int mid, int hi)
    {
        // 生成一个辅助数组，用于缓存归并前数据
        int num = hi - lo + 1;
        std::vector<type> aux(num);
        aux.reserve(num);
        for (int i = lo; i <= hi; i++)
            aux[i - lo] = datas[i];

        // 将辅助数组内数据归并到原数据
        int i = 0;
        int bi = mid - lo;
        int j = mid - lo + 1;
        int bj = hi - lo;
        for (int k = lo; k <= hi; k++)
        {
            if (i > bi)
                datas[k] = aux[j++];
            else if (j > bj)
                datas[k] = aux[i++];
            else if (aux[i] < aux[j])
                datas[k] = aux[i++];
            else
                datas[k] = aux[j++];
        }
    }

    void sort(std::vector<type> &datas, int lo, int hi)
    {
        // 递归终止条件1: 只有一个数据
        if (hi <= lo)
            return;

        // 递归终止条件2: 数据有序
        if (isSorted(datas, lo, hi))
            return;

        // 递归的切分归并
        int mid = (hi + lo) / 2;
        sort(datas, lo, mid);
        sort(datas, mid + 1, hi);
        merge(datas, lo, mid, hi);
    }

    void sort(std::vector<type> &datas)
    {
        if (datas.size() <= 1)
        {
            std::cout << "datas size less than 1, no need sort !!!" << std::endl;
            return;
        }

        // 避免对已经有序的数据进行不必要的排序
        if (isSorted(datas))
            return;

        sort(datas, 0, datas.size() - 1);
    }
};