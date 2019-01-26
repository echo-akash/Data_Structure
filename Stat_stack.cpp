#include<iostream>
#define maxsize 10
using namespace std;


class Stack
{
    int top;
    int a[maxsize];

public:
    Stack();

    bool isfull();
    bool isempty();
    void push(int x);
    void pop();
    void display();
    void Top();
    void Size();
};


Stack::Stack()
    {
        top=0;
    }




bool Stack::isfull()
    {
        if(top==maxsize)
            return true;
        else
            return false;
    }




bool Stack::isempty()
    {
        if(top==0)
            return true;
        else
            return false;
    }



void Stack::push(int x)
{

    if(isfull())
    {
        cout<<"full"<<endl;
        return;
    }
    else
    a[top]=x;
    top++;
}

void Stack::pop()
{
    if(isempty())
    {
        cout<<"nothing in list"<<endl;
        return;
    }
    else
        top--;
        cout<<"pops "<<a[top]<<endl;
}


void Stack::display()
    {
        int i;
        if(top==0)
        {
            cout<<"nothing to display"<<endl;
        }
        else
        cout<<"Displaying"<<endl;
        for(i=0;i<top;i++)
        {
            cout<<a[i]<<endl;
        }

    }

void Stack::Top()
{
    cout<<"top is "<<a[top-1]<<endl;
}

void Stack::Size()
{
    cout<<"size of Stack is "<<top<<endl;
}

int main()
{
    Stack s;
    int ch,element,result;
    while(1)
    {
        cout<<"*--------------------------------------------------------------------*"<<endl;
        cout<<"1.PUSH  2.POP  3.DISPLAY  4.ISFULL  5.ISEMPTY  6.TOP  7.SIZE  8.EXIT "<<endl;
        cout<<"*--------------------------------------------------------------------*"<<endl;
    cin>>ch;
    if(ch==1)
    {
        cout<<"enter element ";
        cin>>element;
        s.push(element);

    }
    else if(ch==2)
    {
        s.pop();
    }
    else if(ch==3)
    {
        s.display();
    }
    else if(ch==4)
    {
        if(s.isfull())
            cout<<"STACK IS FULL"<<endl;
        else
            cout<<"STACK IS NOT FULL"<<endl<<"YOU CAN PUSH"<<endl;
    }
    else if(ch==5)
    {
        if(s.isempty())
            cout<<"STACK IS EMPTY"<<endl;
        else
            cout<<"STACK IS NOT EMPTY"<<endl<<"YOU CAN POP"<<endl;
    }
    else if(ch==6)
    {
        s.Top();
    }
    else if(ch==7)
    {
        s.Size();
    }
    else
    return 0;
    }

    return 0;
}

