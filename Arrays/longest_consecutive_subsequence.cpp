/*
	Longest consecutive subsequence

	Link: https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1

	Q.	Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is 
		to check whether a2[] is a subset of a1[] or not.Both the arrays can be 
		sorted or unsorted. It may be assumed that elements in both array are distinct.

	-----------------------------------------------------
	Input:
	a1[] = {11, 1, 13, 21, 3, 7}
	a2[] = {11, 3, 7, 1}
	
	Output:
	Yes

	Explanation:
	a2[] is a subset of a1[]
	-----------------------------------------------------
	Input:
	a1[] = {10, 5, 2, 23, 19}
	a2[] = {19, 5, 3}
	
	Output:
	No
	
	Explanation:
	a2[] is not a subset of a1[]
	-----------------------------------------------------
	
	Expected Time Complexity : O(N)
	Expected Auxilliary Space : O(N)

*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
//---------------------------------------------------------------------------------------
string isSubset(int a1[], int a2[], int n, int m) 
{
    int hash[ 100001 ] = { 0 } ;
    for( int i = 0 ; i < n ; i ++ )
    {
        hash[ a1[ i ] ] ++ ;
    }
    for( int i = 0 ; i < m ; i ++ )
    {
        if( hash[ a2[ i ] ] == 0 )
            return "No" ;
        hash[ a2[ i ] ] -- ;
    }
    return "Yes";
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
		int n , m ;
		cin >> n >> m ;
		int a1[ n ], a2[ m ] ;
		for (int i = 0; i < n; ++i)
		{
			cin >> a1[ i ] ;
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> a2[ i ] ;
		}
		cout << isSubset( a1 , a2 , n , m ) ;
		cout << endl ;
	}
	return 0 ;
}