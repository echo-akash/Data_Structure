#include<stdio.h>
#include<stdlib.h>
#define init_size 4

int length;
int maxLength;
int *list;

void init();
void expand();
void shrink();
void print();

/**
Insert a given integer in such a position that the list remains sorted and print the modified list
Return index of the inserted element.
**/
int insert(int element){
	int i,j;
	for (i=0;i<length;i++){
        if (list[i]>=element){
            break;  // so here i will have the i value of where i have higher then
        }
	}

	for (j=length-1;j>=i;j--){
        list[j+1]=list[j];
	}
	list[i]=element;
	length++;
	if (length==maxLength){
        expand();
	}
	return i;
}

/**
Delete the first occurrence of a given integer from the list.
Return index of the deleted element.
If the given integer does not exist in the list return -1
**/
int remove(int element){
	int i,j;
    //if (length!=0){
        for (i=0;i<length;i++){
            if (list[i]==element){
                for (j=i;j<=length;j++){
                    list[j]=list[j+1];
                }
                length--;
                if (length<(maxLength/4)){
                    shrink();
                }
            return i;
            }
        }

        for (i=0;i<length;i++){
            if (list[i]!=element) return -1;
        }
}


/**
Determine if a given integer exists in the list.
Return index of the deleted element.
If the given integer does not exist in the list return -1
**/
int linear_search(int element){
	int i;
    for (i=0;i<length;i++){
        if (list[i]==element){
            return i;
        }
    }
    return -1;
}


/**
Each line of input starts with a code letter: I for insert, D for delete, L for linear search, P for print and Q for quit.
For I,D and L; the code letter is followed by a blank space and then an integer, which is to be inserted, deleted or found.
**/
int main(){
	char option; int element, result;
	init();
	while(1){
        printf("------------------------------------------------------------\n");
        printf("I: Insert,     D: Delete,     L: LinearSearch,     P: Print,\n");
        printf("Q: Quit\n");
        printf("------------------------------------------------------------\n\n\n");
        scanf("%c",&option);
		switch(option){
			case 'Q':
            case 'q':
				return 0;
			case 'I':
            case 'i':
				scanf("%d",&element);
				result=insert(element);
				printf("\nInserted at position %d\n",result);
				print();
				break;
			case 'D':
            case 'd':
				scanf("%d",&element);
				result=remove(element);
				if(result==-1){
					printf("\nElement not exist\n");
				}
				else{
					printf("\nDeleted from position %d\n",result);
				}
				print();
				break;
			case 'L':
            case 'l':
				scanf("%d",&element);
				result=linear_search(element);
				if(result==-1){
					printf("\nElement not exist\n");
				}
				else{
					printf("\nFound at position %d\n",result);
				}
				print();
				break;
			case 'P':
            case 'p':
				print();
				break;
		}
	}
}

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
    int *temp,i;
    maxLength=maxLength<<1;
    temp=(int*)malloc(sizeof(int)*maxLength);
    for(i=0;i<length;i++){
        temp[i]=list[i];
    }
    free(list);
    list=temp;
}

/**
Half the capacity of list
**/
void shrink(){
    int *temp,i;
    if(maxLength==init_size) return;
    maxLength=maxLength>>1;
    temp=(int*)malloc(sizeof(int)*maxLength);
    for(i=0;i<length;i++){
        temp[i]=list[i];
    }
    free(list);
    list=temp;
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
	getchar();
}

