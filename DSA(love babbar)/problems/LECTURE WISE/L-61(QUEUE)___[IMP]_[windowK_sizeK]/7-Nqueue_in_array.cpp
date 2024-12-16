// my method 
// next aur prev do array bnae 
// ek agle ka index aur ek pichle ka index store krta hai

#include<iostream>
#include<queue>
#include<deque>
#include<map>
using namespace std;

class NQueue
{   
public:

    int *arr;
    int *top;
    int *back;
    int *next;
    int* prev;
    
    int n, s; // n--> array ki length , s--> number of stack
     
    int freespot;
    // Initialize your data structure.
    NQueue(int N, int S)
    {
        n = N; //  number of stack
        s = S; // array ki length
        arr = new int[s];
        top = new int[n]; // stores index of current top w r t arr
        back = new int[n]; // stores index of current back w r t arr
        next = new int[s];
        prev = new int[s];
        
        //top initialise
        for(int i=0; i<n; i++) {
            top[i] = -1;
            back[i] = -1;
        }
        
        //next initialise
        for(int i=0; i<s; i++) {
            next[i] = i+1;
            prev[i] = i-1;
        }
        //update last index value to -1
        next[s-1] = -1;
        
        //initialise freespot
        freespot = 0;
        
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //check for overflow
        if(freespot == -1) {
            return false;
        }
        
        //find index
        int index = freespot;
        
        arr[index] = x;
        
        //update freespot
        freespot = next[index];
       
        //update next;
        next[index] = back[m-1];
        if (top[m-1]!=-1)
        {
        prev[next[index]] = index;
        }
        
        //update top
        back[m-1] = index;
        if (top[m-1]==-1)
        {
            top[m-1]=index;
        }
        
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwi
        //insert element into arrayse returns the popped element.
    int pop(int m)
    {
        //check underflow condition
        if(back[m-1] == -1)
        {
            return -1;
        }
        if(top[m-1]==back[m-1])
        {
            int index= top[m-1];

            top[m-1] = -1 ;
            back[m-1] = -1 ;

            next[index] = freespot;

            freespot = index;

            return arr[index];
        }

        else
        {
            int index= top[m-1];

            top[m-1] = prev[index];

            next[index] = freespot;

            freespot = index;

            return arr[index];
        }
    }
};

int main()
{
    NQueue* nq = new NQueue(3,27);
    cout<< nq->push(39,3)<<endl;
    cout<<nq->pop(3)<<endl;
    cout<< nq->push(22,2)<<endl;
    cout<< nq->push(34,3)<<endl;
    cout<<nq->pop(3)<<endl;
    cout<<nq->pop(2)<<endl;
    cout<<nq->pop(2)<<endl;
    cout<< nq->push(17,3)<<endl;
    cout<<nq->pop(2)<<endl;
    cout<< nq->push(18,3)<<endl;

}