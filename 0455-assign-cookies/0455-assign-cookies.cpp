class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count=0;
        int n=min(g.size(),s.size());
        int first=0;
        int second=0;
        while(first<g.size() && second<s.size()){
            if(g[first]<=s[second]){
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