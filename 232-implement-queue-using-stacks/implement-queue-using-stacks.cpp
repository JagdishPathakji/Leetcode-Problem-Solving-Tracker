class MyQueue {
public:

    stack<int> st;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        stack<int> temp;
        while(!st.empty()) {
            temp.push(st.top());
            st.pop();
        }

        int x = temp.top();
        temp.pop();

        while(!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }

        return x;
    }   
    
    int peek() {
        stack<int> temp;
        while(!st.empty()) {
            temp.push(st.top());
            st.pop();
        }

        int x = temp.top();

        while(!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }

        return x;
    }
    
    bool empty() {
        return st.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */