class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> binarysearch(n,INT_MAX);

        binarysearch[0] = nums[0];
        int ans = 0;

        for(int i=1; i<n; i++) {

            int element = nums[i];
            int index = ans + 1;

            int start = 0;
            int end = ans;

            while(start <= end) {

                int mid = start + (end - start)/2;

                if(binarysearch[mid] < element) {
                    start = mid + 1;
                }
                else if(binarysearch[mid] == element) {
                    index = mid;
                    break;
                }
                else {
                    index = mid;
                    end = mid - 1;
                }
            }

            binarysearch[index] = min(binarysearch[index],element);
            ans = max(ans,index);
            
        }
        
        return ans + 1;
    }
};