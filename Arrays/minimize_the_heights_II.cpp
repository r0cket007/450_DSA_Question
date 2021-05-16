/*
	Minimize the Heights II 

	Link: https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1

	Q.	Given an array arr[] denoting heights of N towers and a positive integer K, 
		you have to modify the height of each tower either by increasing or decreasing 
		them by K only once. After modifying, height should be a non-negative integer. 
		Find out what could be the possible minimum difference of the height of 
		shortest and longest towers after you have modified each tower.
	
	-----------------------------------------------------
	Input:
	K = 2, N = 4
	Arr[] = {1, 5, 8, 10}
	
	Output:
	5
	
	Explanation:
	The array can be modified as 
	{3, 3, 6, 8}. The difference between 
	the largest and the smallest is 8-3 = 5.
	-----------------------------------------------------

	Expected Time Complexity: O(N*logN)
	Expected Auxiliary Space: O(N)

	Medium
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
//---------------------------------------------------------------------------------

int getMinDiff(int arr[], int n, int k) 
{
    sort( arr , arr + n ) ;
    int mx = arr[ n - 1 ] ;
    int mn = arr[ 0 ] ;
    int result = arr[ n - 1 ] - arr[ 0 ] ;
    for( int i = 1 ; i < n ; i ++ )
    {
        if( arr[ i ] >= k )
        {
            mx = max( arr[ n - 1 ] - k , arr[ i - 1 ] + k ) ;
            mn = min( arr[ 0 ] + k , arr[ i ] - k ) ;
        }
        result = min( result , mx - mn ) ;
    }
    return result ;
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