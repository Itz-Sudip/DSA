class Solution {
public:
    int calculateScore(int a, int b) {
        int s1=0,s2=0;
        for(int i=0; i<32; i++){
            if((1<<i) & a) s1++;
        }

        for(int i=0; i<32; i++){
            if((1<<i) & b) s2++;
        }

        if(s1>=s2) return s1*s2;
        return s2/s1;
    }
};