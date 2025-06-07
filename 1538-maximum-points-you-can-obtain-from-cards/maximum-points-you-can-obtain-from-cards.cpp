class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int lsum = 0;
        int rsum = 0;

        int maxSum = 0;
        for(int i=0; i<k; i++)
        lsum += cardPoints[i];

        maxSum = lsum;
        int rightindex = cardPoints.size()-1;

        for(int i=k-1; i>=0; i--) {
            lsum -= cardPoints[i];
            rsum += cardPoints[rightindex];
            maxSum = max(lsum+rsum,maxSum);
            rightindex--;
        }

        return maxSum;
    }
};