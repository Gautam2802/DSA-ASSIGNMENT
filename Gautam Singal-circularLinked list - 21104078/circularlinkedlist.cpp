//QUESTION-1->WHILE TRAVERSING A CIRCULAR LINKED LIST,WHICH CONDITION ESATBLISHES THAT THE TRAVERSING ELEMENT/VARIABLE HAS REACHED THE FIRST ELEMENT?

//SOLUTION-1( LET US SEE AN BASIC CIRCULAR LINKED LIST)
#include <iostream>
using namespace std;
//creating a node structure
struct node {
    //creating objects
   int data;
   struct node *next;
};

struct node* head = NULL;
//function to insert a node in the linked list
void append(int data) {
   struct node *newnode = (struct node *)malloc(sizeof(struct node));
   struct node *temp = head;
   newnode->data = data;
   newnode->next = head;
   if (head!= NULL) {
    //This is the required condition that establishes that travesing element(temp) has reached the first element(head)
      while (temp->next != head)
      temp = temp->next;
      temp->next = newnode;
   } else
   newnode->next = newnode;
   head = newnode;
}
//function to print elements of linked list from head to the last node
void print() {
   struct node* temp;
   temp = head;
   do {
      cout<<temp->data <<" -> ";
      temp = temp->next;
   } 
   while(temp != head);

}
int main() {
   append(10);
   append(5);
   append(9);
   append(15);
   append(2);
   append(6);
   cout<<"This is the following circular linked list: ";
   print();
   cout<<"head";
   return 0;
}
//with reference to above:-
//in circular linked list last node points to the head of linked list.if node points to the head then that node is end of list
//ACCORDING TO ABOVE CODE(we can conclude) by line 22-24 establish that the variable has reached the first element.



/*QUESTION-2-> What are the practical applications of a circular linked list? (Try to find applications in your respective fields).
Practical applications of circular linked list are :

SOLUTION 2:-

. ENERGY METER->circular linked list are used in energy meter in which after attaining 1 unit electricity it again start from 0 and reach till 9 and add the unit electricity again and again in meter.
. FAN REGULATORS-> the high speed is connected to the min speed while traversing.
. ODOMETER/SPEEDOMETER-> can be act as circular linked list as measure unit distance and unit speed after which it again started to measure unit diastance and speed and store the value.


*/

