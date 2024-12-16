class Queue {
public:
   int* arr;
   int size ;
   int top ;
   int back ;

    Queue() {
        // Implement the Constructor
        size = 100001;
        arr = new int[size];
        top = 0;
        back = -1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(top > back)
        {
            return true ;
        }
        else 
        {
            return false ;
        }
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if (back != size -1)
        {
            back++;
            arr[back] = data;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(top == back)
        {
            int temp = arr[top];
            back--;
            return temp;
        }
        else if(top < back)
        {
            int temp = arr[top];
            int i = top ;
            while(i<back)
            {
                arr[i]=arr[i+1];
                i++;
            }
            // back = i;
            back--;
            return temp ;
        }
        else
        {
            return -1;
        }

    }

    int front() {
        // Implement the front() function
        if(top <= back)
        {
            return arr[top];
        }
        else
        {
            return -1;
        }

    }
}; 