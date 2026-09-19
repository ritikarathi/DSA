class Solution {
public:
    bool solve(vector<int>& hand, int k,int i){
        int count=1;
        int next=hand[i]+1;
        hand[i]=-1;
        i++;
        while(count<k && i<hand.size()){
            if(next==hand[i]){
                next=hand[i]+1;
                hand[i]=-1;
                count++;
            }
            i++;
        }
        return count==k;
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if((hand.size()%groupSize)!=0){
            return false;
        }
        sort(hand.begin(),hand.end());
        for(int i=0; i<hand.size();i++){
            if(hand[i]>=0){
                if(!solve(hand,groupSize,i))
                return false;
            }
        }
        return true;
    }
};