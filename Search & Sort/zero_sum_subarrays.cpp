/*
    Zero Sum Subarrays
    Link: https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1#
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------
class Solution
{
public:
    int findSubarray(vector<int> arr, int n)
    {
        map<int, int> mp;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {

            sum += arr[i];
            if (sum == 0)
            {
                ans++;
            }
            ans += mp[sum];
            mp[sum]++;
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
        int n = 10;
        vector<int>arr = {6, -1, -3, 4, -2, 2, 4, 6, -12, -7};
        cout << obj.findSubarray(arr, n);
        cout << endl;
    }
    return 0 ;
}