#pragma once

#include <iostream>
#include <vector>
#include "utility.h"

template <typename type>
class Insertion
{
public:
    void exch(std::vector<type> &datas, int si, int ti)
    {
        type temp = datas[si];
        datas[si] = datas[ti];
        datas[ti] = temp;
    }

    void sort(std::vector<type> &datas)
    {
        // 避免对已经有序的数据进行不必要的排序
        if (isSorted(datas))
            return;

        int n = datas.size();
        for (int i = 1; i < n; i++)
        {
            for (int j = i; j > 0; j--)
            {
                if (datas[j] < datas[j - 1])
                    exch(datas, j, j - 1);
                else
                    break;
            }
        }
    }
};