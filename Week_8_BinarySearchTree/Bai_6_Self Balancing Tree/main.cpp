#include <iostream>
using namespace std;

typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
    int ht;
} node;

int height(node *N)
{
    if (N == nullptr)
        return -1; 
    return N->ht; 
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getBalance(node *N)
{
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->ht = max(height(y->left), height(y->right)) + 1;
    x->ht = max(height(x->left), height(x->right)) + 1;

    return x; 
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->ht = max(height(x->left), height(x->right)) + 1;
    y->ht = max(height(y->left), height(y->right)) + 1;

    return y; 
}

node *insert(node *root, int val)
{
    if (root == nullptr)
    {
        node *newNode = new node();
        newNode->val = val;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->ht = 0; 
        return newNode;  
    }

    if (val < root->val)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->val)
    {
        root->right = insert(root->right, val);
    }
    else
    {
        return root;
    }

    root->ht = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && val < root->left->val)
    {
        return rightRotate(root);
    }

    if (balance < -1 && val > root->right->val)
    {
        return leftRotate(root);
    }

    if (balance > 1 && val > root->left->val)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && val < root->right->val)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root; 
}

void preOrder(node *root)
{
    if (root != nullptr)
    {
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    node *root = nullptr;

    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6); 

    cout << "Arranged Tree (preorder):" << endl;
    preOrder(root);

    return 0;
}
