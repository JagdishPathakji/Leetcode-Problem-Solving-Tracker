class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        
        int rows = moveTime.size();
        int cols = moveTime[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> distance(rows, vector<int>(cols,INT_MAX));
        vector<vector<bool>> explored(rows, vector<bool>(cols,false));
        
        distance[0][0] = 0;
        pq.push({0,{0,0}});
        int timer = 0;
        while(!pq.empty()) {

            int time = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;

            pq.pop();

            if(i == rows-1 and j == cols-1)
            return distance[i][j];

            if(explored[i][j])
            continue;

            explored[i][j] = 1;

            if(i-1 >= 0 and !explored[i-1][j]) {
                if(distance[i-1][j] > max(moveTime[i-1][j],distance[i][j]) + 1) {
                    distance[i-1][j] = max(moveTime[i-1][j],distance[i][j]) + 1;
                    pq.push({distance[i-1][j],{i-1,j}});
                }             
            }
            if(i+1 < moveTime.size() and !explored[i+1][j]) {
                if(distance[i+1][j] > max(moveTime[i+1][j],distance[i][j]) + 1) {
                    distance[i+1][j] = max(moveTime[i+1][j],distance[i][j]) + 1;
                    pq.push({distance[i+1][j],{i+1,j}});
                }
            }
            if(j-1 >= 0 and !explored[i][j-1]) {
                if(distance[i][j-1] > max(moveTime[i][j-1],distance[i][j]) + 1) {
                    distance[i][j-1] = max(moveTime[i][j-1],distance[i][j]) + 1;
                    pq.push({distance[i][j-1],{i,j-1}});
                }
            }
            if(j+1 < moveTime[i].size() and !explored[i][j+1]) {
                if(distance[i][j+1] > max(moveTime[i][j+1],distance[i][j]) + 1) {
                    distance[i][j+1] = max(moveTime[i][j+1],distance[i][j]) + 1;
                    pq.push({distance[i][j+1],{i,j+1}});
                }
            }
        }

        return distance[rows-1][cols-1];
    }
};