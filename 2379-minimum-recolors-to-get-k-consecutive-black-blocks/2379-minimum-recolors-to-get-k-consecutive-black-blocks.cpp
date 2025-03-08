class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int min = INT_MAX;
        int count = 0;
        for(int i=0; i<=blocks.size()-k; i++) {
            count = 0;
            for(int j=i; j<(k+i) and j<blocks.size(); j++) {
                if(blocks[j] == 'W') {
                    count++;
                }
            }
            if(min > count) {
                min = count;
            }
        }

        return min;
    }
};