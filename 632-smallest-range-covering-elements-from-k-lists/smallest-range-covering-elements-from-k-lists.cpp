class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        vector<int> ans(2);
        ans[0] = -1000000;
        ans[1] = 1000000;
        vector<pair<int,pair<int,int>>> temp;
        int max = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            temp.push_back({nums[i][0],{i,0}});
            max = max < nums[i][0] ? nums[i][0] : max;
        }

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq(temp.begin(),temp.end());

        while(!pq.empty()) {

            int min = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;

            
            if((max-min) < (ans[1]-ans[0])) {
                ans[0]  = min;
                ans[1] = max;
            }

            pq.pop();
            if(j+1 < nums[i].size()) {
                pq.push({nums[i][j+1],{i,j+1}});
                if(max < nums[i][j+1]) {
                    max = nums[i][j+1];
                }
            }
            else {
                break;
            }

        }
        
        return ans;
    }
};