// video method 
// next ka use change kr diya 
// is baar next me pichle ka index store kiya hai 

#include<iostream>
using namespace std;

class kQueue {

    public:
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int freeSpot;
        int *next;

    public:
        kQueue(int n, int k) {
            this -> n = n;
            this -> k = k;
            front = new int[k];
            rear = new int[k];
            for(int i=0; i<k; i++) {
                front[i] = -1;
                rear[i] = -1;
            }

            next = new int[n];
            for(int i=0; i<n; i++) {
                next[i] = i+1;
            }
            next[n-1] = -1;
            arr = new int[n];
            freeSpot = 0;
        }    

        void enqueue(int data, int qn) {

            //overflow
            if( freeSpot == -1) {
                cout << "No Empty space is present" << endl;
                return;
            }

            //find first free index
            int index = freeSpot;

            //update freespot
            freeSpot = next[index];

            //check whther first element
            if(front[qn-1] == -1){
                front[qn-1] = index;
                rear[qn-1] = index;
            }
            else{
                //link new element to the prev element
                next[rear[qn-1]] = index;
            }

            //update next
            next[index] = -1;

            //update rear
            rear[qn-1] = index;

            //push element
            arr[index] = data;
        }

        int dequeue(int qn) {
            //underflow 
            if(front[qn-1] == -1)
            {
                cout << "Queue UnderFlow " << endl;
                return -1;
            }

            //find index to pop
            int index = front[qn-1];

            //front ko aage badhao
            front[qn-1] = next[index];

            //freeSlots ko manage karo
            next[index] = freeSpot;
            freeSpot = index;
            return arr[index];
        }

};

int main() {

    kQueue q(5,2);
    q.enqueue(12, 1);
    q.enqueue(13,2);
    q.enqueue(14, 1);

}