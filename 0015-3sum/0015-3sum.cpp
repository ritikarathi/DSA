class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int p=0;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        while(p<nums.size()){
            if(p>0 && nums[p]==nums[p-1]){
                p++;
                continue;
            }
            int j = p + 1, k = nums.size() - 1;
            int n =0-nums[p];
            while(j<k){
                if(nums[j]+nums[k]<n){
                    j++;
                }
                else if(nums[j]+nums[k]>n){
                    k--;
                }
                else if(nums[k]+nums[j]==n){
                    ans.push_back({nums[p],nums[j],nums[k]});
                    
                    while(j<k && nums[j]==nums[j+1]){
                        j++;
                    }
                    while(j<k && nums[k]==nums[k-1]){
                        k--;
                    }
                    j++;
                    k--;
                    
                }
            } 
            p++;
            
        }
        return ans;
    }
};