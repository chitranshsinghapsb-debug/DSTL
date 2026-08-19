#include <bits/stdc++.h>
using namespace std;
struct Node{
    int rollNo;
    string name;
    float marks;
    Node* prev;
    Node* next;
    Node(int r,string n,float m){
        rollNo=r;
        name=n;
        marks=m;
        prev=nullptr;
        next=nullptr;
    }
};
class StudentRecord{
private:
    Node* head;
    Node* tail;
public:
    StudentRecord(){
        head=nullptr;
        tail=nullptr;
    }
    void addStudent(int rollNo,string name,float marks){
        Node* newNode=new Node(rollNo, name, marks);
        if(head==nullptr){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
        cout<<"Student added successfully.\n";
    }
    void deleteStudent(int rollNo){
        Node* temp=head;
        while(temp!=nullptr && temp->rollNo!=rollNo){
            temp=temp->next;
        }
        if(temp==nullptr){
            cout<<"Student not found.\n";
            return;
        }
        if(temp==head)
            head=temp->next;
        if(temp==tail)
            tail=temp->prev;
        if(temp->prev!=nullptr)
            temp->prev->next=temp->next;
        if(temp->next!=nullptr)
            temp->next->prev=temp->prev;
        delete temp;
        cout<<"Student deleted successfully.\n";
    }
    void updateStudent(int rollNo){
        Node* temp=head;
        while(temp!=nullptr && temp->rollNo!=rollNo){
            temp=temp->next;
        }
        if(temp==nullptr){
            cout<<"Student not found.\n";
            return;
        }
        cout<<"Enter new name: ";
        cin>>ws;
        getline(cin, temp->name);
        cout<<"Enter new marks: ";
        cin>>temp->marks;
        cout<<"Student updated successfully.\n";
    }
    void searchStudent(int rollNo){
        Node* temp=head;
        while(temp!=nullptr){
            if(temp->rollNo==rollNo){
                cout<<"\nStudent Found\n";
                cout<<"Roll No : "<<temp->rollNo<<endl;
                cout<<"Name    : "<<temp->name<<endl;
                cout<<"Marks   : "<<temp->marks<<endl;
                return;
            }
            temp=temp->next;
        }
        cout<<"Student not found.\n";
    }
    void display(){
        if(head==nullptr){
            cout<<"No student records available.\n";
            return;
        }
        Node* temp=head;
        cout<<"\n---------------------------------------------\n";
        cout<<"Roll No\t Name \t Marks\n";
        cout<<"---------------------------------------------\n";
        while(temp!=nullptr){
            cout<<"|"<<temp->rollNo<<"\t"<<temp->name<<"\t"<<temp->marks<<"|"<<"->";
            temp=temp->next;
        }cout<<endl;
        cout<<"---------------------------------------------\n";
    }
    void sortRecords(int choice,bool ascending){
        if(head==nullptr || head->next==nullptr){
            cout<<"Not enough records to sort.\n";
            return;
        }
        bool swapped;
        do{
            swapped=false;
            Node* temp=head;
            while(temp->next!=nullptr){
                bool condition;
                if(choice==1){
                    condition=ascending?temp->rollNo>temp->next->rollNo:temp->rollNo<temp->next->rollNo;
                }else{
                    condition=ascending?temp->marks>temp->next->marks:temp->marks<temp->next->marks;
                }
                if(condition){
                    swap(temp->rollNo, temp->next->rollNo);
                    swap(temp->name, temp->next->name);
                    swap(temp->marks, temp->next->marks);
                    swapped=true;
                }
                temp=temp->next;
            }
        }while(swapped);
        cout<<"Records sorted successfully.\n";
    }
    ~StudentRecord(){
        Node* temp=head;
        while(temp!=nullptr){
            Node* nextNode=temp->next;
            delete temp;
            temp=nextNode;
        }
    }
};
int main(){
    StudentRecord records;
    int choice;
    do{
        cout<<"\n===== Student Record Management System =====\n";
        cout<<"1. Add Student\n";
        cout<<"2. Delete Student\n";
        cout<<"3. Update Student\n";
        cout<<"4. Search Student\n";
        cout<<"5. Display Records\n";
        cout<<"6. Sort Records\n";
        cout<<"7. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
        case 1:{
            int rollNo;
            string name;
            float marks;
            cout<<"Enter Roll No: ";
            cin>>rollNo;
            cout<<"Enter Name: ";
            cin>>ws;
            getline(cin, name);
            cout<<"Enter Marks: ";
            cin>>marks;
            records.addStudent(rollNo, name, marks);
            break;
        }
        case 2:{
            int rollNo;
            cout<<"Enter Roll No to delete: ";
            cin>>rollNo;
            records.deleteStudent(rollNo);
            break;
        }
        case 3:{
            int rollNo;
            cout<<"Enter Roll No to update: ";
            cin>>rollNo;
            records.updateStudent(rollNo);
            break;
        }
        case 4:{
            int rollNo;
            cout<<"Enter Roll No to search: ";
            cin>>rollNo;
            records.searchStudent(rollNo);
            break;
        }
        case 5:{
            records.display();
            break;
	}
        case 6:{
            int sortChoice, order;
            cout<<"\nSort by:\n";
            cout<<"1. Roll Number\n";
            cout<<"2. Marks\n";
            cout<<"Enter choice: ";
            cin>>sortChoice;
            cout<<"\nOrder:\n";
            cout<<"1. Ascending\n";
            cout<<"2. Descending\n";
            cout<<"Enter choice: ";
            cin>>order;
            if(sortChoice!=1 && sortChoice!=2){
                cout<<"Invalid sorting choice.\n";
            }else if(order!=1 && order!=2){
                cout<<"Invalid order choice.\n";
            }else{
                records.sortRecords(sortChoice,order==1);
            }
            break;
        }
        case 7:{
            cout << "Exiting program...\n";
            break;
	}
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }while(choice!=7);
    return 0;
}

/*===== Student Record Management System =====
1. Add Student
2. Delete Student
3. Update Student
4. Search Student
5. Display Records
6. Sort Records
7. Exit
Enter your choice: 1
Enter Roll No: 1
Enter Name: Chitransh
Enter Marks: 95
Student added successfully.

Enter your choice: 1
Enter Roll No: 2
Enter Name: Izhar
Enter Marks: 97
Student added successfully.

Enter your choice: 1
Enter Roll No: 3
Enter Name: Ayush
Enter Marks: 93
Student added successfully.

Enter your choice: 5

---------------------------------------------
Roll No	Name		Marks
---------------------------------------------
1	Chitransh	95
2	Izhar	97
3	Ayush	93
---------------------------------------------

Enter your choice: 6

Sort by:
1. Roll Number
2. Marks
Enter choice: 2

Order:
1. Ascending
2. Descending
Enter choice: 1
Records sorted successfully.

Enter your choice: 5

---------------------------------------------
Roll No	Name		Marks
---------------------------------------------
3	Ayush	93
1	Chitransh	95
2	Izhar	97
---------------------------------------------

Enter your choice: 2
Enter Roll No to delete: 3
Student deleted successfully.

Enter your choice: 5

---------------------------------------------
Roll No	 Name 	 Marks
---------------------------------------------
|1	Izhar	95|->|2	Chitransh	93|
---------------------------------------------


Enter your choice: 3
Enter Roll No to update: 1
Enter new name: Chitransh
Enter new marks: 96
Student updated successfully.

Enter your choice: 4
Enter Roll No to search: 2

Student Found
Roll No : 2
Name    : Izhar
Marks   : 97

Enter your choice: 7 
Exiting program...*/
