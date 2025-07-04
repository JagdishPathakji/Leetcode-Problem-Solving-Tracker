class Solution {
public:

    void buildgraph(vector<int> &parent, vector<vector<int>> &graph) {

        for(int i=0; i<parent.size(); i++) {
            if(parent[i] != -1) {
                graph[parent[i]].push_back(i);
            }
        }
    }

    void dfs(int node, vector<int> &parent, vector<vector<int>> &graph, string &s, unordered_map<char,int> &ancestors) {

        char ch = s[node];

        if(ancestors.count(ch)) {
            parent[node] = ancestors[ch];
        }

        int original = ancestors.count(ch) ? ancestors[ch] : -1;
        ancestors[ch] = node;

        for(int child : graph[node]) {
            dfs(child,parent,graph,s,ancestors);
        }        

        if(original == -1) {
            ancestors.erase(ch);
        }
        else {
            ancestors[ch] = original; 
        }
    }

    int findsize(int node, vector<vector<int>> &graph, vector<int> &ans) {

        int size = 1;

        for(int child : graph[node]) {
            size += findsize(child,graph,ans);
        }
        ans[node] = size;
        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();
        vector<vector<int>> graph(n);
        vector<int> ans(n);
        unordered_map<char,int> ancestors;

        buildgraph(parent,graph);
        dfs(0,parent,graph,s,ancestors);

        graph = vector<vector<int>>(n);
        buildgraph(parent,graph);
        findsize(0,graph,ans);
        
        return ans;
    }
};