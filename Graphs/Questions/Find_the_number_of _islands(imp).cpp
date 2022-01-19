Find the number of islands 

Given a grid consisting of '0's(Water) and '1's(Land). Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
 

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands one is colored in blue 
and other in orange.


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    bool isSafe(int i,int j,vector<vector<bool>>& vis,vector<vector<char>>& grid)
    {
        return (i>=0)&&(i<grid.size()) && (j>=0)&&(j<grid[0].size()) && (vis[i][j]==false) && (grid[i][j]=='1');
    }
    
    void dfs(int i,int j,vector<vector<bool>>& vis,vector<vector<char>>& grid)
    {
        vis[i][j]=true;
        
        int row[]={-1,0,1,-1,1,-1,0,1};
        int col[]={-1,-1,-1,0,0,1,1,1};
        
        for(int k=0;k<8;k++)
        {
            if(isSafe(i+row[k],j+col[k],vis,grid))
            {
                dfs(i+row[k],j+col[k],vis,grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here

    vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));

    int c=0;
    
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[0].size();j++)
        {
            if(vis[i][j]==false && grid[i][j]=='1')
            {
                dfs(i,j,vis,grid);
                 c++;
            }
           
        }
    }
   
    return c;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends