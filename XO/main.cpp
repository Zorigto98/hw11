#include <iostream>
#include "string"
#include "math.h"

using namespace std;

string input(int nameLine)
{
    string line;
    string validChar="XO.";
    bool valid;
    do{
        cout << "Input " << nameLine << " line." << endl;
        cin >> line;
        valid=true;
        for (int i=0; i<line.length(); i++)
        {
            int num;
            num=validChar.find(line[i]);
            if (num==-1) valid=false;
        }
        if (line.length()!=3 || !valid) cout << "Incorrect input. Try again." << endl;
    }
    while (line.length()!=3 || !valid);
    return line;
}

int count_Ch (char ch, string line1, string line2, string line3)
{
    int count=0;
    for (int i=0; i<line1.length(); i++)
    {
        if (line1[i]==ch) count++;
    }
    for (int i=0; i<line2.length(); i++)
    {
        if (line2[i]==ch) count++;
    }
    for (int i=0; i<line3.length(); i++)
    {
        if (line3[i]==ch) count++;
    }
    return count;
}

bool checkRow (string line1, string line2, string line3, char sym)
{
    if ((line1[0]==line1[1] && line1[1]==line1[2] && line1[0]==sym) ||
            (line2[0]==line2[1] && line2[1]==line2[2] && line2[0]==sym) ||
            (line3[0]==line3[1] && line3[1]==line3[2] && line3[0]==sym)) return true;
    else return false;
}

bool checkCol (string line1, string line2, string line3, char sym)
{
    for (int i=0; i<line1.length(); i++)
    {
        if (line1[i] == line2[i] && line2[i] == line3[i] && line1[i]==sym) return true;
    }
}

bool checkDiag (string line1, string line2, string line3, char sym)
{
    if ((line1[0]==line2[1] && line2[1]==line3[2] && line1[0]==sym) ||
            (line1[2]==line2[1] && line2[1]==line3[0] && line1[2]==sym)) return true;
    else return false;
}

bool who_won(string line1, string line2, string line3, char sym)
{
    return (checkRow(line1, line2, line3, sym) ||
            checkCol(line1, line2, line3, sym) ||
            checkDiag(line1, line2, line3, sym));
}

using namespace std;

int main() {
   string line1, line2, line3;
   line1=input(1);
   line2=input(2);
   line3=input(3);

   int countX=count_Ch('X', line1, line2, line3);
   int countO=count_Ch('O', line1, line2, line3);
   //int countPoint=count_Ch('.', line1, line2, line3);

    // Разница между кол-вом крестиков и ноликов
    if (abs(countO-countX)==1 || countO==countX)
    {
        bool winX=who_won(line1, line2, line3, 'X');
        bool winO=who_won(line1, line2, line3, 'O');

        if (winO && winX) cout << "Incorrect";
        else if (!winO && !winX || (countX==countO)) cout << "Nobody";
        else if (winX) cout << "Petya won";
        else if (winO) cout << "Vanya won";
    }
    else cout << "Incorrect";
}