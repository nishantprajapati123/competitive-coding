#include<bits/stdc++.h>
using namespace std;
void swap_value(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
class MinHeap
{
private:
    int capacity;
    //vector<int>heap;
    int *heap;
    int heap_size;//current size
public:
    MinHeap(int cap)
    {
        capacity=cap;
        heap=new int[cap];  //allot memory to array
        heap_size=0;
    }
    int parent(int i)
    {
        return (i-1)/2 ;
    }
    int left(int i) {return ((2*i)+1);}
    int right(int i) {return ((2*i)+2);}
    void insert_heap(int key)
    {
        //check for capacity
        if(heap_size==capacity){
            cout<<"Capacity is full \n";
            return ;
        }
        heap_size++;
        int i=heap_size-1; //point last element of vector
        heap[i]=key;    //put element into last
        //heapify (if min heap property violets)
        while(i!=0 && heap[parent(i)]>heap[i])
        {
            swap_value(&heap[parent(i)], &heap[i]); //if greater than current inserted value then swap
            i=parent(i);    //move parent pointer upward
        }
        //minHeapify(0);
    }
    //top-down process of heapify
    void minHeapify(int i)
    {
        int l=left(i);
        int r=right(i);
        int smallest=i;
        if(l<heap_size && heap[l]<heap[i])
            smallest=l;
        if(r<heap_size && heap[r]<heap[smallest])
            smallest=r;
        if(smallest!=i)
        {
            swap_value(&heap[i],&heap[smallest]);
            minHeapify(smallest);
        }
    }
    void show_heap()
        {
            for(int i=0;i<heap_size;i++)
                cout<<heap[i]<<" ";
        }
};
int main()
{
    MinHeap mh(8);

    mh.insert_heap(22);
    mh.insert_heap(20);
    mh.insert_heap(19);
    mh.insert_heap(18);
    mh.insert_heap(30);
    mh.insert_heap(21);
    mh.insert_heap(23);
   // mh.insert_heap(1);
   //mh.insert_heap(10);
   mh.show_heap();

}
