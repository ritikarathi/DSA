

class Solution {
  public:
    // Function to find the largest number after k swaps.
    void solve(int idx,string& s, int k,string& ans ){
        if(k==0 || idx>=s.size()){
            ans=max(ans,s);
            return;
        }
        char mx=s[idx];
        for(int i=idx+1; i<s.size();i++){
            mx=max(mx,s[i]);
        }
        if(mx==s[idx]){
            solve(idx+1,s,k,ans);
            return;
        }
        for(int i=s.size()-1; i>idx;i--){
            if(s[i]==mx){
                swap(s[i],s[idx]);
                ans=max(ans,s);
                solve(idx+1,s,k-1,ans);
                swap(s[i],s[idx]);
            }
        }
    }
    string findMaximumNum(string& s, int k) {
        // code here.
        string ans=s;
        solve(0,s,k,ans);
        return ans;
    }
};