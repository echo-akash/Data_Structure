#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
};

struct node *head;

void init()
{
    head=NULL;
}

void insertfirst(int element)
{
    struct node *New;
    New=(struct node*)malloc(sizeof(struct node));
    New->value=element;
    New->next=NULL;
    New->next=head;
    head=New;
}

void print()
{
    if(head==NULL)
    {
        printf("list is empty\n");
        return;
    }
    struct node *cur=head;
    int count;
    count=0;
    while(cur!=NULL)
    {
        printf("%d->",cur->value);
        count++;
        cur=cur->next;
    }
    printf("NULL\n");
    printf("number of nodes %d\n",count);
}

void deleteitem(int ele)
{
    if(head==NULL)
        printf("list is empty and nothing to delete\n");
    struct node* cur=head;
    struct node* prev=NULL;
    while(cur->value!=ele)
    {
        prev=cur;
        cur=cur->next;
    }
    if(prev!=NULL)
        prev->next=cur->next;
    free(cur);
}

int searchitem(int ele)
{
    struct node* temp ;
	temp = head;
	while (temp != 0)
	{
		if (temp->value == ele)
            return 1 ;
		temp = temp->next;
	}
	return 0 ;
}

void insertlast(int ele)
{
    struct node *New, *temp;
    New = (struct node*)malloc(sizeof(struct node));
    if(New== NULL)
    {
        printf("Unable to allocate memory.");
        return;
    }
    else
    {
        New->value = ele;
        New->next = NULL;
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = New;
        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

void deletelast()
{
    if(head==NULL)
    {
        printf("list is empty and nothing to delete\n");
    }
    struct node* cur=head;
    struct node* prev=NULL;
    while(cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    if(prev->next!=NULL)
        prev->next=NULL;
    free(cur);
}

void deletefirst()
{
    struct node* cur;
    if(head==NULL)
        printf("list is empty and nothing to delete\n");
    cur=head;
    head=head->next;
    free(cur);
}

void insertafter(int elem, int num)
{
    struct node* New;
    New=(struct node*)malloc(sizeof(struct node));
    New->value=elem;
    New->next=NULL;
    struct node* prev=head;
    while(prev->value!=num)
    {
        prev=prev->next;
    }
    New->next=prev->next;
    prev->next=New;
}

void printReverse(struct node* head)
{
    if (head == NULL)
       return;
    printReverse(head->next);
    printf("%d->", head->value);
}

void reverselist()
{
    struct node* prev=NULL;
    struct node* cur=head;
    struct node* nxt;
    while(cur!=NULL)
    {
        nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
    }
    head=prev;
}

void sum()
{
    int s;
    struct node *cur=head;
    s=0;
    while(cur!=NULL)
    {
        s+=cur->value;
        cur=cur->next;
    }
    printf("Sum of elements is %d\n",s);
}


int main()
{
    init();

    int ch,element;
    while(1)
    {
        printf("\n1. Insert new item. 2. Delete item. 3. Search item. 4. Insert Last. 5. Print. 6.Delete Last 7.Delete First 8.Insert After 9.Print Linked List in Reverse way. 10.Sum 11.Make the linked list reverse 12.Exit\n--------------------------------------------------------------------------------------\n");
        printf("enter choice of input: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("enter element to list: ");
            scanf("%d",&element);
            insertfirst(element);
        }
        else if(ch==2)
        {
            int de;
            printf("enter element to delete ");
            scanf("%d",&de);
            deleteitem(de);
        }
        else if(ch==3)
        {
            int se,reply;
            printf("enter element to search ");
            scanf("%d",&se);
            reply=searchitem(se);
            if(reply==1)
                printf("element found\n");
            else
                printf("element not found\n");
        }
        else if(ch==4)
        {
            int le;
            printf("enter element to insert at last ");
            scanf("%d",&le);
            insertlast(le);
        }
        else if(ch==5)
        {
            print();
        }
        else if(ch==6)
        {
            deletelast();
        }
        else if(ch==7)
        {
            deletefirst();
        }
        else if(ch==8)
        {
            int ie,p;
            printf("enter element to insert: ");
            scanf("%d",&ie);
            printf("enter after which element to insert: ");
            scanf("%d",&p);
            insertafter(ie,p);
        }
        else if(ch==9)
        {
            printReverse(head);
        }
        else if(ch==10)
        {
            sum();
        }
        else if(ch==11)
        {
            reverselist();
        }
        else if(ch==12)
            return 0;
        else
            return 0;
    }
    return 0;
}
















































/*
//finding linked list from another linked list
bool findList(Node* first, Node* second)
{
    Node* ptr1 = first, *ptr2 = second;

    // If both linked lists are empty, return true
    if (first == NULL && second == NULL)
        return true;

    // Else If one is empty and other is not return
    // false
    if ( first == NULL ||
        (first != NULL && second == NULL))
        return false;

    // Traverse the second list by picking nodes
    // one by one
    while (second != NULL)
    {
        // Initialize ptr2 with current node of second
        ptr2 = second;

        // Start matching first list with second list
        while (ptr1 != NULL)
        {
            // If second list becomes empty and first
            // not then return false
            if (ptr2 == NULL)
                return false;

            // If data part is same, go to next
            // of both lists
            else if (ptr1->data == ptr2->data)
            {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }

            // If not equal then  break the loop
            else break;
        }

        // Return true if first list gets traversed
        // completely that means it is matched.
        if (ptr1 == NULL)
            return true;

        // Initialize ptr1 with first again
        ptr1 = first;

        // And go to next node of second list
        second = second->next;
    }

    return false;
}

//FROM MAIN FUNCTION SEND THE INITIAL NODE OF BOTH LINKED LIST

*/






/*
//sorting in linked list

struct node* SortedMerge(struct node* a, struct node* b);
void FrontBackSplit(struct node* source,
          struct node** frontRef, struct node** backRef);

// sorts the linked list by changing next pointers (not data)
void MergeSort(struct node** headRef)
{
  struct node* head = *headRef;
  struct node* a;
  struct node* b;

  //Base case -- length 0 or 1
  if ((head == NULL) || (head->next == NULL))
  {
    return;
  }

  // Split head into 'a' and 'b' sublists
  FrontBackSplit(head, &a, &b);

  // Recursively sort the sublists
  MergeSort(&a);
  MergeSort(&b);

  // answer = merge the two sorted lists together
  *headRef = SortedMerge(a, b);
}

struct node* SortedMerge(struct node* a, struct node* b)
{
  struct node* result = NULL;

  // Base cases
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);

  // Pick either a or b, and recur
  if (a->data <= b->data)
  {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}

// UTILITY FUNCTIONS
//Split the nodes of the given list into front and back halves, and return the two lists using the reference parameters. If the length is odd, the extra node should go in the front list. Uses the fast/slow pointer strategy.
void FrontBackSplit(struct node* source,
          struct node** frontRef, struct node** backRef)
{
  struct node* fast;
  struct node* slow;
  if (source==NULL || source->next==NULL)
  {
    // length < 2 cases
    *frontRef = source;
    *backRef = NULL;
  }
  else
  {
    slow = source;
    fast = source->next;

    //Advance 'fast' two nodes, and advance 'slow' one node
    while (fast != NULL)
    {
      fast = fast->next;
      if (fast != NULL)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }

    // 'slow' is before the midpoint in the list, so split it in two at that point.
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
  }
}

//FROM MAIN SEND THE SORT(&HEAD)

*/



/*
//partition of linked list

struct Node *partition(struct Node *head, int x)
{
    // Let us initialize first and last nodes of three linked lists 1) Linked list of values smaller than x. 2) Linked list of values equal to x. 3) Linked list of values greater than x.
    struct Node *smallerHead = NULL, *smallerLast = NULL;
    struct Node *greaterLast = NULL, *greaterHead = NULL;
    struct Node *equalHead = NULL, *equalLast = NULL;

    // Now iterate original list and connect nodes
    // of appropriate linked lists.
    while (head != NULL)
    {
        // If current node is equal to x, append it
        // to the list of x values
        if (head->data == x)
        {
            if (equalHead == NULL)
                equalHead = equalLast = head;
            else
            {
                equalLast->next = head;
                equalLast = equalLast->next;
            }
        }

        // If current node is less than X, append
        // it to the list of smaller values
        else if (head->data < x)
        {
            if (smallerHead == NULL)
                smallerLast = smallerHead = head;
            else
            {
                smallerLast->next = head;
                smallerLast = head;
            }
        }
        else // Append to the list of greater values
        {
            if (greaterHead == NULL)
                greaterLast = greaterHead = head;
            else
            {
                greaterLast->next  = head;
                greaterLast = head;
            }
        }

        head = head->next;
    }

    // Fix end of greater linked list to NULL if this
    // list has some nodes
    if (greaterLast != NULL)
        greaterLast->next = NULL;

    // Connect three lists

    // If smaller list is empty
    if (smallerHead == NULL)
    {
        if (equalHead == NULL)
            return greaterHead;
        equalLast->next = greaterHead;
        return equalHead;
    }

    // If smaller list is not empty
    // and equal list is empty
    if (equalHead == NULL)
    {
        smallerLast->next = greaterHead;
        return smallerHead;
    }

    // If both smaller and equal list
    // are non-empty
    smallerLast->next = equalHead;
    equalLast->next = greaterHead;
    return  smallerHead;
}


//FROM MAIN CALL partition(head, x);
*/






































































