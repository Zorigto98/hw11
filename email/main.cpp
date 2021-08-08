#include <iostream>

using namespace std;

bool valid_email_address (string email)
{
    string email_part1, email_part2;

    int num_dog=email.rfind('@'); // нахождение символа @

    int count_dog=0;
    for (int i=0; i<email.length(); i++) // разделение адреса на две части
    {
        if (email[i]=='@') count_dog++;
        if (i<num_dog) email_part1+=email[i];
        else if (i>num_dog) email_part2+=email[i];
    }
    if (count_dog!=1) return false; // проверка на количество символов @

    if (email_part1.length()<1 || email_part1.length()>64)return false; // проверка на кол-во символов

    if (email_part2.length()<1 || email_part2.length()>63) return false; // проверка на кол-во символов

    string valid_char_part1=".-!#$%&'*+-/=?^_`{|}~\\" // допустимые символы
                            "qwertyuiopasdfghjklzxcvbnm\\"
                            "QWERTYUIOPASDFGHJKLZXCVBNM\\"
                            "0123456789";
    string valid_char_part2=".-\\"                    // допустимые символы
                            "qwertyuiopasdfghjklzxcvbnm\\"
                            "QWERTYUIOPASDFGHJKLZXCVBNM\\"
                            "0123456789";

    for (int i=0; i<email_part1.length(); i++) // проверка на допустимые символы
    {
        int num_char;
        num_char=valid_char_part1.find(email_part1[i]);
        if (num_char<0) return false;
    }

    for (int i=0; i<email_part2.length(); i++) // проверка на допустимые символы
    {
        int num_char;
        num_char=valid_char_part2.find(email_part2[i]);
        if (num_char<0) return false;
    }

    if (email_part1[1]=='.' || email_part1[email_part1.length()]=='.') return false; // проверка на точки в начале и в конце

    for (int i=0; i<email.length()-1; i++) // проверка на две подряд идущие точки
    {
        if (email[i]=='.' && email[i+1]=='.') return false;
    }

    return true;
}

int main()
{
    string email_address;
    cout << "Input email address" << endl;
    cin >> email_address;

    if (valid_email_address(email_address)) cout << "Yes";
    else cout << "No";
}
