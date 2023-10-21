#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include "platform.h"

typedef struct  
{
    void ** array;
    uint32_t size;
    uint32_t count;
    sint32_t front;
    sint32_t rear;
}queue_t;

/**
 * @brief to define the status of the Queue
 */
typedef enum{
    full,
    empty,
    notFull,
    queue_ok,
    queue_nok 
}queue_status;

/**
 * @brief 
 * 
 * @param size 
 * @param status 
 * @return queue_t* 
 */
queue_t *queue_create(uint32_t size, queue_status * status);
/**
 * @brief 
 * 
 * @param queue 
 * @return queue_status 
 */
queue_status queue_destroy(queue_t* queue);
/**
 * @brief 
 * 
 * @param queue 
 * @param element 
 * @return queue_status 
 */
queue_status queue_enqueue(queue_t* queue, void * element);
/**
 * @brief 
 * 
 * @param queue 
 * @param element 
 * @return queue_status 
 */
queue_status queue_dequeue(queue_t* queue, void * element);
/**
 * @brief 
 * 
 * @param queue 
 * @param status 
 * @return uint32_t 
 */
uint32_t queue_count(queue_t *queue,queue_status * status);
/**
 * @brief 
 * 
 * @param queue 
 * @return void* 
 */
void * queue_front(queue_t* queue);
/**
 * @brief 
 * 
 * @param queue 
 * @return void* 
 */
void * queue_rear(queue_t* queue);

#endif