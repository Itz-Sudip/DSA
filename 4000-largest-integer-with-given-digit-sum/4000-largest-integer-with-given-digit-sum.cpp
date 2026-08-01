class Solution {
public:
    int largestInteger(int n, int s) {
        if(s>(n*9)) return -1;
        int ans=0;
        while(n--){
            if(s>=9){
                ans=(ans*10)+9;
                s-=9;
            }
            else if(s>0){
                ans=(ans*10)+s;
                s=0;
            }
            else ans*=10;
        }
        return ans;
    }
};