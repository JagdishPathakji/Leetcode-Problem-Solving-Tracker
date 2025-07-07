class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        queue<int> q;
        vector<bool> visited(n,false);
        q.push(0);
        visited[0] = 1;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            for(int i=0; i<rooms[node].size(); i++) {
                if(!visited[rooms[node][i]]) {
                    visited[rooms[node][i]] = true;
                    q.push(rooms[node][i]);
                }
            }
        }

        for(int i=0; i<visited.size(); i++) {
            if(visited[i] == false)
            return false;
        }

        return true;
    }
};