/*Design, Develop and Implement a menu driven Program in C for the 
following operations on Circular QUEUE of Characters (Array 
Implementation of Queue with maximum size MAX)
a. Insert an Element on to Circular QUEUE
b. Delete an Element from Circular QUEUE
c. Demonstrate Overflow and Underflow situations on Circular QUEUE
d. Display the status of Circular QUEUE
e. Exit
Support the program with appropriate functions for each of the above 
operations*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 5
char q[MAX];
int f=0,r=0;
void insert(){
    char e;
    if((r+1)%MAX==f){
        printf("\nQueue Overflow\n");
        return;
    }
    printf("\nEnter element to be inserted\n");
    scanf("\n%c",&e);//Very important line
    r=(r+1)%MAX;
    q[r]=e;
}
void delete(){
    if(f==r){
        printf("\nQueue Underflow\n");
        return;
    }
    f=(f+1)%MAX;
    printf("\nThe element being dequeued is %c\n",q[f]);
}
void display(){
    if(f==r){
        printf("\nEmpty Queue\n");
        return;
    }
    int i=f;
    printf("\nThe elements of the queue are:\n");
    while(i!=r){
        i=(i+1)%MAX;
        printf("%c ",q[i]);
    }
}
int main(){
    int ch;
    printf("\nMENU\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    while(1){
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
        }
    }
}
