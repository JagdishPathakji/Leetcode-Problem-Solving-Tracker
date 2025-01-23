class MedianFinder {
public:

    vector<int> v;
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        //there are two default functions for vector as lower_bound and upper_bound
        //both of this functions uses binary search and returns the index of the position where the element could be inserted so that array remains      sorted.
        //The lower_bound function is used to find the first position in a sorted array (or vector) where a given element could be inserted to maintain the sorted order. It returns an iterator pointing to the first element not less than (i.e., greater or equal to) the specified value.

        //The upper_bound function is similar to lower_bound, but it finds the first position where the given element could be inserted to maintain order, but this time it returns the first element strictly greater than (i.e., greater than) the specified value.

        // we can also use lower_bound function over here which would also work as our main goal is sorting
        auto pos = upper_bound(v.begin(),v.end(),num);

        // The insert function will insert the number at the required index, rather than replace any existing element. It doesn't overwrite any existing value; instead, it shifts the existing elements to the right (if necessary) to make space for the new number.
        v.insert(pos,num);
    }
    
    double findMedian() {
        
        int start = 0;
        int end = v.size()-1;

        int mid = start + (end - start)/2;

        if(v.size() % 2 == 0) {
            return (double(v[mid]) + double(v[mid+1]))/2;
        }
        else {
            return (double(v[mid]));
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */