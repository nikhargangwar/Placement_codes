// Kth Smallest Element in a Sorted Matrix


// Given an n x n matrix where each of the rows and columns is sorted 
// in ascending order, return the kth smallest element in the matrix.


// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

// You must find a solution with a memory complexity better than O(n2).




// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
        
//      priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> min_heap;
        
//         for(int i=0;i<matrix.size();i++)
//         {
//             min_heap.push(make_tuple(matrix[0][i],i,0));
//         }
        
//         int j=1;
//         while(j<k)
//         {
//             tuple t= min_heap.top();
//             min_heap.pop();
//             if(get<2>(t) == matrix.size() -1)
//             { j++;
//                 continue;
//             }
//             min_heap.push(make_tuple(matrix[get<2>(t)+1][get<1>(t)],get<1>(t),get<2>(t)+1));
//             j++;
//         }
        
//         return get<0>(min_heap.top());
//     }
// };