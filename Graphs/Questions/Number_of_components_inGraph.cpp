// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

 

// Example 1:


// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2
// Example 2:


// Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3




//based on finding the number of components present in a graph

//application of,  incase of matrix of graph is given instead of adjacency list


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
          if (isConnected.empty()) return 0;
        
        vector<int> v(isConnected.size(),0);
        int res=0;
        
        
        for(int i=0;i<isConnected.size();i++)
        {
            if(v[i]==0)
            {
                dfs(i,v,isConnected);
                res++;
            }
        
        }
        
        cout<<res<<" ";
    
        return res;
    }
    
    void dfs( int src,vector<int>& v,vector<vector<int>>& isConnected)
    {
        v[src]=1;
        
        for(int i=0;i<isConnected[src].size();i++)
        {
            if(i!=src && v[i]==0 && isConnected[src][i]==1)
            {
                dfs(i,v,isConnected);
            }
        }
    }
};