class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        vector<int> a(n);
        int cnt=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='(') cnt++;
            else cnt--;
            a[i]=cnt;
        }

        string ans="";
        for(int i=1;i<n;i++){
            if(a[i]==-1 || a[i-1]==-1) continue;
            ans+=s[i];
        }
        return ans;
    }
};