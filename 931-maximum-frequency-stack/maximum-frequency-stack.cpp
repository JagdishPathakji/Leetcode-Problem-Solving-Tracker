class FreqStack {
public:

    struct cmp {
        
        bool operator()(const pair<int,pair<int,int>> a, const pair<int,pair<int,int>> b) {
            if(a.first != b.first)
            return a.first < b.first;

            return a.second.first < b.second.first;
        }
    };

    unordered_map<int,int> mp;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, cmp> pq;
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