class Solution {
    bool dfs(int i,int color, vector<vector<int>> &adj, vector<pair<int,int>> &vis){
        vis[i].first=1;
        vis[i].second=color;
        for(auto it:adj[i]){
            if(vis[it].first==0){
                if(color==1){
                    if(dfs(it,2,adj,vis)==false) return false;
                }else{ 
                    if(dfs(it,1,adj,vis)==false) return false;
                }
            }
            else {
                if(vis[it].second==color) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<pair<int,int>> vis(n,{0,0});
        for(int i=0;i<n;i++){
            if(vis[i].first==0){
                if(dfs(i,1,graph,vis)==false) return false;
            }
        }
        return true;
    }
};