class Solution {
public:
    int solve(vector<int>& cardPoints, int k){
        int sum=0;
        int mini=INT_MAX;
        int start=0, end=0;
        while(end<cardPoints.size()){
            sum+=cardPoints[end];
            while((end-start+1) >k){
                sum-=cardPoints[start];
                start++;
            }
            if(end-start+1 ==k){
                mini=min(mini,sum);
            }
            end++;
        }
        return mini;
    }
    int maxScore(vector<int>& cardPoints, int k) {
        int total=0;
        int n=cardPoints.size();
        for(int i=0; i<cardPoints.size();i++){
            total+=cardPoints[i];
        }
        int rest = solve(cardPoints,n-k);
        return total - rest;
    }
};