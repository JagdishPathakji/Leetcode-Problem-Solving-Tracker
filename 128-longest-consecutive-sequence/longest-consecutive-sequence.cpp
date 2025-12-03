class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // if(nums.size() == 0)
        // return 0;

        // sort(nums.begin(),nums.end());

        // int num = nums[0];
        // int ans = 1;
        // int real = 1;

        // for(int i=1; i<nums.size(); i++) {
        //     if(nums[i] == num) continue;
        //     if(nums[i]-num == 1) {
        //         ans++;
        //     }
        //     else {
        //         real = max(real,ans);
        //         ans = 1;
        //     }
            
        //     num = nums[i];
        // }

        // real = max(real,ans);
        // return real;


        // O(n) ~ time and O(n) ~ space
        unordered_map<int,bool> mp;

        for(int i=0; i<nums.size(); i++) 
        mp[nums[i]] = true;

        int ans = 0;
        int real = 0;
        for(auto it = mp.begin(); it != mp.end(); it++) {

            if(mp.find(it->first-1) == mp.end()) {

                ans = 1;

                int element = it->first;
                while(mp.find(element+1) != mp.end()) {
                    ans = ans + 1;
                    element = element + 1;
                }

                real = max(real,ans);
                ans = 0;
            }
        }

        return real;
    }
};