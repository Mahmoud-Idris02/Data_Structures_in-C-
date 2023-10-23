#include <stdio.h>
#include "..\Headers\queue.h"

int main(void){
    queue_t  * myQueue;
    queue_status status = queue_nok;
    uint32_t num1 = 2 , num2 = 5 , num3 = 6, num4 = 9;
    void * q_element;

    myQueue = queue_create(5,&status);
    if (queue_ok == status){
        printf("queue has been created\n");
    }else{
        printf("queue is not created \n");
    }

    status = queue_enqueue(myQueue,&num1); printf("%i",status);
    status = queue_enqueue(myQueue,&num2); printf("%i",status);
    status = queue_enqueue(myQueue,&num3); printf("%i",status);
    status = queue_enqueue(myQueue,&num4); printf("%i\n",status);

    q_element= queue_front(myQueue,&status);printf(" queue front is :%i\n",*((uint32_t*) q_element));
    q_element= queue_rear(myQueue,&status);printf(" queue rear is :%i\n",*((uint32_t*) q_element));

    q_element = queue_dequeue(myQueue,&status); printf("%i",status);
    q_element = queue_dequeue(myQueue,&status); printf("%i",status);
    q_element = queue_dequeue(myQueue,&status); printf("%i",status);
    q_element = queue_dequeue(myQueue,&status); printf("%i",status);
    q_element = queue_dequeue(myQueue,&status); printf("%i\n",status);
    queue_destroy(myQueue);


    
    return 0 ;
}