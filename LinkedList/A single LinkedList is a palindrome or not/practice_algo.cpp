/*Industry is the key to success */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;

  node(int data)
  {
    this->data=data;
    this->next=NULL;
  }
};
int main()
{
     node *head=NULL;
    int n;  cin>>n;
    int value;  cin>>value;
    head=new node(value);
    node *current=head;
    for(int i=2;i<=n;i++)
    {
      int val;  cin>>val;
      node *temp=new node(val);
      current->next=temp;
      current=temp;
    }
    if(n==1){
      cout<<"palindrome"<<endl;
      return 1;
    }
   node *fast=head,*slow=head;
   while(fast->next!=NULL&&fast->next->next!=NULL)
   {
    slow=slow->next;
    fast=fast->next->next;
   }
   bool odd=1;
   if(fast->next!=NULL){
   fast=fast->next;
   odd=0;
   }
   if(slow->next!=NULL){
   node *temp=slow;
   slow=slow->next;
   temp->next=NULL;
   }
   current=head;
   while(slow!=NULL)
   {
    node *temp=slow->next;
    slow->next=current;
    current=slow;
    slow=temp;
   }
  /* while(fast!=NULL)
   {
    cout<<fast->data<<" ";
    fast=fast->next;
   }*/
  while(head!=NULL)
   {
     if(head->next==NULL&&odd){
      break;
     }
    if(head->data!=fast->data){
      cout<<"Not Pallindrome"<<endl;
      return 1;
    }
    head=head->next;
    fast=fast->next;
   }
   cout<<"Pallindrome"<<endl;
   
}