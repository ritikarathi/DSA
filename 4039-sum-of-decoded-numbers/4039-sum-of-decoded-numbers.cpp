class Solution {
public:
    long long solve(long long x,long long y,long long mod){
        long long ans=1;
        while(y>0){
            if(y%2==1){
                ans=(ans*x)%mod;
            }
            x=(x*x) % mod;
            y=y/2;
        }
        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        long long mod = 1000000007;
        long long sum=0;

        for(int i=0; i<nums.size();i++){
            long long width=nums[i]%10;
            long long d =nums[i]/10;
            
            string st = to_string(d);
            long divisor =1;
            for(int i=0; i<st.size()-width;i++){
                divisor *=10;
            }
            long long x =d/divisor;
            long long y= d%divisor;
            long long power =solve(x,y,mod);
            sum = (sum+power)%mod;
        }
        return sum;

    }
};