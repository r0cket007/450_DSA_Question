/*
    Minimum Swaps to Sort
    Link: https://practice.geeksforgeeks.org/problems/minimum-swaps/1
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------
class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int ans = 0, n = nums.size();
        vector<int> v = nums;
        unordered_map<int, int> mp;
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            mp[v[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            while(mp[nums[i]] != i)
            {
                swap(nums[i], nums[mp[nums[i]]]);
                ans++;
            }
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
        vector<int> nums = {1, 2, 3, 4};
        Solution obj;
        cout << obj.minSwaps(nums);
        cout << endl;
    }
    return 0 ;
}