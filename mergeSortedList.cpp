#include <iostream>

using namespace std;

struct Node
{
    int x;
    Node *next;
};

Node *merge(Node *list1, Node *list2)
{
    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;

    if (list1->x > list2->x)
    {
        list2->next = merge(list2->next, list1);
        return list2;
    }
    else
    {
        list1->next = merge(list1->next, list2);
        return list1;
    }
}
int main()
{
    Node *a = new Node{1, new Node{3, new Node{5, new Node{7, new Node{9, nullptr}}}}};
    Node *b = new Node{2, new Node{4, new Node{6, new Node{8, new Node{10, nullptr}}}}};

    Node *p = merge(a, b);
    while (p != nullptr)
    {
        cout << p->x << endl;
        p = p->next;
    }
}