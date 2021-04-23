/*
	Sort an array of 0s, 1s and 2s

	Link: https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#

	Q.	Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

	-------------------------------------------
	Input: 
	N = 5
	arr[]= {0 2 1 2 0}
	
	Output:
	0 0 1 2 2
	-------------------------------------------

	Expected Time Complexity: O(n)
	Expected Auxiliary Space: O(1)

	Dutch National Flag Problem
	Medium
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
//---------------------------------------------------------------------------------
void sort012(int arr[], int n)
{
    int left = 0 , right = n - 1 ;
    int mid = 0 ;
    while( mid <= right )
    {
        if( arr[ mid ] == 0 )
        {
            swap( arr[ mid ] , arr[ left ] ) ;
            mid ++ ;
            left ++ ;
        }
        else if( arr[ mid ] == 2 )
        {
            swap( arr[ mid ] , arr[ right ] ) ;
            right -- ;
        }
        else
        {
            mid ++ ;
        }
    }
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
			cin >> v[ i ] ;
		}
		sort012( v , n );
		for( auto i : v )
		{
			cout << i << " " ;
		}
		cout << endl ;
	}
	return 0 ;
}