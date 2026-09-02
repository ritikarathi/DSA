class Solution {
public:
    static bool mycomparator(pair<int,int>p1 , pair<int,int>p2){
        return p1.second>p2.second;

       // return false;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>>vec;
        for(auto it =mp.begin(); it!=mp.end(); it++){
            vec.push_back({it->first,it->second});
        }
        sort(vec.begin(),vec.end(),mycomparator);

       
        vector<int>v;
        for(int i=0; i<k;  i++){
            v.push_back(vec[i].first);
        }
        return v;
    }
};