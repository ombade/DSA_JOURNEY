#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *Next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        Next = NULL;
        prev = NULL;
    }
};

void insertAtHead(Node *&Head, int data)
{
    Node *Temp = new Node(data);
    if (Head == NULL)
    {
    }
}
int main()
{
    return 0;
}