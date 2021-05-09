/*
    Recursively print all sentences that can be formed from list of word lists
    Link: https://www.geeksforgeeks.org/recursively-print-all-sentences-that-can-be-formed-from-list-of-word-lists/

*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
#define R 3
#define C 3
//----------------------------------------------------------------------------------
void solve(string str[R][C], int m, int n, string arr[R])
{
    arr[m] = str[m][n];
    if (m==R-1)
    {
        for (int i=0; i<R; i++)
           cout << arr[i] << " ";
        cout << endl;
        return;
    }
    for (int i=0; i<C; i++)
       if (str[m+1][i] != "")
          solve(str, m+1, i, arr);
}
void print(string str[R][C])
{
   string arr[R];
   for (int i = 0; i < C; i++)
     if(str[0][i] != "")
        solve(str, 0, i, arr);
}
//----------------------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    cin >> testcases ;
    while( testcases -- )
    {
        string str[R][C]  = {{"you", "we"},
                            {"have", "are"},
                            {"sleep", "eat", "drink"}};
        print(str);
        cout << endl ;
    }
    return 0 ;
}