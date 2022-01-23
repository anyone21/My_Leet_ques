class Solution {
public:
    
    // Applied Khaden two times to find max and min sum subarray.
    int maxAbsoluteSum(vector<int>& nums) {
        int globalMax = INT_MIN;
        int globalMin = INT_MAX;
        int currentSum = 0;
        int n = nums.size();
        
        for(int currentEndIndex = 0;currentEndIndex<n;currentEndIndex++){
            currentSum = max(nums[currentEndIndex],currentSum+nums[currentEndIndex]);
            if(currentSum>globalMax){
                globalMax = currentSum;
            }
        }
        
        currentSum = 0;
        
        for(int currentEndIndex = 0;currentEndIndex<n;currentEndIndex++){
            currentSum = min(nums[currentEndIndex],currentSum+nums[currentEndIndex]);
            if(currentSum<globalMin){
                globalMin = currentSum;
            }
        }
        
        
        return max(abs(globalMin),globalMax);
    }
};
