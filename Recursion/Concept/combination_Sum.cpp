class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
         vector<vector<int>> res;
        vector<int> ans;
        func(0,target,candidates,ans,res);
        return res;
        
    }
    
    void func(int i,int target,vector<int>& candidates, vector<int> ans,vector<vector<int>>& res )
    {
        //base case
        if(i==candidates.size()){
            if(target==0)
            {
            res.push_back(ans);
            }
            return ;
          
        }
        
       if(candidates[i]<=target)
       {
         ans.push_back(candidates[i]);
        func(i,target-candidates[i],candidates,ans,res);     
        ans.pop_back();
       }
        

        func(i+1,target,candidates,ans,res);
    
        
        
    }
};