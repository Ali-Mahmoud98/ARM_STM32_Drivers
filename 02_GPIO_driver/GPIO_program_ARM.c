/*********************************************************************************************/
/*********************************************************************************************/


/************** INCLUDE LIB **************/
		 #include "STD_TYPES.h"
		 #include "BIT_MATH.h"
/*****************************************/	 

/************** INCLUDE MCAL**************/
		#include "GPIO_private.h"
		#include "GPIO_interface.h"
		#include "GPIO_config.h"
/*****************************************/

/************** INCLUDE HALL**************/
			

/*****************************************/

/************** INCLUDEAPP***************/


/*****************************************/





/********************************************************** Start_FUNCTION  **********************************************************/
/*		Function Set The Mode Of Pin Mode Take 2Bits	

									MODE_INPUT
									MODE_OUTPUT
									MODE_ALTF
									MODE_ANALOG	

						*/
 void DIO_voidSetPinMode(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8MODE) 
 {	 
	switch (copy_u8PORT)
	{
		case GPIOA_PORT: GPIOA_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN)); break;
		case GPIOB_PORT: GPIOB_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN)); break;
		case GPIOC_PORT: GPIOC_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN)); break;
		case GPIOD_PORT: GPIOD_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN)); break;
		case GPIOE_PORT: GPIOE_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN)); break;
		/*case GPIOF_PORT: GPIOF_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN)); break;
		case GPIOG_PORT: GPIOG_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN)); break;*/
		case GPIOH_PORT: GPIOH_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN)); break;		
		default: break;		
	 }
	 
 }
				

/*********************************************************** END_ FUNCTION   ***********************************************************/


/********************************************************** Start_FUNCTION  **********************************************************/
/*				Function Set The Type Of OutPut (OpenDrain = 0 , PushPull = 1)

								OUTPUT_TYPE_PUSH_PULL
								OUTPUT_TYPE_OPEN_DRAIN	

						*/
void DIO_voidSetOutType(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8Type) 
{
	if (copy_u8Type > OUTPUT_TYPE_OPEN_DRAIN || copy_u8PIN > PIN15 || copy_u8PORT > GPIOH_PORT)
		return;
	
	switch (copy_u8PORT)
	{
		case GPIOA_PORT: GPIOA_OTYPER |=(u32)  (copy_u8Type << (copy_u8PIN)); break;
		case GPIOB_PORT: GPIOB_OTYPER |=(u32)  (copy_u8Type << (copy_u8PIN)); break;
		case GPIOC_PORT: GPIOC_OTYPER |=(u32)  (copy_u8Type << (copy_u8PIN)); break;
		case GPIOD_PORT: GPIOD_OTYPER |=(u32)  (copy_u8Type << (copy_u8PIN)); break;
		case GPIOE_PORT: GPIOE_OTYPER |=(u32)  (copy_u8Type << (copy_u8PIN)); break;
		/*case GPIOF_PORT: GPIOF_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN)); break;
		case GPIOG_PORT: GPIOG_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN)); break;*/
		case GPIOH_PORT: GPIOH_OTYPER |=(u32)  (copy_u8Type << (copy_u8PIN)); break;		
		default: break;		
	 }
}


/*********************************************************** END_ FUNCTION   ***********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/
/*						Function Set The Speed (LOW , Meduim , High ,VeryHaigh		
							
							OUTPUT_LOW_SPEED
							OUTPUT_MEDUIM_SPEED
							OUTPUT_HIGH_SPEED
							OUTPUT_VERY_HIGH_SPEED
							
							

						*/
void DIO_voidSetOutSpeed(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8Speed)  
{
	if (copy_u8Speed > OUTPUT_VERY_HIGH_SPEED || copy_u8PIN > PIN15 || copy_u8PORT > GPIOH_PORT)
		return;
	
	switch (copy_u8PORT)
	{
		case GPIOA_PORT: GPIOA_OSPEEDR |=(u32)  (copy_u8Speed << (copy_u8PIN)); break;
		case GPIOB_PORT: GPIOB_OSPEEDR |=(u32)  (copy_u8Speed << (copy_u8PIN)); break;
		case GPIOC_PORT: GPIOC_OSPEEDR |=(u32)  (copy_u8Speed << (copy_u8PIN)); break;
		case GPIOD_PORT: GPIOD_OSPEEDR |=(u32)  (copy_u8Speed << (copy_u8PIN)); break;
		case GPIOE_PORT: GPIOE_OSPEEDR |=(u32)  (copy_u8Speed << (copy_u8PIN)); break;
		/*case GPIOF_PORT: GPIOF_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN)); break;
		case GPIOG_PORT: GPIOG_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN)); break;*/
		case GPIOH_PORT: GPIOH_OSPEEDR |=(u32)  (copy_u8Speed << (copy_u8PIN)); break;		
		default: break;		
	 }
}


/*********************************************************** END_ FUNCTION   ***********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/
	/*		Function Set The PULL :
								
					PULL_OFF
					PULL_UP
					PULL_DOWN
	
	
		*/
void DIO_voidSetPull(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8PULL_TYPE)  
{
	if (copy_u8PULL_TYPE > PULL_DOWN || copy_u8PIN > PIN15 || copy_u8PORT > GPIOH_PORT)
		return;
	
	switch (copy_u8PORT)
	{
		case GPIOA_PORT: 
						/*GPIOA_OTYPER |=(u32)  (OUTPUT_TYPE_PUSH_PULL << (copy_u8PIN));*/ 
						GPIOA_PUPDR  |=(u32)  (copy_u8PULL_TYPE << copy_u8PIN);
						break;
		case GPIOB_PORT: 
						/*GPIOB_OTYPER |=(u32)  (OUTPUT_TYPE_PUSH_PULL << (copy_u8PIN));*/ 
						GPIOB_PUPDR  |=(u32)  (copy_u8PULL_TYPE << copy_u8PIN);
						break;
		case GPIOC_PORT: 
						/*GPIOC_OTYPER |=(u32)  (OUTPUT_TYPE_PUSH_PULL << (copy_u8PIN));*/
						GPIOC_PUPDR  |=(u32)  (copy_u8PULL_TYPE << copy_u8PIN);
						break;
		case GPIOD_PORT: 
						/*GPIOD_OTYPER |=(u32)  (OUTPUT_TYPE_PUSH_PULL << (copy_u8PIN));*/
						GPIOD_PUPDR  |=(u32)  (copy_u8PULL_TYPE << copy_u8PIN);
						break;
		case GPIOE_PORT: 
						/*GPIOE_OTYPER |=(u32)  (OUTPUT_TYPE_PUSH_PULL << (copy_u8PIN));*/ 
						GPIOE_PUPDR  |=(u32)  (copy_u8PULL_TYPE << copy_u8PIN);
						break;
		/*case GPIOF_PORT: GPIOF_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN)); break;
		case GPIOG_PORT: GPIOG_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN)); break;*/
		case GPIOH_PORT: 
						/*GPIOH_OTYPER |=(u32)  (OUTPUT_TYPE_PUSH_PULL << (copy_u8PIN));*/ 
						GPIOH_PUPDR  |=(u32)  (copy_u8PULL_TYPE << copy_u8PIN);
						break;		
		default: break;		
	 }
}


/*********************************************************** END_ FUNCTION   ***********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/
		/*		Function To Read Data From IDR		*/
u8 DIO_u8ReadData(u8 copy_u8PORT ,u8 copy_u8PIN)
{
	u8 u8Local_Data = 0 ;
	switch (copy_u8PORT)
	{
		case GPIOA_PORT: u8Local_Data =(u8)  GET_BIT(GPIOA_IDR,copy_u8PIN); break;
		case GPIOB_PORT: u8Local_Data =(u8)  GET_BIT(GPIOB_IDR,copy_u8PIN); break;
		case GPIOC_PORT: u8Local_Data =(u8)  GET_BIT(GPIOC_IDR,copy_u8PIN); break;
		case GPIOD_PORT: u8Local_Data =(u8)  GET_BIT(GPIOD_IDR,copy_u8PIN); break;
		case GPIOE_PORT: u8Local_Data =(u8)  GET_BIT(GPIOE_IDR,copy_u8PIN); break;
		/*case GPIOF_PORT: GPIOF_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN)); break;
		case GPIOG_PORT: GPIOG_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN)); break;*/
		case GPIOH_PORT: u8Local_Data =(u8)  GET_BIT(GPIOH_IDR,copy_u8PIN); break;		
		default: break;		
	}
	return u8Local_Data ; 
}


/*********************************************************** END_ FUNCTION   ***********************************************************/


/********************************************************** Start_FUNCTION  **********************************************************/
	/*		
			* Function To Write Data At ODR	Value :
									 high 
									 low	
	*/
void DIO_voidWriteDataOdr(u8 copy_u8PORT ,u8 copy_u8PIN , u8 copy_u8Value )
{
	if (copy_u8Value > HIGH || copy_u8PIN > PIN15)
		return;
	
	switch (copy_u8PORT)
	{
		case GPIOA_PORT: 
			switch (copy_u8Value)
			{
			case HIGH: SET_BIT(GPIOA_ODR, copy_u8PIN); break;
			case LOW: CLR_BIT(GPIOA_ODR, copy_u8PIN); break;
			}
			break;
		case GPIOB_PORT:
			switch (copy_u8Value)
			{
			case HIGH: SET_BIT(GPIOB_ODR, copy_u8PIN); break;
			case LOW: CLR_BIT(GPIOB_ODR, copy_u8PIN); break;
			}
			break;
		case GPIOC_PORT:
			switch (copy_u8Value)
			{
			case HIGH: SET_BIT(GPIOC_ODR, copy_u8PIN); break;
			case LOW: CLR_BIT(GPIOC_ODR, copy_u8PIN); break;
			}
			break;
		case GPIOD_PORT:
			switch (copy_u8Value)
			{
			case HIGH: SET_BIT(GPIOD_ODR, copy_u8PIN); break;
			case LOW: CLR_BIT(GPIOD_ODR, copy_u8PIN); break;
			}
			break;
		case GPIOE_PORT:
			switch (copy_u8Value)
			{
			case HIGH: SET_BIT(GPIOE_ODR, copy_u8PIN); break;
			case LOW: CLR_BIT(GPIOE_ODR, copy_u8PIN); break;
			}
			break;
		/*case GPIOF_PORT: GPIOF_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN)); break;
		case GPIOG_PORT: GPIOG_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN)); break;*/
		case GPIOH_PORT:
			switch (copy_u8Value)
			{
			case HIGH: SET_BIT(GPIOH_ODR, copy_u8PIN); break;
			case LOW: CLR_BIT(GPIOH_ODR, copy_u8PIN); break;
			}
			break;		
	}	
}
/*********************************************************** END_ FUNCTION   ***********************************************************/
	

/*		Function Set The AltFn		: Every Pin Need 4 Bits SO We Have High AND Low			*/
void DIO_voidPinSetAltFn(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8AlT)
{
	if (copy_u8PORT > 15 || copy_u8PIN > 15 || copy_u8AlT > 15)
    {
        return;
    }
	/* From 0 To  7 */
	if (copy_u8PIN <= 7)
	{
		switch (copy_u8PORT)
		{
		case GPIOA_PORT:
			GPIOA_AFRL |= ((u32)copy_u8AlT << (copy_u8PIN * 4));
			break;
		case GPIOB_PORT:
			GPIOB_AFRL |= ((u32)copy_u8AlT << (copy_u8PIN * 4));
			break;
		case GPIOC_PORT:
			GPIOC_AFRL |= ((u32)copy_u8AlT << (copy_u8PIN * 4));
			break;
		case GPIOD_PORT:
			GPIOD_AFRL |= ((u32)copy_u8AlT << (copy_u8PIN * 4));
			break;
		case GPIOE_PORT:
			GPIOE_AFRL |= ((u32)copy_u8AlT << (copy_u8PIN * 4));
			break;
		case GPIOH_PORT:
			GPIOE_AFRL |= ((u32)copy_u8AlT << (copy_u8PIN * 4));
			break;
		}
	}
	/* From 8 To  15 */
	if (copy_u8PIN >= 8 && copy_u8PIN <= 15)
	{
		switch (copy_u8PORT)
		{
		case GPIOA_PORT:
			GPIOA_AFRH |= ((u32)copy_u8AlT << ((copy_u8PIN - 8) * 4)); 
			break;
		case GPIOB_PORT:
			GPIOB_AFRH |= ((u32)copy_u8AlT << ((copy_u8PIN - 8) * 4)); 
			break;
		case GPIOC_PORT:
			GPIOC_AFRH |= ((u32)copy_u8AlT << ((copy_u8PIN - 8) * 4)); 
			break;
		case GPIOD_PORT:
			GPIOD_AFRH |= ((u32)copy_u8AlT << ((copy_u8PIN - 8) * 4));
			break;
		case GPIOE_PORT:
			GPIOE_AFRH |= ((u32)copy_u8AlT << ((copy_u8PIN - 8) * 4));
			break;
		case GPIOH_PORT:
			GPIOE_AFRH |= ((u32)copy_u8AlT << ((copy_u8PIN - 8) * 4));
			break;
		}
	}
}


