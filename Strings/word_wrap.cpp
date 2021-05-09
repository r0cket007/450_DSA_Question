/*
    Word Wrap 
    LINK : https://practice.geeksforgeeks.org/problems/word-wrap1646/1#
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
const int MAX = 500; 
int editDistance(string s, string t) 
{
    int n = s.length();
    int m = t.length();
    int dp[n + 1][m + 1];
    for(int i = 0; i <= n; i++)
    {
        for(int j =0; j <= m; j++)
        {
            if(i == 0)
            {
                dp[i][j] = j;
            }
            else if(j == 0)
            {
                dp[i][j] = i;
            }
            else dp[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if( s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
    }
    return dp[n][m];
}
//-------------------------------------------------------------------------------------
signed main( )
{
    #ifndef ONLINE_JUDGE
    r0cket007
    #endif
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        string s = "geek";
        string t = "gesek";
        cout << editDistance(s, t);
    }
    return 0 ;
}