class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size=0;
        int n=nums.size();
        int start,end,mid,index;
        vector<int>lis(n);
        lis[0]=nums[0];
        for(int i=1; i<n;i++){
            start=0,end=size,index=size+1;
            while(start<=end){
                mid=start+(end-start)/2;
                if(lis[mid]<nums[i]){
                    start=mid+1;
                }
                else if( lis[mid]==nums[i]){
                    index=mid;
                    break;
                }
                else {
                    index=mid;
                    end=mid-1;
                }
            }
            lis[index]=nums[i];
            size=max(size,index);
        }
        return size+1;
    }
};