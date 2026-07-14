class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>ans(speed.size());
        for(int i=0; i<speed.size();i++){
            ans[i]={position[i],speed[i]};
        }
        sort(ans.begin(),ans.end());
        vector<double>time(ans.size());
        for(int i=0; i<ans.size();i++){
            time[i]= (double)(target-ans[i].first)/ans[i].second;
        }
        int chunks=0;
        double maxi=0;
        for(int i=time.size()-1;i>=0;i--){
                if(time[i]>maxi){
                    maxi=time[i];
                    chunks++;
                }
        }
        return chunks;
        
    }
};