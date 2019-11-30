#include<iostream>
#include<stack>
using namespace std;

void displayStack(stack <int> s2)
{
       while(s2.empty()!=true)
       {
           cout<<s2.top()<<" ";
           s2.pop();
       }
}
int main()
{
    stack <int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.pop();
    //cout<<"Top element: "<<s1.top();
    displayStack(s1);// pass by reference
    cout<<endl<<s1.top();


}
