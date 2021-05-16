/*
	Kth smallest element

	Link: https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

	Q.	Given an array arr[] and a number K where K is smaller than size of array, the task
		is to find the Kth smallest element in the given array. It is given that all array 
		elements are distinct.

	-------------------------------------------
	Input:
	N = 6
	arr[] = 7 10 4 3 20 15
	K = 3
	
	Output :
	7
	-------------------------------------------

	Expected Time Complexity: O(nlogn)
	Expected Auxiliary Space: O(1)
	

	Solution
    method 1 : is brute force get smallest everytime O( N * N )
    method 2 : is using hash function or STL O( N )
    method 3 : randomize quicksort O( N ) and O( N*N ) worst case 
    method 4 : sorting O( NlogN ) 

	Medium
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
//---------------------------------------------------------------------------------

int kthSmallest(int arr[], int l, int r, int k) 
{
    
 sort( arr + l , arr + r + 1 ) ;
 return arr[ k - 1 ] ;
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
		cout << kthSmallest( v , 0 ,  n - 1 , k  ) ;
		cout << endl ;
	}
	return 0 ;
}