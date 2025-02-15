class MyHashSet {
public:

    vector<int> hashset;
    MyHashSet() {
        
    }
    
    void add(int key) {
        
        if(hashset.size() == 0) {
            hashset.push_back(key);
            return;
        }

        int start = 0;
        int end = hashset.size()-1;

        while(start <= end) {

            int mid = start + (end - start)/2;

            if(hashset[mid] == key) {
                return;
            }
            else if(hashset[mid] < key) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        hashset.insert(hashset.begin()+start,key);
    }
    
    void remove(int key) {
        
        int start = 0;
        int end = hashset.size()-1;

        while(start <= end) {

            int mid = start + (end - start)/2;

            if(hashset[mid] == key) {
                hashset.erase(hashset.begin()+mid);
                return;
            }
            else if(hashset[mid] < key) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
    }
    
    bool contains(int key) {

        int start = 0;
        int end = hashset.size()-1;

        while(start <= end) {
            
            int mid = start + (end - start)/2;

            if(hashset[mid] == key) {
                return true;
            }
            else if(hashset[mid] < key) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }   

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */