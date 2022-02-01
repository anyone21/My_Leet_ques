// Two pointer...
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n<3){
            return 0;
        }
        
        int maxlength = 0;
        
        for(int i =1;i<n-1;i++)
        {
            if(arr[i-1]<arr[i] && arr[i]>arr[i+1])
            {
                // cout<<i<<endl;
                
                int startNode = i;
                int endNode = i;
                while(startNode>0 && arr[startNode]>arr[startNode-1]){
                    startNode--;
                }
                while(endNode<n-1 && arr[endNode]>arr[endNode+1]){
                    endNode++;
                }
                // cout<<startNode<<endNode<<endl;
                maxlength = max(maxlength,(endNode-startNode+1));
                
                i = endNode;
            }
            
        }
        
        return maxlength;
        
    }
};
