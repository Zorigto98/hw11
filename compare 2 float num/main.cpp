#include <iostream>
#include "string"

using namespace std;

string checkZero (string num)
{
    if (num[0]=='.')
    {
        string str0="0";
        num.insert(0,str0);
    }
    if (num[0]=='-' && num[1]=='.')
    {
        string str0="0";
        num.insert(1,str0);
    }
    if (num.find('.')==-1)
    {
        string str0=".0";
        num.append(str0);
    }
    return num;
}

bool checkNum (string num) // проверка на корректность ввода
{
    int countMinus=0, countPoint=0, countNum=0;
    bool checkNumber=true;
    for (int i=0; i<num.length(); i++)
    {
        if ((num[i]>='0' && num[i]<='9') || num[i]=='.' || num[i]=='-')
        {
            if (num[i]>='0' && num[i]<='9') countNum++;
            if (num[i]=='.') countPoint++;
            if (num[i]=='-') countMinus++;
        }
        else checkNumber=false;
    }
    if (countNum!=0 && countMinus<2 && countPoint<2 && checkNumber) return true;
    else return false;
}
string input (int name)
{
    string num;
    do {
        cout << "Input number " << name << endl;
        cin >> num;
        num=checkZero(num);
        if (!checkNum(num)) cout << "Number" << name << " entered incorrectly. Try again." << endl;
    }
    while(!checkNum(num));
    return num;
}

string split (string num)
{
    bool checkEndZero=false;
    while (!checkEndZero)
    {
        if (num[0]=='0' && num[1]!='.')
        {
            num.erase(0, 1);
        }
        else checkEndZero=true;
    }
    string num_pt;
    int start=0;
    int finish=num.find('.');
    for (int i=start; i<finish; i++)
    {
        num_pt+=num[i];
    }
    return num_pt;
}

string split2 (string num)
{
    while (num[num.length()-1]=='0')
    {
        num.pop_back();
    }

    int start=num.find('.')+1;
    int finish=num.length();
    string num_pt;
    for (int i=start; i<finish; i++)
    {
        num_pt+=num[i];
    }
    return num_pt;
}

void compare (string num1, string num2)
{
    bool checkEqual=true;
    if (num1[0]=='-' && num2[0]!='-')
    {
        cout << "Less";
        checkEqual=false;
    }
    if (num1[0]!='-' && num2[0]=='-')
    {
        cout << "More";
        checkEqual=false;
    }

    bool checkMinus=false;
    if (num1[0]=='-' && num2[0]=='-')
    {
        num1.erase(0,1);
        num2.erase(0,1);
        checkMinus=true;
    }

    string num1p1, num2p1;

    num1p1=split(num1);
    num2p1=split(num2);

    if (num1p1.length()!=num2p1.length())
    {
        if (num1p1.length()<num2p1.length())
        {
            checkMinus ? cout << "More" : cout << "Less";
        }
        else
        {
            checkMinus ? cout << "Less" : cout << "More";
        }
        checkEqual=false;
    }
    else
    {
        for (int i=0; i<num1p1.length(); i++)
        {
            if (num1p1[i]!=num2p1[i])
            {
                if (num1p1[i]<num2p1[i])
                {
                    checkMinus ? cout << "More" : cout << "Less";
                    checkEqual=false;
                }
                else
                {
                    checkMinus ? cout << "Less" : cout << "More";
                    checkEqual=false;
                }
                break;
            }
        }
    }

    if (checkEqual)  // проверка дробной части числа
    {
        string num1p2, num2p2;

        num1p2=split2(num1);
        num2p2=split2(num2);

        if (num1p2.length()!=num2p2.length())
        {
            if (num1p2.length()<num2p2.length())
            {
                checkMinus ? cout << "Less" : cout << "More";
                checkEqual=false;
            }
            else
            {
                checkMinus ? cout << "More" : cout << "Less";
                checkEqual=false;
            }
        }
        else
        {
            for (int i=0; i<num1p2.length(); i++)
            {
                if (num1p2[i]!=num2p2[i])
                {
                    if (num1p2[i]<num2p2[i])
                    {
                        checkMinus ? cout << "More" : cout << "Less";
                        checkEqual=false;
                    }
                    else
                    {
                        checkMinus ? cout << "Less" : cout << "More";
                        checkEqual=false;
                    }

                    break;
                }
            }
        }
    }
    if (checkEqual) cout << "Equal";
}

int main() {
    string num1, num2;

    num1=input(1);
    num2=input(2);

    compare(num1, num2);
}
