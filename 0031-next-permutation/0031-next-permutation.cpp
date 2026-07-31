class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int id=n-2;
        while(id>=0){
            if(nums[id] < nums[id+1]) break;
            id--;
        }

        if(id==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            int k=n-1;
            for(int j=n-1;j>id;j--){
                if((nums[j] > nums[id])){
                    k=j;
                    break;
                }
            }

            swap(nums[id],nums[k]);
            sort(nums.begin()+id+1,nums.end());
        }
    }
};