#include<iostream>//include library
using namespace std;
//create a node 
class node{
  public:
  //node containing variables
  int value;//data
  node*next;//pointer
//constructor
  node(){
    next=NULL;
   }
};

//create a linkedlist
class linkedlist{
  public:
//variable
   node*head;//pointer
//constructor
 linkedlist(){
    head=NULL;
   }

//insert at 1st position
void insert(int newvalue){
  //if linked list is empty
  if(head==NULL){
    //create a new node
    node*temp=new node;
    //assign newvalue
    temp->value=newvalue;
    head=temp;
    }
  //if linked list is non empty
  else{
    //create a new node
    node*temp=new node;
    //assign newvalue there
    temp->value=newvalue;
    //new node should be head
    temp->next=head;
    head=temp;
    }
  }

//display
void display(){
  //1st head has to assign with a pointer
  node*current=head;
  //print value of nodes 
  while(current!=NULL){
      cout<<current->value<<"->";
      current=current->next;
    }
   cout<<"NULL"<<endl;
  }

//delete the 1st node of the linked list
void delet(){
  //if linkedlist is non empty
  if(head!=NULL){
  //head has to assign with a pointer
   node*temp=head;
   //head pointer should move to the next node
   head=head->next;
   delete temp;
    }
  }

//countItems in the linked list
int countItems(){
  //1st assign head to a pointer
  node*current=head;
  //declaration
  int count=0;
  //count till it becomes null
  while(current!=NULL){
     count++;
     current=current->next;
    } 
return count; 
  }

//insertAt any position
void insertAt(int pos,int newvalue){
  //insert at 1st position
  if(pos==1){
   insert(newvalue);
    }
  //if position exceed the no. of countitems
  else if(pos>(countItems()+1)){
    cout<<"linked list does not have that many elements: "<<endl;
  }
  //else insert at inbetween the linkedlist
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

//deletAt any position in the linked list
void deletAt(int pos){
  //if delete at first position
  if (pos==1){
     delet();
    }
   //if delete at postion that does not inside the linkedlist
  else if(pos>countItems()){
    cout<<"linkedlist doesnot have that many elements: "<<endl;
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

int main(){
   linkedlist l1;

   for(int i=10;i>0;i--)
   l1.insert(i);
   l1.display();
   l1.delet();
     cout<<"after deleting the 1st node linked list will be"<<endl;
   l1.display();
   l1.countItems();
     cout<<"no. of iteams:"<<l1.countItems()<<endl;
   l1.display();
   l1.insertAt(20,6);
   l1.display();
   l1.insertAt(4,25); 
   l1.display();
   l1.deletAt(7);
   l1.display();
   l1.deletAt(10);
     cout<<"after "<<endl;
   l1.display();
}






