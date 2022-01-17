Redundant Connection


In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

Example 1:


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:


Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
 

 class Solution {
   
public:
     vector<int> par;
    vector<int> rank;

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        par = vector<int>(edges.size()+1);
        rank = vector<int>(edges.size()+1);
       
         for(int i=0;i<edges.size();i++)
        {
            par[i]=i;
            rank[i]=0;
        } 
        vector<int> res;
        for(auto i:edges)
        {
            if(findPar(i[0])!=findPar(i[1]))
            {
                unionn(i[0],i[1]);
            }
            else{
                res.push_back(i[0]);
                res.push_back(i[1]);
               
            }
        }
        return res;
    }

    
    int findPar(int node)
    {
        if(node==par[node])
        {
            return node;
        }
        
        return par[node] = findPar(par[node]);
        
    }
    
    void unionn(int u,int v)
    {int x,y;
        x=findPar(u);
        y=findPar(v);
        
        if(rank[x]>rank[y])
        {
            par[y]=x;
        }
        else if(rank[x]<rank[y])
        {
            par[y] =x ;
        }
        else{
            par[y]=x;
            rank[x]++;
        }
    }
};