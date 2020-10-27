#include <iostream>
#include <vector>
#include "utility.h"

template <typename type>
class Quick
{
public:
    void exch(std::vector<type> &datas, int si, int ti)
    {
        type temp = datas[si];
        datas[si] = datas[ti];
        datas[ti] = temp;
    }

    int partition(std::vector<type> &datas, int lo, int hi)
    {
        if (hi <= lo)
            return hi;

        int pi = lo;     //切分点索引
        int fi = lo;     //前段搜索索引
        int ei = hi + 1; //后段搜索索引

        while (fi < ei)
        {
            // 查找前段第一个大于切分点变量的值的位置
            // 查找后段第一个小于切分点变量的值的位置
            while (datas[++fi] <= datas[pi])
                if (fi == hi)
                    break;
            while (datas[--ei] >= datas[pi])
                if (ei == lo)
                    break;

            if (fi >= ei)
                break;

            // 将前段较大的点和后段较小的点进行交换
            exch(datas, fi, ei);
        }

        exch(datas, ei, lo);

        return ei;
    }

    void sort(std::vector<type> &datas, int lo, int hi)
    {
        // 递归终止条件1: 只有一个数据
        if (hi <= lo)
            return;

        // 递归终止条件2: 数据有序
        if (isSorted(datas, lo, hi))
            return;

        // 递归切分
        int pi = partition(datas, lo, hi);
        sort(datas, lo, pi);
        sort(datas, pi + 1, hi);
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