class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0,j=0,n=s.length();
        int maxi=INT_MIN;
        map<char,int> mp;
        while(j<n){
            mp[s[j]]++;
            while(mp[s[j]] > 2){
                mp[s[i]]--;
                i++;
            }

            int d=j-i+1;
            maxi=max(maxi,d);
            j++;
        }
        return maxi;
    }
};