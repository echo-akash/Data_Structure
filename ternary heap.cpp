#include<bits/stdc++.h>
#define SIZE 100
using namespace std;



int heapSize(int a[])
{
    for(int i=1;i<SIZE;i++)
    {
        if(a[i]==-9999999) return i-1;
    }
}

int parent(int i)
{
    return (i+1)/3;
}
int left(int i)
{
    return 3*i-1;
}
int  mid(int i)
{
    return 3*i;
}
int right(int i)
{
    return 3*i+1;
}
void heapify(int a[], int i)
{
    //cout<<a[i]<<endl;
    int largest=i;
    int l=left(i);
    int m=mid(i);
    int r=right(i);
    int sz=a[0];
    if(l>sz )
    {
        return;
    }
    if(l<=sz && a[l]>a[largest])
    {
        largest=l;
    }
    if(m<=sz && a[m]>a[largest] )
    {
        largest=m;
    }
    if(r<=sz && a[r]>a[largest])
        {
            largest=r;
        }

    if(largest!=i)
    {
        swap(a[i],a[largest]);
        heapify(a,largest);
    }
    //cout<<"DS";


}
bool checkHeap(int a[])
{
    for(int i=1;i<=heapSize(a)/3;i++)
    {
        int largest;
        int l=left(i);
        int m=mid(i);
        int r=right(i);
        if(l<=heapSize(a)&& a[l]>a[i])
        {
            return false;
        }
        else if(m<=heapSize(a) && a[m]>a[i] )
        {
            return false;
        }
        if(r<=heapSize(a)&& a[r]>a[i])
        {
            return false;
        }

    }
    return true;
}

void buildHeap(int a[])
{
    int temp=heapSize(a);
    for(int i=temp/3;i>=1;i--)
    {
        //cout<<"JDds"<<endl;
        heapify(a,i);
    }
    a[0]=heapSize(a);
}

int heapMaximum(int a[])
{
    return a[1];
}

void upheap(int a[],int i)///kaj korena
{
    int sz=heapSize(a);
    if(i<=1) return;
    //for(int i=sz;i>=1;i--)
    //{
        if(a[parent(i)]>a[i])
        {
            swap(a[i],a[parent(i)]);
            upheap(a,parent(i));
        }
    //}

}
void upheapbuild(int a[])///kaj korena
{
    int sz=heapSize(a);
    for(int i=sz;i>=1;i--)
    {
        upheap(a,i);
    }
}

void heapsort(int a[],int b[])
{
    //buildHeap(a);
    b[0]=a[0];
    for(int i=1;i<=a[0];i++)
    {
        b[i]=a[i];
        //cout<<b[i]<<ends;
    }
    int temp=heapSize(b);
    for(int i=b[0];i>=2;i--)
    {
        swap(b[1],b[i]);
        b[0]--;
        heapify(b,1);
    }
}

void preorder(int a[],int i)
{
    if(i>a[0]) return;
    cout<<a[i]<<ends;
    preorder(a,left(i));
    preorder(a, mid(i));
    preorder(a,right(i));
}


class pq
{
public:

    int arr[SIZE];
    int size;
    pq()
    {
        for(int i=0;i<SIZE;i++)
        {
            arr[i]=-9999999;
        }
        arr[0]=10;
        arr[1]=4;
        arr[2]=1;
        arr[3]=3;
        arr[4]=2;
        arr[5]=16;
        arr[6]=9;
        arr[7]=10;
        arr[8]=14;
        arr[9]=8;
        arr[10]=7;

    }


    void insert(int key)
    {
        int temp=heapSize(arr);
            arr[0]++;
            temp++;
            arr[arr[0]]=-1000000;
            increaseKey(temp,key);
    }
    int findMax()
    {
        return arr[1];
    }
    void extractMax()
    {

        if(heapSize(arr)<1)
        {
            cout<<"Heap underflow"<<endl;
            return;
        }
        int mx=arr[1];
        arr[1]=arr[arr[0]];
        arr[arr[0]]=-9999999;
        arr[0]--;
        heapify(arr,1);
        //return mx;
    }
    void dlt(int i)
    {
        if(i>arr[0])
        {
            cout<<"invalid index"<<endl;
            return;
        }

        arr[i]=arr[arr[0]];
        arr[arr[0]]=-9999999;
        arr[0]--;
        heapify(arr,i);
    }
    void increaseKey(int i, int key)
    {
        if(key<arr[i])
        {
            cout<<"new key is smaller than the current key"<<endl;
            return;
        }
        arr[i]=key;
        while(i>1 && arr[parent(i)]<arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i=parent(i);
        }
        return;
    }

    void decreaseKey(int i, int key)///kaj korena
    {
        if(key>arr[i])
        {
            cout<<"new key is greater than the current key"<<endl;
            return;
        }
        arr[i]=key;
        heapify(arr,i);
        //cout<<arr[i]<<endl;
//        while(i<arr[0] && (arr[left(i)]>arr[i] || arr[right(i)]>arr[i] && arr[mid(i)]>arr[i]))
//        {
//            int p;
//            if(arr[left(i)]>arr[i]) p=left(i);
//            else if(arr[mid(i)]>arr[i] && arr[mid(i)]>p) p=mid(i);
//            else p=right(i);
//            //cout<<arr[p]<<endl;
//            swap(arr[i], arr[p]);
//            i=p;
//        }
        return;
    }
    void print()
    {
        for(int i=1;i<SIZE;i++)
        {
            if(arr[i]==-9999999) break;
            cout<<arr[i]<<ends;
        }
        cout<<endl;
    }

};
int main()
{
    pq p;
    //cout<<"ASD";
    if(!checkHeap(p.arr))
    {
        //p.print();
        buildHeap(p.arr);
        p.print();
    }
    while(1)
    {
        p.arr[0]=heapSize(p.arr);
        printf("1.Insert 2. findMax 3. ExtractMax 4.Delete(i)\n");
        printf("5. IncreaseKey 6.Print 7. HeapSort 8.DecreaseKey\n");
        printf("9. Preorder\n\n");
        int choice;
        cin>>choice;
        if(choice==1)
        {
            int x;
            cin>>x;
            p.insert(x);
            p.print();
        }
        else if(choice==2)
        {
            cout<<p.findMax()<<endl;
        }
        else if(choice == 3)
        {
            p.extractMax();
            p.print();
        }
        else if(choice == 4)
        {
            int i;
            cin>>i;
            p.dlt(i);
            p.print();
        }
        else if(choice == 5)
        {
            int i,k;
            cin>>i>>k;
            p.increaseKey(i,k);
            p.print();
        }
        else if(choice == 6)
        {
            p.print();
        }
        else if(choice == 7)
        {
            int b[SIZE];
            memset(b,-1,sizeof b);
            heapsort(p.arr,b);
            for(int i=1;i<SIZE;i++)
            {
                if(b[i]==-1) break;
                cout<<b[i]<<ends;
            }
            cout<<endl;
            p.print();
            //upheapbuild(p.arr);
        }
        else if(choice == 8)
        {
            int i,k;
            cin>>i>>k;
            p.decreaseKey(i,k);
            p.print();
        }
        else if(choice ==9)
        {
            preorder(p.arr,1);
            cout<<endl;
        }
    }


}



