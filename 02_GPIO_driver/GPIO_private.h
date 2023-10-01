/**************************************************************************************

*	 - Developer can't Edit in it    
*	  - Register _ Defination		
*	  - Design : 
					- #define	:	Yes
					- Union		:	NO
					- Struct	:	NO

**************************************************************************************/

/*************************************************************************************
******************* guard of file will call on time in .c		   *******************
*************************************************************************************/ 


#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/***********************************************************************************
	-----> Macros
			*  Base_Address GPI0X				
************************************************************************************/

#define  GPIOA_BASE_ADDRESS								(0x40020000 + 0x0000U)								
#define  GPIOB_BASE_ADDRESS								(0x40020000 + 0x400U)		
#define  GPIOC_BASE_ADDRESS								(0x40020000 + 0x800U)			
#define  GPIOD_BASE_ADDRESS								(0x40020000 + 0xc00U)			
#define  GPIOE_BASE_ADDRESS								(0x40020000 + 0x1000U)			
#define  GPIOH_BASE_ADDRESS								(0x40020000 + 0x1c00U)					

/***********************************************************************************
	-----> Macros
			  *  Register Map	 GPIO_A		
************************************************************************************/


#define  GPIOA_MODER									(*((volatile u32*) (GPIOA_BASE_ADDRESS + 0x00U)))			
#define  GPIOA_OTYPER									(*((volatile u32*) (GPIOA_BASE_ADDRESS + 0x04U)))			
#define  GPIOA_OSPEEDR									(*((volatile u32*) (GPIOA_BASE_ADDRESS + 0x08U)))			
#define  GPIOA_PUPDR									(*((volatile u32*) (GPIOA_BASE_ADDRESS + 0x0CU)))			
#define  GPIOA_IDR										(*((volatile u32*) (GPIOA_BASE_ADDRESS + 0x10U)))/*IDR is READ ONLY REGISTER*/			
#define  GPIOA_ODR										(*((volatile u32*) (GPIOA_BASE_ADDRESS + 0x14U)))			
#define  GPIOA_BSRR										(*((volatile u32*) (GPIOA_BASE_ADDRESS + 0x18U)))			
#define  GPIOA_LCKR										(*((volatile u32*) (GPIOA_BASE_ADDRESS + 0x1CU)))			
#define  GPIOA_AFRL										(*((volatile u32*) (GPIOA_BASE_ADDRESS + 0x20U)))			
#define  GPIOA_AFRH										(*((volatile u32*) (GPIOA_BASE_ADDRESS + 0x24U)))			
/***********************************************************************************
	-----> Macros
			  *  Register Map	 GPIO_B		
************************************************************************************/


#define  GPIOB_MODER									(*((volatile u32*) (GPIOB_BASE_ADDRESS + 0x00U)))
#define  GPIOB_OTYPER									(*((volatile u32*) (GPIOB_BASE_ADDRESS + 0x04U)))
#define  GPIOB_OSPEEDR							  		(*((volatile u32*) (GPIOB_BASE_ADDRESS + 0x08U)))
#define  GPIOB_PUPDR									(*((volatile u32*) (GPIOB_BASE_ADDRESS + 0x0CU)))
#define  GPIOB_IDR										(*((volatile u32*) (GPIOB_BASE_ADDRESS + 0x10U)))
#define  GPIOB_ODR										(*((volatile u32*) (GPIOB_BASE_ADDRESS + 0x14U)))
#define  GPIOB_BSRR										(*((volatile u32*) (GPIOB_BASE_ADDRESS + 0x18U)))
#define  GPIOB_LCKR										(*((volatile u32*) (GPIOB_BASE_ADDRESS + 0x1CU)))
#define  GPIOB_AFRL										(*((volatile u32*) (GPIOB_BASE_ADDRESS + 0x20U)))
#define  GPIOB_AFRH										(*((volatile u32*) (GPIOB_BASE_ADDRESS + 0x24U)))
																										
/***********************************************************************************
	-----> Macros
			  *  Register Map	 GPIO_C		
************************************************************************************/


#define  GPIOC_MODER									(*((volatile u32*) (GPIOC_BASE_ADDRESS + 0x00U)))
#define  GPIOC_OTYPER									(*((volatile u32*) (GPIOC_BASE_ADDRESS + 0x04U)))
#define  GPIOC_OSPEEDR							    	(*((volatile u32*) (GPIOC_BASE_ADDRESS + 0x08U)))
#define  GPIOC_PUPDR									(*((volatile u32*) (GPIOC_BASE_ADDRESS + 0x0CU)))
#define  GPIOC_IDR										(*((volatile u32*) (GPIOC_BASE_ADDRESS + 0x10U)))
#define  GPIOC_ODR										(*((volatile u32*) (GPIOC_BASE_ADDRESS + 0x14U)))
#define  GPIOC_BSRR										(*((volatile u32*) (GPIOC_BASE_ADDRESS + 0x18U)))
#define  GPIOC_LCKR										(*((volatile u32*) (GPIOC_BASE_ADDRESS + 0x1CU)))
#define  GPIOC_AFRL										(*((volatile u32*) (GPIOC_BASE_ADDRESS + 0x20U)))
#define  GPIOC_AFRH										(*((volatile u32*) (GPIOC_BASE_ADDRESS + 0x24U)))
	
/***********************************************************************************
	-----> Macros
			  *  Register Map	 GPIO_D		
************************************************************************************/


#define  GPIOD_MODER									(*((volatile u32*) (GPIOD_BASE_ADDRESS + 0x00U)))
#define  GPIOD_OTYPER									(*((volatile u32*) (GPIOD_BASE_ADDRESS + 0x04U)))
#define  GPIOD_OSPEEDR							    	(*((volatile u32*) (GPIOD_BASE_ADDRESS + 0x08U)))
#define  GPIOD_PUPDR									(*((volatile u32*) (GPIOD_BASE_ADDRESS + 0x0CU)))
#define  GPIOD_IDR										(*((volatile u32*) (GPIOD_BASE_ADDRESS + 0x10U)))
#define  GPIOD_ODR										(*((volatile u32*) (GPIOD_BASE_ADDRESS + 0x14U)))
#define  GPIOD_BSRR										(*((volatile u32*) (GPIOD_BASE_ADDRESS + 0x18U)))
#define  GPIOD_LCKR										(*((volatile u32*) (GPIOD_BASE_ADDRESS + 0x1CU)))
#define  GPIOD_AFRL										(*((volatile u32*) (GPIOD_BASE_ADDRESS + 0x20U)))
#define  GPIOD_AFRH										(*((volatile u32*) (GPIOD_BASE_ADDRESS + 0x24U)))

/***********************************************************************************
	-----> Macros
			  *  Register Map	 GPIO_E		
************************************************************************************/


#define  GPIOE_MODER									(*((volatile u32*) (GPIOE_BASE_ADDRESS + 0x00U)))
#define  GPIOE_OTYPER									(*((volatile u32*) (GPIOE_BASE_ADDRESS + 0x04U)))
#define  GPIOE_OSPEEDR								    (*((volatile u32*) (GPIOE_BASE_ADDRESS + 0x08U)))
#define  GPIOE_PUPDR									(*((volatile u32*) (GPIOE_BASE_ADDRESS + 0x0CU)))
#define  GPIOE_IDR										(*((volatile u32*) (GPIOE_BASE_ADDRESS + 0x10U)))
#define  GPIOE_ODR										(*((volatile u32*) (GPIOE_BASE_ADDRESS + 0x14U)))
#define  GPIOE_BSRR										(*((volatile u32*) (GPIOE_BASE_ADDRESS + 0x18U)))
#define  GPIOE_LCKR										(*((volatile u32*) (GPIOE_BASE_ADDRESS + 0x1CU)))
#define  GPIOE_AFRL										(*((volatile u32*) (GPIOE_BASE_ADDRESS + 0x20U)))
#define  GPIOE_AFRH										(*((volatile u32*) (GPIOE_BASE_ADDRESS + 0x24U)))	
/***********************************************************************************
	-----> Macros
			  *  Register Map	 GPIO_F		
************************************************************************************/

/*
#define  GPIOE_MODER									
#define  GPIOE_OTYPER									
#define  GPIOE_OSPEEDR							        
#define  GPIOE_PUPDR									
#define  GPIOE_IDR										
#define  GPIOE_ODR										
#define  GPIOE_BSRR										
#define  GPIOE_LCKR										
#define  GPIOE_AFRL										
#define  GPIOE_AFRH										
*/
/***********************************************************************************
	-----> Macros
			  *  Register Map	 GPIO_G		
************************************************************************************/

/*
#define  GPIOG_MODER									
#define  GPIOG_OTYPER									
#define  GPIOG_OSPEEDR								    
#define  GPIOG_PUPDR									
#define  GPIOG_IDR										
#define  GPIOG_ODR										
#define  GPIOG_BSRR										
#define  GPIOG_LCKR										
#define  GPIOG_AFRL										
#define  GPIOG_AFRH										
*/
/***********************************************************************************
	-----> Macros
			  *  Register Map	 GPIO_H		
************************************************************************************/


#define  GPIOH_MODER									(*((volatile u32*) (GPIOH_BASE_ADDRESS +0X00)))
#define  GPIOH_OTYPER									(*((volatile u32*) (GPIOH_BASE_ADDRESS +0X04)))
#define  GPIOH_OSPEEDR									(*((volatile u32*) (GPIOH_BASE_ADDRESS +0X08)))
#define  GPIOH_PUPDR									(*((volatile u32*) (GPIOH_BASE_ADDRESS +0X0C)))
#define  GPIOH_IDR										(*((volatile u32*) (GPIOH_BASE_ADDRESS +0X10)))
#define  GPIOH_ODR										(*((volatile u32*) (GPIOH_BASE_ADDRESS +0X14)))
#define  GPIOH_BSRR										(*((volatile u32*) (GPIOH_BASE_ADDRESS +0X18)))
#define  GPIOH_LCKR										(*((volatile u32*) (GPIOH_BASE_ADDRESS +0X1C)))
#define  GPIOH_AFRL										(*((volatile u32*) (GPIOH_BASE_ADDRESS +0X20)))
#define  GPIOH_AFRH										(*((volatile u32*) (GPIOH_BASE_ADDRESS +0X24)))	
																																																																																																																																												
#endif 

