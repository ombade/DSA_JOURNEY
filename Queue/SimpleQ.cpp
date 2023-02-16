#include <iostream>
using namespace std;

class queue
{
public:
    int *arr;
    int front, rare;

    int size;
    queue(int size1)
    {
        front = rare = -1;
        size = size1;
        arr = new int[size1];
    }
    bool isempty()
    {
        if (front == rare)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enque(int data)
    {
        if (rare == size)
        {
            cout << "The queue is full please try again" << endl;
        }
        else
        {

            arr[rare] = data;
            rare++;
        }
    }

    int deque()
    {
        if (isempty())
        {
            cout << "The queue is empty" << endl;
            return -1;
        }
        else
        {
            int ans = arr[front];
            front++;
            if (front == rare)
            {
                front = rare = 0;
            }
            return ans;
        }
    }

    void display()
    {
        for (int i = front; i < rare; i++)
        {
            cout << arr[i] << "  " << endl;
        }
    }
};
int main()
{
    queue q(5);
    q.deque();
    // cout << q.isempty();
    q.display();
    q.enque(2);
    q.enque(2);
    q.enque(2);
    q.enque(2);
    q.enque(2);
    // q.enque(2);
    // q.enque(2);
    // q.enque(2);
    // q.enque(2);
    // q.enque(2);
    // q.enque(2);
    // q.enque(2);
    // q.enque(2);
    // q.enque(2);
    // q.enque(2);
    // q.enque(2);
    q.enque(2);
    q.enque(2);
    q.enque(23);
    q.enque(2);
    q.enque(2);
    q.enque(2);
    q.enque(2);
    q.enque(2);
    q.enque(2);
    // q.enque(2);
    // q.enque(2);
    // q.enque(2);
    q.display();
    return 0;
}