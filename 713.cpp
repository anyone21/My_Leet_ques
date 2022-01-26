// Brute force
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
     
        int count = 0;
        int n = nums.size();

        for(int i=1;i<n;i++){
            nums[i] *= nums[i-1];
        }
        
        for(int i=0;i<n;i++){
            for(int j = i;j<n;j++){
                if(i==0){
                    if(nums[j]<k){
                        count++;
                    }
                }
                else{
                    if((nums[j]/nums[i-1])<k){
                        count++;
                    }    
                }
            }
        }
        return count;
    }
};

// 
