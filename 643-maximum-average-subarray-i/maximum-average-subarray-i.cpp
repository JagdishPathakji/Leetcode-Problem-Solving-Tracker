class Solution {
public:
    double findMaxAverage(vector<int>& v, int k) {
        

        double sum = 0;
        int i=0,j=0;
        double maxi = INT_MIN;
        int n = v.size();

        while(j < n) {

            sum += v[j];

            if(j-i+1 == k) {
                maxi = max(maxi,(sum/(double)(j-i+1)));
                sum -= v[i];
                i++;
            }

            j++;
        }

        return maxi;
    }
};