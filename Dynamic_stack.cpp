#include<iostream>
#include<stdlib.h>
using namespace std;
int n;
class Stack
{
    int *stc;
    int Size;

public:

    Stack()
    {
        Size=0;
        stc=new int [n];
    }

    void push(int x)
    {
         if(Size<n)
        {
           stc[Size]=x;
            Size++;
        }
        else
        {
            cout<<"your stack is expanding"<<endl;
            {
                int *t,i;
                n=2*n;
                t=new int [n];
                for(i=0;i<n;i++)
                {
                    t[i]=stc[i];
                }
                delete(stc);
                stc=t;
            }
            stc[Size]=x;
            Size++;
        }


    }

	void pop()
	{
	    if(Size>0)
	    {
            cout<<"pops "<<stc[Size-1]<<endl;
            Size--;
        }
        if(Size<(.25*n))
            {
                int *t,i;
                n=.25*n;
                t=new int [n];
                for(i=0;i<n;i++)
                {
                    t[i]=stc[i];
                }
                delete(stc);
                stc=t;
                cout<<"shrinks memory"<<endl;
            }
        }

	int SIZE()
	{
	    return Size;
	}
	int top()
	{
	    return stc[Size-1];
	}
	void display()
	{
	    if(Size!=0)
        {
            int i;
            for(i=0;i<Size;i++)
            {
                cout<<stc[i]<<endl;
            }
        }
        else
        {
            cout<<"Stack is empty"<<endl;
        }

	}
	~Stack()
	{
	    cout<<"Free the memory"<<endl;
	    free(stc);
	}
};

int main()
{
    int ch,element,SS;
    cout<<"Enter size of stack"<<endl;
    cin>>n;
    Stack s;

    while(1)
    {
        cout<<"*--------------------------------------------------------------------*"<<endl;
        cout<<"1.PUSH  2.POP  3.DISPLAY  7. SIZE  8.EXIT "<<endl;
        cout<<"*--------------------------------------------------------------------*"<<endl;
    cin>>ch;
    if(ch==1)
    {
        cout<<"push into stack ";
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
    else if(ch==7)
    {
        SS=s.SIZE();
        cout<<"SIZE OF STACK IS "<<SS<<endl;
    }
    else
        return 0;
    }
    return 0;
}

