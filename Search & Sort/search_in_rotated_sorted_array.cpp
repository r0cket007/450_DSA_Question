/*
    Search in Rotated Sorted Array
    Link: https://leetcode.com/problems/search-in-rotated-sorted-array/  
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//---------------------------------------------------------------------
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int l = 0 ;
        int r = n - 1 ;
        int pos = -1;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
            {
                pos = mid; 
                break;
            }
            else if(nums[l] <= nums[mid]) 
            {
                if(nums[l] <= target && nums[mid] >= target)
                {
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            else
            {
                if(nums[mid] <= target && nums[r] >= target)
                {
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
        }
        return pos;
    }
};
//---------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        Solution obj;
        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 0;
        cout << obj.search(nums, target);
        cout << endl ;
    }
    return 0 ;
}