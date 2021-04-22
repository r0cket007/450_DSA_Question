/*
	Minimum swaps and K together

	Link: https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1#

	Q.	Given an array of n positive integers and a number k.Find the minimum number
		of swaps required to bring all the numbers less than or equal to k together.

	-------------------------------------------
	Input : 
	arr[ ] = {2, 1, 5, 6, 3} 
	K = 3
	
	Output : 
	1
	-------------------------------------------
	Input : 
	arr[ ] = {2, 7, 9, 5, 8, 7, 4} 
	K = 6 
	
	Output : 
	2
	------------------------------------------- 
	
	Expected Time Complexity: O(N)
	Expected Auxiliary Space: O(1)

	Sliding Window Problem
	Medium
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
//---------------------------------------------------------------------------------
int minSwap(int *arr, int n, int k) 
{
    int count = 0 ;
    int i = 0 ;
    while( i < n )
    {
        if( arr[ i ] <= k )
        {
            count ++ ;
        }
        i ++ ;
    }
    int answer = INT_MAX ;
    int temp_count = 0 ;
    for( int it = 0 ; it < count ; it ++ )
    {
    	if( arr[ it ] <= k )
    	{
    		temp_count ++ ;
    	}
    }
    answer = count - temp_count ;
    for( int it = count ; it < n ; it ++ )
    {
    	if( arr[ it - count ] <= k )
    	{
    		temp_count -- ;
    	}
    	if( arr[ it ] <= k )
    	{
    		temp_count ++ ;
    	}
    	answer = min( answer , count - temp_count ) ;
    }
    return answer ;
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
		int v[ n ];
		for (int i = 0; i < n; ++i)
		{
			cin >> v[ i ] ;
		}
		int k ;
		cin >> k ;
		cout << minSwap( v , n , k ) ;
		cout << endl ;
	}
	return 0 ;
}