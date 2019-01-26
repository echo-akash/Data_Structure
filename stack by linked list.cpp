#include<iostream>
#include<stdio.h>
#include<stdlib.h>

#define FAILURE -9999999
#define SUCCESS 9999999
using namespace std;
int cnt=0;
typedef struct Node
{
    int element;
    struct Node * next;
}node;

node* list;

void init()
{
    list = 0;  //initially set to NULL
}

int insertFirst(int element) //insert at the beginning
{
	node * newNode ; // create a new pointer to node
	newNode = (node*) malloc (sizeof(node)) ; // allocate memory for a new node instance and assign pointer to it to newNode
	newNode->element = element ;// update value of the newNode
	if(list==NULL)
    {
        list=newNode;
        newNode->next=NULL;
        cnt++;
        return SUCCESS;
    }
	newNode->next = list ; //point to previous first node
	list = newNode ;
	cnt++; //set list to point to newnode as this is now the first node
	return SUCCESS ;
}


int deleteElement(int element)
{
	node *temp, *prev ;
	temp = list ; //start at the beginning
	while (temp != 0)
	{
		if (temp->element == element) break ;
		prev = temp;
		temp = temp->next ; //move to next node
	}
	if (temp == 0) return FAILURE ; //item not found to delete
	if (temp == list) //delete the first node
	{
		list = list->next ;
		free(temp) ;
	}
	else
	{
		prev->next = temp->next ;
		free(temp);
	}
	return SUCCESS;
}

node* searchItem(int element)
{
	node * temp ;
	temp = list ; //start at the beginning
	while (temp != 0)
	{
		if (temp->element == element) return temp ;
		temp = temp->next ; //move to next node
	}
	return 0 ; //0 means invalid pointer in C, also called NULL value in C
}

void printList()
{
    node * temp;
    temp = list;
    while(temp!=0)
    {
        printf("%d\n", temp->element);
        temp = temp->next;
    }
    printf("\n");
}

/**
Insert element at the end of the list
Retrun SUCCESS for successful insertion
**/
int insertLast(int element1)
{
    //write your codes here
    node* newItem;
    newItem = (node*) malloc (sizeof(node)) ;
    node* temp;
    if(list==NULL)
    {
        list=newItem;
        newItem->element=element1;
        newItem->next=NULL;
    }
    else
    {
        temp=list;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        newItem->element=element1;
        temp->next=newItem;
        newItem->next=NULL;

    }

    //free(temp);
    return SUCCESS;
}

/**
Insert newElement after the first occurrence of oldElement
Return SUCCESS for successful insertion
Return FAILURE if oldElement not exist in the list
**/
int insertAfter(int oldElement, int newElement)
{
    int flag=0;
    node* prev;
    node* newItem;
    newItem = (node*) malloc (sizeof(node)) ;
    newItem->element=newElement;
    newItem->next=NULL;
    prev=list;
    while(prev!=NULL)
    {
        if(prev->element==oldElement)
        {
            flag=1;
            break;
        }
        prev=prev->next;
    }

    if(flag==1)
    {
        newItem->next=prev->next;
        prev->next=newItem;
    }

    //free(prev);
    if(flag==0) return FAILURE;
    else return SUCCESS;
    //write your codes here
}

/**
Delete the last element of the list
Return SUCESS for successful deletion
Return Failure for unsuccessful deletion
**/
int deleteLast()
{
    node* prev;
    node* cur;
    cur=list;
    if(list==NULL) return FAILURE;
    if(list->next==NULL)
    {
        list=list->next;
        free(cur);
        cnt--;
        return SUCCESS;
    }
    while(cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    if(prev!=NULL)
    {
        prev->next=NULL;
    }
    free(cur);
    cnt--;
    return SUCCESS;
    //write your codes here
}

/**
Delete the first element of the list
Return SUCESS for successful deletion
Return Failure for unsuccessful deletion
**/
int deleteFirst()
{
    node* temp;
    temp=list;
    int ans=temp->element;
    if(list!=NULL)
    {
        list=list->next;
        free(temp);
    }
    cnt--;
    return ans;
    //write your codes here
}

int stack_size()
{
    return cnt;
}
void push(int x)
{
    insertFirst(x);
}

int pop()
{
    int a=deleteFirst();
    return a;
}

void print()
{
    printList();
}
int main(void)
{
    init();
    while(1)
    {
        printf("1. Push 2. Pop 3. Size 4. Print 5. Top 6. Exit\n");
        int choice;
        cout<<"enter choice: ";
        cin>>choice;
        if(choice==1)
        {
            int x;
            cout<<"enter element: ";
            cin>>x;
            push(x);
            print();
        }
        else if(choice==2)
        {
            if(stack_size()>0)
            {
                int a=pop();
                cout<<a<<" has been popped"<<endl;
            }
            else cout<<"empty stack"<<endl;

            print();
        }
        else if(choice==3)
        {
            cout<<"size is: "<<stack_size()<<endl;
        }
        else if(choice==4)
        {
            print();
        }
        else if(choice==5)
        {
            if(cnt==0) cout<<"no element in stack"<<endl;
            else cout<<list->element<<endl;
        }
        else if(choice==6) return 0;
    }

}
