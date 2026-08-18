class Solution {
  public:
    int solve(int i,string &digits,vector<int>&dp){
        if(i>=digits.size()){
            return 1;
        }
        if(digits[i]=='0'){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ways=solve(i+1,digits,dp);
        
        if(i+1<digits.size()){
            int num=(digits[i]-'0')*10+(digits[i+1]-'0');
            if(num>=10 && num<=26){
                ways+=solve(i+2,digits,dp);
            }
        }
        return dp[i]=ways;
        
    }
    int countWays(string &digits) {
        // Code here
        vector<int>dp(digits.size(),-1);
        return solve(0,digits,dp);
    }
};