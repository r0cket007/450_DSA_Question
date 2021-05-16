/*
    Majority Element II
    Link: https://leetcode.com/problems/majority-element-ii/ 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//----------------------------------------------------------------------
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {   
        int n = nums.size( ) ;
        int number1 = 0 , number2 = 1 , ct1 = 0 , ct2 = 0 ;
        for( int i = 0 ; i < n ; i ++ )
        {
            if( number1 == nums[ i ] )
            {
                ct1 ++ ;
            }
            else if( number2 == nums[ i ] )
            {
                ct2 ++ ;
            }
            else if( ct1 == 0 )
            {
                number1 = nums[ i ] ;
                ct1 ++ ;
            }
            else if( ct2 == 0 )
            {
                number2 = nums[ i ] ;
                ct2 ++ ;
            }
            else if( ct1 > 0 )
            {
                ct1 -- ;
                ct2 -- ;
            }
        }
        ct1 = ct2 = 0 ;
        for( auto i : nums )
        {
            if( number1 == i )
            {
                ct1 ++ ;
            }
            else if( number2 == i )
            {
                ct2 ++ ;
            }   
        }
        if( ct1 > n / 3 && ct2 > n / 3 )
        {
            return { number1 , number2 } ;
        }
        if( ct1 > n / 3 )
        {
            return { number1 } ;
        }
        if( ct2 > n / 3 )
        {
            return { number2 } ;
        }
        return { } ;
    }
};
//----------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        vector<int> nums = {3, 2, 3};
        Solution obj;
        vector<int> ans = obj.majorityElement(nums);
        for(auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl ;
    }
    return 0 ;
}