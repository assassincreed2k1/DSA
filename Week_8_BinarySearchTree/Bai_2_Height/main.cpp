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

class BinarySearchTree
{

public:
    BinarySearchTree()
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

    void display()
    {
        displayBinarySearchTree(root, 0);
    };

    int height()
    {
        return treeHeight(root);
    }

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

    void displayBinarySearchTree(Node *node, int space)
    {
        if (node == nullptr)
        {
            return;
        }

        space += 10;

        displayBinarySearchTree(node->right, space);

        cout << endl;
        cout << setw(space) << node->data << endl;

        displayBinarySearchTree(node->left, space);
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
};

int main()
{
    BinarySearchTree tree;
    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int data;
        cin >> data;
        tree.insert(data);
    }
    cout << tree.height();

    // cout << "Binary Search Tree:" << endl;
    // tree.display();

    return 0;
}
