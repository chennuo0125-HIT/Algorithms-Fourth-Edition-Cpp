#include <iostream>
#include <string>
#include <vector>

namespace binary_search
{

struct Node
{
    std::string key;
    int value;
    Node() {}
    Node(const std::string &key, int value) : key(key), value(value) {}
};

class BinarySearchST
{
public:
    BinarySearchST() : nodes_(0), size_(0) {}
    void put(std::string &key, int value)
    {
        int index = rank(key);
        if (index < size_ && nodes_[index].key == key)
            nodes_[index].value = value;
        else
        {
            nodes_.resize(size_ + 1);
            for (int i = size_; i > index; i--)
                nodes_[i] = nodes_[i - 1];
            nodes_[index] = Node(key, value);
        }

        size_ = nodes_.size();
    }

    bool get(const std::string &key, int &value)
    {
        int index = rank(key);
        if (index < size_ && nodes_[index].key == key)
        {
            value = nodes_[index].value;
            return true;
        }
        else
            return false;
    }

    // 二分查找
    int rank(const std::string &key)
    {
        int lo = 0;
        int hi = size_ - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (nodes_[mid].key == key)
                return mid;
            else if (nodes_[mid].key < key)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        return lo;
    }

    void getKeys(std::vector<std::string> &keys)
    {
        keys.resize(nodes_.size());
        for (int i = 0; i < nodes_.size(); i++)
            keys[i] = nodes_[i].key;
    }

private:
    std::vector<Node> nodes_;
    int size_;
};

} // namespace binary_search