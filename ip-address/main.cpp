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

bool check_ip_address (string address)
{
    int ip_pt1, ip_pt2, ip_pt3, ip_pt4;
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

    //разделение на 4 части ip адреса
    int st_point=0;
    int fn_point=address.find('.');
    ip_pt1=Convert_Str2Int(st_point, fn_point, address);

    st_point=fn_point+1;
    fn_point=address.find('.', st_point);
    ip_pt2=Convert_Str2Int(st_point, fn_point, address);

    st_point=fn_point+1;
    fn_point=address.find('.', st_point);
    ip_pt3=Convert_Str2Int(st_point, fn_point, address);

    st_point=fn_point+1;
    fn_point=address.length();
    ip_pt4=Convert_Str2Int(st_point, fn_point, address);

    // проверка на значение
    if (ip_pt1<0 || ip_pt1>255 ||
        ip_pt2<0 || ip_pt2>255 ||
        ip_pt3<0 || ip_pt3>255 ||
        ip_pt4<0 || ip_pt4>255) return false;

    return true;
}

int main()
{
    string ip_address;
    cout << "Input ip-address" << endl;
    cin >> ip_address;

    if (check_ip_address(ip_address)) cout << "Yes";
    else cout << "No";
}