/*
In this problem I have to tell the length of the longest subsequence and 
print the data of the longest subsequence.

// Approch-1
// Brute force  O(2^n)
In this approch we find all the subsets and check each subset that it is a LIS or not.

// Approch-2
// Optimizaton of above brute force approch to O(n^2)
// In this approch we optimize the above approch using memoization.

// Approch-3
// Using binary search O(nlog n)


Note:
Proper way of solving any DP problem is:
1. Form a recursive solution.
2. Memoise the solution
3. Create DP tabulation using the recursive equation.

Resource:
https://www.youtube.com/watch?v=SHFyIAnjj90
https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326552/Optimization-From-Brute-Force-to-Dynamic-Programming-Explained!

*/

// Approch-1
class Solution {
public:
    
    int LIShelper(vector<int>& nums,int prev,int current){
        if(current == nums.size()){
            return 0;
        }
        
        int yes = 0;
        if(prev==-1 || nums[prev]<nums[current]){
            yes = 1+LIShelper(nums,current,current+1);  //to include
        }
        
        int no = LIShelper(nums,prev,current+1);  // to not include the number
        
        return max(yes,no);
    }
    int lengthOfLIS(vector<int>& nums) {
        return LIShelper(nums, -1,0);
    }
};


// Approch-2
// Time Complexity : O(N^2)
// Space Complexity : O(N^2)

class Solution {
public:
    vector<vector<int>> dp;
    int LIShelper(vector<int>& nums,int prev,int current){
        if(current == nums.size()){
            return 0;
        }
        
        if(prev!=-1 && dp[prev][current]!=0){
            return dp[prev][current];
        }
        
        int yes = 0;
        if(prev==-1 || nums[prev]<nums[current]){
            yes = 1+LIShelper(nums,current,current+1);  //to include
        }
        
        int no = LIShelper(nums,prev,current+1);  // to not include the number
        
        if(prev!=-1){
            dp[prev][current] = max(yes,no);
        }
        
        return max(yes,no);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(size(nums), vector<int>(1+size(nums), 0));
        
        return LIShelper(nums, -1,0);
    }
};

// O(n^2) approch
// This appproch will only return the length of the longest increasing subsequence
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> d(n,1);
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[j]<nums[i]){
                    d[i] = max(d[i],d[j]+1);
                }
            }
        }
        
        // finding the maximum in d
        int result = d[0];
        for(auto i:d){
            if(i>result){
                result = i;
            }
        }
        
        return result;
    }
};

// Same as above approch in this we will print the sussequence also
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> d(n,1),p(n,-1);
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[j]<nums[i] && d[i] <d[j]+1){
                    d[i] = d[j]+1;
                    p[i] = j;
                }
            }
        }
        
        // finding the maximum in d
        int result = d[0],pos = 0;
        for(int i = 1;i<n;i++{
            if(d[i]>result){
                result = d[i];
                pos = i;
            }
        }
        
        vector<int> subseq;
        while(pos!=-1){
            subseq.push_back(nums[pos]);
            pos = p[pos];
        }
            reverse(subseq.begin(),subseq.end());
        return result;
    }
};

            

// approch-3 
// Using binary search
// This prblem might be think in direction of binary search because lot Longest increasing subsequence which is formed is the combination of lot of small increasing subsequences

