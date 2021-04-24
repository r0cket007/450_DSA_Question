/*
	Search a 2D Matrix
	LINK : https://leetcode.com/problems/search-a-2d-matrix/

    Binary Search
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size( ) ;
        int m = matrix[ 0 ].size( ) ;
        int pos ;
        for( pos = 0 ; pos < n - 1 ; pos ++ )
        {
            if( target < matrix[ pos + 1 ][ 0 ] )
            {
                break ;
            }
        }
        int left = 0 , right = m - 1 ;
        while( left <= right )
        {
            int mid = left + ( right - left ) / 2 ;
            if( matrix[ pos ][ mid ] == target )
            {
                return true ;
            }
            else if( matrix[ pos ][ mid ] > target )
            {
                right = mid - 1 ;
            }
            else 
                left = mid + 1 ;
        }
        return false ;
    }
};