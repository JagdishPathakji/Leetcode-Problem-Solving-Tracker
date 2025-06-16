class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        int first = 0;
        int second = 0;
        int third1;
        int third2;

        for(int i=n-1; i>=0; i--) {
            third1 = cost[i] + min(first,second);
            if(i != 0)
            third2 = cost[i] + min(first,second);

            first = second;
            second = third1;
        }
        
        return min(third1,third2);
    }
};