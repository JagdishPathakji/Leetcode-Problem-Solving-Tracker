class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int i = 0;
        int j = 0;

        long long sum = 0;
        int counter = 0;
        while(j < arr.size()) {

            sum += arr[j];

            if(j-i+1 == k) {
                if(sum/k >= threshold) {
                    counter++;
                }
                sum -= arr[i];
                i++;
            }

            j++;
        }

        return counter;
    }
};