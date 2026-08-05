class Solution {
public:
    bool solve(int i, int target,vector<int>& nums,vector<vector<int>>&dp){
        if(target<0 || i>=nums.size()){
            return false;
        }
        if(target==0){
            return true;
        }
        if(dp[i][target]!=-1){
            return dp[i][target] ;
        }
        int take=solve(i+1,target-nums[i],nums,dp);
        int skip=solve(i+1,target,nums,dp);
        return dp[i][target] =(skip || take);
        
    }
    bool canPartition(vector<int>& nums) {
        int target=0;
        for(int i=0;i<nums.size();i++){
            target+=nums[i];
        }
        if(target%2!=0){
            return false;
        }
        target=target/2;
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        return solve(0,target,nums,dp);
    }
};