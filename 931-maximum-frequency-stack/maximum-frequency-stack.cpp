class FreqStack {
public:

    unordered_map<int,int> mp;
    priority_queue<pair<int,pair<int,int>>> pq;
    int timer = 0;

    FreqStack() {
        
    }
    
    void push(int val) {
        mp[val]++;
        timer++;
        pq.push({mp[val],{timer,val}});
    }
    
    int pop() {
        int element = pq.top().second.second;
        mp[element]--;
        pq.pop();
        return element;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */