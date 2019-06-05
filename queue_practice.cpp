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

class queue{
  public:
  node*front;
  node*end;

//constructor
queue(){
  front=NULL;
  end=NULL;
  }

//insert at 1st position
//same as insert of linked list
//here we use the function enqueue();

void enqueue(int newvalue){
  //if queue is already empty
  if(front==NULL){
    //create a new node
    node*temp=new node();
    temp->value=newvalue;
    front=temp;
    }
  else{
    //create a new node
    node*temp=new node();
    temp->value=newvalue;
    temp->next=front;
    front=temp;
    }
  }
//display
void display(){
  node*current=front;
  while(current!=NULL){
    cout<<current->value<<"->";
    current=current->next;
  }
  cout<<"NULL"<<endl;
}

//delete occurs at the end of the queue
//here we use the function dequeue();
//it is same as the linkedlist deletAt();

//1st we have to move to that place where to be dequeue

//delete
void dequeue(){
  //if queue is already empty
  if(front==NULL){
    //do nothing
    }
  else{
    //go to the previous position of end
    node*current=front;
    while(current->next!=end){
       current=current->next;
    }
    node*temp=end;
    current->next=NULL;
    delete temp;
    end=current;
    }
  }
};

//int main function
int main(){
   queue q1;
   for(int i=1;i<=5;i++){
   q1.enqueue(i);
  }
   q1.display();
   q1.enqueue(12);
   q1.display();
   q1.dequeue();
   q1.display();
   q1.dequeue();
   q1.display();
   q1.dequeue();
   q1.display();
}

