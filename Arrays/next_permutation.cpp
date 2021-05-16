/*
	Count Inversions

	Link: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
	
	Q.	Given an array of integers. Find the Inversion Count in the array. 

		Inversion Count: For an array, inversion count indicates how far (or close) the array
		is from being sorted. If array is already sorted then the inversion count is 0. 
		If an array is sorted in the reverse order then the inversion count is the maximum. 
		
		Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
	
	-----------------------------------------------------
	Input: N = 5, arr[] = {2, 4, 1, 3, 5}
	
	Output:
	3
	
	Explanation: The sequence 2, 4, 1, 3, 5 
	has three inversions (2, 1), (4, 1), (4, 3).
	-----------------------------------------------------
	
	Input: N = 5
	arr[] = {2, 3, 4, 5, 6}
	Output: 0

	-----------------------------------------------------
	
	Expected Time Complexity: O(NLogN).
	Expected Auxiliary Space: O(N).

	Medium
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
//---------------------------------------------------------------------------------------
long long merge( long long arr[] , int l , int mid , int r )
{
    long long temp[ r - l + 1 ] ;
    int i = l ; 
    int j = mid + 1 ;
    int counter = 0 ;
    long long ans = 0 ;
    while( i <= mid && j <= r )
    {
        if( arr[ i ] <= arr[ j ] )
        {
            temp[ counter ] = arr[ i ++ ];
        }
        else
        {
            temp[ counter ] = arr[ j ++ ] ;
            ans += ( ( mid + 1 ) - i )   ;
        }
        counter ++ ;
    }
    while( i <= mid )
    {
        temp[ counter ++ ] = arr[ i ++ ] ;
    }
    while( j <= r )
    {
        temp[ counter ++ ] = arr[ j ++ ] ;
    }
    for( int k = 0 ; k < counter ; k ++ )
    {
    	arr[ k + l ] = temp[ k ] ;
    }
    return ans ;
}

//--------------------------------------------------------------------------------------
long long mergesort( long long arr[ ] , int l , int r )
{
    if( l >= r )
        return 0 ;
    int mid = l + ( r - l ) / 2 ;
    long long res = 0 ;
    res += mergesort( arr , l , mid ) ;
    res += mergesort( arr , mid + 1 , r ) ;
    res += merge( arr , l , mid , r ) ;
    return res ;
}

//----------------------------------------------------------------------------------------
long long inversionCount(long long arr[], long long N)
{
   return mergesort( arr , 0 , N - 1 ) ;
}
//-----------------------------------------------------------------------------------------
signed main( )
{
	#ifndef ONLINE_JUDGE
    r0cket007
    #endif
	int testcases = 1 ;
	// cin >> testcases ;
	while( testcases -- )
	{
		long long n ;
		cin >> n ;
		long long arr[ n ] ;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[ i ] ;
		}
		inversionCount( arr , n ) ;
		cout << endl ;
	}
	return 0 ;
}