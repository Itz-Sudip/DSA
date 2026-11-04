class Solution {
public:
    int minMoves(vector<int>& nums) {
        int x=*max_element(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=x-nums[i];
        }

        return sum;
    }
};