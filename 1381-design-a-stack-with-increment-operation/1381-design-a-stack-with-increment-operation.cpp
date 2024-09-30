class CustomStack {
    int max_s;
    stack<int>s;
public:
    CustomStack(int maxSize) {
        max_s = maxSize;        
    }
    
    void push(int x) {
        if(s.size() < max_s){
            s.push(x);
        }        
    }
    
    int pop() {
        if(s.empty()){
            return -1;
        }
        int temp = s.top();
        s.pop();
        return temp;
    }
    
    void increment(int k, int val) {
        stack<int>s_temp;
        while(!s.empty()){
            s_temp.push(s.top());
            s.pop();
        }
        while(k-- && !s_temp.empty()){
            s.push(s_temp.top()+val);
            s_temp.pop();
        }
        while(!s_temp.empty()){
            s.push(s_temp.top());
            s_temp.pop();
        }        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */