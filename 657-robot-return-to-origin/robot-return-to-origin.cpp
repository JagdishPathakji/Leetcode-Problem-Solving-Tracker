class Solution {
public:
    bool judgeCircle(string moves) {
        
        int count1 = 0;
        int count2 = 0;

        for(int i=0; i<moves.size(); i++) {
            if(moves[i] == 'L')
            count1++;
            else if(moves[i] == 'R')
            count1--;
        
            if(moves[i] == 'U')
            count2++;
            else if(moves[i] == 'D')
            count2--;
        }

        return (count1 == count2) && (count1 == 0);
    }
};