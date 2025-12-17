class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> ans(n+1);

        for(int i=0; i<=n; i++) {
            int num = i;
            int count = 0;
            while(num != 0) {
                num = (num & (num-1));
                count++;
            }
            ans[i] = count;
        }

        return ans;
    }
};