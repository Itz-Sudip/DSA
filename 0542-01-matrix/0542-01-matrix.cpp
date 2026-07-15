class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        }
        int delr[4]={-1,0,1,0};
        int delc[4]={0,1,0,-1};
        while(!q.empty()){
            int k=q.size();
            while(k--){
                auto it=q.front();
                q.pop();
                for(int l=0;l<4;l++){
                    int r=it.first+delr[l];
                    int c=it.second+delc[l];
                    if(r>=0 && r<mat.size() &&c>=0 && c<mat[0].size() && dis[r][c]==-1){
                        dis[r][c]=dis[it.first][it.second]+1;
                        q.push({r,c});
                    }
                }
            }
        }
        return dis;
    }
};