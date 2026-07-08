class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        if(s.size()>t.size()){
            return false;
        }
        int n=s.size();
        int m =t.size();
        vector<int>pref(n+1,m);
        vector<int>suff(n+1,-1);
        pref[0]=0;
        int j=0;
        for(int i=0;i<n;i++){
            while(j<t.size() && s[i]!=t[j]){
                j++;
            }
            if(j==m){
                break;
            }
            pref[i+1]=j+1;
            j++;
        }
        if(pref[n]!=m){
            return true;
        }
        j=m-1;
        suff[n]=m;
        for(int i=n-1;i>=0;i--){
            while(j>=0 && s[i]!=t[j]){
                j--;
            }
            if(j<0){
                break;
            }
            suff[i]=j;
            j--;
        }
        for(int i=0; i<n;i++){
            if(pref[i]<suff[i+1]){
                return true;
            }
        }
        return false;
    }
};