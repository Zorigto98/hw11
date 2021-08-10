#include <iostream>
#include "string"

using namespace std;

int Convert_Str2Int (int start, int finish, string address)
{
    string add_pt;
    for (int i=start; i<finish; i++)
    {
        add_pt+=address[i];
    }
    if (add_pt[0]=='0' && add_pt.length()!=1) return -1;
    else return stoi(add_pt);
}

bool checkValue (int ip_pt)
{
    if (ip_pt<0 || ip_pt>255) return false;
    return true;
}

bool check_ip_address (string address)
{
    string valid_char="0123456789.";

    int count_point=0; // проверка на три точки и на допустимые значения
    for (int i=0; i<address.length(); i++)
    {
        if (address[i]=='.') count_point++;
        int num_char;
        num_char=valid_char.find(address[i]);
        if (num_char<0) return false;
    }
    if (count_point!=3) return false;

    for (int i=0; i<address.length()-1; i++)
    {
        if (address[i]=='.' && address[i+1]=='.') return false;
    }

    int ip_pt;
    int st_point=0;

    for (int i=1; i<=4; i++)
    {
        int fn_point=address.find('.', st_point);
        if (i==4) fn_point=address.length();
        ip_pt=Convert_Str2Int(st_point, fn_point, address);
        if (ip_pt<0 || ip_pt>255) return false;
        //checkValue(ip_pt) ;
        st_point=fn_point+1;
    }

    return true;
}

int main()
{
    string ip_address;
    cout << "Input ip-address" << endl;
    cin >> ip_address;

    int ip_pt;
    int st_point=0;

    for (int i=1; i<=4; i++)
    {
        int fn_point=ip_address.find('.', st_point);
        if (i==4) fn_point=ip_address.length();
        //cout << st_point << " " << fn_point << endl;
        ip_pt=Convert_Str2Int(st_point, fn_point, ip_address);
        checkValue(ip_pt);
        cout << checkValue(ip_pt) << endl;
        st_point=fn_point+1;
    }

    if (check_ip_address(ip_address)) cout << "Yes";
    else cout << "No";
}