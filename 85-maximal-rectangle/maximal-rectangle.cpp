class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> nser(n,n);
        vector<int> nsel(n,-1);
        stack<int> st;

        for(int i=0; i<n; i++) {

            while(!st.empty() and (heights[st.top()] > heights[i])) {
                nser[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        st = stack<int>();

        for(int i=n-1; i>=0; i--) {

            while(!st.empty() and (heights[st.top()] > heights[i])) {
                nsel[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int area = 0;
        for(int i=0; i<n; i++) {
            int ans = (nser[i]-nsel[i]-1)*heights[i];
            if(ans > area) {
                area = ans;
            }
        }

        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> v(cols,0);
        int ans = 0;

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(matrix[i][j] == '0') {
                    v[j] = 0;
                }
                else {
                    v[j]++;
                }
            }
            ans = max(ans,largestRectangleArea(v));
        }

        return ans;
    }
};