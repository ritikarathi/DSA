class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        vector<int>res;
        int maxi=0;
        int prev=-1;
        for(int i=0; i<s.size();i++){
            maxi=max(maxi,mp[s[i]]);
            if(maxi==i){
                res.push_back(maxi-prev);
                prev=maxi;
            }
        }
        return res;
    }
};