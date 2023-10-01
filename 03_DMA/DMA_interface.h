
/*************************************************************************************
*************************************************************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

/* DMA init */
void DMA_vInit(u8 Copy_u8SreamID);
/* Function to set source and distination */
void DMA_vSetAddress(u32 *Ptr_u32SrcAdd , u32 *Ptr_u32DistAdd , u32 Copy_u32Size ,u8 Copy_u8SreamID );

void DMA_vStreamEnable(u8 Copy_u8SreamID );

void DMA_VidSetCallBackChannel1( void ( *Ptr ) ( void ) );

void DMA1_Channel1_IRQHandler(void);



#endif 
/*************************************************************************************/