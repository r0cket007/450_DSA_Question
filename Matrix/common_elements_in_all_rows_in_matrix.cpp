/*
    Common elements in all rows of a given matrix
    LINK : https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/

    Expected Time Complexity : O(n*m)
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
const int MAX = 500; 

//-----------------------------------------------------------------------------------
void printCommonElements(int matrix[MAX][MAX], int n, int m) 
{
    unordered_map<int,int> mp ;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m ; j ++)
        {
            if( mp[matrix[i][j]] == i )
            {
                mp[matrix[i][j]] ++ ;
            }
        }
    }
    for(auto i : mp)
    {
        if( i.second == n )
        {
            cout << i.first << " ";
        }
    }
}
//-------------------------------------------------------------------------------------
signed main( )
{
    #ifndef ONLINE_JUDGE
    r0cket007
    #endif
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        int mat[MAX][MAX] ={
            {1, 2, 1, 4, 8},
            {3, 7, 8, 5, 1},
            {8, 7, 7, 3, 1},
            {8, 1, 2, 7, 9},
        };
        printCommonElements(mat, 4, 5);
    }
    return 0 ;
}