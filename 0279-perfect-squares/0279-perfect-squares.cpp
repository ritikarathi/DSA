class Solution {
public:
    int solve(int idx, int n, vector<int>&sq,vector<vector<int>>&dp){
        if(n==0){
            return 0;
        }
        if(idx>=sq.size()){
            return 1e9;
        }
        if(dp[idx][n]!=-1){
            return dp[idx][n];
        }
        int skip =solve(idx+1,n,sq,dp);
        int take=1e9;
        if(sq[idx]<=n){
            take=1+solve(idx,n-sq[idx],sq,dp);
        }
        return dp[idx][n]=min(skip,take);
    }
    int numSquares(int n) {
        vector<int>sq;
        for(int i=1; i*i<=n;i++){
            sq.push_back(i*i);
        }
        vector<vector<int>>dp(sq.size(),vector<int>(n+1,-1));
        return solve(0,n,sq,dp);
    }
};