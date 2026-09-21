class Solution {
public:
    int cutRod(vector<int>& price) {

        int n = price.size();

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            // Don't cut the rod
            dp[i] = price[i - 1];

            // Cut into two parts
            for (int j = 1; j < i; j++) {

                dp[i] = max(dp[i],
                            dp[j] + dp[i - j]);
            }
        }

        return dp[n];
    }
}; 
