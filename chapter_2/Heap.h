#pragma once

#include <iostream>
#include <vector>
#include "utility.h"

template <typename type>
class Heap
{
public:
    void exch(std::vector<type> &datas, int si, int ti)
    {
        type temp = datas[si];
        datas[si] = datas[ti];
        datas[ti] = temp;
    }

    // 从idx位置下沉到最大ti位置，从ti位置开始保存了丢弃的最大值
    void sink(std::vector<type> &datas, int idx, int ti)
    {
        // 当存在子节点时
        while (2 * idx < ti)
        {
            int left_idx = 2 * idx;
            int righ_idx = 2 * idx + 1;
            // 只有一个子节点时，只用比较该子节点
            if (righ_idx + 1 > ti)
            {
                if (datas[left_idx] > datas[idx])
                {
                    exch(datas, left_idx, idx);
                    idx = left_idx;
                }
                else
                    break;
            }
            // 当有两个子节点时，需要与较大的子节点进行比较
            else
            {
                if (datas[left_idx] >= datas[righ_idx] && datas[left_idx] > datas[idx])
                {
                    exch(datas, left_idx, idx);
                    idx = left_idx;
                }
                else if (datas[left_idx] < datas[righ_idx] && datas[righ_idx] > datas[idx])
                {
                    exch(datas, righ_idx, idx);
                    idx = righ_idx;
                }
                else
                    break;
            }
        }
    }

    void sort(std::vector<type> &raw_datas)
    {
        // 添加一个空的头部，保证第一个元素的索引是1
        std::vector<type> datas(raw_datas.size() + 1);
        for (int i = 0; i < raw_datas.size(); i++)
            datas[i + 1] = raw_datas[i];

        if (datas.size() <= 1)
        {
            std::cout << "datas size less than 1, no need sort !!!" << std::endl;
            return;
        }

        // 避免对已经有序的数据进行不必要的排序
        if (isSorted(datas, 1, datas.size() - 1))
            return;

        // 堆的构造
        for (int i = datas.size() / 2; i >= 1; i--)
            sink(datas, i, datas.size());

        // 下沉排序
        for (int i = 1; i < datas.size(); i++)
        {
            exch(datas, 1, datas.size() - i);
            sink(datas, 1, datas.size() - i);
        }

        // 还原数据
        for (int i = 0; i < raw_datas.size(); i++)
            raw_datas[i] = datas[i + 1];
    }
};