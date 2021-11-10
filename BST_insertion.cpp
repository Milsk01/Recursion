#include <iostream>
#include <initializer_list>

#include <stdexcept>
using std::cout;
using std::endl;
using std::invalid_argument;

struct Node
{
    int x;
    Node *left;
    Node *right;
};

void preOrder(Node *head)
{
    if (head != nullptr)
    {

        cout << head->x;
        preOrder(head->left);
        preOrder(head->right);
    }
}
void inOrder(Node *head)
{
    if (head != nullptr)
    {

        inOrder(head->left);
        cout << head->x;
        inOrder(head->right);
    }
}
void postOrder(Node *head)
{
    if (head != nullptr)
    {

        postOrder(head->left);
        postOrder(head->right);
        cout << head->x;
    }
}
class Tree
{
    Node *head;

public:
    Node *getRoot()
    {
        return head;
    }
    Tree()
    {
        head = nullptr;
    }
    Tree(std::initializer_list<int> list) : Tree()
    {
        std::initializer_list<int>::const_iterator it = list.begin();

        while (it != list.end())
        {
            head = insert(head, *it);
            it++;
        }
    }
    Node *insert(Node *headPtr, int data)
    {
        if (headPtr == nullptr)
        {
            headPtr = new Node{data, nullptr, nullptr};
            return headPtr;
        }

        if (headPtr->x > data)
        {
            headPtr->left = insert(headPtr->left, data);
        }
        else
        {
            headPtr->right = insert(headPtr->right, data);
        }

        return headPtr;
    }

    void traverse(void (*traverseMode)(Node *))
    {

        traverseMode(head);
    }

    int minElem()
    {

        Node *dummy = head;
        if (head != nullptr)
        {

            if (head->left == nullptr)
            {
                return head->x;
            }
            else
            {
                while (dummy->left != nullptr)
                {
                    dummy = dummy->left;
                }
                return dummy->x;
            }
        }
        else
        {
            throw invalid_argument("Empty List");
        }
    }

    int maxElem()
    {

        Node *dummy = head;
        if (head != nullptr)
        {
            if (head->right == nullptr)
            {
                return head->x;
            }
            else
            {
                while (dummy->right != nullptr)
                {
                    dummy = dummy->right;
                }
            }
            return dummy->x;
        }
        else
        {
            throw invalid_argument("Empty List");
        }
    }

    bool search(int target)
    {
        Node *dummy = head;
        if (head == nullptr)
        {
            return 0;
        }

        while (dummy != nullptr)
        {
            if (dummy->x == target)
            {
                return 1;
            }
            if (head->x > target)
            {
                dummy = dummy->left;
            }
            else
            {
                dummy = dummy->right;
            }
        }

        return 0;
    }
};

int main()
{
    Tree binary_search_tree({5, 6, 2, 4, 9});
    Node *Root = binary_search_tree.getRoot();
    binary_search_tree.insert(Root, 10);
    cout << binary_search_tree.minElem() << endl;
    cout << binary_search_tree.maxElem() << endl;

    //binary_search_tree.traverse(preOrder);
}