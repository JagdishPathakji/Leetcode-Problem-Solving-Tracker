class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> ms;
        while(true) {

            if(ms.find(n) != ms.end())
            return false;

            ms.insert(n);
            int sq = 0;
            int num = n; 
            while(num != 0) {
                int p = num % 10;
                sq = p*p + sq;
                num = num / 10;
            }

            if(sq == 1)
            return true;

            n = sq;
        }

        return false;
    }
};