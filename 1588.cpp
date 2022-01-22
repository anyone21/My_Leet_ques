// O(n^2) approch
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int result=0,temp = 0;
        
        for(auto i:arr){
            result+=i;
        }
        
        // cumulative sum array
        for(int i =1;i<n;i++){
            arr[i] += arr[i-1];
        }
        
        for(int i = 0;i<n;i++){
            temp = 0;
            for(int j = i+1;j<n;j++){
                if((j-i+1)%2!=0){
                    if(i==0){
                        temp += (arr[j]);    
                    }else{
                        temp += (arr[j]-arr[i-1]);
                    }
                }
            }
            result+= temp;
            temp = 0;
        }
        return result;
    }
};


// Another intresting approch

// Reference: https://blogs.asarkar.com/assets/docs/algorithms-curated/Subarray%20Sums%20-%20Stanford.pdf
/*
In this approch we find the contribution of each element in th TOTAL_SUM.
Consider the subarray contains A[i], we can take 0,1,2,3,... i elements on the left, from A[0] to A[i],
we have i+1 choices.

We can take 0,1,2, ... , n-1-i elements on the right, from A[i] to A[n-1], we have (n-i) choices.

In total there are K = (i+1)*(n-i) subarrays, that contains A[i].
There are (K+1)/2 subarrays with odd length, that contains A[i].
There are K/2 subarrays with even length, that contains A[i].

A[i] will be counted ((i + 1) * (n - i) + 1) / 2 times for our question.

Example of array [1,2,3,4,5]

1 2 3 4 5 subarray length 1
1 2 X X X subarray length 2
X 2 3 X X subarray length 2
X X 3 4 X subarray length 2
X X X 4 5 subarray length 2
1 2 3 X X subarray length 3
X 2 3 4 X subarray length 3
X X 3 4 5 subarray length 3
1 2 3 4 X subarray length 4
X 2 3 4 5 subarray length 4
1 2 3 4 5 subarray length 5

5 8 9 8 5 total times each index was added, k = (i + 1) * (n - i)
3 4 5 4 3 total times in odd length array with (k + 1) / 2
2 4 4 4 2 total times in even length array with k / 2

*/

// CODE
int sumOddlengthSubarrays(vector<int>& arr){
  int result = 0;
  int SIZE = arr.size();
  for(int i = 0;i<SIZE;i++){
    result += ((i+1)*(n-i)+1)/2*A[i];
  }
  return result;
  
}


