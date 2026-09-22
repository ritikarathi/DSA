class Solution {
public:
    int solve(int i, string  &s, vector<int>&dp){
        if(i==s.size()){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long ways=0;
        if(s[i]=='*'){
            ways+= 9LL*solve(i+1,s,dp);
        }
        else if(s[i]!='0'){
            ways+= solve(i+1,s,dp); 
        }

        
        
        if(i+1<s.size()){
            if(s[i+1]=='*'){
                if(s[i]=='1'){
                    ways+= 9LL* solve(i+2,s,dp);
                }
                else if(s[i]=='2'){
                    ways+= 6LL* solve(i+2,s,dp);
                }
                else if(s[i]=='*'){
                    ways+=15LL*solve(i+2,s,dp);
                }
                
            }
            else{
                if(s[i]=='*'){
                    if((s[i+1]-'0')>=0 && (s[i+1]-'0')<7){
                        ways+= 2LL*solve(i+2,s,dp);
                    }
                    else{
                        ways+= solve(i+2,s,dp);
                    }
                    
                }
                else{
                    int n =(s[i]-'0')*10+ (s[i+1]-'0');
                    if(n>=10 && n<27){
                        ways+=solve(i+2,s,dp);
                    } 
                }
            }
        }
        
        return dp[i]= ways %1000000007;


    }
    int numDecodings(string s) {
        vector<int>dp(s.size(),-1);
        return solve(0,s,dp);
    }
};