/*
    Smallest factorial number
    Link: https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1#
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------
class Solution
{
public:
    int trail_(int x)
    {
        int ans = 0;
        while (x)
        {
            ans += x / 5;
            x = x / 5;
        }
        return ans;
    }
    int findNum(int n)
    {
        int l = 0, r = 5e4, mid, ans = INT_MAX;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (trail_(mid) >= n)
            {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};
//--------------------------------------------------------------------
signed main()
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        Solution obj;
        int n = 6;
        cout << obj.findNum(n);
        cout << endl ;
    }
    return 0 ;
}