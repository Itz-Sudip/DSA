class Solution {
public:
    int f(vector<int> &a,int i,int j,vector<vector<int>> &dp){
        if(i==j) return a[i];
        if(dp[i][j]!=-1) return dp[i][j];
        int path1=a[i]-f(a,i+1,j,dp);
        int path2=a[j]-f(a,i,j-1,dp);
        return dp[i][j]=max(path1,path2);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(piles,0,piles.size()-1,dp)>=0;
    }
};