#include "globals.h"
bool AdminLogin(Admin admins[], int adminscount)
{
    cout << "---System Login---\n";
    string username;
    string password;
    cout << "Enter your username:\n";
    cin >> username;
    cout << "Enter your password:\n";
    cin >> password;
    for (int i = 0; i < adminscount; i++)
    {
        if ((username == admins[i].UserName) && (password == admins[i].password))
        {
            return true;
        }
    }
      return false;
}
