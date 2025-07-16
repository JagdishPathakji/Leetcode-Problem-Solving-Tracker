class node {
public:
    int data;
    node *next;
    node *prev;

    node(int data) {
        this->data = data;
        next = prev = nullptr;
    }
};

class FrontMiddleBackQueue {
public:

    node *head;
    node *tail;
    int size;
    FrontMiddleBackQueue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    void pushFront(int val) {
        node *element = new node(val);
        
        if(!head) {
            head = element;
            tail = element;
        }
        else {
            element->next = head;
            head->prev = element;
            head = element;
        }
        size++;
    }
    
    void pushMiddle(int val) {
        node *element = new node(val);
        int iteration = size/2;

        node *curr = head;
        node *pre = nullptr;
        while(curr and iteration--) {
            pre = curr;
            curr = curr->next;
        }

        if(pre) {
            pre->next = element;
            element->prev = pre;
            element->next = curr;
            if(curr) 
            curr->prev = element;
            else
            tail = element;
        }
        else {
            element->next = head;
            
            if(head)
            head->prev = element;    
            else
            tail = element;
            
            head = element;
        }


        size++;
    }
    
    void pushBack(int val) {
        node *element = new node(val);

        if(!head) {
            head = element;
            tail = element;
        }
        else {
            tail->next = element;
            element->prev = tail;
            tail = tail->next;
        }
        size++;
    }
    
    int popFront() {
        
        if(!head) {
            return -1;
        }

        int data = head->data;
        head = head->next;
        
        if(head)
        head->prev = nullptr;
        else
        tail = nullptr;

        size--;
        return data;
    }
    
    int popMiddle() {
        
        if(!head) {
            return -1;
        }
        
        node *curr = head;
        int iteration = (size-1)/2;
        
        while(iteration--) {
            curr = curr->next;
        }   

        int data = curr->data;
        
        if(curr->prev) 
        curr->prev->next = curr->next;
        else
        head = curr->next;

        if(curr->next)
        curr->next->prev = curr->prev;
        else
        tail = curr->prev;

        size--;
        return data;
    }
    
    int popBack() {
        
        if(!head) {
            return -1;
        }

        int data = tail->data;
        
        tail = tail->prev;
        if(tail)
        tail->next = nullptr;
        else
        head = nullptr;

        size--;
        return data;
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