#include <iostream>

using namespace std;
struct Node
{
    int x;
    Node *left;
    Node *right;
};

void printLeaves(Node *head)
{
    if (head == nullptr)
    {
        return;
    }

    if (head->left == nullptr && head->right == nullptr)
    {
        cout << head->x;
        return;
    }

    if (head->left != nullptr)
    {
        printLeaves(head->left);
    }

    if (head->right != nullptr)
    {
        printLeaves(head->right);
    }
}