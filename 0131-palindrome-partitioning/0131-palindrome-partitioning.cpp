class Solution {
private:
    bool ispal(string s,int low,int high){
        while(low < high){
            if(s[low++]!=s[high--]) return false;
        }
        return true;
    }
public:
    void f(int i,string s,vector<vector<string>> &ans,vector<string> &ds){
        if(i>=s.size()){
            ans.push_back(ds);
            return;
        } 
        for(int k=i;k<s.size();k++){
            if(ispal(s,i,k)){
                ds.push_back(s.substr(i,k-i+1));
                f(k+1,s,ans,ds);
                ds.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<string>> ans;
        vector<string> ds;
        f(0,s,ans,ds);
        return ans;
    }
};