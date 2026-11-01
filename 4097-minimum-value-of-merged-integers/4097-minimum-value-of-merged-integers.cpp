class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int i=0;
        int mini=INT_MAX;

        while(i<nums.size()-1){
            string s="";
            s+=to_string(nums[i]);
            s+=to_string(nums[i+1]);
            int n=stoi(s);
            mini=min(mini,n);
            i=i+2;
        }
        return mini;
    }
};