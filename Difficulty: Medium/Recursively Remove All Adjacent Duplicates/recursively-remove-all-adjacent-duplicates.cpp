class Solution {
  public:
    void solve(string &s,bool &flag){
        if(flag==false){
            return;
        }
        int x=1;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                x=0;
                break;
            }
        }
        if(x!=0){
            flag=false;
            return;
        }
        string ans="";
        int i=0;
        while(i<s.size()){
            if(i<s.size()-1 && s[i]==s[i+1]){
                char ch =s[i];
                while(i<s.size() && s[i]==ch){
                    i++;
                }
            }
            else{
                ans.push_back(s[i]);
                i++;
            }
        }
        s=ans;
        solve(s,flag);
    }
    string removeUtil(string &s) {
        // code here
        bool flag=true;
        solve(s,flag);
        return s;
    }
};