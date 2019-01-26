#include<iostream>
#define MAX_SIZE 100
#define MINUS_INF -999999

using namespace std;

class Queue{
    int arr[MAX_SIZE];
    int frnt;
    int rear;

public:
    Queue(){frnt=0;rear=0;}
    void enqueue(int element);
    int dequeue();
    bool isEmpty();
    int queueSize();
    bool isFull();
    void display_queue();
};


/**
Check whether the queue is empty.
Return 1 if empty, otherwise 0
**/
bool Queue::isEmpty(){
    //if(frnt==0 && rear==0)
      if(frnt==rear)
        return true;
    else
        return false;
}

/**
Check whether the queue is full.
Return 1 if full, otherwise 0
**/
bool Queue::isFull(){
    if((rear+1)%MAX_SIZE == frnt)
        return true;
    else
        return false;
}


/**
Enqueue an element in the queue in circular fashion
Before enqueue check whether the queue is full by calling isFull() function
Print "Queue Overflow" if full
**/
void Queue::enqueue(int element){
    if(isFull())
    {
        cout<<"Error: Queue is Full\n";
        return;
    }

    else
    {
     arr[rear] = element;
        rear = (rear+1)%MAX_SIZE;
    }

}

/**
Dequeue the element at the front of the queue from the queue
Before enqueue check whether the queue is empty by calling isEmpty() function
Print "Queue Underflow" if empty and return MINUS_INF
**/
int Queue::dequeue(){
    if(isEmpty())
    {
        cout<<"Error: Queue is Empty\n";
        return MINUS_INF;
    }

    else
    {
        int re=arr[frnt];
        frnt = (frnt+1)%MAX_SIZE;
        return re;
    }
}


/**
Return the current size of the queue
**/
int Queue::queueSize(){
    int num = (rear+MAX_SIZE-frnt)%MAX_SIZE;
    return num;
}

/**
Print the current elements of the queue
**/
void Queue::display_queue(){
    cout<<"Queue       : ";
    for(int i=0; i<queueSize(); i++)
    {
        int index = (frnt+i) % MAX_SIZE;
        cout<<arr[index]<<" ";
    }
    cout<<endl;
}

int main(){
    int option, n, value,siz;
    Queue q;
    do
    {
        cout << "\n 1.Insert an element in queue";
        cout << "\n 2.Delete an element from queue";
        cout << "\n 3.Display queue";
        cout << "\n 4.Queue Size";
        cout << "\n 5.Quit";
        cout << "\n Enter your choice: ";
        cin >> option;
        switch(option){
            case 1:
                cout << "\n Enter element: ";
                cin >> n;
                q.enqueue(n);
                break;
            case 2:
                value = q.dequeue();
                if(value!=MINUS_INF)
                    cout << "\n Dequeued element is: "<< value << endl;
                break;
            case 3:
                q.display_queue();
                break;
            case 4:
                siz=q.queueSize();
                cout<<"Size of Queue is "<<siz<<endl;
                break;
            case 5:
                return 0;
        }
    }
    while(option!=-1);
    return 0;
}




//problem on date 2-3-17
/*
    int i,p,num,j=1;
    cout<<"enter number of people to kill"<<endl;
    cin>>p;

    for(i=1;i<=p;i++)
    {
        q.enqueue(i);
    }

    while(q.queueSize()!=1)
    {
        num=q.dequeue();
        q.enqueue(num);
        q.dequeue();
        q.display_queue();
    }

    q.display_queue();

*/
