#include <iostream>
#include <string.h>

using namespace std;

char encoder (char ch, char startCh, char finalCh, int shift)
{
    if (ch+shift>finalCh)
    {
        ch=startCh+(ch+shift-finalCh-1);
    }
    else if (ch+shift<startCh)
    {
        ch=finalCh-(startCh-(ch+shift)-1);
    }
    else
    {
        ch+=shift;
    }
}

string encrypt_caesar(string str, int shift)
{
    for (int i=0; i<str.length(); i++)
    {
        if (str[i]>='a' && str[i]<='z')
        {
            str[i]=encoder(str[i], 'a', 'z', shift);
        }
        if (str[i]>='A' && str[i]<='Z')
        {
            str[i]=encoder(str[i], 'A', 'Z', shift);
        }
    }
    return str;
}

string decrypt_caesar(string str, int shift)
{
    return encrypt_caesar(str, -shift);
}



int main()
{
    string str, newStr;
    cout << "Input string ";
    cin >> str;
    //str="The quick brown fox jumps over the lazy dog";

    int shift=0;
    cout << "Input num ";
    cin >> shift;

    newStr=encrypt_caesar(str, shift);

    cout << newStr << endl;

    cout << decrypt_caesar(newStr, shift);


}

