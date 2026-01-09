class Solution {
public:
    
    int dp[501][501];
    int find(vector<int> &nums1, vector<int> &nums2, int i, int j) {

        if(i >= nums1.size() || j >= nums2.size())
        return -1e9;

        if(dp[i][j] != -1e9)
        return dp[i][j];

        int val = nums1[i] * nums2[j];
        int take_i_j = (val) + find(nums1,nums2,i+1,j+1);
        int take_i = find(nums1,nums2,i+1,j);
        int take_j = find(nums1,nums2,i,j+1);
        int skip_i_j = find(nums1,nums2,i+1,j+1);

        return dp[i][j] = max({val,take_i_j,take_i,take_j,skip_i_j});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();

        for(int i=0; i<501; i++) {
            for(int j=0; j<501; j++) {
                dp[i][j] = -1e9;
            }
        }

        return find(nums1,nums2,0,0);
    }
};
