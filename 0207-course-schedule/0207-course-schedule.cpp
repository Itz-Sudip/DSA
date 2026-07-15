class Solution {
private:
public:
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<vector<int>> adj(n);
        for(int i=0;i<a.size();i++){
            adj[a[i][1]].push_back(a[i][0]);
        }

        vector<int> indeg(n,0);
        for(int i=0;i<n;i++){
            for(int it:adj[i]){
                indeg[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            cnt++;
            for(auto it: adj[i]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        return cnt==n;
    }
};