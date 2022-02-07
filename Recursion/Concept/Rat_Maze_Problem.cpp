// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> vis(n,vector<int>(n,0));
        string ans="";
        vector<string> res;
        
        int dx[]={+1,0,0,-1};
        int dy[]={0,-1,+1,0};
        if(m[0][0]==1)
        fun(0,0,m,vis,ans,res,n,dx,dy);
        return res;
    }
    
    
    void fun(int x,int y,vector<vector<int>> &m,vector<vector<int>>& vis, string ans,  vector<string>& res,int n,int dx[],int dy[] )
    {
        if(x==n-1 && y==n-1)
        {
            res.push_back(ans);
            return;
        }
        
        string s="DLRU";
        for(int i=0;i<4;i++)
        {
           
            int nextx=x+dx[i];
            int nexty=y+dy[i];
            if(nextx>=0 &&nexty>=0 &&nextx<n &&nexty<n && !vis[nextx][nexty] && m[nextx][nexty]==1)
            { vis[x][y]=1;
                fun(nextx,nexty,m,vis,ans+s[i],res,n,dx,dy);
                vis[x][y]=0;
            }
        }
        
        // //down
        // if(m[x+1][y]==1 && x+1<n && vis[x+1][y]==0)
        // {
        //     vis[x][y]=1;
        //     fun(x+1,y,m,vis,ans+'D',res,n);
        //      vis[x][y]=0;
        // }
        // //left
        //  if(m[x][y-1]==1 && y-1>=0 && vis[x][y-1]==0)
        // {
        //     vis[x][y]=1;
        //     fun(x,y-1,m,vis,ans+'L',res,n);
        //      vis[x][y]=0;
        // }
        // //right
        //  if(m[x][y+1]==1 && y+1<n && vis[x][y+1]==0)
        // {
        //     vis[x][y]=1;
        //     fun(x,y+1,m,vis,ans+'R',res,n);
        //      vis[x][y]=0;
        // }
        // //upward
        //  if(m[x-1][y]==1 && x-1>=0 && vis[x-1][y]==0)
        // {
        //     vis[x][y]=1;
        //     fun(x-1,y,m,vis,ans+'U',res,n);
        //      vis[x][y]=0;
        // }
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends