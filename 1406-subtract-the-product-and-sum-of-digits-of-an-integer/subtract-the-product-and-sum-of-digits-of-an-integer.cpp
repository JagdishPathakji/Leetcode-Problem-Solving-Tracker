class Solution {
public:
    int subtractProductAndSum(int n) {
        
        int prod = 1;
        int sum = 0;

        while(n != 0) {
            int p = n % 10;
            sum = sum + p;
            prod = prod * p;
            n = n / 10;
        }
        
        return prod-sum;
    }
};