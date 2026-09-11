class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        pair<int,int>prev;
        int n=speed.size();
        prev={speed[n-1],position[n-1]};
        int count=1;
        for(int i=n-2;i>=0;i--){
            if(speed[i]>prev.first || prev.second - position[i] <= distance){
                prev={prev.first,position[i]};
            }
            else{
                count++;
                prev={speed[i],position[i]};
            }
        }
        return count;
    }
};