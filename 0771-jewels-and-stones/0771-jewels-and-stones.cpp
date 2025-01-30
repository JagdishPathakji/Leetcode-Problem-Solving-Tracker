class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        vector<int> v1(27,0);
        vector<int> v2(27,0);

        for(int i=0; i<stones.size(); i++) {
            if(stones[i] >= 'a' and stones[i] <= 'z') {
                v1[stones[i]-'a']++;
            }
            else {
                v2[stones[i]-'A']++;
            }
        }

        int count = 0;
        for(int i=0; i<jewels.size(); i++) {
            if(jewels[i] >= 'a' and jewels[i] <= 'z') {
                if((v1[jewels[i]-'a']) > 0) {
                    count = count + v1[jewels[i]-'a'];
                }
            }
            else {
                if((v2[jewels[i]-'A']) > 0) {
                    count = count + v2[jewels[i]-'A'];
                }
            }
        }

        return count;
    }
};