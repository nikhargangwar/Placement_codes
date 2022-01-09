// A swap is defined as taking two distinct positions in an array and swapping the values in them.

// A circular array is defined as an array where we consider the first element and the last element to be adjacent.

// Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.



//example 1
// Input: nums = [0,1,0,1,1,0,0]
// Output: 1
// Explanation: Here are a few of the ways to group all the 1's together:
// [0,0,1,1,1,0,0] using 1 swap.
// [0,1,1,1,0,0,0] using 1 swap.
// [1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
// There is no way to group all 1's together with 0 swaps.
// Thus, the minimum number of swaps required is 1.
 
 //example 2
// Input: nums = [1,1,0,0,1]
// Output: 0
// Explanation: All the 1's are already grouped together due to the circular property of the array.
// Thus, the minimum number of swaps required is 0.



class Solution {
public:
    int minSwaps(vector<int>& nums) {
       
        int k=0;
        //counting number of 1s present in the vector
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            k++;
        }
        
        if(k==0)
            return 0;
        
        
       
        int j=0,i=0,count=0,min=INT_MAX;
        
        //considering the size of window = number of 1s present in the given vector = k
        while(j<nums.size())
        {
            if(nums[j]==0)
            {
                count++;
            }
            
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1>=k)
            {
                if(min>count)
                {
                    min=count;
                }
                
                if(nums[i]==0)
                {
                    
                    count--;
                }
                
                i++;
                j++;
            }
            
        }
        j=0;
        while(i<nums.size())
        {
             if(nums[j]==0)
            {
                count++;
            }
            
            if(min>count)
                {
                    min=count;
                }
                
                if(nums[i]==0)
                {
                    
                    count--;
                }
                
                i++;
                j++;
            
            
        }
        return min;
        
    }
};