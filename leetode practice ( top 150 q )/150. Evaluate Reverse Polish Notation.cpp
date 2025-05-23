class Solution {
    public:
        int evalRPN(vector<string>& t) {
            stack<int> s;
            for(string i:t){
                if(i=="+" || i=="-" || i=="*" || i=="/"){
                    int r=s.top();
                    s.pop();
                    int l=s.top();
                    s.pop();
                    if(i=="+") s.push(r+l);
                    if(i=="-") s.push(l-r);
                    if(i=="*") s.push(r*l);
                    if(i=="/") s.push(l/r);
                }
                else{
                    s.push(stoi(i));
                }
            }
            return s.top();
        }
    };