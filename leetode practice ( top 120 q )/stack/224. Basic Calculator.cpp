class Solution {
    public:
        int calculate(string s) {
            s = "(" + s + ")"; 
            stack<int> nums;     // Stack for numbers
            stack<char> ops;     // Stack for operators
    
            int i = 0, n = s.length();
            while (i < n) {
                char c = s[i];
    
                if (c == ' ') {
                    i++; 
                    continue;  
                }
    
                if (isdigit(c)) {
                    int num = 0;
                    while (i < n && isdigit(s[i])) {  
                        num = num * 10 + (s[i] - '0');
                        i++;
                    }
                    nums.push(num);
                    continue; 
                } 
                else if (c == '(') {
                    ops.push(c);
                } 
                else if (c == '+' || c == '-') {
                    int j = i - 1;
                    while (j >= 0 && s[j] == ' ') j--;
                    if (j < 0 || s[j] == '(') {
                        nums.push(0);  // Convert "-x" to "0 - x"
                    }
                    
                    while (!ops.empty() && ops.top() != '(') {
                        processTop(nums, ops);
                    }
                    ops.push(c);
                } 
                else if (c == ')') {
                    while (!ops.empty() && ops.top() != '(') {
                        processTop(nums, ops);
                    }
                    ops.pop(); 
                }
                i++;  
            }
            return nums.top();
        }
    
        void processTop(stack<int> &nums, stack<char> &ops) {
            if (nums.size() < 2 || ops.empty()) return;
    
            int b = nums.top(); nums.pop();
            int a = nums.top(); nums.pop();
            char op = ops.top(); ops.pop();
    
            if (op == '+') nums.push(a + b);
            if (op == '-') nums.push(a - b);
        }
    };
    
    
    // first i add a ( at beg and ) at end 
    // i will be suing two stacks , both of string 
    // one for storing numbers and other for +,-,(
    // as i know a number is always surrounded by any of +,-,(,)
    // so i iterat over string 
    // when i get (,+ ,- i just put in secomd stacl 
    // and theor in between number as string in first stack 
    // whenevr i see ) i run a while loop untill i get ( on second stack top 
    // - i pop out operator from second stack and two number from first stack then compute the result and [ut them in first stack again 
    
    // but there is a catch eg ---> 2-1+2
    // isme emre according pahle 1+2 hoga then 2-3 = -1 
    // but hona pahle 2-1 then 1+2 = 3
    // so update --> jab bhi koi operator aaye toh usse pahle agar koi operator ho toh pahle use solve krlo , then usko push kro 
    // this is ensure in process top by checking num.size >2 , so tabhi chalega jab min ek operator toh honge hi 
    // and this ensure ki stack me ek time pe ek hi operator rhega 
    
    // another catch --> (1-(-2))
    // isme hum isko as treak kr rhe hai - (1-(0-2))
    // 