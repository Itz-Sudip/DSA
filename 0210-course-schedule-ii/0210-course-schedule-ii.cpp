class Solution {
private:
    bool dfs(int i,vector<int> &vis,vector<vector<int>> adj,stack<int> &s){
        vis[i]=1;
        for(auto it: adj[i]){
            if(vis[it]==0){ 
                if(dfs(it,vis,adj,s)) return true;
            }
            else if(vis[it]==1) {
                return true;
            }
        }
        vis[i]=2;
        s.push(i);
        return false;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& a) {
        vector<vector<int>> adj(n);
        for(int i=0;i<a.size();i++){
            adj[a[i][1]].push_back(a[i][0]);
        }
        vector<int> vis(n,0);
        stack<int> s;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(dfs(i,vis,adj,s)) return {};
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};