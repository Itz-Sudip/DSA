class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        vector<int> delr={-1,0,1,0};
        vector<int> delc={0,1,0,-1};
        while(!pq.empty()){
            int d=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(d>dist[x][y]) continue;
            if(x==n-1 && y==m-1) return d;
            for(int i=0;i<4;i++){
                int r=x+delr[i];
                int c=y+delc[i];
                if(r>=0 && c>=0 && r<n && c<m){
                    int newd=max(d,abs(heights[x][y]-heights[r][c]));
                    if(newd < dist[r][c]){
                        dist[r][c]=newd;
                        pq.push({newd,{r,c}});
                    }
                }
            }
        }
        return 0;
    }
};