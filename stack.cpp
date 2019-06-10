/* a stack which does not have previous linked list */

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

class stack{
 public:
  node*top;

//constructor
stack(){
  top=NULL;
  }

//insert at top most position
//use function push();
void push(int newvalue){
  //if it is an empty stack
 if(top==NULL){
  //create a new node and insert
  node*temp=new  node();
  temp->value=newvalue;
  top=temp;
    }
 else{
    //create a new node and insert there
    node*temp=new node();
    temp->value=newvalue;
    temp->next=top;
    top=temp;
    }
  }

//delete at top most position
//use function  pop();
void pop(){
 //if stack is already empty
 if(top==NULL){
  //print "sorry delete can't possible due to unavailablity of node"
  cout<<"sorry! delete can't be possibledue to unavailability of node"<<endl;
    }
 else{
    //delete the 1st node
    node*temp=top;
    top=top->next;
    delete temp;
    }
  }

//display
void display(){
  node*current=top;
  while(current!=NULL){
    cout<<current->value<<"->";
    current=current->next;
    }
  cout<<"NULL"<<endl;
  }
};

//int main function
int main(){
  stack s1;
  for(int i=1;i<10;i++)
  s1.push(i);
  s1.display();
  s1.push(12);
  s1.display();
  s1.push(20);
  s1.display();
  s1.pop();
    cout<<"after deletion"<<endl;
  s1.display();
}













