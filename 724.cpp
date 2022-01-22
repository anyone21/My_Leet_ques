// Mine solution O(N)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[i]+= nums[i-1];
        }
        int index = -1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i==0){
                if(nums[n-1]-nums[i]==0){
                    index=i;
                    break;
                }
            }
            if(i==n-1){
                if(nums[i-1]==0){
                    index=i;
                    break;
                }
            }
            if(i>0 && i<n-1 && nums[i-1]==nums[n-1]-nums[i]){
                index=i;
                break;
            }
        }
        return index;
    }
};


// Improved version O(N) complexity
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int GLOBAL_SUM = 0;
        int LEFT_SUM = 0;
        int SIZE = nums.size();
       
        for(auto i:nums){
            GLOBAL_SUM += i;
        }
        
        for(int i = 0;i<SIZE;i++){
            if(LEFTSUM==GLOBAL_SUM-LEFTSUM-nums[i]){
                return i;
            }
            LEFTSUM+= nums[i];
        }
        return -1;
    }
};
