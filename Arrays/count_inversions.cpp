/*
	Count pairs with given sum

	Link: https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1
	
	Q.	Given an array of N integers, and an integer K,
		find the number of pairs of elements in the array whose sum is equal to K.

	
	-----------------------------------------------------
	Input:
	N = 4, K = 6
	arr[] = {1, 5, 7, 1}
	
	Output: 
	2
	
	Explanation: 
	arr[0] + arr[1] = 1 + 5 = 6 
	and arr[1] + arr[3] = 5 + 1 = 6.
	-----------------------------------------------------
	
	Input:
	N = 4, X = 2
	arr[] = {1, 1, 1, 1}
	
	Output: 
	6
	
	Explanation: 
	Each 1 will produce sum 2 with any 1.
	-----------------------------------------------------
	
	Expected Time Complexity: O(N)
	Expected Auxiliary Space: O(N)

*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
int N = 1e6 + 1 ;
//---------------------------------------------------------------------------------------
int getPairsCount(int arr[], int n, int k) 
{
    
    int hash[ N ] = { 0 } ; 
    int result = 0 ;
    for( int i = 0 ; i < n ; i ++ )
    {
        if( k - arr[ i ] > 0 && k - arr[ i ] < N && hash[ k - arr[ i ] ] )
        {
            result += hash[ k - arr[ i ] ] ;        
        }
        hash[ arr[ i ] ] ++ ;
    }
    return result ;
    
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
		int n , k ;
		cin >> n ;
		cin >> k ;
		int arr[ n ] ;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[ i ] ;
		}
		cout << getPairsCount( arr , n , k ) ;
		cout << endl ;
	}
	return 0 ;
}