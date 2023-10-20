#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include "platform.h"

typedef struct {
    void ** Array ;
    sint32_t ElementCount;
    uint32_t MaxSize;
    sint32_t top;
}stack_t;

typedef enum {
    full,
    empty,
    not_full
}Stack_State;

/**
 * @brief to help intializing the stack 
 * @param size 
 * @param ret 
 * @return stack_t* 
 */
stack_t * Stack_create(uint32_t size,return_status * ret);
/**
 * @brief to free dynamically allocated memory from stack
 * @param stack 
 * @param ret 
 * @return stack_t* 
 */
stack_t * Stack_Destroy(stack_t * stack,return_status * ret);
/**
 * @brief to push an void ptr element to the stack array 
 * @param stack 
 * @param valuePtr 
 * @return return_status 
 */
return_status Stack_push(stack_t * stack,void * valuePtr);
/**
 * @brief  to pop an void ptr element from stack array 
 * @param stack 
 * @param ret 
 * @return void* 
 */
void * Stack_pop(stack_t * stack,return_status * ret);
/**
 * @brief to get stack top
 * @param stack ptr* 
 * @param ret 
 * @return void* 
 */
void * Stack_top(stack_t * stack,return_status * ret);
/**
 * @brief to know whither stack is full or not
 * @param stack 
 * @return Stack_State 
 */
static uint8_t Stack_full(stack_t* stack);
/**
 * @brief to know whither stack is empty or not
 * @param stack 
 * @return Stack_State 
 */
static uint8_t Stack_empty(stack_t* stack);
#endif