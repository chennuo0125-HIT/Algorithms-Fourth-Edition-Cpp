#include <iostream>
#include <vector>
#include <string>

namespace bst
{

struct Node
{
    std::string key;
    int value;
    int index;
    Node *left;
    Node *right;
    Node() : left(NULL), right(NULL), index(0) {}
    Node(std::string key, int value) : key(key), value(value), left(NULL), right(NULL), index(0) {}
};

class BST
{
public:
    BST() : root_(NULL) {}
    ~BST()
    {
        release(root_);
    }

    void release(Node *node)
    {
        if (!node)
            return;
        else
        {
            Node *left = node->left;
            Node *right = node->right;
            delete node;
            release(left);
            release(right);
        }
    }

    void put(Node *node, std::string &key, int value)
    {
        if (!node)
            node = new Node(key, value);
        else
        {
            if (node->key > key)
                put(node->left, key, value);
            else if (node->key < key)
                put(node->right, key, value);
            else
                node->value = value;
        }
    }

    void put(std::string &key, int value)
    {
        put(root_, key, value);
    }

    bool get(const Node *node, const std::string &key, int &value)
    {
        if (node->key > key)
            return get(node->left, key, value);
        else if (node->key < key)
            return get(node->right, key, value);
        else
        {
            value = node->value;
            return true;
        }
    }

    bool get(const std::string &key, int &value)
    {
        return get(root_, key, value);
    }

private:
    Node *root_;
};

} // namespace bst