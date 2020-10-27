#pragma once

#include <iostream>
#include "utility.h"

template <typename type>
class Shell
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

        // 计算最大间隔
        int n = datas.size();
        int h = 1;
        while (h < n / 3)
            h = 3 * h + 1;

        while (h >= 1)
        {
            // 对间隔为h的数据进行排序
            for (int i = h; i < n; i++)
            {
                for (int j = i; j >= h; j -= h)
                {
                    if (datas[j - h] > datas[j])
                        exch(datas, j, j - h);
                    else
                        break;
                }
            }

            h = h / 3; //缩小间隔
        }
    }
};