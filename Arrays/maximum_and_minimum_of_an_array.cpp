/*
	Kadane's Algorithm 

	Link: https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

	Q.	Given an array arr of N integers. Find the contiguous sub-array with maximum sum. 
	
	Expected Time Complexity: O(n)
	and minimum comparisions ; 
	
	-----------------------------------------------------
	Input:
	N = 5
	arr[] = {1,2,3,-2,5}
	
	Output:
	9
	
	Explanation:
	Max subarray sum is 9
	of elements (1, 2, 3, -2, 5) which 
	is a contiguous subarray.
	-----------------------------------------------------
	
	Expected Time Complexity: O(N)
	Expected Auxiliary Space: O(1)

	Medium
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
//---------------------------------------------------------------------------------

int maxSubarraySum(int arr[], int n)
{
    int max_till_now = arr[ 0 ] ;
    int max_till_idx = 0 ;
    for( int i = 0 ; i < n ; i ++ )
    {
        if( max_till_idx + arr[ i ] > 0 )
        {
            max_till_now = max( max_till_now , max_till_idx + arr[ i ] );
            max_till_idx += arr[ i ] ;
        }
        else 
        {
            max_till_idx = 0 ;
        }
    }
    return max_till_now ;
}

//------------------------------------------------------------------------------------
signed main( )
{
	#ifndef ONLINE_JUDGE
    r0cket007
    #endif
	int testcases = 1 ;
	// cin >> testcases ;
	while( testcases -- )
	{
		int n ;
		cin >> n ;
		int arr[ n ] ;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[ i ] ;
		}
		cout << maxSubarraySum( arr , n ) ;
	}
	return 0 ;
}