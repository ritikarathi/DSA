class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>> dp(m,vector<int>(n,1e9));
        vector<vector<int>>a={{-1,1},{-1,0},{-1,-1}};

        for(int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<3;k++){
                    int u=i+a[k][0];
                    int v=j+a[k][1];
                    if(u>=0 && u<m && v>=0 && v<n){
                        dp[i][j]=min(dp[u][v]+matrix[i][j],dp[i][j]);
                    }
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[m-1][i]);
        }
        return ans;
    }
};