class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        
        vector<int>ans(startTime.size()+1,0);
        ans[0]=startTime[0];
        for(int i=1; i<startTime.size();i++){
            ans[i]=startTime[i]-endTime[i-1];
        }
        ans[startTime.size()]= eventTime-endTime[endTime.size()-1];

        int start=0,end=0;
        int maxi=0;
        int sum=0;
        while(end<ans.size()){
            sum+=ans[end];
            while(end-start+1>k+1){
                sum-=ans[start];
                start++;
            }
            maxi=max(maxi,sum);
            end++;
        }
        return maxi;

    }
};