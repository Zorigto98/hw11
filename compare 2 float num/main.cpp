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

int convert_Str2Int (int start, int finish, string num)
{
    string num_pt;
    {
        for (int i=start; i<finish; i++)
        {
            num_pt+=num[i];
        }
        return stoi(num_pt);
    }
}

void compare (string num1, string num2)
{
    int num1_pt1, num1_pt2, num2_pt1, num2_pt2;

    if (num1.find('.')>0)
    {
        num1_pt1=convert_Str2Int(0, num1.find('.'), num1);
        num1_pt2=convert_Str2Int(num1.find('.')+1, num1.length(), num1);

        num2_pt1=convert_Str2Int(0, num2.find('.'), num2);
        num2_pt2=convert_Str2Int(num2.find('.')+1, num2.length(), num2);
    }
    else if (num2.find('.')>0)
    {
        num2_pt1=convert_Str2Int(0, num2.find('.'), num2);
        num2_pt2=convert_Str2Int(num2.find('.')+1, num2.length(), num2);
    }
    else if (num1.find('.')<0 && num2.find('.')<0)
    {
        num1_pt1=stoi(num1);
        num1_pt2=0;
        num2_pt1=stoi(num2);
        num2_pt2=0;
    }

    if (num1_pt1==num2_pt1 && num1_pt2==num2_pt2) cout << "Equal";

    else if (num1_pt1!=num2_pt1)
    {
        if (num1_pt1>num2_pt1) cout << "More";
        else cout << "Less";
    }
    else
    {
        if (num1_pt1>num2_pt1) cout << "More";
        else cout << "Less";
    }
}

int main() {
    string num1, num2;

    num1=input(1);
    num2=input(2);

    compare(num1, num2);
}
