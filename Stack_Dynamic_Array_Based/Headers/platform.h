#ifndef PLATFORM_H
#define PLATFORM_H

typedef char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed int sint32_t;


 /**
  * @brief to define functions status 
  * @retval R_OK ----> for successfully processed | R_NOK ---> for errors detection
  */
typedef enum{
    // to define whether the fuction performed well or not 
    R_NOK,
    R_OK
}return_status;

#endif