class Solution {
public:
    int minimumPushes(string word) {
        map<char,int> mp;
        int m=word.size();
        for(int i=0;i<m;i++) mp[word[i]]++;
        vector<int> a;
        for(auto it:mp){
            a.push_back(it.second);
        }
        sort(a.rbegin(),a.rend());
        int sum=0;
        int n=a.size();
        for(int i=0;i<n;i++){
           int p=(i/8)+1;
           sum+=a[i]*p;
        }
        return sum;
    }
};