#include<iostream>
using namespace std;
// trailing
// basic approch to return the trailing zeros
int trailing_zeros (int num) 
{
    int number =1 ; // variable for the counting the numbers
    int cnt = 0;
    while (true)
    {

        int temp = number ;
        while (temp%5 == 0)
        {
            cnt ++;
            cout<<"CONnt -> "<<cnt<<endl;
            temp /= 5 ;
        }
        
    if (cnt >= num )
    {
        return number;
        break;
    }
    number++;
    }
} 
bool check (int p ,) 

int main ()
{
    cout <<trailing_zeros(2) << endl;
}