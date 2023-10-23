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
    if (NULL  == queue || NULL == element){
        return queue_nok;
    }else if (queue->count == queue->size){
        return full;
    }else{
        (queue->rear)++;
        if (queue->rear == queue->size && queue->front >0){
            queue->rear = 0;
        }
        if (-1 == queue -> front == queue->rear){
            queue->front = queue->rear = 0 ;
        }
        
        queue->array[queue->rear] = element ;
        (queue->count)++;
        
    }
    
    return queue_ok;  
}


void * queue_dequeue(queue_t *queue, queue_status * status){
    void * l_queue;
    if (NULL ==queue || NULL == status){
        * status = queue_nok;
    }else if (queue->count == 0){
        * status = empty;
    }else{
        l_queue = queue->array[queue->front];
        (queue->front)++ ;
        if (queue->size == queue->front){
            queue->front = 0 ; 
        }  
        *status =  queue_ok ; 
        (queue->count)--;
    }

    return l_queue;  
}

void *queue_front(queue_t *queue, queue_status * status){
    if (NULL ==queue || NULL == status){
        * status = queue_nok;
    }else if(queue->count == 0){
        * status = empty;
    }
    return (queue->array[queue->front]);
}

void *queue_rear(queue_t *queue, queue_status * status){
    if (NULL ==queue || NULL == status){
        * status = queue_nok;
    }else if(queue->count == 0){
        * status = empty;
    }
    return (queue->array[queue->rear]);
}

uint32_t queue_count(queue_t *queue,queue_status * status){
    if (NULL ==queue || NULL == status){
        * status = queue_nok;
    }else if(queue->count == 0){
        * status = empty;
    }
    return (queue->count);
}