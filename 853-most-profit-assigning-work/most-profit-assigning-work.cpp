class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        vector<pair<int,int>> combine;
        for(int i=0; i<difficulty.size(); i++) {
            combine.push_back({profit[i],difficulty[i]});
        }

        sort(combine.begin(),combine.end());
        sort(worker.begin(),worker.end());

        int maxprofit = 0;
        int i = worker.size()-1;
        int j = combine.size()-1;

        while(i >= 0) {
            while(j >= 0 && combine[j].second > worker[i]) {
                j--;
            }
            if(j < 0) 
            break;
            maxprofit += combine[j].first;
            i--;
        }

        return maxprofit;
    }
};