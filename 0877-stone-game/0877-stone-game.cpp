class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=piles[i];
        }
        for(int i=0;i<n;i++){
            for(int j=n-1;j>i;j--){
                int path1=piles[i]-dp[i+1][j];
                int path2=piles[j]-dp[i][j-1];
                dp[i][j]=max(path1,path2);
            }
        }
        return dp[0][n-1];
    }
};