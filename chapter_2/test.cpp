#include <time.h>
#include "Selection.h"
#include "Insertion.h"
#include "Shell.h"
#include "Merge.h"
#include "Quick.h"
#include "Heap.h"

int main(int argc, char **argv)
{
    int rand_num_size = 10000;
    if (argc == 2)
    {
        rand_num_size = atof(argv[1]);
        std::cout << "use " << rand_num_size << " random number test " << std::endl;
    }
    else
        std::cout << "use default " << rand_num_size << " random number test" << std::endl;

    // 产生随机数
    std::vector<int> rand_nums = genRandNum(rand_num_size);

    // 选择排序
    clock_t select_start = clock();
    std::vector<int> select_datas = rand_nums;
    Selection<int> select_sorter;
    select_sorter.sort(select_datas);
    bool select_ok = isSorted(select_datas);
    clock_t select_end = clock();
    if (select_ok)
        std::cout << "select sorted ok, cost time " << double(select_end - select_start) / 1000000 << "[sec] :) :) :)" << std::endl;
    else
        std::cout << "select sorted fail :( :( :( !!!" << std::endl;

    // 插入排序
    clock_t insert_start = clock();
    std::vector<int> insert_datas = rand_nums;
    Insertion<int> insert_sorter;
    insert_sorter.sort(insert_datas);
    bool insert_ok = isSorted(insert_datas);
    clock_t insert_end = clock();
    if (insert_ok)
        std::cout << "insert sorted ok, cost time " << double(insert_end - insert_start) / 1000000 << "[sec] :) :) :)" << std::endl;
    else
        std::cout << "insert sorted fail :( :( :( !!!" << std::endl;

    // 希尔排序
    clock_t shell_start = clock();
    std::vector<int> shell_datas = rand_nums;
    Shell<int> shell_sorter;
    shell_sorter.sort(shell_datas);
    bool shell_ok = isSorted(shell_datas);
    clock_t shell_end = clock();
    if (shell_ok)
        std::cout << "shell sorted ok, cost time " << double(shell_end - shell_start) / 1000000 << "[sec] :) :) :)" << std::endl;
    else
        std::cout << "shell sorted fail :( :( :( !!!" << std::endl;

    // 归并排序
    clock_t merge_start = clock();
    std::vector<int> merge_datas = rand_nums;
    Merge<int> merge_sorter;
    merge_sorter.sort(merge_datas);
    bool merge_ok = isSorted(merge_datas);
    clock_t merge_end = clock();
    if (merge_ok)
        std::cout << "merge sorted ok, cost time " << double(merge_end - merge_start) / 1000000 << "[sec] :) :) :)" << std::endl;
    else
        std::cout << "merge sorted fail :( :( :( !!!" << std::endl;

    // 快速排序
    clock_t quick_start = clock();
    std::vector<int> quick_datas = rand_nums;
    Quick<int> quick_sorter;
    quick_sorter.sort(quick_datas);
    bool quick_ok = isSorted(quick_datas);
    clock_t quick_end = clock();
    if (quick_ok)
        std::cout << "quick sorted ok, cost time " << double(quick_end - quick_start) / 1000000 << "[sec] :) :) :)" << std::endl;
    else
        std::cout << "quick sorted fail :( :( :( !!!" << std::endl;

    // 快速排序
    clock_t heap_start = clock();
    std::vector<int> heap_datas = rand_nums;
    Heap<int> heap_sorter;
    heap_sorter.sort(heap_datas);
    bool heap_ok = isSorted(heap_datas);
    clock_t heap_end = clock();
    if (heap_ok)
        std::cout << "heap sorted ok, cost time " << double(heap_end - heap_start) / 1000000 << "[sec] :) :) :)" << std::endl;
    else
        std::cout << "heap sorted fail :( :( :( !!!" << std::endl;

    return 0;
}