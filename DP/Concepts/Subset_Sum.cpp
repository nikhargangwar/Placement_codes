

// { Driver Code Starts
//Initial template for C++
#include <iostream>
#include <queue>
#include<vector> 

using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        bool t[N+1][sum+1];
        
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(i==0)
                {
                    t[i][j]=false;
                }
                if(j==0)
                 t[i][j]=true;
            }
        }
        
  
    //     for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= sum; j++) {
    //         if (j < set[i - 1])
    //             subset[i][j] = subset[i - 1][j];
    //         if (j >= set[i - 1])
    //             subset[i][j] = subset[i - 1][j]
    //                           || subset[i - 1][j - set[i - 1]];
    //     }
    // }
        
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(arr[i-1]>j)
                t[i][j]=t[i-1][j];
                else
                {
                    t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j];
                }
            }
        }
        
        return t[N][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends