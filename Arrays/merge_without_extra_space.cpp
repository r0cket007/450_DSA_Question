/*
	Merge Without Extra Space

	Link: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

	Q.	Given two sorted arrays arr1[] of size N and arr2[] of size M. 
		Each array is sorted in non-decreasing order.Merge the two arrays into 
		one sorted array in non-decreasing order without using any extra space.
	
	-----------------------------------------------------
	Input:
	N = 4, M = 5
	arr1[] = {1, 3, 5, 7}
	arr2[] = {0, 2, 6, 8, 9}
	
	Output:
	0 1 2 3 5 6 7 8 9
	-----------------------------------------------------
	
	Expected Time Complexity: O((n+m)*log(n+m))
	Expected Auxiliary Space: O(1)

	Hard
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
//---------------------------------------------------------------------------------

void merge(int arr1[], int arr2[], int n, int m) 
{
    int l = n - 1 ;
    int r = 0 ;
    // shift all greater element of 1st to 2nd array
    while( l >= 0 && r < m )
    {
        if( arr1[ l ] > arr2[ r ] )
        {
            swap( arr1[ l ] , arr2[ r ] ) ;
            l -- ;
            r ++ ;
        }
        else
        {
            // if no such element found that means all element in arr1 are smaller than arr2
            break ;
        }
    }
    // sort both arr individually 
    sort( arr1 , arr1 + n ) ;
    sort( arr2 , arr2 + m ) ;
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
		int n , m ;
		cin >> n >> m ;
		int arr1[ n ] , arr2[ m ];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr1[ i ] ;
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> arr2[ i ] ;
		}
		merge( arr1 , arr2 , n , m ) ;
	}
	return 0 ;
}