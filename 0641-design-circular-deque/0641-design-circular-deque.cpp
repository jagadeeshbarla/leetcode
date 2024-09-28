class MyCircularDeque {
    deque<int>d;
    int k;
public:
    MyCircularDeque(int kl) {
        k = kl;        
    }
    
    bool insertFront(int value) {
        if(d.size() >= k){
            return false;
        }        
        d.push_front(value);  
        return true;
    }
    
    bool insertLast(int value) {
        if(d.size() >= k){
            return false;
        } 
        d.push_back(value);
        return true;
        
    }
    
    bool deleteFront() {
        if(d.size()>0){
            d.pop_front();
            return true;
        }        
        return false;
    }
    
    bool deleteLast() {
        if(d.size()>0){
            d.pop_back();
            return true;
        }        
        return false;        
    }
    
    int getFront() {
        if(d.size() == 0){
            return -1;
        } 
        return d.front();        
    }
    
    int getRear() {
        if(d.size() == 0){
            return -1;
        } 
        return d.back();        
    }
    
    bool isEmpty() {
        if(d.size() > 0){
            return false;
        }        
        return true;
    }
    
    bool isFull() {
        if(d.size() >= k){
            return true;
        }        
        return false;
        
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */