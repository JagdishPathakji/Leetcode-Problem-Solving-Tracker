class Solution {
public:
    int alternateDigitSum(int n) {
        
        int sum = 0;
        int i = 0;

        int c  = 0;
        while(n > 0) {
            int p = n % 10;
            c = c * 10 + p;
            n = n / 10;
        }

        while(c > 0) {
            int p = c%10;
            if(i%2==0) sum = sum + p;
            else sum = sum - p;
            c = c/10;
            i++;
        }   

        return sum;
    }
};