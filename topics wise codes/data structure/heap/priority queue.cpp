#include<bits/stdc++.h>
using namespace std;

struct heap{

    vector<int>heap;

    int Size;

    int left(int parent)    {  int l= parent*2+1; if(l<heap.size()) return l; else return -1; }
    int right(int parent)   {  int r= parent*2+2; if(r<heap.size()) return r; else return -1; }
    int parent(int child)   {  if(child==0) return -1;  return  (child-1)/2;   }


    void heapifyup(int index)
    {
        if(index>0 && heap[index]< heap[parent(index)])
        {
            swap(heap[index], heap[parent(index)]);
            heapifyup(parent(index));
        }


    }


    void Insert(int element)
    {
        heap.push_back(element);
        heapifyup(heap.size()-1);

    }
    void DeleteMin()
    {
        Size=heap.size()-1;
        if(heap.size()==0) {printf("-1\n"); return ; }
        else
        {
            heap[0]= heap[heap.size()-1];
            heap.pop_back();
            heapifydown(0);
        }

    }

    int ExtractMin()
    {
        if(heap.size()==0) return -1;
        else return heap.front();

    }
    void DisplayHeap()
    {
        for(int i=0;i<heap.size();i++) printf("%d ",heap[i]);
        puts("");

    }

     void heapifydown(int index)
    {

        int child=left(index);
        int child1=right(index);

        if(child>0 && child1>0 && heap[child]>heap[child1])
            child=child1;

        if(child>0 && heap[index] > heap[child] && child<Size && index < Size){

        swap(heap[index], heap[child]);
        heapifydown(child);

        }

    }

     void Delete2()
    {
        if(heap.size()==0) {printf("-1\n"); return ; }
        else
        {
            printf("%d ",heap[0]);
            swap(heap[0],heap[Size-1]);
            Size--;
            //heap.pop_back();
            heapifydown(0);

        }

    }
    void heapsort()
    {
        Size= heap.size();

        while(Size)
        {
            Delete2();
        }


    }


};

int main()
{
    heap h;
    while(1)
    {
        int choice;
        cin>>choice;

        switch(choice)
        {
            case 1:
                printf("how many numbers to insert?");
                int n,i;
                cin>>n;
                printf("insert the numbers");
                int x;
                for(i=0;i<n;i++)
                {
                    cin>>x;
                    h.Insert(x);
                }
                break;
            case 2:
                h.DeleteMin();
                break;

            case 3:
                h.DisplayHeap();
                break;
            case 4:
                h.heapsort();


        }



    }



    return 0;
}
