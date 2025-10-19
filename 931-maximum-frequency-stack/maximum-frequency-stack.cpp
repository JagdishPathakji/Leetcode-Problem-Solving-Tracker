class FreqStack {
public:

    unordered_map<int,int> mp;
    stack<int> st;

    FreqStack() {
        
    }
    
    void push(int val) {
        mp[val]++;
        st.push(val);
    }
    
    int pop() {
        
        vector<int> v;

        int maxFreq = INT_MIN;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(maxFreq < it->second) {
                maxFreq = it->second;
            }
        }

        while(mp[st.top()] != maxFreq) {
            v.push_back(st.top());
            st.pop();
        }

        int element = st.top();
        mp[element]--;
        st.pop();

        int j = v.size()-1;
        while(j >= 0) {
            st.push(v[j]);
            j--;
        }

        return element;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */