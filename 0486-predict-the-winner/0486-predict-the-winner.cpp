class Solution {
private:
    int f(vector<int> &nums,int l,int r){
        if(l==r) return nums[l];
        int left=nums[l]-f(nums,l+1,r);
        int right=nums[r]-f(nums,l,r-1);
        return max(left,right);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        return f(nums,i,j)>=0;
    }
};