#include <iostream>

using namespace std;

struct Node
{
    int x;
    Node *next;
};

Node *reverseLinkedList(Node *head)
{

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *p = reverseLinkedList(head->next);

    head->next->next = head;
    head->next = nullptr;
    return p;
}
int main()
{
    Node *head = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, nullptr}}}}};

    head = reverseLinkedList(head);
    while (head != nullptr)
    {
        cout << head->x;
        head = head->next;
    }
}