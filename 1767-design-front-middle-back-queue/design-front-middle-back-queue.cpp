class FrontMiddleBackQueue {
public:

    deque<int> d1;
    deque<int> d2;

    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        if(d1.size() == d2.size()) {
            d1.push_front(val);
        }    
        else {
            d2.push_front(d1.back());
            d1.pop_back();
            d1.push_front(val);
        }
    }
    
    void pushMiddle(int val) {
        if(d1.size() == d2.size()) {
            d1.push_back(val);
        }
        else {
            d2.push_front(d1.back());
            d1.pop_back();
            d1.push_back(val);
        }
    }
    
    void pushBack(int val) {
        if(d1.size() == d2.size()) {
            d2.push_back(val);
            d1.push_back(d2.front());
            d2.pop_front();
        }
        else {
            d2.push_back(val);
        }
    }
    
    int popFront() {
        
        if(d1.size() == 0)
        return -1;

        int el;
        if(d1.size() == d2.size()) {
            el = d1.front();
            d1.pop_front();
            d1.push_back(d2.front());
            d2.pop_front();
        }
        else {
            el = d1.front();
            d1.pop_front();
        }

        return el;
    }
    
    int popMiddle() {
        
        if(d1.size() == 0)
        return -1;

        int el;
        if(d1.size() == d2.size()) {
            el = d1.back();
            d1.pop_back();
            d1.push_back(d2.front());
            d2.pop_front();
        }
        else {
            el = d1.back();
            d1.pop_back();
        }

        return el;
    }
    
    int popBack() {

        int el;
        if(d1.size() != 0 && d2.size() == 0) {
            el = d1.back();
            d1.pop_back();
            return el;
        }

        if(d1.size() == 0 && d2.size() == 0) 
        return -1;

        if(d1.size() == d2.size()) {
           el = d2.back();
           d2.pop_back();
        }
        else {
            el = d2.back();
            d2.pop_back();
            d2.push_front(d1.back());
            d1.pop_back();
        }

        return el;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */