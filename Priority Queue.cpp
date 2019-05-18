//final
#include<bits/stdc++.h>
#define SIZE 100
using namespace std;



int heapSize(int a[])
{
    for(int i=1;i<SIZE;i++)
    {
        if(a[i]==-9999999 || a[i]==9999999) return i-1;
    }
}

int parent(int i)
{
    return i/2;
}
int left(int i)
{
    return 2*i;
}
int right(int i)
{
    return 2*i+1;
}
void heapify(int a[], int i)
{
    int largest;
    int l=left(i);
    int r=right(i);
    int sz=a[0];
    if(l>sz ) return;
    if(l<=sz && a[l]>a[i])
    {
        largest=l;
    }
    else largest=i;
    if(r<=sz&& a[r]>a[largest])
    {
        largest=r;
    }
    //cout<<i<<" "<<largest<<endl;
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        heapify(a,largest);
    }
    //cout<<"DS";


}
bool checkHeap(int a[])
{
    for(int i=1;i<=heapSize(a)/2;i++)
    {
        int largest;
        int l=left(i);
        int r=right(i);
        if(l<=heapSize(a)&& a[l]>a[i])
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
    for(int i=temp/2;i>=1;i--)
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


void heapsort(int a[],int b[])///using temporary array
{
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

void heapsort2(int a[])///without any temporary array
{
    int temp=heapSize(a);
    for(int i=a[0];i>=2;i--)
    {
        swap(a[1],a[i]);
        a[0]--;
        heapify(a,1);
    }
}

void preorder(int a[],int i)
{
    if(i>a[0]) return;
    cout<<a[i]<<ends;
    preorder(a,left(i));
    preorder(a,right(i));
}

class pq
{
public:

    int arr[SIZE];
    int size;
public:
    pq()
    {
        for(int i=0;i<SIZE;i++)
        {
            arr[i]=-9999999;
        }
        ///16 14 10 8 7 9 3 2 4 1
//        arr[0]=10;
//        arr[1]=4;
//        arr[2]=1;
//        arr[3]=3;
//        arr[4]=2;
//        arr[5]=16;
//        arr[6]=9;
//        arr[7]=10;
//        arr[8]=14;
//        arr[9]=8;
//        arr[10]=7;
        arr[1]=100;
        arr[2]=10;
        arr[3]=50;
        arr[4]=3;
        arr[5]=4;
        arr[6]=30;
        arr[7]=40;

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

    int extractMin()
    {
        if(heapSize(arr)<1)
        {
            cout<<"Heap Underflow"<<endl;
            return -1;
        }
        int mn=1e7;
        int mni=-1;
        for(int i=arr[0]/2+1;i<=arr[0];i++)
        {
            if(arr[i]<mn)
            {
                mn=arr[i];
                mni=i;
            }
        }
        int res=mn;
        swap(arr[mni],arr[arr[0]]);
        arr[arr[0]]=99999999;
        arr[0]--;
        cout<<mni<<ends<<arr[arr[0]]<<endl;
        heapify(arr,parent(mni));
        return mn;
    }


    int extractMin2()
    {
        if(heapSize(arr)<1)
        {
            cout<<"Heap Underflow"<<endl;
            return -1;
        }
        int mn=1e7;
        int mni=-1;
        for(int i=arr[0]/2+1;i<=arr[0];i++)
        {
            if(arr[i]<mn)
            {
                mn=arr[i];
                mni=i;
            }
        }
        int res=mn;
        dlt(mni);
        return mn;
    }


    void dlt(int i)
    {
        if(i>arr[0])
        {
            cout<<"invalid index"<<endl;
            return;
        }
        int x=arr[i];
        int y=arr[arr[0]];
        if(x>=y)
        {
            arr[i]=arr[arr[0]];
            arr[arr[0]]=-9999999;
            arr[0]--;
            heapify(arr,i);
        }
        else
        {
            increaseKey(i,y);
            arr[arr[0]]=-9999999;
            arr[0]--;
        }

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
        //cout<<arr[i]<<endl;
        while(i<arr[0] && (arr[left(i)]>arr[i] || arr[right(i)]>arr[i]))
        {
            int p;
            if(arr[left(i)]>arr[i]) p=left(i);
            else p=right(i);
            //cout<<arr[p]<<endl;
            swap(arr[i], arr[p]);
            i=p;
        }
        return;
    }

    void print()
    {
//        for(int i=1;i<SIZE;i++)
//        {
//            if(arr[i]==-9999999) break;
//            cout<<arr[i]<<ends;
//        }
        for(int i=1;i<=arr[0];i++)
        {
            cout<<"\t"<<arr[i]<<ends;
        }
        cout<<endl;
    }

    void largerThan(int x, int pos)
    {
        if(arr[1]<x)
        {
            cout<<"There is no element larger than "<<x<<endl;
            return;
        }
        if(pos>heapSize(arr))
            return;
        if(arr[pos]<=x)
        {
            return;
        }
        cout<<arr[pos]<<ends;
        largerThan(x,right(pos));
        largerThan(x,left(pos));
    }

};
int main()
{
    pq p;
    //cout<<"ASD";
    if(!checkHeap(p.arr))
    {
        cout<<"das"<<endl;
        buildHeap(p.arr);
        p.print();
    }
    p.arr[0]=heapSize(p.arr);
    while(1)
    {
        printf("1.Insert 2. findMax 3. ExtractMax 4.Delete(i)\n");
        printf("5. IncreaseKey 6.Print 7. HeapSort 8.DecreaseKey\n");
        printf("9. Preorder 10. ExtractMin 11. Larger than 12. Exit\n\n");
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
            //int b[SIZE];
            //memset(b,-1,sizeof b);
            //heapsort(p.arr,b);
            heapsort2(p.arr);
            for(int i=1;i<SIZE;i++)
            {
                if(p.arr[i]<=-99) break;
                cout<<"\t"<<p.arr[i]<<ends;
            }
            cout<<endl;
            p.arr[0]=heapSize(p.arr);
            buildHeap(p.arr);
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
        else if(choice==10)
        {
            int ans=p.extractMin();
            if(ans==-1);
            else cout<<"Min is "<<ans<<" which has been extracted"<<endl;
            p.print();
        }
        else if(choice == 11)
        {
            int key;
            cin>>key;
            p.largerThan(key,1);
            cout<<endl;
        }
        else if(choice == 12) break;
    }


}



