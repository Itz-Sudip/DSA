class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }

        char odd='?';
        int oddf=0;
        string a="";
        for(auto it:mp){
            int f=it.second;
            if(f&1){
                odd=it.first;
            }
            f/=2;
            while(f--){
                a+=it.first;
            }
        }

        string b=a;
        if(odd!='?') b+=odd;
        reverse(a.begin(),a.end());
        return b+a;
    }
};