/*
	Three way partitioning

	Link: https://practice.geeksforgeeks.org/problems/three-way-partitioning/1#

	Q.	Given an array of size n and a range [a, b]. The task is to partition the array 
		around the range such that array is divided into three parts.
		1) All elements smaller than a come first.
		2) All elements in range a to b come next.
		3) All elements greater than b appear in the end.
		The individual elements of three sets can appear in any order.You are required to 
		return the modified array.

	-------------------------------------------
	Input: 
	n = 5
	A[] = {1, 2, 3, 3, 4}
	[a, b] = [1, 2]
	
	Output: 1
	
	Explanation: One possible arrangement is:
	{1, 2, 3, 3, 4}. If you return a valid
	arrangement, output will be 1.
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
void threeWayPartition(vector<int>& array,int a, int b)
{
    int left = 0 , right = array.size( ) - 1 ;
    int counter = 0 ;
    while( counter <= right )
    {
        if( array[ counter ] < a )
        {
            swap( array[ counter ] , array[ left ] ) ;
            left ++ ;
            counter ++ ;
        }
        else if( array[ counter ] > b )
        {
            swap( array[ counter ] , array[ right ] ) ;
            right -- ;
        }
        else 
            counter ++ ;
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
		std::vector<int> v( n );
		for (int i = 0; i < n; ++i)
		{
			cin >> v[ i ] ;
		}
		int a , b ;
		cin >> a >> b ;
		threeWayPartition( v , a , b ) ;
		for( auto i : v )
		{
			cout << i << " " ;
		}
		cout << endl ;
	}
	return 0 ;
}