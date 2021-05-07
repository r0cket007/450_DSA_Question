/*
    Count of number of given string in 2D character array
    Link: https://www.geeksforgeeks.org/find-count-number-given-string-present-2d-character-array/

*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;

//-----------------------------------------------------------------------------------------
bool check(int row, int col, int n, int m, string arr[], string txt, int pos)
{
    return ( n > row && m > col && row >= 0 && col >= 0 && arr[row][col] == txt[pos] );
}
int bruteforce(string txt, int pos, string arr[], int row, int col, int n, int m)
{
    int ans = 0;
    if( pos == txt.length())
    {
        return 1;
    }
    char ch = arr[row][col];
    arr[row][col] = 0 ;
    if( check( row + 1, col, n, m, arr, txt, pos) )
    {
        ans += bruteforce(txt, pos + 1, arr, row + 1, col, n, m);
    }
    if( check( row - 1, col, n, m, arr, txt, pos ) )
    {
        ans += bruteforce( txt, pos + 1, arr, row - 1, col, n, m);
    }
    if( check( row , col + 1, n, m, arr, txt, pos) )
    {
        ans += bruteforce( txt, pos + 1, arr, row, col + 1, n, m);
    }
    if( check( row, col - 1, n, m, arr, txt, pos) )
    {
        ans += bruteforce( txt, pos + 1, arr, row , col - 1, n, m);
    }
    arr[row][col]= ch;
    return ans;
}
int searchString(string txt, string arr[], int n, int m)
{
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j ++)
        {
            ans += bruteforce(txt, 0, arr, i, j, n, m);
        }
    }
    return ans;
}
//---------------------------------------------------------------------------------------

signed main()
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
    
        string needle = "MAGIC";
        string input[] = { "BBABBM",
                           "CBMBBA",
                           "IBABBG",
                           "GOZBBI",
                           "ABBBBC",
                           "MCIGAM" };
        int n = (sizeof(input) / sizeof(*input));
        int m = input[0].length();
        cout << searchString( needle, input, n, m);
        cout << endl ;
    }
    return 0 ;
}
