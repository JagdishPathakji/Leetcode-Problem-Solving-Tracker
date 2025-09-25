class Solution {
public:

    int maxProfit(vector<int>& prices) {
        
        int minpricetobuysofar = INT_MAX;
        int maxprofitsofar = 0;

        for(int i=0; i<prices.size(); i++) {
            minpricetobuysofar = min(minpricetobuysofar,prices[i]);
            maxprofitsofar = max(maxprofitsofar,prices[i]-minpricetobuysofar);
        }

        return maxprofitsofar;
    }
};