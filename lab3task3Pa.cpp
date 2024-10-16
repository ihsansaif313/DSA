/* Find the Minimum number of bracket reversals needed to make an expression balanced.
A balanced expression is an expression in which all opening brackets have respective
closing brackets. For example 2+ {3*(7-2)} is a balanced expression whereas 2+{3*(7-
2}is not a balanced expression. Write a program to ask user to enter an expression.
Expression must consists of only brackets {or}, but the expression may not be balanced.
Find minimum number of bracket reversals to make the expression balanced.
*/
#include<iostream>
using namespace std;

class balance
{
    string exp;
    char *arr;
    char *arr2;
    int size, size2;
    int top = -1, top2 = -1;

public:
    balance(string str, int s, int s2)
    {
        size = s;
        size2 = s2;
        exp = str;
        arr = new char[size];
        arr2 = new char[size2];
    }
    void pushandbalance()
    {
        for (int i = 0; i < exp.length(); i++)
        {
            if (exp[i] == '{')
            {
                top++;
                arr[top] = '{';
            }
            else if (exp[i] == '(')
            {
                top2++;
                arr2[top2] = '(';
            }
            else if (exp[i] == '}' && top >= 0)
            {
                top--;
            }
            else if (exp[i] == ')' && top2 >= 0)
            {
                top2--;
            }
        }
     cout<<"Total number of '{' missing is : "<< top+1<<endl;
     cout<<"Total number of '(' missing is : "<< top2+1<<endl;
    }

};

int main()
{

    string exp;
    cout << "Enter string";
    getline(cin, exp);
    int cb = 0, rb = 0;

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '{')
        {
            cb++;
        }
        else if (exp[i] == '(')
        {
            rb++;
        }
    }
    balance b(exp, cb, rb);
    b.pushandbalance();

    return 0;
}