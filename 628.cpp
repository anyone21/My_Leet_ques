// approch-1

// For non-general case

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN,max2 = INT_MAX, max3 = INT_MIN;
        int min1 = INT_MAX,min2 = INT_MAX;
         
        for(auto n:nums){
            if(n>max1){
                max3 = max2;
                max2 = max1;
                max1 = n;
            }else if(n>max2){
                max3 = max2;
                max2 = n;
            }else if(n>max3){
                max3 = n;
            }
            
            if(n<min1){
                min2 = min1;
                min1 = n;
            }else if(n<min2){
                min2 = n;
            }
        }
        
        return max(max1*max2*max3, min1*min2*max1);
    }
};

// Above approch is not suitable for Maximum products of K numbers
// It's a DP approch 
// We are considering K = 3
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int k = 3;
        vector<vector<int>> dpProd;
        
        dpProd[0][0] = 1;
        dpProd[1][0] = 1;
        
        for(int i =1;i<=k;i++){
            dpProd[0][i] = INT_MIN;
            dpProd[1][i] = INT_MAX;
        }
        
        for(int i=0;i<nums.size();i++){
            // pending
        }
    }
};


/*
 0   ......   k+1
 ----------------
|     |     |    |  --> MaxProduct
 ----------------
|     |     |    |  --> MinProduct
 ----------------
 
*/


// Using maxHeap and minHeap
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int k = 3;
        // Here we make a maxHeap and minHeap that store K largest and smallest number
        priority_queue<int> maxQ(nums.begin(),nums.end());  // max_heap
        priority_queue<int,vector<int>,greater<int>> minQ(nums.begin(),nums.end());  //min_heap
        
        int maxNum = maxQ.top();
        int count = 0;
        int minP = 1;
        int maxP = 1;
        
        if(k%2!=0){
            while(count!=k-1){
                minP *= minQ.top();
                minQ.pop();
                count++;
            }
        }else{
            while(count!=k){
                minP *= minQ.top();
                minQ.pop();
                count++;
            }
        }

        
        if(k%2!=0){
            minP *= maxNum;
        }
        
        count = 0;
        while(count!=k){
            maxP = maxP*maxQ.top();
            maxQ.pop();
            count++;
        }

        return max(maxP,minP);
    }
};

// Above approch is not valid for K elements it only valid for k = 3 elements
// Above will fail in [-7, -6, 1, 2, 3, 4, 9, 10, 11]


