class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0; i<tokens.size();i++){
            string x=tokens[i];
            if(x!="*" && x!="/" && x!="+" && x!="-" ){
               int n=stoi(tokens[i]);
                st.push(n);
            }
            else{
                int second =st.top();
                st.pop();
                int first =st.top();
                st.pop();

                if(x=="*"){
                    st.push(first*second);
                }
                else if(x=="-"){
                    st.push(first-second);
                }
                else if(x=="+"){
                    st.push(first+second);
                }
                else if(x=="/"){
                    st.push(first/second);
                } 
            }
        }
        return st.top();
    }
};