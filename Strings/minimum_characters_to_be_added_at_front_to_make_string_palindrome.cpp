/*
    Minimum characters to be added at front to make string palindrome
    Link: https://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------------

int minAddition(string s)
{
    int n = s.length();
    string temp = s;
    reverse(s.begin(), s.end());
    s = temp + "$" + s ;
    int m = s.length();
    int LPS[m] = {0};
    for(int i = 1; i < m; i ++)
    {
        int j = LPS[i - 1];
        while(j > 0 && s[i] != s[j])
        {
            j = LPS[j - 1];
        }
        if(s[i] == s[j])
        {
            j ++;
        }
        LPS[i] = j;
    }
    return n - LPS[m - 1];
}

//--------------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        string s = "AACECAAAA"; 
        cout << minAddition(s);  
        cout << endl ;
    }
    return 0 ;
}
