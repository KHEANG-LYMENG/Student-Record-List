//Build C++ program with linked list that can store and delete student;
#include<iostream>
#include<stdbool.h>
using namespace std;
typedef struct Date{
    int year,month,day;
}Date;
struct Student{
    string Name,Id;
    int age;
    Date BDate;
    Student *next;
};
struct StudentList{
    int Count;
    Student *Head,*Tail;
};
void Menu();
string ToupperCase(string text);
void SubHeader(string Text);
void Header();
StudentList *createEmptyList();

//Insert Section
void askInput(Student *st);
void insertToEnd(StudentList *stls);
void insertToBegin(StudentList *stls);
void insertWithPost(StudentList *stls,int pos);
//Delete section
void deleteFirstElement(StudentList *stls);
void deleteLastElement(StudentList *stls);
void deleteWithPos(StudentList *stls,int pos);

bool isValid(StudentList *stls,string id);

//Display Section
void displayData(StudentList *stls);
void displayDataIndividual(StudentList *stls,int pos);
void displayById(StudentList *stls,string Id);

void displayEqSym(int n);
int main(){
    StudentList *StudentLs=createEmptyList();
    while(2>1){
        cout<<"\n\n\n";
        Menu();
        int x,choice;
        cout<<"\nInput your Choice:";cin>>choice;
        if(choice==1){
            cout<<"How many student you need to input?:";cin>>x;
            cout<<"Input your student Data:\n";
            for(int i=0;i<x;i++){
                cout<<"\tStudent #"<<i+1<<":\n";
                insertToEnd(StudentLs);
            }
        }else if(choice==2){
            cout<<"How many student you need to input?:";cin>>x;
            cout<<"Input your student Data:\n";
            for(int i=0;i<x;i++){
                cout<<"\tStudent #"<<i+1<<":\n";
                insertToBegin(StudentLs);
            }
        }else if(choice==3){
            int pos;
            cout<<"\nHow many student you need to input?:";cin>>x;
            cout<<"Input Position that you want to add to:";cin>>pos;
            cout<<"Input your student Data:\n";
            for(int i=0;i<x;i++){
                cout<<"\tStudent #"<<i+1<<":\n";
                insertWithPost(StudentLs,pos+i);
            }
        }else if(choice==4){
            if(StudentLs->Count==0){
                SubHeader("There arn't Data in List");
            }else{
                int state;
                SubHeader("STUDENT GOING TO DELETE!");
                cout<<"  ";
                displayEqSym(74);
                printf("|");
                Header();
                displayDataIndividual(StudentLs,1);
                cout<<"  ";
                displayEqSym(74);
                cout<<"Are You sure?(1.Yes|2.No):";cin>>state;

                if(state==1){
                    deleteFirstElement(StudentLs);
                    SubHeader("Delete Sucessful!!");
                }else continue;
            }
        }else if(choice==5){
            if(StudentLs->Count==0){
                SubHeader("There arn't Data in List");
            }else{
                int state;
                SubHeader("STUDENT GOING TO DELETE!");
                cout<<"  ";
                displayEqSym(74);
                printf("|");
                Header();
                displayDataIndividual(StudentLs,StudentLs->Count);
                cout<<"  ";
                displayEqSym(74);
                cout<<"Are You sure?(1.Yes|2.No):";cin>>state;
                if(state==1){
                    deleteLastElement(StudentLs);
                    SubHeader("Delete Sucessful!!");
                }else continue;
            }
        }
        else if(choice==6){
            if(StudentLs->Count==0){
                SubHeader("There arn't Data in List");
            }else{
                int state,pos;
                cout<<"Input student Position:";cin>>pos;
                cout<<"How many student you want to remove?:";cin>>x;
                SubHeader("STUDENT GOING TO DELETE!");
                cout<<"  ";
                displayEqSym(74);
                printf("|");
                Header();
                for(int i=0;i<x;i++){
                    displayDataIndividual(StudentLs,pos+i);
                }
                cout<<"  ";
                displayEqSym(74);

                cout<<"You sure?(1.Yes|2.No):";cin>>state;
                if(state==1){
                    for(int i=0;i<x;i++){
                        deleteWithPos(StudentLs,pos);
                    }

                    SubHeader("Delete Sucessful!!");
                }else continue;
            }
        }
        else if(choice==7){
            if(StudentLs->Count==0){
                SubHeader("There arn't Data in List");
            }else{
                SubHeader("All Student List");
                displayData(StudentLs);
            }
        }else if(choice==8){
            string id;
            cout<<"Input student ID:";cin>>id;

            displayById(StudentLs,id);
        }
        else if(choice==9){
            if(StudentLs->Count==0){
                SubHeader("There arn't Data in List");
            }else{
                int state;
                SubHeader("STUDENT GOING TO DELETE");
                displayData(StudentLs);
                cout<<"Are You sure?(1.Yes|2.No):";cin>>state;
                x=StudentLs->Count;
                if(state==1){
                    for(int i=0;i<x;i++){
                        deleteFirstElement(StudentLs);
                    }
                    SubHeader("Delete Sucessful!!");
                }else continue;
            }
        }else break;
    }
}
void Menu(){
    printf("\t\t");
    for(int i=0;i<70;i++){
        printf("=");
    }
    printf("\n");
    printf("\t\t||\t%-60s||\n"
           "\t\t||\t%-60s||\n"
           "\t\t||\t%-60s||\n"
           "\t\t||\t%-60s||\n"
           "\t\t||\t%-60s||\n"
           "\t\t||\t%-60s||\n"
           "\t\t||\t%-60s||\n"
           "\t\t||\t%-60s||\n"
           "\t\t||\t%-60s||\n"
           "\t\t||\t%-60s||\n",
           "1.Add Student to the end of list",
           "2.Add Student to the Begin of list",
           "3.Add Student to the specific position",
           "4.Remove Student at the Begin",
           "5.Remove Student at the End",
           "6.Remove Student with specific position",
           "7.Display all Student List",
           "8.Display Student with ID",
           "9.Delete all data",
           "10.Quite");
    printf("\t\t");
    for(int i=0;i<70;i++){
        printf("=");
    }
}
string ToupperCase(string text){
    int i=0;
    while(text[i]!='\0'){
        if(text[i]>=97 && text[i]<=122){
            text[i]=text[i]-32;
        }
        i++;
    }
    return text;
}
void SubHeader(string Text){
    cout<<"\n\t\t\t  ==============================================="
    <<"\n\t\t\t\t\t    "<<Text<<
    "\n\t\t\t  ===============================================\n";
}
void displayEqSym(int n){
    for(int i=0;i<n;i++){
        cout<<"=";
    }
    cout<<endl;
}
void Header(){

    printf("|%-20s|%-30s|%-10s|%-10s ||\n","ID","NAME","AGE","BIRTH DATE");
}
StudentList *createEmptyList(){
    StudentList *stls=new StudentList;
    stls->Count=0;
    stls->Head=NULL;
    stls->Tail=NULL;
    return stls;
}
void askInput(StudentList *stls,Student *st){
    int i=0;
    do{
            if(i!=0){
                SubHeader("Data already Existed!!");
            }
            cout<<"\t\tId:";cin>>st->Id;
            i++;
    }while(!isValid(stls,st->Id));
    cout<<"\t\tName:";getline(cin,st->Name);getline(cin,st->Name);
    cout<<"\t\tAge:";cin>>st->age;
    cout<<"\t\tBirthDate:(dd mm yyyy):";cin>>st->BDate.day;cin>>st->BDate.month;cin>>st->BDate.year;
}
void insertToEnd(StudentList *stls){
    Student *tmp=new Student;
    tmp->next=NULL;
    askInput(stls,tmp);
    if(stls->Count==0){
        stls->Head=tmp;
        stls->Tail=tmp;
    }else{
        stls->Tail->next=tmp;
        stls->Tail=tmp;
    }
    stls->Count=stls->Count+1;
}
void insertToBegin(StudentList *stls){
    Student *tmp=new Student;
    tmp->next=NULL;
    askInput(stls,tmp);
    if(stls->Count==0){
        stls->Head=tmp;
        stls->Tail=tmp;
    }else{
        tmp->next=stls->Head;
        stls->Head=tmp;
    }
    stls->Count=stls->Count+1;
}
void insertWithPost(StudentList *stls,int pos){
    Student *tmp1,*tmp=new Student;
    tmp1=stls->Head;
    if(pos==1){
        insertToBegin(stls);
    }else{
        for(int i=2;i<=pos-1;i++){
            tmp1=tmp1->next;
            if(tmp1==NULL){
                break;
            }
        }
        if(tmp1!=NULL){
            tmp->next=NULL;
            askInput(stls,tmp);
            tmp->next=tmp1->next;
            tmp1->next=tmp;
        }else{
            insertToEnd(stls);
        }
        stls->Count=stls->Count+1;
    }
}



void deleteFirstElement(StudentList *stls){
    Student *tmp=stls->Head;
    stls->Head=tmp->next;
    free(tmp);
    stls->Count=stls->Count-1;
}
void deleteLastElement(StudentList *stls){
    Student *tmp=stls->Head;
    while(tmp->next->next!=NULL){
        tmp=tmp->next;
    }
    free(stls->Tail);
    tmp->next=NULL;
    stls->Tail=tmp;
    stls->Count=stls->Count-1;
}
void deleteWithPos(StudentList *stls,int pos){
    Student *tmp1,*tmp=stls->Head;
    if(pos==1){
        deleteFirstElement(stls);
    }else{
        for(int i=2;i<pos;i++){
            tmp=tmp->next;
            if(tmp==NULL){
                break;
            }
        }
        if(tmp!=NULL){
            tmp1=tmp;
            tmp1=tmp->next;
            tmp->next=tmp1->next;
            free(tmp1);
        }else{
            deleteLastElement(stls);
        }
    }
    stls->Count=stls->Count-1;
}

bool isValid(StudentList *stls,string id){
    Student *tmp=stls->Head;
    if(stls->Count==0){
        return true;
    }
    while(tmp!=NULL){
        if(ToupperCase(tmp->Id)==ToupperCase(id)){
            return false;
        }
        tmp=tmp->next;
    }
    return true;
}

void displayData(StudentList *stls){
    Student *tmp=stls->Head;
    int i=1;
    cout<<"  ";
    displayEqSym(85);
    printf("||%-10s","Count");
    Header();
    while(tmp!=NULL){
        printf("||%-10.03d|%-20s|%-30s|%-10.03d|%02d/%02d/%d ||\n",i,
               tmp->Id.c_str(),tmp->Name.c_str(),tmp->age,
               tmp->BDate.day,tmp->BDate.month,
               tmp->BDate.year);
        tmp =tmp->next;
        i++;
    }
    cout<<"  ";
    displayEqSym(85);
}
void displayDataIndividual(StudentList *stls,int pos){
    Student *tmp=stls->Head;
    for(int i=1;i<pos;i++){
        tmp=tmp->next;
        if(tmp==NULL){
            break;
        }
    }

    if(tmp!=NULL){

        printf("||%-20s|%-30s|%-10.03d|%02d/%02d/%d ||\n",
               tmp->Id.c_str(),tmp->Name.c_str(),tmp->age,
               tmp->BDate.day,tmp->BDate.month,
               tmp->BDate.year);
    }
}
void displayById(StudentList *stls,string Id){
    Student *tmp=stls->Head;
    int i=1,state=0;
    while(tmp!=NULL){
        if(ToupperCase(tmp->Id)==ToupperCase(Id)){
            state=1;
            break;
        }
        tmp=tmp->next;
        i++;
    }
    if(state==1){
        if(i>0 && i<stls->Count){
            SubHeader("Student List");
            cout<<"  ";
            displayEqSym(74);
            printf("|");
            Header();
            displayDataIndividual(stls,i);
            cout<<"  ";
            displayEqSym(74);

        }

    }else{
        SubHeader("DATA NOT FOUND!!\n\n");
    };
}