//Find Subsequence of Length K With the Largest Sum


// Input: nums = [3,4,3,3], k = 2
// Output: [3,4]
// Explanation:
// The subsequence has the largest sum of 3 + 4 = 7. 
// Another possible subsequence is [4, 3].



//implementing pair inside priority queue / min heap




// class Solution {
// public:
//     vector<int> maxSubsequence(vector<int>& nums, int k) {
        
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
       
        
        
//         for(int i=0;i<nums.size();i++)
//         {
//             min_heap.push({nums[i],i});
            
//             if(min_heap.size()>k)
//             {
//                 min_heap.pop();
//             }
            
            
//         }
        
//         vector<pair<int,int>> ans;
        
//         while(min_heap.size()!=0)
//         {
//             ans.push_back({min_heap.top().second,min_heap.top().first});
            
//             min_heap.pop();
//         }
        
//       sort(ans.begin(),ans.end());
        
//         vector<int> finalAns;
        
//         for(auto x:ans)
//         {
//             finalAns.push_back(x.second);
//         }
        
//         return finalAns;

                

        
//     }
// };