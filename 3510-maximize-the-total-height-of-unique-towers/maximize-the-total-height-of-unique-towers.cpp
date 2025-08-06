class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {

        // nlogn solution 
        long long sum = 0;
        sort(maximumHeight.begin(),maximumHeight.end());

        int n = maximumHeight.size();
        sum = maximumHeight[n-1];

        set<int> s;
        s.insert(maximumHeight[n-1]);
        
        for(int i=n-2; i>=0; i--) {
            if(s.find(maximumHeight[i]) == s.end()) {
                sum += maximumHeight[i];
                s.insert(maximumHeight[i]);
            }    
            else {
                int mini = *s.begin();
                if(mini - 1 <= 0) {
                    return -1;
                }
                sum += mini-1;
                s.insert(mini-1);
            }
        }

        return sum;
    }
};