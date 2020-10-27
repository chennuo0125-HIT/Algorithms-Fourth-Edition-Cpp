#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "utility.h"

template <typename type>
class Selection
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
        for (int i = 0; i < n; i++)
        {
            // 在余下的数据中查找最小值
            int min_index = i;
            type min_value = datas[i];
            for (int j = i + 1; j < n; j++)
            {
                if (datas[j] < min_value)
                {
                    min_value = datas[j];
                    min_index = j;
                }
            }

            // 将余下的数据最小值交换到余下的数据最前方
            exch(datas, i, min_index);
        }
    }
};
