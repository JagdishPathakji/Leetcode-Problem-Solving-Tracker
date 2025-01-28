class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        if(arr.size() < 3) {
            return false;
        }

        int i = 0;
        int j = 1;
        int index = 0;
        while(i < arr.size() and j < arr.size()) {
            if(arr[i] == arr[j]) {
                return false;
            }

            if(arr[i] < arr[j]) {
                index = j;
                i++;
                j++;
            }
            else {
                break;
            }
        }

        if(index == 0) {
            return false;
        }
        if(index == arr.size()-1) {
            return false;
        }

        for(int i=index; i<arr.size()-1; i++) {
            if(arr[i] <= arr[i+1]) {
                return false;
            }
        }

        return true;
    }
};