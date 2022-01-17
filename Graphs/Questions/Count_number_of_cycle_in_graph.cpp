There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 

Example 1:


Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:


Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.


//count the number of cycles and components in the graph
//after the completetion of process number of cycles counted will be twice because 1 edge is counted twice
//eg ->  1-2 and 2-1 forms the one edge to form cycle but counted twice

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        int cycle=0,component = 0;
        
        for(auto x: connections)
        {
            adj[x[0]].push_back(x[1]);
             adj[x[1]].push_back(x[0]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            { 
                dfs(i,-1,vis,adj,cycle);
                 component++;             
            }
        }
        
       //number of cycles counted has to halfed in order to get exact number of cycles in a graph
       //because while couting the number of cycles 1 edge is counted twice

        if(cycle/2>=component-1)
        {
            return component-1;
        }
        else{
            return -1;
            }
        
        
    }
    
    void dfs(int src,int pre,vector<int>& vis , vector<vector<int>>& adj, int& cycle)
    {
        vis[src]=1;
        
        for(auto x:adj[src])
        { 
            if(vis[x]==0)
            {
              
                 dfs(x,src,vis,adj,cycle);
            }
            else if(x!=pre)
            {
              
                 cycle++;
                
            }
        }
    }
};


