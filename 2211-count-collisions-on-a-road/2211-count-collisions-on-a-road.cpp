class Solution {
public:
    int countCollisions(string directions) {
        int r=0,l=0;
        for(int i=0; i<directions.size();i++){
            if(directions[i]=='L'){
                l++;
            }
            else if(directions[i]=='R'){
                r++;
            }
        }
        int i=0;
        while(i<directions.size() && directions[i]=='L'){
            l--;
            i++;
        }
        i=directions.size()-1;
        while(i>=0 && directions[i]=='R'){
            r--;
            i--;
        }
        return r+l;

    }
};