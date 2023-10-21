#include <stdio.h>
#include "..\Headers\queue.h"

int main(void){
    queue_t  * myQueue;
    queue_status status = queue_nok;
    myQueue = queue_create(5,&status);
    if (queue_ok == status){
        printf("queue has been created\n");
    }else{
        printf("queue is not created \n");
    }
    queue_destroy(myQueue);


    
    return 0 ;
}