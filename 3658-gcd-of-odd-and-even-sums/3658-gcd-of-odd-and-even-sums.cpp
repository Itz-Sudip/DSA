class Solution {
public:
    int gcdOfOddEvenSums(int n) {
       int odd=1,even=2;
       long long oddSum=0,evenSum=0;
       for(int i=0;i<n;i++){
        oddSum+=odd;
        evenSum+=even;
        odd+=2;
        even+=2;
       } 

       return __gcd(oddSum,evenSum);
    }
};