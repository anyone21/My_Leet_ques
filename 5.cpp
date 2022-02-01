// Simple Brute force approch
// Here we are contracting window. If we find a palindrom in largest window that we don't looking further in that window

class Solution {
public:
    
    bool checkPalin(string s,int start, int end){
        while(start<end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        // cout<<s.substr(0,2);
        int size = s.size();

        if(size==0){
            return "";
        }
        
        if(size==1){
            return s;
        }
        
        int result = 0;
        int start = 0;
        int end = 0;
        
        for(int i =0;i<size;i++){
            for(int j = size-1;j>i;j--){
                if(s[i]==s[j]){
                    if(checkPalin(s,i,j)){
                        if(result < j-i+1){
                            result= j-i+1;
                            start = i;
                            end = j;
                        }
                        break;
                    }
                }
            }
        }
        
        string r = "";
        for(int i = start;i<=end;i++){
            r+=  s[i];
        }
        return r;
        
    }
};

