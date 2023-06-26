#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    Node()
    {
        data = 0;
        next = NULL;
    }
};

void insertAtHead(Node *&Head, int data)
{
    // creating the new node with the new keyword;
    Node *temp = new Node(data);

    // condition for the the empty list
    if (Head == NULL)
    {
        Head = temp;
    }

    else
    {
        temp->next = Head;
        Head = temp;
    }
}

void insertAtTail(Node *&Tail, int data)
{
    // creating the new node with the new keyword;
    Node *temp = new Node(data);

    // condition for the the empty list
    if (Tail == NULL)
    {
        Tail = temp;
    }
    else
    {
        Tail->next = temp;
        Tail = temp;
    }
}
void cnt(Node *&Head)
{
    Node *temp = new Node(0);
    temp = Head;
    int count = 0;
    if (Head == NULL)
    {
        cout << "The List is Empty " << endl;
    }
    else
    {
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        cout << "The Number of Nodes in The List is ->  " << count << endl;
    }
}

void InsertAtPostion(Node *&Head, int postion, int data)
{
    if (postion == 1)
    {
        insertAtHead(Head, data);
    }
    else
    {
    }
}
void print(Node *Head)
{
    Node *temp = new Node(0);
    temp = Head;

    if (Head == NULL)
    {
        cout << "The List is Empty " << endl;
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl
             << endl;
    }
}
// int main()
// {
//     Node *Node1 = new Node(0);
//     Node *Head = Node1;
//     Node *Tail = Node1;
//     print(Head);
//     insertAtHead(Head, 10);
//     print(Head);
//     insertAtTail(Tail, 20);
//     print(Head);
//     cnt(Head);
//     return 0;
// }