#include <iostream>
#include <unordered_map>
#include "singleLL.cpp"
#include <Vector>
#include <unordered_set>
using namespace std;

// Middle of the Linked list ---------------------------------------------------------------------------
int getlen(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
Node *middleNode(Node *head)
{
    int ans = (getlen(head) / 2);
    if (ans % 2 == 0)
    {
        ans = ans + 1;
    }
    Node *temp = head;
    int cnt = 0;
    while (cnt < ans)
    {
        temp = temp->next;
        cnt++;
    }
    return temp;
}

//------------------------------------------------------------------------------------------------------
Node *reverse(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *chota = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return chota;
}
Node *reverseLinkedList(Node *head)
{

    // return reverse(head);
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
// remove Duplicate from the the  unsorted linked list --------------------------------------------------------------------
Node *removeDuplicates(Node *head)
{
    // your code goes here
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head;
    while (curr != NULL)

    {
        Node *temp = curr;
        while (temp != NULL)
        {
            if (temp != NULL && temp->data == temp->next->data)
            {
                Node *temp_next_next = temp->next->next;
                // node * delete_node = temp->next ;
                // delete(delete_node);
                temp->next = temp_next_next;
            }
            else
            {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

// approch 2 using the unorded set -----------------------------------------------------------
Node *removeDuplicates(Node *head)
{
    unordered_set<int> s;
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    while (curr != NULL)
    {
        if (s.find(curr->data) != s.end())
        {
            prev->next = curr->next;
            free(curr);
        }
        else
        {
            s.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
    return head;
}
// /remove Duplicate from the the  unsorted linked list -------------------------------------
// sort 0,1,2 in the linked list #######################################################################
// approch 1 using the brot force approch two while loops
Node *segregate(Node *head)
{

    int zero = 0;
    int one = 0;
    int two = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero++;
        }
        else if (temp->data == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (zero != 0)
        {
            temp->data = 0;
            zero--;
        }
        else if (one != 0)
        {
            temp->data = 1;
            one--;
        }
        else
        {
            temp->data = 2;
            two--;
        }
        temp = temp->next;
    }
    return head;
}

//// approch two using the  marge sort ofthe respective list ;

// function for the insert the current element at the tail of the node
void insertAtTail(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}

Node *segregate(Node *head)
{

    // creating the head and tail node of thezero one and two node respective and giveing the root value ass -1
    Node *zerohead = new Node(-1);
    Node *zerotail = zerohead;
    Node *onehead = new Node(-1);
    Node *onetail = onehead;
    Node *twohead = new Node(-1);
    Node *twotail = twohead;

    Node *curr = head;
    while (curr != NULL)
    {
        int value = curr->data;
        if (value == 0)
        {
            insertAtTail(zerotail, curr);
        }
        else if (value == 1)
        {
            insertAtTail(onetail, curr);
        }
        else if (value == 2)
        {
            insertAtTail(twotail, curr);
        }
        curr = curr->next;
    }

    // mearge the 3 sublist ;
    if (onehead->next != NULL)
    {
        zerotail->next = onehead->next;
    }
    else
    {
        zerotail->next = twohead->next;
    }
    onetail->next = twohead->next;
    twotail->next = NULL;
    // head setup
    head = zerohead->next;
    delete zerohead;
    delete onehead;
    delete twohead;
    return head;
}

// #############################################################################################

// Meage the Two sorted linklist
Node *solve(Node *head1, Node *head2)
{

    if (head1->next == NULL)
    { // merging single element of first ll to another

        // here head1->val <= head2->val is considered

        head1->next = head2;

        return head1;
    }

    Node *curr1 = head1;

    Node *next1 = curr1->next;

    Node *curr2 = head2;

    Node *next2 = curr2->next;

    while (next1 && curr2)
    {

        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {

            curr1->next = curr2;

            next2 = curr2->next;

            curr2->next = next1;

            curr1 = curr2;

            curr2 = next2;
        }

        else
        {

            curr1 = curr1->next;

            next1 = next1->next;

            if (!next1)
            {

                curr1->next = curr2;

                return head1;
            }
        }
    }

    return head1;
}

Node *sortedMerge(Node *head1, Node *head2)

{

    if (!head1)

        return head2;

    if (!head2)

        return head1;

    if (head1->data > head2->data)
    {

        solve(head2, head1);
    }

    else

        solve(head1, head2);
}
// ================================================================================================================/

// --------------------------------------------Palindrone linklist question----------------------------------
bool Palindrome(vector<int> arr)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        if (arr[s] != arr[e])
        {
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}
// Function to check whether the list is palindrome.
bool isPalindrome(Node *head)
{
    // Your code here
    vector<int> v;
    Node *temp = head;
    while (temp != NULL)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    return (Palindrome(v));
}

// --------second approch using the mid reverse ---------------------------------------------------------
//   this approch shows the segment falut in gfg and working with some cases with the leatcode

Node *getmid(Node *head)
{
    Node *temp = head;
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node *rev(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;

    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to check whether the list is palindrome.
bool isPalindrome(Node *head)
{
    // step 1  find the middle node of the linked list
    Node *mid = getmid(head);

    /// step 2 reverse the LL after the midle
    Node *temp = mid->next;
    mid->next = rev(temp);

    // compare between two halves
    Node *head1 = head;
    Node *head2 = mid->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}
///  ////////////////////////////////////////////////////////////////////////////////
// split the link list into two equal parts -----------------------------------------------
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *slow = head;

    Node *fast = head->next;

    while (fast != head && fast->next != head)
    {

        slow = slow->next;

        fast = fast->next->next;
    }

    *head1_ref = head;

    *head2_ref = slow->next;

    slow->next = *head1_ref;

    Node *curr = *head2_ref;

    while (curr->next != head)
    {

        curr = curr->next;
    }

    curr->next = *head2_ref;
    // -------------------------------------------------------------------------------------

    /// add the 2 number Represented  by the two linked list------------------------------------------------
    Node *insertAtTail(struct Node * &head, struct Node * &tail, int data)
    {
        Node *temp = new Node(data);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    Node *add(struct Node * first, struct Node * second)
    {
        int carry = 0;
        Node *ansHead = NULL;
        Node *ansTail = NULL;
        while (first != NULL || second != NULL || carry != 0)
        {
            int val1 = 0;
            if (first != NULL)
            {
                val1 = first->data;
            }
            int val2 = 0;
            if (second != NULL)
            {
                val2 = second->data;
            }

            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
            if (first != NULL)
            {
                first = first->next;
            }

            if (second != NULL)
            {
                second = second->next;
            }
        }
        return ansHead;
    }

    Node *rev(Node * &head)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node * first, struct Node * second)
    {
        // step 1 reverse the both the link list
        first = rev(first);
        second = rev(second);

        // step 2 add the both the linked list
        Node *ans = NULL;

        ans = add(first, second);
        // step 3 reverse the ans linked list
        ans = rev(ans);
        return ans;
    }

    // --------------------------------------------------------------------------------------------------------

    // clone the linked list using map question ---------------------------------------------------------
    void insertAtTail(Node * &head, Node * &tail, int data)
    {
        Node *temp = new Node(data);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    Node *copyList(Node * head)
    {

        // step 1 creating the clone linked list of the given list
        Node *clonehead = NULL;
        Node *cloneTail = NULL;
        Node *temp = head;
        while (temp != NULL)
        {
            insertAtTail(clonehead, cloneTail, temp->data);
            temp = temp->next;
        }

        //  step 2 Creating the map storing the mapping from clone ll and orginal ll
        unordered_map<Node *, Node *> oldToNewNode;

        Node *orginalNode = head;
        Node *cloneNode = clonehead;
        while (orginalNode != NULL && cloneNode != NULL)
        {
            oldToNewNode[orginalNode] = cloneNode;
            orginalNode = orginalNode->next;
            cloneNode = cloneNode->next;
        }
        orginalNode = head;
        cloneNode = clonehead;
        while (orginalNode != NULL)
        {
            cloneNode->arb = oldToNewNode[orginalNode->arb];
            cloneNode = cloneNode->next;
            orginalNode = orginalNode->next;
        }
        return clonehead;
    }
    // -------------------------------------------------------------------------------------------------
    // clone the linked list by not using map but using the relation
    void insertAtTail(Node * &head, Node * &tail, int data)
    {
        Node *temp = new Node(data);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    Node *copyList(Node * head)
    {

        // step 1 create the clone linked list
        Node *clonehead = NULL;
        Node *clonetail = NULL;
        Node *temp = head;
        while (temp != NULL)
        {
            insertAtTail(clonehead, clonetail, temp->data);
            temp = temp->next;
        }

        // step 2 add the clone node between the two orginal nodes

        Node *next = NULL;
        Node *next2 = NULL;
        Node *orginalNode = head;
        Node *cloneNode = clonehead;
        while (orginalNode != NULL && cloneNode != NULL)
        {
            /*
          next =  orginalNode->next;
          orginalNode->next = cloneNode ;
          next2 = cloneNode ->next;
          cloneNode ->next = next ;
          orginalNode = next;
          */
            next = orginalNode->next;
            orginalNode->next = cloneNode;
            orginalNode = next;
            next = cloneNode->next;
            cloneNode->next = orginalNode;
            cloneNode = next;
        }

        // step 3 random pointer copy
        temp = head;
        while (temp != NULL)
        {
            if (temp->next != NULL)
            {
                temp->next->arb = temp->arb ? temp->arb->next : temp->arb;
            }
            temp = temp->next->next;
        }

        // step 4 revert changes done in the step 2 ;
        orginalNode = head;
        cloneNode = clonehead;
        while (orginalNode != NULL && cloneNode != NULL)
        {
            orginalNode->next = cloneNode->next;
            orginalNode = orginalNode->next;
            if (orginalNode != NULL)
            {
                cloneNode->next = orginalNode->next;
            }
            cloneNode = cloneNode->next;
        }
        // return the ans
        return clonehead;
    }

    //-------------------------------------------------------------------------------------------------
}
int main()
{
    Node *Node1 = new Node(0);
    Node *Head = Node1;
    Node *Tail = Node1;
    print(Head);
    insertAtHead(Head, 10);
    print(Head);
    insertAtTail(Tail, 20);
    print(Head);
    cnt(Head);
    return 0;
}