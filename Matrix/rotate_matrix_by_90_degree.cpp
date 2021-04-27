/*
    Rotate Image
    LINK : https://leetcode.com/problems/rotate-image/

    Expected Time Complexity : O(n*n)
    Expected Auixiliary Space : O(1)
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
const int MAX = 500; 

//-----------------------------------------------------------------------------------
void rotate(vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    for(int i = 0; i < n/2; i ++)
    {
        
        for(int j = i; j < n - 1 - i ; j++)
        {
            int temp = matrix[i][j];
            
            matrix[i][j] = matrix[n - 1  - j][i];
                
            matrix[n - 1 - j][i] = matrix[n - 1 - i][ n - 1 -j];
            
            matrix[n - 1 - i][ n - 1 -j] = matrix[j][n - 1 - i];
            
            matrix[j][n - 1 - i] = temp ;
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
        int n, m;
        cin >> n >> m;
        std::vector<vector<int>> matrix(n, vector<int>(m,0));
        for(int i = 0; i < n; ++i) 
        {
            for(int j = 0; j < m; j ++)
            {
                cin >> matrix[i][j];
            }
        }
        rotate(matrix);

        for(auto i : matrix)
        {
            for(auto j : i)
            {
                cout << j << " " ;
            }
            cout << endl;
        }
        cout << endl ;
    }
    return 0 ;
}