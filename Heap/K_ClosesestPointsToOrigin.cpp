// / K Closest Points to Origin



// Given an array of points where points[i] = [xi, yi] represents a point 
// on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).



// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
//         priority_queue<pair<int, pair<int,int>>> max_heap;
//         vector<vector<int>> v;
        
//         for(int i=0;i<points.size();i++)
//         {
            
//     max_heap.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}});
            
//             if(max_heap.size()>k)
//             {
//                 max_heap.pop();
//             }
//         }
        
//         while(max_heap.size()>0)
//         {
//             v.push_back({max_heap.top().second.first,max_heap.top().second.second});
//             max_heap.pop();
//         }
        
//         return v;
        
//     }
// };