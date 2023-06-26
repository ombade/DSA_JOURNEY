#include <iostream>
using namespace std;

void q1()
{
    int a, b = 1;
    a = 10;
    if (++a)
    {
        cout << b;
    }
    else
    {
        cout << ++b;
    }
}
void q2()
{
    int a = 1, b = 2;
    if (a-- > 0 && ++b > 2)
    {
        cout << "stage 1 \n";
    }
    else
    {
        cout << "Stage 2";
    }
    cout << a << "  " << b << endl;
}
int main()
{
    q2();
    return 0;
}