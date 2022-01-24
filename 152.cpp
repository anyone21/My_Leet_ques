class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int current = nums[0];
        for(int i =1;i<nums.size();i++){
            
            if(nums[i]<0){
                swap(minProduct,maxProduct);
            }
            
            minProduct = min(nums[i],nums[i]*minProduct);
            maxProduct = max(nums[i],nums[i]*maxProduct);
            
            current = max(current,maxProduct);
        }
        return current;
    }
};

// There are some issue that we might face:
/*
> if currentProduct become zero  so we can't use cumulative product array
> we also have to take care of -veproduct
for example if consider [-2,3 ,-4] 
in subarray it will consider [-2,3] 3 instead of -6
and that -6 *-4 became 24 but we got 3 as or answer. so we have to mantain for a negative
** Dry run the code to understand why we have swap the values.

Refernces:
https://leetcode.com/problems/maximum-product-subarray/discuss/203013/C%2B%2B-O(N)-time-O(1)-space-solution-with-explanation
https://leetcode.com/problems/maximum-product-subarray/discuss/48230/Possibly-simplest-solution-with-O(n)-time-complexity
*/
