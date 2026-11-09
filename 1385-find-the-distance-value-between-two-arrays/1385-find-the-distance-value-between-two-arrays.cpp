class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
       sort(arr2.begin(),arr2.end());
       int n=arr1.size();
       int sum=0;
       for(int i=0;i<n;i++){
        int j=0;
        while(j<arr2.size() && abs(arr1[i]-arr2[j]) > d ){
            j++;
        }

        if(j==arr2.size()) sum++;
       } 
       return sum;
    }
};