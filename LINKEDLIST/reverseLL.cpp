#include <iostream>
#include "singleLL.cpp"
using namespace std;

Node *reverseLL(Node *&start)
{
    Node *next = NULL;
    Node *curr = start;
    Node *prev = NULL;
    int i = 0;
    while (curr != NULL)
    {
        next = curr->next;
        cout << "for NEXT -> " << i << " --- " << next->data << endl;
        curr->next = prev;
        // cout << "for prev  -> " << i << " --- " << prev->data << endl;
        prev = curr;
        cout << "for prev -> " << i << " --- " << prev->data << endl;
        curr = next;
        // cout << "for current  -> " << i << " --- " << next->data << endl;
        // i++;
    }
    start = next;
    return prev;
}

int main()
{
    Node *N1 = new Node(1);
    Node *start = N1;
    insertAtHead(start, 2);
    insertAtHead(start, 3);
    insertAtHead(start, 4);
    insertAtHead(start, 5);
    print(start);
    reverseLL(start);
    print(start);
}