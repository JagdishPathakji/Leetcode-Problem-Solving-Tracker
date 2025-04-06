class Solution {
public:
    int countEven(int num) {
        
        int count = 0;
        for(int i=1; i<=num; i++) {
            
            int x = i;
            int c = 0;
            while(x > 0) {
                int p = x % 10;
                c = c + p;
                x = x / 10;
            }

            if(c%2 == 0)
            count++;

        }

        return count;
    }
};