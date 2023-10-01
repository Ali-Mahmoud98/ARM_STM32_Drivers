/******************************************************************************************/
/******************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_private.h"
#include "DMA_config.h"
#include "DMA_interface.h"



void ( *DMA_CallBackChannel1 )( void );

void DMA_vInit(u8 Copy_u8SreamID )
{
     /* 1- Before Any Config The Bit Of EN Must = 0 ,It must Be Disable*/
	/* Use Stream NUM = 0 */
	/* If Enable Bit == 1 */
	
	CLR_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR, 0U);
	

  	/* 2- Select The Channel(Used For Conect Peripheral To Memory) In stream  But From Mermoery To Memory Not Use*/
	/*select channel 5*/
	SET_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR, 25U);
	CLR_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR, 26U);
	SET_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR, 27U);
	
	/* 3-SoftWare Priority Stream :{ LOW , Medium , High , VeryHigh} BIT(16 , 17)---> VeryHigh  */
	SET_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR, 16U);
	SET_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR, 17U);
	
	/* 4- Set DIR Mode :{ (MTM) ,PTM ,MTP} BIT (6,7) */
	#if MODE == MEM2MEM
	/*memory to memory*/
	CLR_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR , 6U);
	SET_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR , 7U);
	#elif MODE == MEM2PREPH
	SET_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR , 6U);
	CLR_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR , 7U);
	#elif MODE == PREPH2MEM
	CLR_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR , 6U);
	CLR_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR , 7U);
	#endif
	
	/* 5- Set M & M SIZE BIT(13,14) ,(11,12) :{Byte , HaveWord , (Word)}*/
	/* 	As Word 32 For Source	*/ 
	/*Peripheral data size -> Word*/
	CLR_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR , 11U);
	SET_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR , 12U);
	/*memory data size -> Word*/
	CLR_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR , 13U);
	SET_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR , 14U);
	
	
	/* 6- Disable Direct Mode to used fifo  */
	SET_BIT(DMAUSED->StreamID[Copy_u8SreamID].FCR, 2U);
	
	/* 7-Set FIFO Threshold {(1/4),(1/2),(3/4),full} */
	/* Use (1/2)*/
	SET_BIT(DMAUSED->StreamID[Copy_u8SreamID].FCR, 0U);
	CLR_BIT(DMAUSED->StreamID[Copy_u8SreamID].FCR, 1U);

	
	/* 8-SRC & DIS Increament For Both */
	SET_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR , 9U);
	SET_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR , 10U);
    
	/* 9- EN Interrput Of Transfer Complete */
	SET_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR , 4U);

	/*Enable Double buffer mode*/
	SET_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR, 18);
}






void DMA_vSetAddress(u32 *Ptr_u32SrcAdd , u32 *Ptr_u32DistAdd , u32 Copy_u32Size ,u8 Copy_u8SreamID )
{
	if (Copy_u32Size > 65535)
	{
		return;
	}
	DMAUSED->StreamID[Copy_u8SreamID].NDTR = Copy_u32Size;

	#if MODE == MEM2MEM
	/*memory to memory*/
	/*The current target memory is Memory 1 (addressed by the DMA_SxM1AR pointer)*/	
	SET_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR, 19);

	DMAUSED->StreamID[Copy_u8SreamID].M0AR = Ptr_u32SrcAdd;
	DMAUSED->StreamID[Copy_u8SreamID].M1AR = Ptr_u32DistAdd;
	#elif MODE == MEM2PREPH
	DMAUSED->StreamID[Copy_u8SreamID].M0AR = Ptr_u32SrcAdd;
	DMAUSED->StreamID[Copy_u8SreamID].PAR = Ptr_u32DistAdd;
	#elif MODE == PREPH2MEM
	DMAUSED->StreamID[Copy_u8SreamID].PAR = Ptr_u32SrcAdd;
	DMAUSED->StreamID[Copy_u8SreamID].M0AR = Ptr_u32DistAdd;
	#endif

}

void DMA_vStreamEnable(u8 Copy_u8SreamID )
{
	/* All Flag == 0 or make them =0 */
	DMAUSED->HIFCR |= 0x0F7D0F7D;
	DMAUSED->LIFCR |= 0x0F7D0F7D;

	SET_BIT(DMAUSED->StreamID[Copy_u8SreamID].CR, 0U);
}

void DMA_VidSetCallBackChannel1( void ( *Ptr ) ( void ) )
{
	DMA_CallBackChannel1 = Ptr;
}

void DMA1_Channel1_IRQHandler(void){
	DMA_CallBackChannel1();
}
/******************************************************************************************/

/********************************
DMA STEPS
*********************************
	/*Enable clock access to DMA*/

	/*Disable DMA1 Stream6*/ /*CR

    /*Wait until DMA1 Stream 6 is disabled */ /*CR

	/*Clear all interrupt flags of Stream6*/ /*HIFCR

	/*Set the destination buffer*/  /*PAR

	/*Set the source buffer*/  /*M0AR

	/*Set length*/  /*NDTR

	/*Select Stream6 CH4*/ /*CR

	/*Enable memory increment*/  /*CR

	/*Configure transfer direction*/  /*CR

	/*Enable DMA transfer complete interrupt*/  /*CR

	/*Enable direct mode and disable FIFO*/  /*FCR

	/*Enable DMA1 Stream6*/  /*CR

	/*Enable UART2 transmitter DMA*/  /* UART DMA

	/*DMA Interrupt enable in NVIC*/ /*NVIC_EnableIRQ(DMA1_Stream6_IRQn);

/*******************************/

