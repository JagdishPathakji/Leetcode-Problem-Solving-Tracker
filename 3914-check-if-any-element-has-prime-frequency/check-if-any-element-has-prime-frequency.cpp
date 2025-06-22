class Solution {
public:

    bool isprime(int n) {
        if(n <= 1)
        return 0;
        if(n == 2)
        return 1;

        for(int i=2; i*i<=n; i++) {
            if(n%i == 0)
            return 0;
        }

        return 1;
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }

        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(isprime(it->second))
            return true;
        }

        return false;
    }
};