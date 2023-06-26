

#include <iostream>
#define Long Long ll;
using namespace std;
void rev()
{
    int num0, num1, num2;
    int rev_odd = 0;
    int cnt = 0;
    num0 = num2 = num1 = 79312;
    while (num0 != 0)
    {
        cnt++;
        num0 = num0 / 10;
    }
    int cnt1 = cnt;
    while (num1 != 0)
    {
        int digit = num1 / 10 * cnt1;
        cout << digit << endl;
        if (digit % 2 != 0)
        {
            rev_odd = (rev_odd * 10) + digit;
        }

        num1 = num1 / 10;
    }

    cout << "The rev_odd -> " << rev_odd << endl;
    cout << "cnt -> " << cnt;
}
int main()
{
    // cout << 1234 / 10;
    rev();
}

// # # Online Python compiler (interpreter) to run Python online.
// # # Write Python 3 code in this online editor and run it.
// # # print(int(1234/10))
// # num0=num1=num1=79312468
// # cnt = 0;
// # while(num0 != 0):

// #     cnt ++
// #     num0 /10;

// # while(num != 0):
// # {
// #     digit = int(num/(10*cnt));
// #     if(digit %2 != 0)
// #     {
// #         odd_rev = odd_rev*10 +digit;
// #     }
// #     num = int(num/10)
// #     cnt --;
// # }
// # ans = 0
// # while (num1 != 0):
// # {
// #   digit1 = num1/(cnt *10)
// #   if(digit % 2 !=0)
// #   {
// #       ans = ans*10+odd_rev/(cnt*10)
// #   }
// #   else
// #   {
// #       ans = ans +digit;
// #   }
// #   odd_rev= odd_rev/10;
// #   num1 = num1/10;
// #   cnt--;
// # }

// # print(ans);
// print(1%2)
