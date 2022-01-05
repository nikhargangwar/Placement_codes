// { Driver Code Starts
#include <iostream>
#include <queue>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    long long smallestElement(long long A[],long long n, long long k)
    {
        priority_queue<int > max_heap;
        
        for(long long int i=0;i<n;i++)
        {
            max_heap.push(A[i]);
            
            if(max_heap.size()>k)
            {
                max_heap.pop();
            }
            
        }
        
        return max_heap.top();
        
    }
    
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        
        long long int r1,r2,sum=0;
        r1=smallestElement(A,N,K1);
        r2=smallestElement(A,N,K2);
        
        
        for(long long int i=0;i<N;i++)
        {
            if(A[i]>r1 && A[i]<r2)
            {
                sum+=A[i];
            }
        }
        
        return sum;
        
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends