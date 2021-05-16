/*
	Spirally traversing a matrix 
	LINK : https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1#

	Expected Time Complexity: O(R*C)
	Expected Auxiliary Space: O(R*C)
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
{
    int left = 0 ;
    int right = c - 1 ;
    int top = 0 ;
    int down = r - 1 ;
    int counter = 0 ;
    vector<int> ans( r * c , 0 ) ;
    while( true )
    {
        int temp_left = left ;
        int temp_right = right ;
        while( temp_left <= temp_right )
        {
            ans[counter ++] = matrix[ top ][ temp_left++ ] ;
        }
        if( counter == r * c ) 
        	break ;
        top ++ ;
        int temp_top = top ;
        int temp_down = down ;
        while( temp_top <= temp_down )
        {
            ans[counter ++] = matrix[ temp_top++ ][ right ] ;
        }
        if( counter == r * c ) 
        	break ;
        right -- ;
        temp_right = right ;
        temp_left = left ;
        while( temp_left <= temp_right )
        {
            ans[counter ++] = matrix[ down ][ temp_right -- ] ;
        }
        if( counter == r * c ) 
        	break ;
        down -- ;
        temp_top = top ;
        temp_down = down ;
        while( temp_top <= temp_down )
        {
            ans[counter ++] = matrix[ temp_down -- ][ left ] ;
        }
        if( counter == r * c ) 
        	break ;
        left ++ ;
    }
    return ans ;
}
signed main( )
{
	#ifndef ONLINE_JUDGE
    r0cket007
    #endif
	int testcases = 1 ;
	// cin >> testcases ;
	while( testcases -- )
	{
		vector< vector< int > > matrix = { {1, 2, 3, 4} };
		int R = 1, C = 4  ;
		vector< int > ans = spirallyTraverse( matrix , R , C ) ;
		for( auto i : ans )
		{
			cout << i << " " ;
		}
		cout << endl ;
	}
	return 0 ;
}