#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <dos.h>
//#include<bits/stdc++.h>
#include<windows.h>
#include<time.h>
#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <pthread.h> 
#include <semaphore.h> 
#define MAX_CUSTOMERS 2 

void *customer(void *num); 
void *customer1(void *); 
void randwait(int secs); 

sem_t wait; 
sem_t EnterShop; 

sem_t ShopForAWhile; 

sem_t LeaveShop;

int allDone = 0; 

void *customer(void *number) { 
     int num = *(int *)number; 
     printf("Customer %d leaving for  shop.\n", num); 
     randwait(5); 
     printf("Customer %d arrived at shop.\n", num); 
     sem_wait(&wait); 
     printf("Customer %d entering waiting room.\n", num); 
     sem_wait(&EnterShop); 
     sem_post(&wait); 
     printf("Customer %d doing shopping.\n", num); 
     sem_post(&ShopForAWhile); 
     sem_wait(&LeaveShop); 
     sem_post(&EnterShop); 
     printf("Customer %d leaving  shop.\n", num); 
} 

void *customer1(void *junk) 
{ 

   
  while (!allDone) { 
    printf("The customer is shopping\n"); 
    sem_wait(&ShopForAWhile); 
    if (!allDone) 
    { 
     printf("The customer is shopping\n"); 
     randwait(3);
     printf("The customer has finished shopping.\n"); 
     sem_post(&LeaveShop); 
    } 
    else { 
         printf("The customer is leaving shopping.\n"); 
    } 
   }
}
    
void randwait(int secs) { 
     int len = 1; 
     Sleep(len); 
}

int main(int argc, char *argv[]) 
{
    pthread_t btid; 
    pthread_t tid[MAX_CUSTOMERS]; 
    int i, y, numCustomers, numLeft; int Number[MAX_CUSTOMERS]; 
    printf("Maximum number of customers can only be 2. Enter number of customers and left handed.\n");
    scanf("%d",&y);
    numCustomers = y; 
    scanf("%d",&y);
    numLeft = y;
    if (numCustomers > MAX_CUSTOMERS) { 
       printf("The maximum number of Customers is %d.\n", MAX_CUSTOMERS); 
       system("PAUSE");    
       return 0;
    } 
    printf("A solution to the shopping customer problem using semaphores.\n"); 
    for (i = 0; i < MAX_CUSTOMERS; i++) { 
        Number[i] = i; 
    } 
    sem_init(&wait, 0, numLeft); 
    sem_init(&EnterShop, 0, 1);
    sem_init(&ShopForAWhile, 0, 0); 
    sem_init(&LeaveShop, 0, 0); 

    
     pthread_create(&btid, NULL, customer1, NULL); 
     
    for (i = 0; i < numCustomers; i++) {
        pthread_create(&tid[i], NULL, customer,(void *)&Number[i]); 
    } 
    
    for (i = 0; i < numCustomers; i++) { 
        pthread_join(tid[i],NULL); 
    } 
   
    allDone = 1; 
    sem_post(&ShopForAWhile); 
    pthread_join(btid,NULL); 
    system("PAUSE");    
    return 0;
} 
