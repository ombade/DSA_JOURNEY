// Iterative C++ program to reverse a linked list
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node
{
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node *head;
    LinkedList() { head = NULL; }

    /* Function to reverse the linked list */
    void reverse()
    {
        // Initialize current, previous and next pointers
        Node *curr = head;
        Node *prev = NULL, *next = NULL;
        int i = 0;
        cout << endl;
        while (curr != NULL)
        {
            // // Store next
            // next = current->next;
            // // Reverse current node's pointer
            // current->next = prev;
            // // Move pointers one position ahead.
            // prev = current;
            // current = next;
            next = curr->next;
            cout << "for curr -> " << i << " --- " << curr->data << endl;
            curr->next = prev;
            // cout << "for prev  -> " << i << " --- " << prev->data << endl;
            prev = curr;
            cout << "for prev -> " << i << " --- " << prev->data << endl;
            curr = next;
            cout << "for next  -> " << i << " --- " << next->data << endl;
            i++;
        }
        head = prev;
    }

    /* Function to print linked list */
    void print()
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

/* Driver code*/
int main()
{
    /* Start with the empty list */
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);

    cout << "Given linked list\n";
    ll.print();

    ll.reverse();

    cout << "\nReversed linked list \n";
    ll.print();
    return 0;
}
