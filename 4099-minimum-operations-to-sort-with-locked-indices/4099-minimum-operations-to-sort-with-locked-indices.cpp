class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n=nums.size();
        int op=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                if(nums[j]>nums[j+1]){
                    if(locked[j]==1){
                        if(k==0) return -1;
                        k--;
                        locked[j]=0;
                        op++;
                    }
                    if(locked[j+1]==1){
                        if(k==0) return -1;
                        k--;
                        op++;
                        locked[j+1]=0;
                    }
                    swap(nums[j],nums[j+1]);
                    op++;
                }
            }
        }
        return op;
    }
};