class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc] == color)
        return image;

        queue<pair<int,int>> q;
        int start = image[sr][sc];
        image[sr][sc] = color;
        q.push({sr,sc});

        int rarr[] = {0,0,1,-1};
        int carr[] = {1,-1,0,0};

        while(!q.empty()) {

            auto node = q.front();
            q.pop();
            int r = node.first;
            int c = node.second;

            for(int i=0; i<4; i++) {
                int newr = rarr[i] + r;
                int newc = carr[i] + c;

                if(newr >=0 && newc >= 0 && newr < image.size() && newc < image[r].size() && image[newr][newc] == start) {
                    image[newr][newc] = color;
                    q.push({newr,newc});
                }
            }
        }

        return image;
    }
};