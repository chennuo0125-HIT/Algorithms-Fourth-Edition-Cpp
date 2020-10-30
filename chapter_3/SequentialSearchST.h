#include <string>
#include <vector>

namespace sequential_search
{

// 链表节点
struct Node
{
    std::string key;
    int value;
    Node *next;
    Node() : next(NULL) {}
    Node(const std::string &key, int value) : key(key), value(value), next(NULL) {}
};

class SequentialSearchST
{
public:
    SequentialSearchST() : first_(NULL), keys_(0) {}
    ~SequentialSearchST()
    {
        Node *next = first_;
        while (next)
        {
            Node *next_next = next->next;
            delete next;
            next = NULL;
            next = next_next;
        }
    }

    void put(const std::string &key, int value)
    {
        // 查找是否当前键已经存在，如果存在则更新键值
        Node *next = first_;
        while (next)
        {
            if (next->key == key)
            {
                next->value = value;
                return;
            }
            else
                next = next->next;
        }

        // 链表以前端插入的方式添加键
        Node *last_first = first_;
        first_ = new Node(key, value);
        first_->next = last_first;
        keys_.push_back(key);
        size_++;
    }

    bool get(const std::string &key, int &value)
    {
        Node *next = first_;
        while (next)
        {
            if (next->key == key)
            {
                value = next->value;
                return true;
            }
            else
                next = next->next;
        }

        return false;
    }

    bool contains(const std::string &key)
    {
        Node *next = first_;
        while (next)
        {
            if (next->key == key)
                return true;
            else
                next = next->next;
        }

        return false;
    }

    void getKeys(std::vector<std::string> &keys)
    {
        keys = keys_;
    }

private:
    Node *first_;                   //用于存储符号表的链表的首节点
    int size_;                      //键数
    std::vector<std::string> keys_; //键值集合
};

} // namespace sequential_search