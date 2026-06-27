class MinStack {
public:
    stack<int>st,mst;
    MinStack() {
        //stack<int>st,mst;
    }
    
    void push(int value) {
        st.push(value);
        if(mst.empty() || mst.top()>=value){
            mst.push(value);
        }
    }
    
    void pop() {
        if(!st.empty() && !mst.empty() && st.top()==mst.top()){
            st.pop();
            mst.pop();
        }
        else if(!st.empty()){
            st.pop();
        }
    }
    
    int top() {
       return st.top();
    }
    
    int getMin() {
      return mst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */