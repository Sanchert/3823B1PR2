#include <iostream>

using namespace std;

template <typename TKey, typename TValue>
class BinSTree
{
private:
    struct TableRec
    {
        TKey key;
        TValue value;
    };
    struct Node
    {
        TableRec data;
        Node* left;
        Node* right;
    };
    Node* root;

    void Print(Node* p)
    {
        if (p == nullptr)
            return;
        Print(p->left);
        cout << p->data.key << " - " << p->data.value << endl;
        Print(p->right);
    }

    Node* FindNode(TKey key, Node* node)
    {
        if (node == nullptr)
            return nullptr;
        if (key < node->data.key)
            node = FindNode(key, node->left);
        if (key > node->data.key)
            node = FindNode(key, node->right);
        return node;
    }

public:
    BinSTree() : root(nullptr) {};
    ~BinSTree() {};
    
    void Print() {
        cout << "table: " << endl;
        Print(root);
    }

    TValue* Find(TKey key)
    {
        Node* node = FindNode(key, root);
        if (node == nullptr)
            return nullptr;
        return &node->data.value;
    }

    // вставка и удаление
    void Insert(TKey key, TValue value)//, BinSTree* tree)
    {
        if (!Find(key))
        {
            Node* newNode = new Node{TableRec{key, value}, nullptr, nullptr};
            Node* current = root;
            Node* parent = nullptr;
            while (current != nullptr) {
                parent = current;
                if (key < current->data.key) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            if (key < parent->data.key) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
        }
    }

};
