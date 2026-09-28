#include <iostream>
using namespace std;
int heap[100],n=0;
void heapify(int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && heap[left]>heap[largest]) largest=left;
    if(right<n && heap[right]>heap[largest]) largest=right;
    if(largest!=i){
        swap(heap[i],heap[largest]);
        heapify(largest);
    }
}
void insert(int value){
    int i=n++;
    heap[i]=value;
    while(i>0){
        int parent=(i-1)/2;
        if(heap[parent]>=heap[i])
            break;
        swap(heap[parent],heap[i]);
        i=parent;
    }
}
void buildHeap(){
    for(int i=n/2-1;i>=0;i--) heapify(i);
}
void addWithoutHeapify(int value){heap[n++]=value;}
void display(){
    for(int i=0;i<n;i++)
        cout<<heap[i]<<" ";
    cout<<endl;
}
void deleteHighestPriority(){
    if(n==0){
        cout<<"Priority Queue is empty\n";
        return;
    }
    cout<<"Deleted: "<<heap[0]<<endl;
    heap[0]=heap[--n];
    heapify(0);
}
int main(){
    int choice,value;
    do{
        cout<<"\n1. Insert\n2. Heapify\n3. Display\n4. Delete Highest Priority\n5. Exit\n6. Add Without Heapify\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value: ";
                cin>>value;
                insert(value);
                break;
            case 2:
                buildHeap();
                cout<<"Heapified successfully\n";
                break;
            case 3:
                display();
                break;
            case 4:
                deleteHighestPriority();
                break;
            case 5:
                cout<<"Exiting...\n";
                break;
            case 6:
                cout<<"Enter value: ";
                cin>>value;
                addWithoutHeapify(value);
                break;
            default:
                cout<<"Invalid choice\n";
        }
    } while(choice!=5);
    return 0;
}
/*csl-2@csl2-V520-15IKL:~/Desktop/7228$ g++ priority_queue.cpp -o priority_queue && ./priority_queue
1. Insert
2. Heapify
3. Display
4. Delete Highest Priority
5. Exit
6. Add Without Heapify

Enter choice: 3
11 13 16 22 20 30 22 50 45 56 70 98 88 76 99
Enter choice: 2
Heapified successfully
Enter choice: 3
99 70 98 50 56 88 76 22 45 13 20 30 11 16 22
Enter choice: 4
Deleted: 99
Enter choice: 3
98 70 88 50 56 30 76 22 45 13 20 22 11 16
*/
