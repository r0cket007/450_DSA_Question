/*
    Function to fpos Number of customers who could not get a computer
    Link: https://www.geeksforgeeks.org/function-to-fpos-number-of-customers-who-could-not-get-a-computer
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------------------
int runCustomerSimulation(int n, const char *str)
{
    char hash[256] = {0};
    int res = 0;
    int counter = 0;
    for (int i=0; str[i]; i++)
    {
        int pos = str[i] - 'A';
        if (hash[pos] == 0)
        {
            hash[pos] = 1;
            if (counter < n)
            {
                counter++;
                hash[pos] = 2;
            }
            else
                res++;
        }
        else
        {
           if (hash[pos] == 2)
               counter--;
           hash[pos] = 0;
        }
    }
    return res;
}
//--------------------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    cin >> testcases ;
    while( testcases -- )
    {
        cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl;
        cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl;
        cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl;
        cout << runCustomerSimulation(1, "ABCBCA") << endl;
        cout << runCustomerSimulation(1, "ABCBCADEED") << endl;
        cout << endl ;
    }
    return 0 ;
}
