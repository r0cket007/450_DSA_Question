/*
    Min Number of Flips
    Link: https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1#

    Expected Time Complexity: O(|S|).
    Expected Auxiliary Space: O(1).

    Constraints:
    1<=|S|<=105
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//-----------------------------------------------------------------------------------
int minFlips (string S)
{
    int ans1 = 0, ans2 = 0;
    int flip = 0;
    int n = S.length();
    for(int i = 0; i < n; i ++)
    {
        if(S[i] != flip + 48)
        {
            ans1 ++;
        }
        flip ^= 1;
    }
    flip = 1;
    for(int i = 0; i < n; i ++)
    {
        if(S[i] != flip + 48)
        {
            ans2 ++;
        }
        flip ^= 1;
    }
    return min(ans2, ans1);
}
//-----------------------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        string s = "0001010111";
        cout << minFlips(s);
        cout << endl ;
    }
    return 0 ;
}
