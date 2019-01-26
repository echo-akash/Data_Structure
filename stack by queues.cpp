#include<iostream>
#define MAX_SIZE 6
#define MINUS_INF -999999

using namespace std;

class Queue
{
    int arr[MAX_SIZE];
    int frnt;
    int rear;
    int cnt;

public:
    Queue()
    {
        frnt=0;
        rear=0;
        cnt=0;
    }
    void enqueue(int element);
    int dequeue();
    bool isEmpty();
    int queueSize();
    bool isFull();
    int top();
    int bottom();
    void display_queue(Queue q);
};

void Queue::enqueue(int element)
{
    if(isFull())
    {
        cout<<"overflow"<<endl;
    }
    else
    {
        if(rear==MAX_SIZE)
            rear=0;
        arr[rear++]=element;
        cnt++;
    }
}

int Queue::dequeue()
{
    if(isEmpty())
    {
        cout<<"underflow"<<endl;
        return MINUS_INF;
    }
    int a=arr[frnt++];
    if(frnt==MAX_SIZE) frnt=0;
    cnt--;
    return a;
}
int Queue::top()
{
    return arr[frnt];
}
int Queue::bottom()
{
    return arr[rear-1];
}
bool Queue::isEmpty()
{
    if(cnt==0) return true;
    else return false;
}
bool Queue::isFull()
{
    if(cnt==MAX_SIZE) return true;
    else return false;
}
int Queue::queueSize()
{
    return cnt;
}
void Queue::display_queue(Queue q)
{
    Queue q1;
    q1=q;
    while(!q.isEmpty())
    {
        cout<<q.dequeue()<<" "<<endl;
    }
    cout<<endl;
    q=q1;

}

void push(Queue *q1,Queue *q2,int x)
{
    if(q1->isEmpty())
    {
        q2->enqueue(x);
    }
    else
    {
        q1->enqueue(x);
    }
}

int pop(Queue *q1, Queue *q2)
{
    if(q1->isEmpty())
    {
        if(q2->isEmpty())
        {
            cout<<"underflow"<<endl;
            return MINUS_INF;
        }
        else
        {
            while(q2->queueSize()>1)
            {
                int x=q2->dequeue();
                q1->enqueue(x);

            }

            return q2->dequeue();
        }
    }
    else
    {
        while(q1->queueSize()>1)
        {
            int x=q1->dequeue();
            q2->enqueue(x);
        }
        return q1->dequeue();
    }
}
void print(Queue *q1,Queue *q2)
{
    if(q1->isEmpty())
    {
        q2->display_queue(*q2);
    }
    else
    {
        q1->display_queue(*q1);
    }
}
int size(Queue *q1, Queue *q2)
{
    if(q1->isEmpty()) return q2->queueSize();
    else return q1->queueSize();
}
int top1(Queue *q1, Queue *q2)
{
    if(q1->isEmpty()) return q2->bottom();
    else return q1->bottom();
}
int main()
{

    Queue q1,q2;
    int choice, result, element;
	do{
		cout << "\n1. Push  2. Pop  3. Top  4. Is Empty  5. Is Full 6. Size  7. Print  8. Quit\n";
		cout << "Enter Choice: ";
		cin >> choice;
		switch(choice){
			case 1:
				cout << "\nEnter Element: " ;
				cin >> element;
				push(&q1,&q2,element);
				print(&q1,&q2);
				break;

			case 2:
				cout<<"popped element: "<<pop(&q1,&q2)<<endl;
				print(&q1,&q2);
				break;

			case 3:
				cout << "Top of the stack is: " << top1(&q1,&q2);
				break;


			case 6:
				cout << "\n Stack size is: " << size(&q1,&q2) << endl;
				break;
			case 7:
				print(&q1,&q2);
		}
	}while(choice!=8);


}
