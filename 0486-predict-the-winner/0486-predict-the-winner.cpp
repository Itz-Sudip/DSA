class Solution {
public:
    bool f(vector<int> &nums,int l,int r,int p,long long s1,long long s2){
        if(l>r){
            return s1>=s2;
        }
        if(p){
            if(f(nums,l+1,r,0,s1+nums[l],s2) || f(nums,l,r-1,0,s1+nums[r],s2)) return true;
        }
        if(!p){
            if(f(nums,l+1,r,1,s1,s2+nums[l]) && f(nums,l,r-1,1,s1,s2+nums[r])) return true;
        }
        return false;
    }
    bool predictTheWinner(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        return f(nums,i,j,1,0LL,0LL);
    }
};