class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        
        
        unordered_map<char,int> mp;
        for(int i=0; i<tasks.size(); i++) {
            mp[tasks[i]]++;
        }
        
        // create priority-queue (min-heap)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            pq.push({0,it->first});
        }
        
        int timer = 0;
        while(!pq.empty()) {
            
            auto peek = pq.top();
            pq.pop();
            
            int reqtimer = peek.first;
            char task = peek.second;
            
            if(timer < reqtimer)
            timer = reqtimer;

            mp[task]--;
            if(mp[task] != 0) {
                pq.push({reqtimer+k+1,task});   
            }
            
            timer++;
        }
        
        return timer;
    
    }
};