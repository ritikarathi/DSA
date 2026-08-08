class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m=potions.size();
        sort(potions.begin(),potions.end());
        vector<int>pairs(spells.size(),0);
        for(int i=0;i<spells.size();i++){
            int left=0;
            int right=m-1;
            int mid=0,ans=m;
            while(left<=right){
                mid=left+(right-left)/2;
                long long prod = (long long)potions[mid] * (long long)spells[i];
                if(prod>=success){
                    right=mid-1;
                    ans=mid;
                }
                else{
                    left=mid+1;
                }
            }
            pairs[i]=m-ans;
        }
        return pairs;
    }
};