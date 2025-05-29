class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        
        coordinate1[0] = coordinate1[0]-'a'+1;
        coordinate2[0] = coordinate2[0]-'a'+1;
        
        if((coordinate1[0]-'0' + coordinate1[1]-'0')%2 == (coordinate2[0]-'0' + coordinate2[1]-'0')%2)
        return true;

        return false;
    }
};