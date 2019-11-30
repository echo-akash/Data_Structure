#include<bits/stdc++.h>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int sz;
public:
    Stack(int sz)
    {
        this->sz=sz;
        top=-1;
        arr=new int[sz];
    }
    void push(int x)
    {
        if(top<sz)
        {
            arr[++top]=x;
        }
        else cout<<"The stack is full\n";
    }
    void pop()
    {
        if(top<0)cout<<"The stack is empty\n";
        else top--;
    }
    void displayStack()
    {
        for(int i=0;i<=top;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};


int main()
{
    Stack s1(10);

    while(1)
    {
    cout<<"\n1.PUSH\n2.POP\n3.DISPLAY\n";
    int s;
    cout<<"Enter your choice: ";
    cin>>s;

    switch(s)
    {
    case 1:
        int a;
        cin>>a;
        s1.push(a);
        system("cls");
        break;
    case 2:
        system("cls");
        s1.pop();
        break;
    case 3:
        s1.displayStack();
        break;
    default:
        cout<<"Invalid choice";
    }
    }

}
