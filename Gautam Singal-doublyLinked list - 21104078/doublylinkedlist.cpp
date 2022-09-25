#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// creating node class
class node{
    public:
    string Name;
    int Age;
    node*previous;
    node*next;
    node(string x,int y){
        Name = x;
        Age = y;
        previous=NULL;
        next=NULL;

    }
};
// creating a function to push nodes in linked list
void push_nodes(node *&head,node *&current){
    if(head==NULL){
        head=current;
        return;
    }
    node* tmp = head;
    while(tmp->next!=NULL){
        tmp = tmp->next;
    }
    tmp->next = current;
    current->previous = tmp;
    return;
}
//creating a function to print linked list
void printfamilylist(node* head){
    while(head!=NULL){
        cout<<head->Name<<" "<<head->Age<< " <--> ";
        head = head->next;
    }
    return;
} 

signed main(){
    node* head = NULL;
    int n;
    cout<<"Enter the total member count in family: ";
    cin>>n;
    while(n--){
        string x;
        int y;
        cout<<"Enter the name of family member: ";
        cin>>x;
        cout<<"Enter the age of family member: ";
        cin>>y;
        node* current = new node(x,y);
        push_nodes(head,current);
    }
    printfamilylist(head);
    cout<<"NULL"<<endl;
    return 0;
}



//bonus(we could not create relation between the linked list nodes as the linked list are linear data structure so we could not imply to it.)