class Solution {
public:
    int find(vector<vector<int>>& rides,int time,int n){
        
        int start=0,end=rides.size()-1,mid,res=rides.size();
        while(start<=end){
            mid= start+(end-start)/2;
            if(rides[mid][0]>=time){
                res=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return res;
    }
    long long solve(int i, int n,vector<vector<int>>& rides,vector<long long>&dp){
        if(i>=rides.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long skip =solve(i+1,n,rides,dp);
        int j=find(rides,rides[i][1],n);
        long long take =rides[i][1]-rides[i][0]+rides[i][2]+solve(j,n,rides,dp);
        return dp[i]=max(take,skip);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        vector<long long>dp(rides.size(),-1);
        return solve(0,n,rides,dp);
    }
};