#include "..\Headers\queue.h"

queue_t *queue_create(uint32_t size, queue_status * status){
    
    queue_t * l_queue ;
    l_queue = (queue_t*)malloc(sizeof(queue_t));
    
    if (NULL == l_queue ){
        *status = queue_nok;
    }else{
        l_queue->array = (void**) calloc(size,sizeof(void*));
        l_queue->count = 0 ;
        l_queue->front = -1 ;
        l_queue->rear = -1 ;
        l_queue->size =size ;
    }
    
    return l_queue;
}
queue_status queue_destroy(queue_t *queue){
    if (NULL == queue){
        return queue_nok;
    }else{
        free(queue->array);
        free(queue);
        printf("queue has been destroyed\n");
    }
    
   return queue_ok;
}

queue_status queue_enqueue(queue_t *queue, void *element){
    // return queueStatus();
}

queue_status queue_dequeue(queue_t *queue, void *element){
    // return queueStatus();
}
void *queue_front(queue_t *queue){
    // return nullptr;
}

void *queue_rear(queue_t *queue){
    // return nullptr;
}

uint32_t queue_count(queue_t *queue,queue_status * status){

}