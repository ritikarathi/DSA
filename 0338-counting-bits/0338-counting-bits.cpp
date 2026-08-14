class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0; i<=n;i++){
            int sum=0;
            int n=i;
            while(n!=0){
                sum+=n%2;
                n=n/2;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};