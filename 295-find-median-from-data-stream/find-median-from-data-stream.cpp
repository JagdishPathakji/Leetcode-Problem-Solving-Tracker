class MedianFinder {
public:

    priority_queue<double> pqmax;
    priority_queue<double, vector<double>, greater<double>> pqmin;

    MedianFinder() {

    }
    
    void addNum(int num) {
        
        if(pqmax.empty()) {
            pqmax.push(num);
            return;
        }

        if(pqmax.size() > pqmin.size()) {

            if(pqmax.top() > num) {
                int el = pqmax.top();
                pqmax.pop();
                pqmin.push(el);
                pqmax.push(num);
            }
            else {
                pqmin.push(num);
            }
        }
        else if(pqmax.size() < pqmin.size()) {

            if(pqmin.top() < num) {
                int el = pqmin.top();
                pqmin.pop();
                pqmax.push(el);
                pqmin.push(num);
            }
            else {
                pqmax.push(num);
            }
        }
        else {
            if(pqmin.top() < num) {
                pqmin.push(num);
            }
            else {
                pqmax.push(num);
            }
        }
        
    }
    
    double findMedian() {
        
        if(pqmax.size() == pqmin.size()) 
        return (pqmax.top()+pqmin.top())/2;
        else if(pqmax.size() > pqmin.size()) 
        return pqmax.top();
        else
        return pqmin.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */