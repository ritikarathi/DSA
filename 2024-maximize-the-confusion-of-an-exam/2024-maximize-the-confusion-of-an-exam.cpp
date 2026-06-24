class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        unordered_map<char,int>mp;
        int start=0,end=0;
        int t =0,f=0;
        int count=0;
        while(end<answerKey.size()){
            if(answerKey[end]=='T'){
                t++;
            }
            else{
                f++;
            }
            while(min(t,f)>k){
                if(answerKey[start]=='T'){
                    t--;
                }
                else{
                    f--;
                }
                start++;
            }

            count=max(count,end-start+1);
            end++;
        }
        return count;
    }
};