class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int sum=0,p=1;
        while(n>=8){
           sum+=(8*p);
           p++;
           n-=8; 
        }
        sum+=n*p;
        return sum;
    }
};