class Solution {
public:

    void winner(int &n, vector<bool> &person, int &personleft, int k, int index) {

        if(personleft == 1) {
            return;
        }

        while(person[index])
        index = (index+1)%n;

        int step = 0;
        while(step < k) {
            if(!person[index]) {
                step++;
            }
            if(step == k) break;
            index = (index+1)%n;
        }

        person[index] =  true;
        personleft--;
        winner(n,person,personleft,k,(index+1)%n);
    }

    int findTheWinner(int n, int k) {
        
        int personleft = n;
        vector<bool> person(n,false);
        int index = 0;

        winner(n,person,personleft,k,index);

        for(int i=0; i<n; i++) {
            if(!person[i])
            return i+1;
        }

        return -1;
    }
};