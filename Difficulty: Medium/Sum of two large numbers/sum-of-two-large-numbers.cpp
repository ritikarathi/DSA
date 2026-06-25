class Solution {
  public:
    string findSum(string &s1, string &s2) {
        // Your code goes here
        int i=s1.size()-1,j=s2.size()-1,carry=0;
        string ans="";
        while(i>=0 || j>=0 || carry){
            int sum =carry;
            if(i>=0){
                sum+=s1[i]-'0';
            }
            if(j>=0){
                sum+=s2[j]-'0';
            }
            ans.push_back((sum%10)+'0');
            carry =sum/10;
            i--;j--;
        }
        reverse(ans.begin(),ans.end());
        i=0;
        while(i<ans.size()-1 && ans[i]=='0'){
            i++;
        }
        return ans.substr(i);
    }
};