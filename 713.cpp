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

// Another brute force approch
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // Approch-2
        // Here we find total subarray whose product >= k
        
        int count = 0;
        int n = nums.size();
        int total = (n*(n+1))/2;
        
        for(int i= 0;i<n;i++){
            int temp = 1;
            for(int j = i;j<n;j++){
                temp *= nums[j];
                if(temp>=k){
                    count+= (n-j);
                    break;
                }
            }
        }
        
        return total-count;
    }
};


// using the sliding window approch
// o(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        
        int count = 0;
        int left = 0;
        int n = nums.size();
        int tempP = 1;
        
        if(k<=1){
            return 0;
        }
        for(int right = 0;right<n;right++){
            tempP *= nums[right];
            while(tempP>=k){
                tempP /= nums[left++];
            }
            count += right-left+1;
        }
        
        return count;
        
    }
};
