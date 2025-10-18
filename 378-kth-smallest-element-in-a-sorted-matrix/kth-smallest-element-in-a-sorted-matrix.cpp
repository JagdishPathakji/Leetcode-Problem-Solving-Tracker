class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<pair<int,pair<int,int>>> v;
        for(int i=0; i<cols; i++) 
        v.push_back({matrix[0][i],{0,i}});

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq(v.begin(),v.end());

        int ans,i,j;
        while(k--) {
            
            auto node = pq.top();
            pq.pop();

            ans = node.first;
            i = node.second.first;
            j = node.second.second;

            if(i+1 < rows) {
                pq.push({matrix[i+1][j],{i+1,j}});
            }
        }

        return ans;
    }
};