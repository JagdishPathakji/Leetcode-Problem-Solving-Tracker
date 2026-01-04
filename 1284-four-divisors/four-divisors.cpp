class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        
        // Brute force -> not optimal
        // 21 -> 1 3 7 21
        // Optimal way to find factors : 
        /*
        if 1 is factor of 21 then 21/1 will also be factor of 21
        if 3 is factor of 21 then 21/3 will also be factor of 21

        No need to loop till the number to find factors, do only upto root(number)
        Edge case : n = 36
        factors : (1,36), (2,18), (3,12), (4,9), (6,6) -> dont include 6 again
        */

        int ans = 0;

        for(int i=0; i<nums.size(); i++) {

            int number = nums[i];
            int sum = 0;
            int divisor = 0;

            for(int fact = 1; fact <= sqrt(number); fact++) {
                if(number%fact == 0) {
                    int otherfact = number/fact;
                    if(otherfact == fact) {
                        divisor++;
                        sum += fact;
                    }
                    else {
                        divisor += 2;
                        sum += (fact+otherfact);
                    }
                }

                if(divisor > 4)
                break;
            }

            if(divisor == 4) {
                ans += sum;
            }
        }

        return ans;
    }
};