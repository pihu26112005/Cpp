#include<stack>
class MyQueue {
public:
    int front;
    stack<int> s1;
    stack<int> s2;

   /////////    
    MyQueue() {
 
    }
    
    void push(int x) { // s1 me push karta toh lifo ke according jata, so har baar jab bhi push krr ha hu sath me hi order ulta kar deta hu, taaki new x last me nhi pahle jaae and main niche se hi pop kar saku 
        if(s1.empty())
            {
                s1.push(x);
                return ;
            }
        while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        s1.push(x);
        while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }

    }
    
    int pop() {
         if (s1.empty()) {
            return -1;
        }
        int topElement = s1.top(); 
        s1.pop();
        return topElement; 
    }
    
    int peek() {
         if (s1.empty()) {
            return -1;
        }
        return s1.top(); 
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */