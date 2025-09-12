class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(color == image[sr][sc])
        return image;
        
        int initialColor = image[sr][sc];

        queue<pair<int,int>> q;
        q.push({sr,sc});

        while(!q.empty()) {

            auto node = q.front();
            q.pop();

            int i = node.first;
            int j = node.second;

            if(image[i][j] == initialColor)
            image[i][j] = color;

            if(i+1 < image.size() && image[i+1][j] == initialColor) 
            q.push({i+1,j});

            if(i-1 >= 0 and image[i-1][j] == initialColor)
            q.push({i-1,j});

            if(j+1 < image[i].size() and image[i][j+1] == initialColor)
            q.push({i,j+1});

            if(j-1 >= 0 and image[i][j-1] == initialColor)
            q.push({i,j-1});
        }

        return image;
    }
};