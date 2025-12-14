class ProductOfNumbers {
public:

    vector<int> v;
    vector<int> pm;
    int zeroIndex = -1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        // O(1) TC to add a element
        v.push_back(num);     
        if(num == 0)
        zeroIndex = v.size()-1;

        if(v.size() == 1)
        pm.push_back(num);
        else {
            if(pm.back() == 0)
            pm.push_back(num);
            else
            pm.push_back(num * pm.back());
        }
    }
    
    int getProduct(int k) {
        // O(1) TC to return product
        if(k == 1)
        return v.back();
        
        if(v.size() == k && zeroIndex == -1)
        return pm.back();

        if(v.size() == k && zeroIndex != -1)
        return 0;

        if(zeroIndex != -1 && zeroIndex >= (v.size()-k))
        return 0;

        int dangerIdx = pm.size()-k-1;
        if(pm[dangerIdx] == 0)
        return pm.back();
        else
        return (pm.back()/pm[dangerIdx]);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */