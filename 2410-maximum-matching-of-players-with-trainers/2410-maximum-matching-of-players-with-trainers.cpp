class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int count=0;
        int first=0;
        int second=0;
        while(first<players.size() && second<trainers.size()){
            if(players[first]<=trainers[second]){
                count++;
                first++;
                second++;
            }
            else{
                second++;
            }
        }
        return count;
    }
};