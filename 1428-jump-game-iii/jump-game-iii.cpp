class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        queue<int> q;
        q.push(start);

        vector<bool> visited(arr.size(),false);
        visited[start] = true;

        while(!q.empty()) {

            int idx = q.front();
            q.pop();

            if(arr[idx] == 0)
            return true;

            if(idx+arr[idx] < arr.size()) {
                if(visited[idx+arr[idx]] == false) {
                    q.push(idx+arr[idx]);
                    visited[idx+arr[idx]] = true;
                }
            }

            if(idx-arr[idx] >= 0) {
                if(visited[idx-arr[idx]] == false) {
                    q.push(idx-arr[idx]);
                    visited[idx-arr[idx]] = false;
                }
            }
        }

        return false;
    }
};