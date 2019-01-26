#include<stdio.h>
#include<stdlib.h>
#define maxLength 100

int length=0;
int list[maxLength];


/***
insert n at the end of the list and increment length of the list
Check whether the list is full or not
In case of successful insertion return the index where the element has been inserted
Otherwise return failure
***/
int insertLast(int element){
    if(length==maxLength)
    {
        return -1;
    }
    else
        list[length]=element;
        length++;
        return length-1;
}

/**
insert element at given position pos. Here 0<=pos<=length
In case of successful insertion return the index where the element has been inserted
Return -1 if the list is full
Return -2 if the value of pos is outside of the valid range
**/
int insertAt(int element, int pos){
    int i;
    if(length+1>maxLength)
        return -1;
    if(pos>length || pos<0)
        return -2;
    for(i=length-1;i>=pos;i--)
    {
        list[i+1]=list[i];
    }
    list[pos]=element;
    length++;
    return pos;
}


/**
Print all the elements of the list
**/
void print(){
	int i;
	for(i=0;i<length;i++){
		printf("%d ",list[i]);
	}
	printf("\n");
}

/**
Find n in the list and return the index of the first occurrence
Return -1 if element is not present in the list
**/
int indexOf(int element){
    int i;
    for(i=0;i<length;i++)
    {
        if(element==list[i])
        {
            return i;
        }
    }
    return -1;
}


/**
Find n in the list and return the index of the last occurrence
Return -1 if element is not present in the list
**/
int lastIndexOf(int element){
    int i;
    for(i=length-1;i>=0;i--)
    {
        if(element==list[i])
            return i;
    }
    return -1;
}

/**
Delete the last element from the list
Return -1 if the list is empty
**/
int deleteLast(){
    if(length==0)
        return -1;
    else
        length--;
}

/**
Delete the element at a given position pos from the list
Here 0<=pos<length
Generate error message if the list is empty or pos is out of bound
**/
int deleteAt(int pos){
    int i;
    if(pos>length-1||pos<0)
        return -2;
    for(i=pos;i<length;i++)
    {
        list[i]=list[i+1];
    }
    length--;
    return pos;
}

/**
delete the first occurrence of element from the list
**/
int deleteElement(int element){
    int pos;
    pos=indexOf(element);
    if(pos!=-1)
        deleteAt(pos);
    return pos;
}

/**
Delete all occurrence of n from the list
**/
void deleteAllElement(int element){
    int res;
    while(1)
    {
        res=deleteElement(element);
        if(res==-1)
            return;
    }
}

int main(){
	int choice,element, pos, res;
	while(1){
		printf("\n***************************************************\n");
		printf("1. InsertLast  2. InsertAt  3. IndexOf  4. LastIndexOf\n");
		printf("5. DeleteLast  6. DeleteAt  7. DeleteElement   8. DeleteAllElement\n");
		printf("9. Print  10. Quit\n");
		printf("***************************************************\n\n");
		scanf("%d",&choice);
		switch(choice){
			case 0:
				return 0;
			case 1:
				printf("Enter element: ");
				scanf("%d",&element);
				res=insertLast(element);
				if(res==-1)
					printf("List is full\n");
				else
					printf("Inserted at position %d\n",res);
				break;
			case 2:
				printf("Enter element & position: ");
				scanf("%d %d",&element,&pos);
				res=insertAt(element,pos);
				if(res==-1)
					printf("List is full\n");
				else if(res==-2)
					printf("Incorrect pos value\n");
				else
					printf("Inserted at position %d\n",res);
				break;
			case 3:
				printf("Enter element: ");
				scanf("%d",&element);
				res=indexOf(element);
				if(res==-1)
					printf("Element not found\n");
				else
					printf("First index is %d\n",res);
				break;
			case 4:
				printf("Enter element: ");
				scanf("%d",&element);
				res=lastIndexOf(element);
				if(res==-1)
					printf("Element not found\n");
				else
					printf("Last index is %d\n",res);
				break;
			case 5:
				res=deleteLast(element);
				if(res==-1)
					printf("Empty List\n");
				else
					printf("Deleted from position %d\n",res);
				break;
			case 6:
				printf("Enter position: ");
				scanf("%d",&pos);
				res=deleteAt(pos);
				if(res==-1)
					printf("List Empty\n");
				else if(res==-2)
					printf("Incorrect pos value\n");
				else
					printf("Deleted from position %d\n",res);
				break;
			case 7:
				printf("Enter element: ");
				scanf("%d",&element);
				res=deleteElement(element);
				if(res==-1)
					printf("%d not exist in the list\n",element);
				else
					printf("Deleted from position %d\n",res);
				break;
			case 8:
				printf("Enter element: ");
				scanf("%d",&element);
				deleteAllElement(element);
				break;
			case 9:
				print();
				break;
            case 10:
				return 0;
		}
	}
	return 0;
}
