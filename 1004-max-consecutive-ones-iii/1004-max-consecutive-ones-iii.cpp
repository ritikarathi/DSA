class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0,end=0;
        vector<int>freq(2,0);
        int x=0;
        int count=0;
        while(end<nums.size()){
            if(nums[end]==0){
                freq[0]++;
                x++;
            }
            else{
                freq[1]++;
            }
            while(x>k){
                if(nums[start]==0){
                    x--;
                }
                freq[nums[start]]--;
                start++;
            }
            count=max(count,end-start+1);
            end++;
        }
        return count;
    }
};