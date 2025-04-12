#include <iostream>
#include <vector>

using namespace std;

template <typename TKey, typename TValue>
class AVLTree
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
        int balance;
    };
    Node* root;

    void Print(Node* p)
    {
        if (p == nullptr)
            return;
        Print(p->left);
        cout << p->data.key << " - " << p->data.value << "; balance: " << p->balance << endl;
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
            return root;
        if (key < root->data.key) 
            root->left = deleteNode(root->left, key);
        else if (key > root->data.key) 
            root->right = deleteNode(root->right, key);
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
                while (minNode->left != nullptr)
                    minNode = minNode->left;
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

    void UpdateBalance(Node* node) {
        node->balance =  Depth(node->right) - Depth(node->left);
    }

    Node* RotateRight(Node* y) {
        Node* x = y->left;
        if (y == root)
        {
            root = x;   
        }
        y->left = x->right;
        x->right = y;
        UpdateBalance(y);
        UpdateBalance(x);
        return x;
    }

    Node* RotateLeft(Node* x) {
        Node* y = x->right;
        if (x == root)
        {
            root = y;   
        }
        x->right = y->left;
        y->left = x;
        UpdateBalance(x);
        UpdateBalance(y);
        return y;
    }

    Node* Balance(Node* node) {
        UpdateBalance(node);

        if (node->balance == 2) {
            if (node->right->balance < 0) {
                node->right = RotateRight(node->right);
            }
            return RotateLeft(node);
        }
        if (node->balance == -2) {
            if (node->left->balance > 0) {
                node->left = RotateLeft(node->left);
            }
            return RotateRight(node);
        }
        return node;
    }

public:
    AVLTree() : root(nullptr) {};
    ~AVLTree() {};
    
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
            vector<Node*> path;
            Node* newNode = new Node{TableRec{key, value}, nullptr, nullptr, 0};
            if (root == nullptr)
                root = newNode;
            else
            {
                Node* current = root;
                Node* parent = nullptr;
                while (current != nullptr) 
                {
                    parent = current;
                    path.push_back(parent);
                    if (key < current->data.key) 
                        current = current->left;
                    else 
                        current = current->right;    
                }
                if (key < parent->data.key)
                    parent->left = newNode;
                else
                    parent->right = newNode;

                for (auto node = path.rbegin(); node != path.rend(); ++node) 
                    *node = Balance(*node);
            }
        }
    }

    void Delete(TKey key)
    {
        root = deleteNode(root, key);    
    }
};

