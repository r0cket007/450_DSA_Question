/*
    Stickler Thief
    Link: https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1#
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------
class Solution
{
public:
    int FindMaxSum(int arr[], int n)
    {
        if (n == 1)
            return arr[0];
        if (n == 2)
        {
            return max(arr[0], arr[1]);
        }
        int dp[n] = {arr[0], max(arr[1], arr[0])};
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
        }
        return dp[n - 1];
    }
};
//--------------------------------------------------------------------
signed main()
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        int n = 6 ;
        int a[] = {5, 5, 10, 100, 10, 5};
        Solution obj;
        cout << obj.FindMaxSum(a, n);
        cout << endl;
    }
    return 0 ;
}