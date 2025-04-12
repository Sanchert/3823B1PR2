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
        else if (key < node->data.key)
            node = FindNode(key, node->left);
        else if (key > node->data.key)
            node = FindNode(key, node->right);
        return node;
    }

    Node* deleteNode(Node* root, TKey key) {
        if (root == nullptr) 
        {
            return root;
        }
        if (key < root->data.key) 
        {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->data.key) 
        {
            root->right = deleteNode(root->right, key);
        } 
        else 
        {
            
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }
            else if (root->left == nullptr)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else 
            {
                Node* minNode = root->right;
                while (minNode->left != nullptr) {
                    minNode = minNode->left;
                }
                root->data = minNode->data;
                root->right = deleteNode(root->right, minNode->data.key);
            }
        }
        return root;
    }

    int Depth(Node* root)
    {
        if (!root)
            return 0;
        else
        {
            int left_depth = Depth(root->left);
            int right_depth = Depth(root->right);
            return max(left_depth, right_depth) + 1;
        }
    }

public:
    BinSTree() : root(nullptr) {};
    ~BinSTree() {};
    
    int Depth()
    {
        return Depth(root);
    }

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

    void Insert(TKey key, TValue value)
    {
        if (!Find(key))
        {
            
            Node* newNode = new Node{TableRec{key, value}, nullptr, nullptr};
            if (root == nullptr)
            {
                root = newNode;
            }
            else
            {
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
    }

    void Delete(TKey key)
    {
        root = deleteNode(root, key);    
    }
};
