#include<iostream>
#define MAX_SIZE 8

using namespace std;

class stack
{
	int array[MAX_SIZE];
	int top_of_stack;

public:
	stack() { top_of_stack=0; } ///constructor
	void push(int x);
	int pop();
	int isEmpty();
	int isFull();
	int size();
	int top();
	void print();
	friend void print(stack *s1, stack *s2);
};

/**
push an element at the top of the stack is the stack if not full
print "stack overflow" if the stack is full
**/
void stack::push(int x){
        if(top_of_stack==MAX_SIZE) cout<<"Stack overflow"<<endl;
        else array[top_of_stack++]=x;
}

/**
pop the element at the top of the stack
print "stack underflow" if the stack is empty
**/
int stack::pop(){
        if(top_of_stack==0)
        {
            cout<<"Stack underflow"<<endl;
            return -9999;
        }
        else
        {
            int x=array[top_of_stack-1];
            //cout<<array[top_of_stack-1]<<" has been popped out"<<endl;
            top_of_stack--;
            return x;
        }

}

/**
return the element at the top of the stack
print "stack underflow" if the stack is empty and return a very large negative value(-infinity)
**/
int stack::top(){
        if(top_of_stack==0)
        {
            cout<<"stack underflow"<<endl;
            return -100000;
        }
        int a=array[top_of_stack-1];
        return a;
}

/**
return 1 if the stack is empty
otherwise return 0
**/
int stack::isEmpty(){
    if(top_of_stack==0) return 1;
    else return 0;
}

/**
return 1 if the stack is full
otherwise return 0
**/
int stack::isFull(){
    if(top_of_stack==MAX_SIZE) return 1;
    else return 0;
}

/** return the current size of the stack **/
int stack::size(){
    return top_of_stack;
}

/** print all elements of the stack**/
void stack::print(){
        int i;
        for(i=0;i<top_of_stack;i++)
        {
            cout<<array[i]<<" "<<endl;
        }
}

void enqueue(stack *s1,int x)
{
    s1->push(x);
}
int dequeue(stack *s1, stack *s2)
{
    if(s2->isEmpty())
    {
        if(s1->isEmpty())
        {
            cout<<"underflow"<<endl;
            return -99999;
        }
        else
        {
            while(!s1->isEmpty())
            {
                int x=s1->pop();
                s2->push(x);
            }
        }
        return s2->pop();
    }
    else
    {
        return s2->pop();
    }
}
int top1(stack *s1,stack *s2)
{
    //if()
}
void print(stack *s1,stack *s2)
{
    if(!s2->isEmpty())
    {
        for(int i=s2->top_of_stack-1;i>=0;i--)
            cout<<s2->array[i]<<" ";
    }
    if(!s1->isEmpty())
    {
        for(int i=0;i<s1->top_of_stack;i++)
            cout<<s1->array[i]<<" ";
    }
    cout<<endl;
}
int size(stack *s1,stack *s2)
{
    return s1->size()+s2->size();
}

int main(){
	stack s1,s2;
	int choice, result, element;
	do{
		cout << "\n1. Push  2. Pop  3. Top  4. Is Empty  5. Is Full 6. Size  7. Print  8. Quit\n";
		cout << "Enter Choice: ";
		cin >> choice;
		switch(choice){
			case 1:
				cout << "\nEnter Element: " ;
				cin >> element;
				enqueue(&s1,element);
				print(&s1,&s2);
				break;

			case 2:
				cout<<dequeue(&s1,&s2)<<endl;;
				print(&s1,&s2);
				break;

			case 3:
				cout << "Top of the stack is: " << top1(&s1,&s2);
				break;


			case 6:
				cout << "\n Stack size is: " << size(&s1,&s2) << endl;
				break;
			case 7:
				print(&s1,&s2);
		}
	}while(choice!=8);

	return 0;
}
