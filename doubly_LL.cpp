#include <iostream>
#include <string>
using namespace std;

struct Node{
    int rollNo;
    string name;
    float marks;
    Node *prev,*next;
    Node(int r,string n,float m):rollNo(r),name(n),marks(m),prev(nullptr),next(nullptr){}
};

class StudentList{
    Node *head,*tail;

public:
    StudentList():head(nullptr),tail(nullptr){}

    void add(int rollNo,string name,float marks){
        Node *newNode=new Node(rollNo,name,marks);
        if(!head) head=tail=newNode;
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
        cout<<"Record added successfully.\n";
    }

    void display(bool ascending=true,bool byMarks=true){
        if(!head){
            cout<<"No records found.\n";
            return;
        }

        Node *temp=head;
        while(temp){
            cout<<"Roll No: "<<temp->rollNo<<" | Name: "<<temp->name<<" | Marks: "<<temp->marks<<'\n';
            temp=temp->next;
        }
    }

    void deleteRecord(int rollNo){
        Node *temp=head;
        while(temp && temp->rollNo!=rollNo) temp=temp->next;

        if(!temp){
            cout<<"Record not found.\n";
            return;
        }

        if(temp->prev)temp->prev->next=temp->next;
        else head=temp->next;

        if(temp->next)temp->next->prev=temp->prev;
        else tail=temp->prev;
        delete temp;
        cout<<"Record deleted successfully.\n";
    }

    void update(int rollNo){
        Node *temp=head;
        while(temp && temp->rollNo!=rollNo) temp=temp->next;

        if(!temp){
            cout<<"Record not found.\n";
            return;
        }

        cout<<"Enter new name: ";
        cin.ignore();
        getline(cin,temp->name);
        cout<<"Enter new marks: ";
        cin>>temp->marks;
        cout<<"Record updated successfully.\n";
    }

    void search(int rollNo){
        Node *temp=head;
        while(temp && temp->rollNo!=rollNo) temp=temp->next;

        if(!temp){
            cout<<"Record not found.\n";
            return;
        }

        cout<<"Roll No: "<<temp->rollNo<<'\n';
        cout<<"Name: "<<temp->name<<'\n';
        cout<<"Marks: "<<temp->marks<<'\n';
    }

    void sortRecords(bool byMarks,bool ascending){
        if(!head || !head->next) return;

        for(Node *i=head;i;i=i->next){
            for(Node *j=i->next;j;j=j->next) {
                bool condition;
                if(byMarks)
                    condition=ascending ? i->marks>j->marks : i->marks<j->marks;
                else
                    condition=ascending ? i->rollNo>j->rollNo : i->rollNo<j->rollNo;

                if(condition){
                    swap(i->rollNo,j->rollNo);
                    swap(i->name,j->name);
                    swap(i->marks,j->marks);
                }
            }
        }

        cout<<"Records sorted successfully.\n";
    }

    void create(){
        int n;
        cout<<"Enter number of students: ";
        cin>>n;

        for(int i=0;i<n;i++){
            int rollNo;
            string name;
            float marks;

            cout<<"\nEnter Roll No: ";
            cin>>rollNo;
            cin.ignore();
            cout<<"Enter Name: ";
            getline(cin,name);
            cout<<"Enter Marks: ";
            cin>>marks;

            add(rollNo,name,marks);
        }
    }
};

int main() {
    StudentList list;
    int choice;

    do{
        cout<<"\nStudent Record Management System\n";
        cout<<"1. Create Records\n";
        cout<<"2. Add Record\n";
        cout<<"3. Delete Record\n";
        cout<<"4. Update Record\n";
        cout<<"5. Search Record\n";
        cout<<"6. Sort by Marks Ascending\n";
        cout<<"7. Sort by Marks Descending\n";
        cout<<"8. Sort by Roll No Ascending\n";
        cout<<"9. Sort by Roll No Descending\n";
        cout<<"10. Display Records\n";
        cout<<"0. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                list.create();
                break;

            case 2:{
                int rollNo;
                string name;
                float marks;

                cout<<"Enter Roll No: ";
                cin>>rollNo;
                cin.ignore();
                cout<<"Enter Name: ";
                getline(cin,name);
                cout<<"Enter Marks: ";
                cin>>marks;

                list.add(rollNo,name,marks);
                break;
            }

            case 3:{
                int rollNo;
                cout<<"Enter Roll No to delete: ";
                cin>>rollNo;
                list.deleteRecord(rollNo);
                break;
            }

            case 4:{
                int rollNo;
                cout<<"Enter Roll No to update: ";
                cin>>rollNo;
                list.update(rollNo);
                break;
            }

            case 5:{
                int rollNo;
                cout<<"Enter Roll No to search: ";
                cin>>rollNo;
                list.search(rollNo);
                break;
            }

            case 6:
                list.sortRecords(true,true);
                list.display();
                break;

            case 7:
                list.sortRecords(true,false);
                list.display();
                break;

            case 8:
                list.sortRecords(false,true);
                list.display();
                break;

            case 9:
                list.sortRecords(false,false);
                list.display();
                break;

            case 10:
                list.display();
                break;

            case 0:
                cout<<"Program exited.\n";
                break;

            default:
                cout<<"Invalid choice.\n";
        }
    }while(choice!=0);

    return 0;
}

/*
se5@adminpc-HP-280-G3-MT:~/Desktop/7222$ g++ doubly_LL.cpp -o doubly_LL
se5@adminpc-HP-280-G3-MT:~/Desktop/7222$ ./doubly_LL

Student Record Management System
1. Create Records
2. Add Record
3. Delete Record
4. Update Record
5. Search Record
6. Sort by Marks Ascending
7. Sort by Marks Descending
8. Sort by Roll No Ascending
9. Sort by Roll No Descending
10. Display Records
0. Exit
Enter choice: 1
Enter number of students: 3

Enter Roll No: 7222
Enter Name: Chitransh
Enter Marks: 91
Record added successfully.

Enter Roll No: 7228
Enter Name: Izhar
Enter Marks: 93
Record added successfully.

Enter Roll No: 7229
Enter Name: Soham
Enter Marks: 90
Record added successfully.

Student Record Management System
1. Create Records
2. Add Record
3. Delete Record
4. Update Record
5. Search Record
6. Sort by Marks Ascending
7. Sort by Marks Descending
8. Sort by Roll No Ascending
9. Sort by Roll No Descending
10. Display Records
0. Exit
Enter choice: 6
Records sorted successfully.
Roll No: 7229 | Name: Soham | Marks: 90
Roll No: 7222 | Name: Chitransh | Marks: 91
Roll No: 7228 | Name: Izhar | Marks: 93

Student Record Management System
1. Create Records
2. Add Record
3. Delete Record
4. Update Record
5. Search Record
6. Sort by Marks Ascending
7. Sort by Marks Descending
8. Sort by Roll No Ascending
9. Sort by Roll No Descending
10. Display Records
0. Exit
Enter choice: 10
Roll No: 7229 | Name: Soham | Marks: 90
Roll No: 7222 | Name: Chitransh | Marks: 91
Roll No: 7228 | Name: Izhar | Marks: 93

Student Record Management System
1. Create Records
2. Add Record
3. Delete Record
4. Update Record
5. Search Record
6. Sort by Marks Ascending
7. Sort by Marks Descending
8. Sort by Roll No Ascending
9. Sort by Roll No Descending
10. Display Records
0. Exit
Enter choice: 0
Program exited.
*/
