class Solution {
public:
    int minInsertions(string s) {
        int cnt=0,right=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){ 
                if (right % 2 != 0) {
                    cnt++; 
                    right--; 
                }
                right+=2;
            }
            else{
                right--;
                if (right < 0) {
                    cnt++;     
                    right += 2; 
                }
            }
        }
        return cnt+right;
    }
};