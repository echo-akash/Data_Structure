

#include<stdio.h>
#include<stdlib.h>
#define init_size 4

int length;
int maxLength;
int *list;

/**
Initialize the list with maximum length=init_size
**/
void init(){

    list=(int*)malloc(sizeof(int)*init_size);
    maxLength=init_size;
    length=0;
}

/**
Double the capacity of the list
Hint: Double the value of maxLength, Take another integer pointer
    Allocate memory of size maxlength to it and copy the content from previous list to it
    Release the memory occupied by previous list and assign new list to the previous one
**/
void expand(){
     int p=2*maxLength;
     list=realloc(list,p);

}

/**
Half the capacity of list
**/
void shrink(){
    int p=maxLength/2;
    list=realloc(list,p);
}


/***
insert n at the end of the list and increment length of the list
Check whether the list is full or not, if full expand the list
In case of successful insertion return the index where the element has been inserted
Otherwise return -1
***/
int insertLast(int element){
    if(length == maxLength) expand();
    list[length]=element;
    length++;
    return length-1;
}

/**
insert element at given position pos. Here 0<=pos<=length
Check whether the list is full or not, if full expand the list
In case of successful insertion return the index where the element has been inserted
Return -1 if the value of pos is outside of the valid range
**/
int insertAt(int element, int pos){
    if(length==maxLength) expand();
    if(pos<0 || pos>length)
        return -2;
    int i;
    for(i=length;i>=pos;i--){
        list[i+1]=list[i];
    }
    length++;
    list[pos]=element;
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
Find element in the list and return the index of the first occurrence
Return -1 if element is not present in the list
**/
int indexOf(int element){
    int i;
    for(i=0;i<length;i++){
        if(list[i]==element){
            return i;
        }
    }
    return -1;
}


/**
Find element in the list and return the index of the last occurrence
Return -1 if element is not present in the list
**/
int lastIndexOf(int element){
    int i;
    for(i=length-1;i>=0;i--){
        if(list[i]==element){
            return i;
        }
    }
    return -1;
}

/**
Delete the last element from the list
Return -1 if the list is empty
Shrink the list if the current length of the list is less than one fourth of the maxLength
**/
int deleteLast(){
    if(length==0)
        return -1;
    length=length-1;

    if(length<maxLength/4) shrink();
}

/**
Delete the element at a given position pos from the list
Here 0<=pos<length
Return -1 if the list is empty
Return -2 if the pos value is outside of the valid range
Shrink the list if the current length of the list is less than one fourth of the maxLength
**/
int deleteAt(int pos){
    int i;
    for(i=pos;i<length-1;i++){
        list[i]=list[i+1];
    }
    length--;
    if(length<maxLength/4) shrink();
    return length;
}

/**
delete the first occurrence of n from the list
Return -1 if the list is empty
Shrink the list if the current length of the list is less than one fourth of the maxLength
**/
int deleteElement(int n){
    int pos;
    pos=indexOf(n);
    if(pos!=-1){
        deleteAt(pos);
    }
    return pos;
}

/**
Delete all occurrence of n from the list
Shrink the list if the current length of the list is less than one fourth of the maxLength
**/
void deleteAllElement(int n){
    if(length==0){
        return -1;
    }
    int pos;
    while(1)
    {
        pos=deleteElement(n);
        if(pos==-1)
        {
            break;
        }
    }
}

int main(){
	int choice,element, pos, res;
	init();
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
				res=deleteLast();
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
					printf("Deleted from position %d\n",pos);
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
                exit(1);
                break;
		}
	}
	return 0;
}

