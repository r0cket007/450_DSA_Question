/*
    Product array puzzle
    Link: https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1#
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------
class Solution
{
public:
    vector<long long> productExceptSelf(vector<long long> &nums, int n)
    {
        long long prod = 1;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                count++;
            prod *= max(1LL, nums[i]);
        }
        vector<long long> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (count)
            {
                if (nums[i] == 0 && count == 1)
                {
                    ans[i] = prod;
                }
            }
            else
                ans[i] = prod / nums[i];
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
        int n = 5 ;
        vector<int> nums = {10, 3, 5, 6, 2};
        Solution obj;
        vector<int> ans = obj.productExceptSelf(nums, n);
        for(auto i : ans)
            cout << i << " ";
        cout << endl;
    }
    return 0 ;
}