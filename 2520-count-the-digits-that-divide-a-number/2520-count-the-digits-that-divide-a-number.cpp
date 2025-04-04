class Solution {
public:
    int countDigits(int num) {
        
        int count = 0;
        int Num  = num;
        while(num > 0) {
            int p = num % 10;
            if(Num%p == 0) count++;
            num = num / 10;
        }

        return count;
    }
};