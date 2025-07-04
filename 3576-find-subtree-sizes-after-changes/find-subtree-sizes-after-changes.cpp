class Solution {
public:

    void buildgraph(vector<int> &parent, vector<vector<int>> &graph) {

        for(int i=0; i<parent.size(); i++) {
            if(parent[i] != -1) {
                graph[parent[i]].push_back(i);
            }
        }
    }

    void DFS(int node, vector<int> &parent, vector<vector<int>> &graph, string &s, unordered_map<char,int> &ancestors) {

        char ch = s[node];

        // If an ancestor with the same character s[node] exists, update parent[node] to point to that ancestor.
        // Uses unordered_map<char, int> to remember the latest node with a given character on the path from root.
        if(ancestors.count(ch)) {
            parent[node] = ancestors[ch];
        }

        int original = ancestors.count(ch) ? ancestors[ch] : -1;
        ancestors[ch] = node;

        // Apply DFS on the chilrens
        for(int child : graph[node]) {
            DFS(child,parent,graph,s,ancestors);
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

        /* Steps : 
        1. Build the graph
        2. Perform DFS and change the parent of each node to its immediate parent with same s[node] == s[parent]
        3. Build the new graph with new parents obtained in above DFS
        4. Find out the size of each subtree
        */        

        int n = parent.size();
        vector<int> ans(n,0); // answer to be returned
        vector<vector<int>> graph(n); // n vertices
        unordered_map<char,int> ancestors; // help to find out the immediate parent with same s[node] == s[parent] during DFS.

        buildgraph(parent,graph); // step 1
        DFS(0,parent,graph,s,ancestors); // step 2

        // re-initialize the graph to not override the previous information
        graph = vector<vector<int>>(n);
        buildgraph(parent,graph); // step 3
        findsize(0,graph,ans); // step 4

        return ans;
    }
};