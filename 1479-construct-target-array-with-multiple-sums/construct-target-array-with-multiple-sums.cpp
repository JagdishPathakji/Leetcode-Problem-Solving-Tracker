class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        // Max-Heap
        priority_queue<long long> pq(target.begin(),target.end());
        long long sum = 0;
        for(int i=0; i<target.size(); i++)
        sum+=target[i];

        long long Maxelement,Remainingsum,Element;

        while(pq.top() != 1) {

            Maxelement = pq.top();
            pq.pop();

            Remainingsum = sum - Maxelement;
            if(Remainingsum <= 0 || Remainingsum >= Maxelement)
            return 0;

            Element = Maxelement%Remainingsum;
            if(Element == 0 and Remainingsum != 1)
            return 0;
            else if(Element == 0 and Remainingsum == 1)
            return 1;

            sum = Remainingsum + Element;   
            pq.push(Element);

        }
        
        return 1;
    }
};