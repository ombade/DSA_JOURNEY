//  Implement a problem of smallest number with at 
// least n trailing zeroes in factorial.
// Statement: Given a number n. The task is to find the 
// smallest number whose factorial contains at least n 
// trailing zeroes.
// Input : n = 1 Output : 5 
// Input : n = 6 Output : 25


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


int main ()
{
    cout <<trailing_zeros(2) << endl;
}