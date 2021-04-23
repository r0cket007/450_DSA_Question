/*
	Common elements

	Link: https://practice.geeksforgeeks.org/problems/common-elements1132/1
	
	Q.	Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
		
		Note: can you take care of the duplicates without using any additional Data Structure?

	
	-----------------------------------------------------
	Input:
	n1 = 6; A = {1, 5, 10, 20, 40, 80}
	n2 = 5; B = {6, 7, 20, 80, 100}
	n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
	
	Output: 20 80
	
	Explanation: 20 and 80 are the only
	common elements in A, B and C.
	-----------------------------------------------------
	
	Expected Time Complexity: O(n1 + n2 + n3)
	Expected Auxiliary Space: O(n1 + n2 + n3)

*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
int N = 1e6 + 1 ;
//---------------------------------------------------------------------------------------
vector<int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector< int > ans ;
    int n = n1 + n2 + n3 ;
    int temp[ n ] ;
    int i = 0 , j = 0 , k = 0 ;
    int counter = 0 ;
    while( i < n1 && j < n2 && k < n3 )
    {
        if( i > 0 && i < n1 && A[ i - 1 ] == A[ i ] )
        {
            i++ ;
        }
        if( j > 0 && j < n2 && B[ j - 1 ] == B[ j ] )
        {
            j++ ;
        }
        if( k > 0 && k < n3 && C[ k - 1 ] == C[ k ] )
        {
            k++ ;
        }
        if( i < n1 && j < n2 && k < n3 )
        {
            if( A[ i ] == B[ j ] and B[ j ] == C[ k ] )
            {
                
            }
        }
    }
    
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
		int n1 , n2 , n3 , k ;
		cin >> n1 >> n2 >> n3 ;
		int arr1[ n1 ], arr2[ n2 ], arr3[ n3 ] ;
		for (int i = 0; i < n1; ++i)
		{
			cin >> arr1[ i ] ;
		}
		for (int i = 0; i < n2; ++i)
		{
			cin >> arr2[ i ] ;
		}
		for (int i = 0; i < n3; ++i)
		{
			cin >> arr3[ i ] ;
		}
		vector<int> ans = commonElements( arr1 , arr2 , arr3 , n1 , n2 , n3 ) ;
		cout << endl ;
	}
	return 0 ;
}