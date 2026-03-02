class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        map<int,int> mp;

        for(int i=0; i<trips.size();  i++) {

            mp[trips[i][1]] += trips[i][0];
            mp[trips[i][2]] -= trips[i][0]; 
        }

        int sum = 0;
        for(auto it = mp.begin(); it != mp.end(); it++) {

            sum += it->second;
            if(sum > capacity)
            return false;
        }

        return true;
    }
};