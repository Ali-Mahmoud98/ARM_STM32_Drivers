/****************************************************************************************
***************************   The Foundation Of Function   ***************************** 
****************************************************************************************/


/************** INCLUDE LIB **************/
		 #include "BIT_MATH.h"
		 #include "STD_TYPES.h"
/*****************************************/	 

/************** INCLUDE MCAL**************/
		#include "RCC_private.h"
		#include "RCC_interface.h"
		#include "RCC_config.h"
/*****************************************/

/************** INCLUDE HALL**************/
			

/*****************************************/

/************** INCLUDEAPP***************/


/*****************************************/





/************************************ Start_FUNCTION  ************************************/
/* About The Function :
	
				- CLK		: HSE | HSI |PLL	
				- PLLSrc	:PLL_HSE | PLL_HSI
				- HSESrc    :HSE_Crystal ,HSE_RC 
				- If not used send 0
 */
 void RCC_voidInitSysClock( ClkSrcName_t ClkSrc , HSESrcName_t HSESrc , PllSrcName_t PLLSrc  , AHBPreName_t AHB_Prescaler , APB1PreName_t APB1_Prescaler  , APB2PreName_t APB2_Prescaler ) 
 {
		switch(ClkSrc)
		{
			/*HSE*/
			case HSE_CLK:
				/*HSE on*/
				SET_BIT(RCC_CR, 16);
				switch (HSESrc)
				{	 
					case  HSE_Crystal :
					/*turn off BYPASS*/
					CLR_BIT(RCC_CR, 16);
					break; 
					case  HSE_RC :
					/*turn off BYPASS*/
					CLR_BIT(RCC_CR, 16);
					break;
					/*default		:  break;*/	
				}
		    break ;
			 /*******************************************************************************/ 
			 /*HSI: pin zero in RCC_RC active HSI*/  
			case HSI_CLK: 
			 SET_BIT(RCC_CR, 0);
			 break; 
			/*********************************************************************************/

			case PLL_CLK :
				SET_BIT(RCC_CR, 24);
				 switch(PLLSrc)
				 {
					 case PLL_HSE :
					 SET_BIT(RCC_PLLCFGR, 22);						 
					 break ;
					 case PLL_HSI :
					 CLR_BIT(RCC_PLLCFGR, 22);						 
					 break ;
					 	/*default		:  break;*/
					 
				 }
			
			break; 
		/*default		:  break;*/
			
			 }
			/****************************************************************************************/
				/*
	 ABP1_Pre1
	 ABP1_Pre2
	 ABP1_Pre4
	 ABP1_Pre8
	 ABP1_Pre16
	10, 11 , 12
	*/
	switch (APB1_Prescaler)
	{
		case ABP1_Pre1:
		CLR_BIT(RCC_CFGR, 10);
		CLR_BIT(RCC_CFGR, 11);
		CLR_BIT(RCC_CFGR, 12);
		break; 
		case ABP1_Pre2:
		CLR_BIT(RCC_CFGR, 10);
		CLR_BIT(RCC_CFGR, 11);
		SET_BIT(RCC_CFGR, 12);
		break;
		case ABP1_Pre4:
		SET_BIT(RCC_CFGR, 10);
		CLR_BIT(RCC_CFGR, 11);
		SET_BIT(RCC_CFGR, 12);
		break;
		case ABP1_Pre8:
		CLR_BIT(RCC_CFGR, 10);
		SET_BIT(RCC_CFGR, 11);
		SET_BIT(RCC_CFGR, 12);
		break;
		case ABP1_Pre16:
		SET_BIT(RCC_CFGR, 10);
		SET_BIT(RCC_CFGR, 11);
		SET_BIT(RCC_CFGR, 12);
		break;
			/*default		:  break;*/
		
		
	}
/**************************************************************************************************/	
		/*
		* APB2_Prescaller 
		ABP2_Pre1
		ABP2_Pre2
		ABP2_Pre4
		ABP2_Pre8
		ABP2_Pre16
		13 , 14 ,15
		*/
		switch (APB2_Prescaler)
		{
			case ABP1_Pre1:
			CLR_BIT(RCC_CFGR, 13);
			CLR_BIT(RCC_CFGR, 14);
			CLR_BIT(RCC_CFGR, 15);
			break; 
			case ABP1_Pre2:
			CLR_BIT(RCC_CFGR, 13);
			CLR_BIT(RCC_CFGR, 14);
			SET_BIT(RCC_CFGR, 15);
			break;
			case ABP1_Pre4:
			SET_BIT(RCC_CFGR, 13);
			CLR_BIT(RCC_CFGR, 14);
			SET_BIT(RCC_CFGR, 15);
			break;
			case ABP1_Pre8:
			CLR_BIT(RCC_CFGR, 13);
			SET_BIT(RCC_CFGR, 14);
			SET_BIT(RCC_CFGR, 15);
			break;
			case ABP1_Pre16:
			SET_BIT(RCC_CFGR, 13);
			SET_BIT(RCC_CFGR, 14);
			SET_BIT(RCC_CFGR, 15);
			break;
			
			/*default		:  break;*/
		}
	
			
			/*
					AHB_Pre1
					AHB_Pre2
					AHB_Pre4
					AHB_Pre8
					AHB_Pre16
					AHB_Pre32
					AHB_Pre64
					AHB_Pre128
					AHB_Pre256
					AHB_Pre512
					4 pins : 4,5,6,7 in reg: RCC_CFGR
			*/
			switch (AHB_Prescaler)
			{
				case AHB_Pre1 :
				CLR_BIT(RCC_CFGR, 4);
				CLR_BIT(RCC_CFGR, 5);
				CLR_BIT(RCC_CFGR, 6);
				CLR_BIT(RCC_CFGR, 7);
				break ;                 
				/***********/           
				case AHB_Pre2 :         
				CLR_BIT(RCC_CFGR, 4);
				CLR_BIT(RCC_CFGR, 5);
				CLR_BIT(RCC_CFGR, 6);
				SET_BIT(RCC_CFGR, 7);
				break ;                 
				/***********/           
				case AHB_Pre4 :         
				SET_BIT(RCC_CFGR, 4);
				CLR_BIT(RCC_CFGR, 5);
				CLR_BIT(RCC_CFGR, 6);
				SET_BIT(RCC_CFGR, 7);
				break ;                 
				/***********/           
				case AHB_Pre8 :       
				CLR_BIT(RCC_CFGR, 4);
				SET_BIT(RCC_CFGR, 5);
				CLR_BIT(RCC_CFGR, 6);
				SET_BIT(RCC_CFGR, 7);
						
				break ;                 
				/***********/     
				/* case AHB_Pre32 : */
				/***********/   
				case AHB_Pre16 :        
				SET_BIT(RCC_CFGR, 4);
				SET_BIT(RCC_CFGR, 5);
				CLR_BIT(RCC_CFGR, 6);
				SET_BIT(RCC_CFGR, 7);
				break ;                 
				/***********/           
				case AHB_Pre64 :        
				CLR_BIT(RCC_CFGR, 4);
				CLR_BIT(RCC_CFGR, 5);
				SET_BIT(RCC_CFGR, 6);
				SET_BIT(RCC_CFGR, 7);
				break ;                 
				/***********/           
				case AHB_Pre128 :       
				SET_BIT(RCC_CFGR, 4);
				CLR_BIT(RCC_CFGR, 5);
				SET_BIT(RCC_CFGR, 6);
				SET_BIT(RCC_CFGR, 7);
				break ;                 
				case AHB_Pre256 :       
				CLR_BIT(RCC_CFGR, 4);
				SET_BIT(RCC_CFGR, 5);
				SET_BIT(RCC_CFGR, 6);
				SET_BIT(RCC_CFGR, 7);
				break ;                 
				/***********/           
				case AHB_Pre512 :       
				SET_BIT(RCC_CFGR, 4);
				SET_BIT(RCC_CFGR, 5);
				SET_BIT(RCC_CFGR, 6);
				SET_BIT(RCC_CFGR, 7);
				break ;
				/***********/
					/*default		:  break;*/ 
				
			}
		 
 }



/*********************************************************** END_ FUNCTION   ***********************************************************/



\
/************************************ Start_FUNCTION  ************************************/

 void RCC_voidEnableClock (BusName_t BusName ,u8 Copy_u8PerName  )
 {
	 switch(BusName) 
	 {
		 case AHB1_BUS :
			SET_BIT(RCC_AHB1ENR , Copy_u8PerName  ) ;
		 break ; 
		 
		 case AHB2_BUS  :
			SET_BIT(RCC_AHB2ENR , Copy_u8PerName  ) ;
		 break ;
		 
		/* case AHB3_BUS  :
			 SET_BIT(RCC_AHB3ENR , Copy_u8PerName  ) ;
		 break ;*/
		 
		 case APB1_BUS  :
			SET_BIT(RCC_APB1LPENR , Copy_u8PerName  ) ;	
		 break ;
		 
		 case APB2_BUS  :
			SET_BIT(RCC_APB2LPENR , Copy_u8PerName  ) ;	
		 break ;
		 
			/*default		:  break;*/
		 
		 
	 }
 }

 
