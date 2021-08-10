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

int convert_Str2Int (string num)
{
    string num_pt;
    int start=0;
    int finish=num.find('.');
    for (int i=start; i<finish; i++)
    {
        num_pt+=num[i];
    }
    return stoi(num_pt);
}

int convert_Str2Int2 (string num)
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
    return stoi(num_pt);
}

void compare (string num1, string num2)
{
    int num1Int, num2Int;

    num1Int=convert_Str2Int(num1)+convert_Str2Int2(num1);
    num2Int=convert_Str2Int(num2)+convert_Str2Int2(num2);

    if (num1Int==num2Int) cout << "Equal";
    else num1Int<num2Int ? (cout << "Less") : (cout << "More");
}

int main() {
    string num1, num2;

    num1=input(1);
    num2=input(2);

    compare(num1, num2);
}
