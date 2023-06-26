#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string name[100];
    string number[100];
    ofstream obj("phone.txt", ios::app);
    int ch = 0;
    while (ch != 4)
    {
        cout << "\n---------------------------------------\nMENU \n1)ADD THE PHONE NUMBER \n2)DISPLAY THE PHONE NUMBER \n3)SEARCH THE PHONE NUMBER \n4)EXIT\n-----------------------------------------------\n. " << endl;
        cin >> ch;
        if (ch == 1)
        {
            int num = 0;
            cout << "-----------------------HOW MANY CONTACT TO BE ADDED------------------- " << endl;
            cin >> num;
            for (int i = 0; i < num; i++)
            {
                cout << "ENTER THE NAME -> ";
                cin >> name[i];
                obj << name[i] << "\t\t";
                cout << "ENTER THE NUMBER -> ";
                cin >> number[i];
                obj << number[i] << endl;
            }
            cout << "\n----------------------CONTACT ADDED ----------------------------\n";
        }
        if (ch == 2)
        {
            char arr1[100];
            string myText;
            ifstream obj1("phone.txt");
            while (getline(obj1, myText))
            {
                cout << myText << endl;
            }
            cout << "-------------------------------------END--------------------------------------\n\n";
        }
        if (ch == 3)
        {
            char f;
            cout << "Enter the fist letter -> ";
            cin >> f;
            // char arr1[100];
            string myText;
            ifstream obj1("phone.txt");
            while (getline(obj1, myText))
            {
                if (myText[0] == f)
                    cout << myText << endl;
            }
        }
    }
    return 0;
}
//}