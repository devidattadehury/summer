#include<iostream>
using namespace std;

class node{
  public:

  int value;
  node*next;
//constructor
  node(){
    next=NULL;
   }
};

class linkedlist{
  public:

   node*head;
//constructor
 linkedlist(){
    head=NULL;
   }

//insert
void insert(int newvalue){
  //if linked list is empty
  if(head==NULL){
    node*temp=new node;
    temp->value=newvalue;
    head=temp;
    }
  else{
    node*temp=new node;
    temp->value=newvalue;
    temp->next=head;
    head=temp;
    }
  }

//display
void display(){
  node*current=head;
  while(current!=NULL){
      cout<<current->value<<"->";
      current=current->next;
    }
   cout<<"NULL"<<endl;
  }

//delete
void delet(){
  //if linkedlist is non empty
  if(head!=NULL){
   node*temp=head;
   head=head->next;
   delete temp;
    }
  }

//countItems
int countItems(){
  node*current=head;
  int count=0;
  while(current!=NULL){
     count++;
     current=current->next;
    } 
return count; 
  }

//insertAt
void insertAt(int newvalue,int pos){
  //insert at 1st position
  if(pos==1){
   insert(newvalue);
    }
  else{
   node*current=head;
   int count=1;
   while(count<(pos-1)){
       current=current->next;
       count++;
     }
       //create a new node there
       node*temp=new node();
       temp->value=newvalue;
       temp->next=current->next;
       current->next=temp;
    }
  }

//deletAt(pos)
void deletAt(int pos){
  //if delete at first position
  if (pos==1){
     delet();
    }
  else {
     node*current=head;
     int count=1;
     while(count<(pos-1)){
       current=current->next;
       count++;
      }
      node*temp=current->next;
      current->next=(current->next)->next;
     delete temp;
    }
  }
};

//compare two linked list
int compareLinkedlist(node*a,node*b){
  //if both linkedlist are empty
  if(a==NULL && b==NULL){
    return 1;
   }
  else if(a==NULL || b==NULL){
    return 0;
   }
  if(a->value==b->value){
    return compareLinkedlist(a->next,b->next);
   }
  else{
    return 0;
   }
 }

int main(){
   linkedlist l1;
   for(int i=0;i<10;i++){
   l1.insert(i);
  }
   linkedlist l2;
   for(int j=0;j<5;j++){
   l2.insert(j);
  }
   l1.display();
   l2.display();
   l1.delet();
     cout<<"after deleting linked list will be"<<endl;
   l1.display();
   l1.countItems();
     cout<<"no. of iteams:"<<l1.countItems()<<endl;
   l1.display();
   l1.insertAt(20,6);
   l1.display();
   l1.deletAt(7);
   l1.display();
   if (compareLinkedlist(l1.head,l2.head)==1){
          cout<<"both linkedlist are identical"<<endl;
   }
   else{
          cout<<"not identical"<<endl;
 }
};






