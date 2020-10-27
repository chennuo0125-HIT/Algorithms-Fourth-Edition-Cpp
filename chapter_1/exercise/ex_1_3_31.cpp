/**********************
 * 
 * Realization of bidirectional linked list
 * (Exercise 1.3.31)
 * 
 **********************/

#include <iostream>

template <typename T>
class DoubleNode
{
public:
    DoubleNode() : prev(NULL), next(NULL) {}
    ~DoubleNode() {}
    T item;
    DoubleNode *prev;
    DoubleNode *next;
};

template <typename T>
class DoubleList
{
public:
    DoubleList() : first(NULL), last(NULL), N(0) {}
    ~DoubleList()
    {
        while (first)
        {
            DoubleNode<T> *next = first->next;
            delete first;
            first = NULL;
            first = next;
        }
        last = NULL;
    }

    int size() { return N; }

    bool isEmpty() { return NULL == first; }

    // search corresponding node by index
    DoubleNode<T> *getNode(int index)
    {
        if (index < 0)
            index = -index;
        if (index >= size())
        {
            std::cout << "index " << index << " beyond boundary [0, " << (N - 1) << "]" << std::endl;
            return NULL;
        }

        if (index > 0.5 * N) //search from last
        {
            DoubleNode<T> *cur_node = last;
            int cur_index = N - 1;
            while (cur_index != index)
            {
                cur_node = cur_node->prev;
                cur_index--;
            }
            return cur_node;
        }
        else //search from first
        {
            DoubleNode<T> *cur_node = first;
            int cur_index = 0;
            while (cur_index != index)
            {
                cur_node = cur_node->next;
                cur_index++;
            }
            return cur_node;
        }
    }

    void prepend(T item)
    {
        DoubleNode<T> *node(new DoubleNode<T>());
        node->item = item;

        if (isEmpty())
        {
            first = node;
            last = node;
            N++;
            return;
        }

        node->next = first;
        first->prev = node;
        first = node;
        N++;
    }

    void append(T item)
    {
        DoubleNode<T> *node(new DoubleNode<T>());
        node->item = item;

        if (isEmpty())
        {
            first = node;
            last = node;
            N++;
            return;
        }

        node->prev = last;
        last->next = node;
        last = node;
        N++;
    }

    void insertBefore(DoubleNode<T> *node, T item)
    {
        if (node == first)
            prepend(item);
        else
        {
            DoubleNode<T> *new_node(new DoubleNode<T>);
            new_node->item = item;
            node->prev->next = new_node;
            new_node->prev = node->prev;
            new_node->next = node;
            node->prev = new_node;
        }
        N++;
    }

    void insertAfter(DoubleNode<T> *node, T item)
    {
        if (node == last)
            append(item);
        else
        {
            DoubleNode<T> *new_node(new DoubleNode<T>());
            new_node->item = item;
            node->next->prev = new_node;
            new_node->next = node->next;
            new_node->prev = node;
            node->next = new_node;
        }
        N++;
    }

    T removeFirst()
    {
        if (isEmpty())
        {
            last = NULL;
            std::cout << "double list is empty !" << std::endl;
            return T();
        }

        if (size() == 1)
        {
            T result = first->item;
            delete first;
            first = NULL;
            last = NULL;
            return result;
        }

        DoubleNode<T> *last_first = first;
        first = first->next;
        first->prev = NULL;

        T result = last_first->item;
        delete last_first;
        last_first = NULL;
        N--;
        return result;
    }

    T removeLast()
    {
        if (isEmpty())
        {
            first = NULL;
            std::cout << "double list is empty !" << std::endl;
            return T();
        }

        if (size() == 1)
        {
            T result = last->item;
            delete last;
            last = NULL;
            first = NULL;
            return result;
        }

        DoubleNode<T> *last_last = last;
        last = last_last->prev;
        last->next = NULL;

        T result = last_last->item;
        delete last_last;
        last_last = NULL;
        N--;
        return result;
    }

    T remove(DoubleNode<T> *node)
    {
        T result;

        if (node == first)
            result = removeFirst();
        else if (node == last)
            result = removeLast();
        else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            result = node->item;
            delete node;
            node = NULL;
        }

        N--;
        return result;
    }

private:
    DoubleNode<T> *first;
    DoubleNode<T> *last;
    int N;
};

/**************************************** test ************************************************/
int data[5] = {2, 4, 6, 8, 10};

void showList(DoubleList<int> &list)
{
    int size = list.size();
    for (int i = 0; i < size; i++)
    {
        std::cout << list.getNode(i)->item << " ";
    }
    std::cout << std::endl;
}

void testPrepend()
{
    DoubleList<int> list;
    for (int i = 0; i < 5; i++)
        list.prepend(data[i]);
    std::cout << "test prepend result : ";
    showList(list);
}

void testAppend()
{
    DoubleList<int> list;
    for (int i = 0; i < 5; i++)
        list.append(data[i]);
    std::cout << "test append result : ";
    showList(list);
}

void testRemoveFirst()
{
    DoubleList<int> list;
    for (int i = 0; i < 5; i++)
        list.append(data[i]);

    std::cout << "test remove first result : ";
    for (int i = 0; i < 5; i++)
        std::cout << list.removeFirst() << " ";
    std::cout << std::endl;
}

void testRemoveLast()
{
    DoubleList<int> list;
    for (int i = 0; i < 5; i++)
        list.append(data[i]);

    std::cout << "test remove last result : ";
    for (int i = 0; i < 5; i++)
        std::cout << list.removeLast() << " ";
    std::cout << std::endl;
}

void testRemove()
{
    DoubleList<int> list;
    for (int i = 0; i < 5; i++)
        list.append(data[i]);

    int remove_indexs[4] = {2, -1, 1, 1};
    std::cout << std::endl;
    std::cout << "test remove result : " << std::endl;
    for (int i = 0; i < 4; i++)
        std::cout << "remove node[" << remove_indexs[i] << "]->" << list.remove(list.getNode(remove_indexs[i])) << std::endl;
}

void testInsertBefore()
{
    DoubleList<int> list;
    for (int i = 0; i < 5; i++)
        list.append(data[i]);

    int k[4] = {3, 2, 1, -1};
    int x[4] = {12, 14, 16, 18};
    std::cout << std::endl;
    std::cout << "test insert before result : " << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << "insert " << x[i] << " before node[" << k[i] << "]" << std::endl;
        list.insertBefore(list.getNode(k[i]), x[i]);
    }
    showList(list);
}

void testInsertAfter()
{
    DoubleList<int> list;
    for (int i = 0; i < 5; i++)
        list.append(data[i]);

    int k[4] = {2, -2, -1, 1};
    int x[4] = {9, 11, 13, 15};
    std::cout << std::endl;
    std::cout << "test insert after result : " << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << "insert " << x[i] << " after node[" << k[i] << "]" << std::endl;
        list.insertAfter(list.getNode(k[i]), x[i]);
    }
    showList(list);
}

int main(int argc, char **argv)
{
    testPrepend();
    testAppend();
    testRemoveFirst();
    testRemoveLast();
    testRemove();
    testInsertBefore();
    testInsertAfter();

    return 0;
}