#include <iostream>
#include <iomanip>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
private:
    Node *root;

    Node *insert(Node *node, int data)
    {
        if (node == nullptr)
        {
            return new Node(data);
        }
        if (data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else
        {
            node->right = insert(node->right, data);
        }
        return node;
    }

    void inOrderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    int treeHeight(Node *node)
    {
        if (node == nullptr)
        {
            return -1;
        }
        int leftHeight = treeHeight(node->left);
        int rightHeight = treeHeight(node->right);
        return 1 + max(leftHeight, rightHeight);
    }

    bool checkBST(Node *node, int min, int max)
    {
        if (node == nullptr)
            return true;
        if (node->data <= min || node->data >= max)
            return false;
        return checkBST(node->left, min, node->data) &&
               checkBST(node->right, node->data, max);
    }

public:
    BinaryTree()
    {
        root = nullptr;
    }

    void insert(int data)
    {
        root = insert(root, data);
    }

    void inOrder()
    {
        inOrderTraversal(root);
    }

    int height()
    {
        return treeHeight(root);
    }

    bool checkBST()
    {
        return checkBST(root, INT_MIN, INT_MAX);
    }
};

int main()
{
    BinaryTree tree;
    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int data;
        cin >> data;
        tree.insert(data);
    }

    cout << "Height: " << tree.height() << endl;
    cout << "InOrder Traversal: ";
    tree.inOrder();
    cout << endl;

    if (tree.checkBST())
    {
        cout << "YES, This is BST!" << endl;
    }
    else
    {
        cout << "NO, This is not a BST!" << endl;
    }

    return 0;
}
