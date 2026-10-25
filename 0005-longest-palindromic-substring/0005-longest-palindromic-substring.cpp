class Solution {
public:
    bool isPalindrome(int i, int j, string&s, vector<vector<int>>&dp){
        if(i>=j){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]!=s[j]){
            return false;
        }
        return dp[i][j]=isPalindrome(i+1,j-1,s,dp);
    }
    string longestPalindrome(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        int maxlen=0;
        int idx=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                int len=0;
                if(isPalindrome(i,j,s,dp)){
                    len=j-i+1;
                }
                if(len>maxlen){
                    maxlen=len;
                    idx=i;
                }
            }
        }
        return s.substr(idx,maxlen);
    }
};