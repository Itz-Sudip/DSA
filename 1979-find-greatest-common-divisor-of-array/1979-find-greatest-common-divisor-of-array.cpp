class Solution {
public:
    int findGCD(vector<int>& nums) {
        int el1=*max_element(nums.begin(),nums.end());
        int el2=*min_element(nums.begin(),nums.end());
        return __gcd(el1,el2);
    }
};