/* 1351. Count Negative Numbers in a Sorted Matrix
Solved
Easy
Topics
Companies
Hint
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100
 

Follow up: Could you find an O(n + m) solution?

*/

// algorithms:
/*
Brute Force:
1. iterate over each elememt of the matrix to get negative integer and increment the count --> time complexity= O(m*n)

Binary Searcg:
Initialize variables:

count = 0, to count the total number of negative elements in the matrix.
n = grid[0].size(), to store the number of elements in each row.

We iterate on each row of the matrix grid, and for each row, we find the index of the first negative element left. As all the elements from left to n - 1 will be negative elements thus we increment count by n - left.
Note: You can use in-built STL methods for the binary search like upper_bound, etc., or implement it on your own.

Utilise Sorting with Linear Traversal:
1. since we know it's sorted in non-increasing manner so the last element of first row is the smallest element of that row and similar for other rows as well
2. but to focus on this info we know, if columns are also sorted. so here in this question we got outselves a pattern, if the last element of first row is negative then only we move to the left
else we refreshes our pointer to point the last element of next row to get negative integers count.
3. repeat this till the end of all the rows

*/


// solution:

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid[0].size(); // cols
        int m = grid.size(); // rows
        int i=0, j=n-1;
        while(i<m){
            while(j>=0){
                if(grid[i][j]<0){ // negative
                    j--;
                    count++;
                }else break;
            }
            i++;
            j = n-1;
        }
        return count;
    }
};
