class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums1[i]&1) cnt++;
        }

        if(!cnt || cnt==n) return true;
        sort(nums1.begin(),nums1.end());
        int even=-1;
        int odd=-1;
        for(int i=0; i<n ;i++){
            if(nums1[i]&1){
                odd=nums1[i];
                break;
            }
        }
        for(int i=0; i<n ;i++){
            if(nums1[i]%2==0){
                even=nums1[i];
                break;
            }
        }

        if(even - odd >=1 ) return true;
        return false;
    }
};