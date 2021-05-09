/*
    Minimum Swaps for Bracket Balancing
    Link: https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1#
    
    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(1)

    Constraints:
    1<=|S|<=100000
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//-----------------------------------------------------------------------
int minimumNumberOfSwaps(string S)
{
    int n = S.length();
    int counter = 0 ;
    int ans = 0;
    int close = 0 ;
    for(int i = 0; i < n; i++)
    {
        if( S[i] == '[' )
        {
            counter ++ ;
            ans += close ;
            close = max(close - 1, 0LL);
        }
        else
        {
            if( counter <= 0 )
            {
                close ++ ;
            }
            counter --;  
        }
    }
    return ans;
}
//----------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        string s = "]]][][[[";
        //answer is 9
        cout << minimumNumberOfSwaps(s);
        cout << endl ;
    }
    return 0 ;
}