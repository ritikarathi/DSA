class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size();i++){
            mp[nums[i]]++;
        }
        int i=1;
        while(i<nums.size()){
            while(i<nums.size() && nums[i]==nums[i-1]){
                mp[nums[i]]--;
                i++;
            }
            i++;
        }
        int count=0;
        for(auto it = mp.begin(); it!=mp.end(); it++){
            if(it->second==1){
                count++;
            }
        }
        return count;
    }
};