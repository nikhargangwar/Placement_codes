//Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.


// class Solution {
// public:
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
//         priority_queue<pair<int,int>> max_heap;
        
//         vector<int> v;
        
//         for(int i=0;i<arr.size();i++)
//         {
            
//             max_heap.push({abs(arr[i]-x),arr[i]});
            
//             if(max_heap.size()>k)
//             {
//                 max_heap.pop();
//             }
                
//         }
        
           
//         while(max_heap.size()>0)
//         {
//            v.push_back(max_heap.top().second);
           
//             max_heap.pop();
           
//         }
//          sort(v.begin(),v.end());
    
//         return v;
        
//     }
    
