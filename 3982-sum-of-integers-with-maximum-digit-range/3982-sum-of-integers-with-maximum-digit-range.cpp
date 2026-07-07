class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int ans=0;
        int res=0;
        for(int i=0; i<nums.size();i++){
            int x=nums[i];
            string s =to_string(x);
            int maxi=INT_MIN;
            int mini =INT_MAX;
            for(int j=0; j<s.size();j++){
                maxi=max(maxi,s[j]-'0');
                mini=min(mini,s[j]-'0');
            }
            if(ans<maxi-mini){
                ans=maxi-mini;
                res=nums[i];
            }
            else if(ans==(maxi-mini)){
                res+=nums[i];
            }
        }
        return res;
    }
};