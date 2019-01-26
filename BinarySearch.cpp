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
int insertAt(int index)
{
    //length++;
    int i;
    for( i=length; i>index; i--)
    {
        list[i]=list[i-1];
    }
    length++;
}
int binary_insert(int element){
	// Write your code here
	if(length==0){
        list[0]=element;
        length++;
        return 0;
	}
	int lo=0,hi=length-1;
	int mid;
	while(lo<=hi){
        mid=(lo+hi)/2;
        if(element==list[mid]) break;
        if(element<list[mid]){
            hi=mid-1;
        }
        else if(element>list[mid]){
            lo=mid+1;
        }
	}
	if(list[mid]>=element){
        for(int j=length-1;j>=mid;j--){
        list[j+1]=list[j];
	    }
	    list[mid]=element;
	    length++;
	}
	else{
        mid++;
        for(int j=length-1;j>=mid;j--){
        list[j+1]=list[j];
	}
	    list[mid]=element;
	    length++;
	}
	return mid;
}

int insert(int element)
{
    int i;
    for(i=0; i<length; i++)
    {
        if(list[i]==element)
        {
            insertAt(i);
            list[i]=element;
            break;
        }

        else if(list[i]<element && list[i+1]>element)
        {
            insertAt(i+1);
            list[i]=element;
            break;
        }
    }

    if (maxLength==length) expand();

}

/**
Delete the first occurrence of a given integer from the list.
Return index of the deleted element.
If the given integer does not exist in the list return -1
**/
int remove(int element){
	// Write your code here
	int i,j;
//	for(i=0;i<length;i++)
//    {
//        if(list[i]==element)
//        {
//            break;
//        }
//    }

    int hi=length-1,lo=0;
    while(lo<=hi)
    {
        int mid=(hi+lo)/2;
        if(list[mid]==element)
        {
            i=mid;
            break;
        }
        else if(list[mid]>element) hi=mid-1;
        else lo=mid+1;
        if(lo>hi) return -1;
    }
    //if(i==length-1) return -1;
    for(j=i;j<length-1;j++)
    {
        list[j]=list[j+1];
    }
    length--;
    if(length<maxLength/4) shrink();
    return i;
}

/**
Determine if a given integer exists in the list.
Return index of the deleted element.
If the given integer does not exist in the list return -1
**/
int linear_search(int element){
	// Write your code here
	int i;
	for(i=0;i<length;i++)
    {
        if(list[i]==element) return i;
    }
    return -1;
}

/**
Perform binary search in the sorted list
return index of the element if exist
otherwise return -1
**/
int binary_search(int element){
    int hi=length-1,lo=0;
    while(lo<=hi)
    {
        int mid=(hi+lo)/2;
        if(list[mid]==element) return mid;
        else if(list[mid]>element) hi=mid-1;
        else lo=mid+1;
        if(lo>hi) return -1;
    }

}
int firstIndexOf(int element)
{
    int i,j,hi=length-1,lo=0;
    while(lo<=hi)
    {
        int mid=(hi+lo)/2;
        if(list[mid]==element)
        {
            if(mid==0) return mid;
            if(list[mid-1]==element) hi=mid-1;
            else return mid;
        }
        else if(list[mid]>element) hi=mid-1;
        else lo=mid+1;
        if(lo>hi) return -1;
    }
}

int lastIndexOf(int element)
{
    int i,j,hi=length-1,lo=0;
    while(lo<=hi)
    {
        int mid=(hi+lo)/2;
        if(list[mid]==element)
        {
            if(mid==length-1) return mid;
            if(list[mid+1]==element) lo=mid+1;
            else return mid;
        }
        else if(list[mid]>element) hi=mid-1;
        else lo=mid+1;
        if(lo>hi) return -1;
    }
}

int numberOfOccurence(int element)
{

        int a=firstIndexOf(element);
        int b=lastIndexOf(element);
        int ans=b-a+1;
        if(a==-1 && b==-1) return -1;
        return ans;
}

int smallest_missing_num()
{
    int lo=0,hi=length-1;
    if(list[0]!=1) return 1;
    else
    {
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;

            if(hi-lo==1) return hi+1;
            else if(list[mid]==mid+1) lo=mid;
            else hi=mid;
        }
    }

}

/**
Each line of input starts with a code letter: I for insert, D for delete, L for linear search, B for binary search, P for print and Q for quit.
For I,D,L and B; the code letter is followed by a blank space and then an integer, which is to be inserted, deleted or found.
**/
int main(){
	char option; int element,result;
	init();
	while(1){
        printf("\nPlease Enter Your Choice\n\n");
        printf("Q.Quit   I.Binary_Insert   D.Remove   L.Linear_Search   B.Binary_Search   P.Print  N.Number of occurance   S.Smallest missing number\n\n");
		scanf("%c",&option);
		switch(option){
			case 'Q':
				return 0;
			case 'I':
				scanf("%d",&element);
				result=binary_insert(element);
				printf("\nInserted at position %d\n",result);
				print();
				break;
			case 'D':
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
			case 'B':
				scanf("%d",&element);
				result=binary_search(element);
				if(result==-1){
					printf("\nElement not exist\n");
				}
				else{
					printf("\nFound at position %d\n",result);
				}
				print();
				break;
            case 'N':
                scanf("%d",&element);
                result=numberOfOccurence(element);
                if(result==-1) printf("element does not exist\n");
                else printf("found %d times\n",result);
			case 'P':
				print();
				break;
            case 'S':
                int ans=smallest_missing_num();
                printf("%d\n",ans);
		}
	}
	return 0;
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
}
//Binary Search.cpp
//Open with
//Displaying Binary Search.cpp.
