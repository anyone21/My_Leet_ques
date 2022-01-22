// Maximum Subarray
// Kadane's Algorithm is an O ( n ) {\displaystyle O(n)} {\displaystyle O(n)} algorithm for finding the maximum contiguous subsequence in a one-dimensional sequence. 

int maxSubArray(vector<int>& nums) {
        
        int currentMaxSum = nums[0];
        int maxSum = currentMaxSum;
        int maxStartIndex = 0, maxEndIndex = 0;
        int currentStartIndex = 0;

        for(int currentEndIndex = 1; currentEndIndex<nums.size();currentEndIndex++){
            currentMaxSum = max(nums[currentEndIndex],currentMaxSum+nums[currentEndIndex]);

            if(currentMaxSum>maxSum){
                maxSum = currentMaxSum;
                maxStartIndex = currentStartIndex;
                maxEndIndex = currentEndIndex;
            }
            if(currentMaxSum <0){
                currentMaxSum = 0;
                currentStartIndex = currentEndIndex+1;
            }
        }
        return maxSum;
}


// Without starting and ending index of that subarray

int maxSubArray(vector<int>& nums) {
        
        int currentMaxSum = nums[0];
        int maxSum = currentMaxSum;

        for(int currentEndIndex = 1; currentEndIndex<nums.size();currentEndIndex++){
            currentMaxSum = max(nums[currentEndIndex],currentMaxSum+nums[currentEndIndex]);

            if(currentMaxSum>maxSum){
                maxSum = currentMaxSum;
            }
            if(currentMaxSum <0){
                currentMaxSum = 0;
            }
        }
        return maxSum;
}
