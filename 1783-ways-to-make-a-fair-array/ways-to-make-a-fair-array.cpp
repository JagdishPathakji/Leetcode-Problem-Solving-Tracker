class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        
        int O = 0;
        int E = 0;

        for(int i=0; i<nums.size(); i++) {
            if(i%2 == 0) {
                E += nums[i];
            }
            else {
                O += nums[i];
            }
        }

        int PO = 0;
        int PE = 0;
        int count = 0;
        
        int CE,CO;
        for(int i=0; i<nums.size(); i++) {
            if(i%2 == 0) {
                PE += nums[i];
            }
            else {
                PO += nums[i];
            }
            
            if(i%2 == 0)
            CO = PO + (E - PE);
            else
            CO = PO + (E - PE) - nums[i];
            
            
            if(i%2 == 0)
            CE = PE + (O - PO) - nums[i];
            else
            CE = PE + (O - PO);

            if(CO == CE) {
                count++;
            }
        }


        return count;
    }
};