class StockSpanner {
public:

    vector<int>ans;
    vector<int>idx;
    stack<int>st;
    int i;
    StockSpanner() {
        i=0;
    }
    
    int next(int price) {

        idx.push_back(price);

        if(st.empty()){
            ans.push_back(1);
            st.push(0);
        }
        else{
            while(!st.empty() && idx[st.top()]<=price){
                st.pop();
            }
            if(st.empty())
                ans.push_back(i + 1);
            else
                ans.push_back(i - st.top());
            st.push(i);
        }
        i++;
        return ans.back();
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */