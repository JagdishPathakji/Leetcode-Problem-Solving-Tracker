class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        int first1 = 0;
        int second1 = 0;
        int third1;

        for(int i=n-1; i>=0; i--) {
            third1 = cost[i] + min(first1,second1);
            first1 = second1;
            second1 = third1;
        }

        int first2 = 0;
        int second2 = 0;
        int third2;
        for(int i=n-1; i>=1; i--) {
            third2 = cost[i] + min(first2,second2);
            first2 = second2;
            second2 = third2;

        }
        
        return min(third1,third2);
    }
};