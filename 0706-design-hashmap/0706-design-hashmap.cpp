class MyHashMap {
public:

    vector<pair<int,int>> v;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        if(v.size() == 0) {
            v.push_back({key,value});
            return;
        }

        int start = 0;
        int end = v.size()-1;

        while(start <= end) {

            int mid = start + (end - start)/2;

            if(v[mid].first == key) {
                v[mid].second = value;
                return;
            }
            else if(v[mid].first < key) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        v.insert(v.begin()+start,{key,value});
    }
    
    int get(int key) {
        
        int start = 0;
        int end = v.size()-1;

        while(start <= end) {

            int mid = start + (end - start)/2;

            if(v[mid].first == key) {
                return v[mid].second;
            }
            else if(v[mid].first < key) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        
        int start = 0;
        int end = v.size()-1;

        while(start <= end) {

            int mid = start + (end - start)/2;

            if(v[mid].first == key) {
                v.erase(v.begin()+mid);
                return;
            }
            else if(v[mid].first < key) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */