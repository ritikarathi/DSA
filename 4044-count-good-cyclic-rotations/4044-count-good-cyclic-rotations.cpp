class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        int n=nums.size();
        
        long long l=0;
        for(int i=0;i<(n/2);i++){
            l+=nums[i];
        }
        int sol=0;
        for(int i=(n/2);i<n;i++){
            
            long long r=total-l;
            if(l!=r){
                sol++;
            }
            l+=nums[i];
            l-=nums[i-n/2];
            
        }
        return sol;
    }
};