class Solution {
public:
    int f(vector<int>& arr, int n, int i, vector<int>& memo){
        if(i==n) return 0;
        if(memo[i]!=-1) return memo[i];
        int min_cost = 1e9; 
        for (int step = 1; step <= 3; ++step) {
            int j = i + step;
            if (j <= n) {
                int cost = arr[j - 1] + (step * step);
                int total_cost = cost + f(arr, n, j,memo);
                min_cost = min(min_cost, total_cost);
            }
        }
        
        return memo[i]=min_cost;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> memo(n,-1);
        return f(costs,n,0,memo);
    }
};