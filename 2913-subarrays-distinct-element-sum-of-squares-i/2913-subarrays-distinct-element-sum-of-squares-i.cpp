class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        
        map<int,int> mp;
        for(int i=0; i<n; i++){
            set<int> st;
            for(int j=i; j<n; j++){
                mp[nums[j]]++;
                st.insert(nums[j]);
                int k=st.size();
                sum+=k*k;
            }
            mp[nums[i]]--;
            if(mp[nums[i]] == 0){
                st.erase(nums[i]);
                mp.erase(nums[i]);
            }
        }
        return sum;
    }
};