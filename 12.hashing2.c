/*Given a File of N employee records with a set K of Keys(4-digit) which 
uniquely determine the records in file F. Assume that file F is maintained 
in memory by a Hash Table(HT) of m memory locations with L as the 
set of memory addresses (2-digit) of locations in HT. Let the keys in K 
and addresses in L are Integers. Design and develop a Program in C that 
uses Hash function H: K ®L as H(K)=K mod m (remainder method), and 
implement hashing technique to map a given key K to the address space 
L. Resolve the collision (if any) using linear probing.*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int a[MAX],key,empno,i;
void linear_prob(){
    for(i=key;i+1!=key;i=(i+1)%MAX){
        if(a[i]==-1){
            a[i]=empno;
            return;
        }
    }
    printf("\nHASHTABLE FULL. No place for empno %d",empno);
}
void display(){
    printf("\nThe hashtable is\n");
    for(i=0;i<MAX;i++)
        if(a[i]!=-1)
            printf("\n%d %d",i,a[i]);
}
int main(){
    FILE *fp;
    fp=fopen("employee.txt","r");
    if(fp==NULL){
        printf("File cannot be opened");
        return 1;
    }
    for(i=0;i<MAX;i++)
        a[i]=-1;
    while(fscanf(fp,"%d",&empno)!=EOF){
            key=empno%100;
            linear_prob();
    }
    display();
}
