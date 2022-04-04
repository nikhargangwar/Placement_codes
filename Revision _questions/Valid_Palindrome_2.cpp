//https://leetcode.com/problems/valid-palindrome-ii/submissions/

// Valid Palindrome II


// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

// Example 1:

// Input: s = "aba"
// Output: true




//Note 
// In this soln if you see there are two nested while loop used ->  so the time complexity seems to be O(n^2).
// but on careful obeservation we see that the complete string is being traversed once only - > as jaha pehle waala loop khatam ho rha hai
// doosra waala loop bache hue elements ko traverse kr rha hai ... koi extra elements ko traverse nahi kar rha hai



class Solution {
public:
    bool validPalindrome(string s) {
    
        int i=0,j=s.length()-1;
        
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return isPalindrome(s,i,j-1) || isPalindrome(s,i+1,j);
            }
            i++;
            j--;
        }
        
        return true;
    }
    
    bool isPalindrome(string s , int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
};