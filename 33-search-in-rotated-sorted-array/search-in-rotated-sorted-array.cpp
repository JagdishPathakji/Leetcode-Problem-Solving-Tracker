class Solution {
public:
    int search(vector<int>& arr, int key) {
        int start = 0;
        int end = arr.size()-1;
        int mid;
        
        while(start <= end) {
            
            mid = start + (end - start)/2;
            if(arr[mid] == key) {
                return mid;
            }
            else if(arr[mid] >= arr[start]) {
                if(arr[mid] > key and arr[start] <= key) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
            else {
                if(arr[mid] < key and arr[end] >= key) {
                    start = mid + 1;
                }
                else {
                    end = mid -1;
                }
            }
        }
        
        return -1;
    }
};