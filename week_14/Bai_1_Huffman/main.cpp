#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
};

void decodeHuffman(Node *root, const string &encodedString)
{
    Node *current = root;
    string decodedString;

    for (char bit : encodedString)
    {
        if (bit == '0')
        {
            current = current->left;
        }
        else if (bit == '1')
        {
            current = current->right;
        }

        if (!current->left && !current->right)
        {
            decodedString += current->data;
            current = root;
        }
    }

    cout << decodedString << endl;
}

int main()
{
    Node *root = new Node{'*', nullptr, nullptr};
    root->left = new Node{'*', nullptr, nullptr};
    root->right = new Node{'*', nullptr, nullptr};
    root->left->left = new Node{'A', nullptr, nullptr};
    root->left->right = new Node{'B', nullptr, nullptr};
    root->right->left = new Node{'C', nullptr, nullptr};
    root->right->right = new Node{'D', nullptr, nullptr};

    string encodedString;
    cin >> encodedString;

    decodeHuffman(root, encodedString);

    return 0;
}
