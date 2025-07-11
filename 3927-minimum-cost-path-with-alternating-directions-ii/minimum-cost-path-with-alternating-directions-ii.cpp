class Solution {
public:
    long long minCost(int n, int m, vector<vector<int>>& waitCost) {

        /*
        Assumes:
        1. Each cell (i, j) can be visited only once.
        2. There is one best cost to reach each cell.

        ⚠️ Problem:
        In your logic:
        time % 2 == 0: You wait and pay waitCost[i][j]
        time % 2 == 1: You move
        Actually reaching a cell (i, j) at even time step vs odd leads to very different behavior and costs.
        But you're treating both as the same — and that's incorrect.
        */

        /*
        priority_queue<pair<pair<long long,long long>,pair<long long, long long>>, vector<pair<pair<long long, long long>,pair<long long, long long>>>, greater<pair<pair<long long, long long>,pair<long long, long long>>>> pq;
        pq.push({{1,1},{0,0}});

        vector<vector<bool>> visited(n,vector<bool>(m,false));
        vector<vector<int>> distance(n,vector<int>(m,INT_MAX));

        while(!pq.empty()) {

            int cost = pq.top().first.first;
            int time = pq.top().first.second;
            int i = pq.top().second.first;
            int j = pq.top().second.second;

            pq.pop();

            if(visited[i][j]) {
                continue;
            }

            visited[i][j] = true;

            if(time%2 == 0) {
                int newCost = cost + waitCost[i][j];
                if(newCost < distance[i][j]) {
                    visited[i][j] = false;
                    distance[i][j] = newCost;
                    pq.push({{newCost,time+1},{i,j}});
                }
            }
            else {
                if(i+1 < n) {
                    int newCost = cost + (i+2) * (j+1);
                    if(newCost < distance[i+1][j]) {
                        distance[i+1][j] = newCost;
                        pq.push({{newCost,time+1},{i+1,j}});
                    }
                }
                if(j+1 < m) {
                    int newCost = cost + (i+1) * (j+2);
                    if(newCost < distance[i][j+1]) {
                        distance[i][j+1] = newCost;
                        pq.push({{newCost,time+1},{i,j+1}});
                    }
                }
            }
        }

        return distance[n-1][m-1];
        */

        
        /*
        Correct Way : 
        For each cell (i, j), you can:
        Track the best cost to reach it at even time → distance[i][j][0]
        Track the best cost to reach it at odd time → distance[i][j][1]
        Track visited status independently for even and odd time.
        This way, we preserve Dijkstra's greedy correctness, while allowing the same cell 
        to be visited twice — once on an even time  step, once on an odd time step — if the cost is better.
        */

        priority_queue<pair<pair<long long, long long>,pair<long long, long long>>, vector<pair<pair<long long, long long>,pair<long long, long long>>>, greater<pair<pair<long long, long long>,pair<long long, long long>>> > pq;
        pq.push({{1,1},{0,0}}); // Start from (0, 0) at time = 1, cost = 1
        vector<vector<vector<long long>>> distance(n, vector<vector<long long>>(m, vector<long long>(2, LLONG_MAX)));
// 2 sized 3rd dimension, one for odd time and other for even time.
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(2, false)));
// 2 sized 3rd dimension, one for odd time and other for even time.

        /* 
        In case of distance and visited 3d array
        // 0 means even time step.
        // 1 means odd time step.
        */
        distance[0][0][1] = 1;

        while(!pq.empty()) {

            long long cost = pq.top().first.first;
            long long time = pq.top().first.second;
            int i = pq.top().second.first;
            int j = pq.top().second.second;

            pq.pop();

            if(visited[i][j][time%2/*if time is odd/even and is visited then skip*/])
            continue;
            
            visited[i][j][time%2] = true; // make it visited for whatever the time (odd/even)

            if(time % 2 == 0) {
                long long newCost = cost + waitCost[i][j];
                if(newCost < distance[i][j][1]) { // \U0001f448 pushing to time + 1 (ODD)
                    distance[i][j][1] = newCost;
                    pq.push({{newCost,time+1},{i,j}});
                }
            }
            else {
                if(i + 1 < n) {
                    long long newCost = cost + (i+2) * (j+1);
                    if(newCost < distance[i+1][j][0]) {// \U0001f448 pushing to time + 1 (EVEN)
                        distance[i+1][j][0] = newCost;
                        pq.push({{newCost,time+1},{i+1,j}});
                    }
                }
                if(j + 1 < m) {
                    long long newCost = cost + (i+1) * (j+2);
                    if(newCost < distance[i][j+1][0]) { // \U0001f448 pushing to time + 1 (EVEN)
                        distance[i][j+1][0] = newCost;
                        pq.push({{newCost,time+1},{i,j+1}});
                    }
                }
            }
        }

        return min(distance[n-1][m-1][0],distance[n-1][m-1][1]);
    }
};