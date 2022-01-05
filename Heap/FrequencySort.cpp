//Given an array of integers nums, sort the array in increasing order based on the frequency of the values. 
//If multiple values have the same frequency, sort them in decreasing order.


// class Solution {
// public:
//     vector<int> frequencySort(vector<int>& nums) {
        
//         map<int,int> map;
//         priority_queue<pair<int,int>,vector<int>, greater<int>> min_heap;
//         vector<int> v;
        
//         for(int i=0;i<nums.size();i++)
//         {
//             map[nums[i]]++;
//         }
        
//         for(auto i=map.begin();i!=map.end();i++)
//         {
//             min_heap.push({i->second,i->first});
            
//         }
        
//         while(min_heap.size()>0)
//         {
//             for(int i=0;i<min_heap.top().first;i++)
//             {
//                 v.push_back(min_heap.top().second);
//             }
            
//             min_heap.pop();
//         }
        
//         return v;
        
//     }
// };