
class MyQueue {
public:
    stack<int> i, o;
    MyQueue() {
        
    }
    
    void push(int x) {
        i.push(x);
    }
    
    int pop() {
        if(o.empty()) {
          while(!i.empty()) {
            o.push(i.top());
            i.pop();
          }
        }
        int x = o.top();
        o.pop();
        return x;
    }
    
    int peek() {
        if(o.empty()) {
          while(!i.empty()) {
            o.push(i.top());
            i.pop();
          }
        }
        int x = o.top();
        return x;
    }
    
    bool empty() {
        return (i.empty() && o.empty());
    }
};

