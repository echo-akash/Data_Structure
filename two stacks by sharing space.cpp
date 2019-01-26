#include<iostream>
#include<stdlib.h>
using namespace std;
class twoStacks
{
    int *arr;
    int size,top1,top2;
    public:
    twoStacks(int n)
    {
        size=n;
        arr= new int[n];
        top1=0;
        top2=size-1;
    }
    void push1(int x)
    {
        cout<<top1<<" "<<top2<<endl;
        if(top1<=top2)
        {
            arr[top1++]=x;
            cout<<x<<" has been pushed in stk1."<<endl;
        }
        else
        {
            cout<<"stack overflow"<<endl;
            return;
        }
    }
    void push2(int x)
    {
        cout<<top1<<" "<<top2<<endl;
        if(top1<=top2)
        {
            arr[top2--]=x;
            cout<<x<<" has been pushed in stk2."<<endl;
        }
        else
        {
            cout<<"stack overflow"<<endl;
            return;
        }
    }
    int pop1()
    {
        cout<<top1<<" "<<top2<<endl;
        if(top1==0)
        {
            cout<<"stack underflow"<<endl;
            return -99999;
        }
        else
        {
            int x=arr[top1-1];
            top1--;
            return x;
        }
    }
    int pop2()
    {
        cout<<top1<<" "<<top2<<endl;
        if(top2==size-1)
        {
            cout<<"stack underflow"<<endl;
            return -99999;
        }
        else
        {
            int x=arr[top2+1];
            top2++;
            return x;
        }
    }
};

int main()
{
    twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push1(31);
    ts.push2(432);
    cout<<"popped element from stk1: "<<ts.pop1()<<endl;
    ts.push2(40);
    cout<<"popped element from stk2: "<<ts.pop2()<<endl;
    cout<<"popped element from stk1: "<<ts.pop1()<<endl;
    cout<<"popped element from stk2: "<<ts.pop2()<<endl;
}
