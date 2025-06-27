class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        vector<double> ans;

        int i = 0;
        int j = 0;
        
        vector<int> s;

        while(j < nums.size()) {
            
            auto lb = lower_bound(s.begin(),s.end(),nums[j]);
            s.insert(lb,nums[j]);

            if(j-i+1 == k) {
                if(k%2 == 1) {
                    ans.push_back((double)s[s.size()/2]);
                }
                else {
                    ans.push_back((double)((double)s[s.size()/2]+(double)s[s.size()/2-1])/2);
                }
                auto remove = lower_bound(s.begin(),s.end(),nums[i]);
                s.erase(remove);
                i++;
            }

            j++;
        }
    
        return ans;
    }
};