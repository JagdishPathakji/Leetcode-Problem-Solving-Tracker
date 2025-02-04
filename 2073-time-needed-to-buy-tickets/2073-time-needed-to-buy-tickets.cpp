class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int i=0;
        int count = 0;
        while(tickets[k]) {
            if(tickets[i] == 0) {
                i++;
                if(i == tickets.size()) {
                    i = 0;
                }
                continue;
            }
            tickets[i] = tickets[i] - 1;
            i++;
            count++;
            if(i == tickets.size()) {
                i = 0;
            }
        }

        return count;
    }
};