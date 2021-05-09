/*
	Chocolate Distribution Problem
	
	Link: https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1#

	Q.Given an array A[ ] of positive integers of size N, where each 
	value represents the number of chocolates in a packet.Each packet
	can have a variable number of chocolates.There are M students, the
	task is to distribute chocolate packets among M students such that :
	1. Each student gets exactly one packet.
	2. The difference between maximum number of chocolates given to 
	a student and minimum number of chocolates given to a student is minimum.

	------------------------------------------
	Input:
	N = 8, M = 5
	A = {3, 4, 1, 9, 56, 7, 9, 12}
	
	Output: 6
	
	Explanation: The minimum difference between 
	maximum chocolates and minimum chocolates 
	is 9 - 3 = 6 by choosing following M packets :
	{3, 4, 9, 7, 9}.
	------------------------------------------------
	Expected Time Complexity: O(N*Log(N))
	Expected Auxiliary Space: O(1)

	Easy Tag
*/

#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;



//-------------------------------------------------------------------------
long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort( a.begin( ) , a.end( ) ) ;
    long long diff = INT_MAX ;
    long long left = 0 ;
    long long right = m - 1 ;
    while( right < n )
    {
        diff = min( diff , a[ right ] - a[ left ] ) ;
        left ++ , right ++ ;
    }
    return diff ;
} 
//--------------------------------------------------------------------------
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
		cin >> n ;
		std::vector<int> v( n ) ;
		for (int i = 0; i < n; ++i)
		{
			cin >> v[ i ] ;
		}
		cin >> m ;
		cout << findMinDiff( v , n , m ) ;
		cout << endl ;
	}
	return 0 ;
}