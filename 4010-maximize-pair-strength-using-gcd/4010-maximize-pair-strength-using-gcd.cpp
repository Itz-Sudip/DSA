class Solution {
public:
    long long strength(int a, int b){
        long long c=a,d=b;
        long long e=gcd(c,d);
        return (c*d)/(e*e);
    }
    long long maxPairStrength(vector<int>& nums) {
        long long maxi=0LL;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                maxi=max(maxi,strength(nums[i],nums[j]));
            }
        }
        return maxi;
    }
};