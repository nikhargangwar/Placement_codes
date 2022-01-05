// There are given N ropes of different lengths, we need to connect these ropes into one rope. 
// The cost to connect two ropes is equal to sum of their lengths.
// The task is to connect the ropes with minimum cost.


//Minimum Cost of ropes


// long long minCost(long long arr[], long long n) {
//         // Your code here
//         priority_queue<long long int,vector<long long int>, greater<long long int>> min_heap;
//         long long int p1,p2,cost=0;
        
//         for(long long int i=0;i<n;i++)
//         {
//             min_heap.push(arr[i]);
//         }
        
//         while(min_heap.size()>=2)
//         {
//             p1=min_heap.top();
//             min_heap.pop();
//             p2=min_heap.top();
//             min_heap.pop();
            
//             cost = cost+ p1+p2;
//             min_heap.push(p1+p2);

//         }
        
//         return cost;
        
//     }