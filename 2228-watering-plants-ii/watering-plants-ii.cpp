class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n=plants.size();
        int refill_count=0;
        int ca=capacityA;
        int cb=capacityB;

        int alice=0;
        int bob=n-1;

        while(alice<bob)
        {   
            if(ca<plants[alice])
            {
                ca=capacityA;
                refill_count++;//1
            }
            if(cb<plants[bob])
            {
                cb=capacityB;
                refill_count++;
            }

            ca-=plants[alice];
            cb-=plants[bob];

            alice++;
            bob--;
        }         
        if(alice==bob)
        {
            if(ca<plants[alice] && cb<plants[bob])
            {
                refill_count++;
                ca=capacityA;
            }
        }
        return refill_count;   

    }
};