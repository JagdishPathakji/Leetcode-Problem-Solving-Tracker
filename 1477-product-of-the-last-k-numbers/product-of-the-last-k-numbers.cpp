class ProductOfNumbers {
public:

    vector<int> v;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        v.push_back(num); // O(1) TC
    }
    
    int getProduct(int k) {
        int n = v.size()-1;
        int ans = 1;
        while(k--) {
            ans *= v[n];
            n--;
        }

        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */