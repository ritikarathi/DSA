class Solution {
  public:
    int solve(int i,vector<int> &coins, int sum,vector<vector<int>>&dp){
        if(i>=coins.size() || sum<0){
            return 1e9;
        }
        if(sum==0){
            return 0;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        
        int take= 1+ solve(i,coins,sum-coins[i],dp);
        int skip =solve(i+1,coins,sum,dp);
        
        return dp[i][sum] =min(take,skip);
    }
    int minCoins(vector<int> &coins, int sum) {
        // code here
        vector<vector<int>>dp(coins.size(),vector<int>(sum+1,-1));
        int ans= solve(0,coins,sum,dp);
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};