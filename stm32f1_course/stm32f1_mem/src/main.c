#include "stm32f1xx.h"

#define	    BUFFER_SIZE			32

uint8_t	    src_buffer[BUFFER_SIZE];
uint8_t	    dst_buffer[BUFFER_SIZE];

DMA_HandleTypeDef dma;

void copy_cpu()
{
    int i;
    for (i = 0; i < BUFFER_SIZE;i++)
        dst_buffer[i] = src_buffer[i];
}

void copy_dma()
{
    HAL_DMA_Start(&dma, (uint32_t)src_buffer, (uint32_t)dst_buffer, BUFFER_SIZE);
    HAL_DMA_PollForTransfer(&dma, HAL_DMA_FULL_TRANSFER, HAL_MAX_DELAY);
}

int main(void)
{
    int i;

    SystemCoreClock = 8000000; // taktowanie 8Mhz
    HAL_Init();

    __HAL_RCC_DMA1_CLK_ENABLE();

    dma.Instance = DMA1_Channel1;
    dma.Init.Direction = DMA_MEMORY_TO_MEMORY;
    dma.Init.PeriphInc = DMA_PINC_ENABLE;
    dma.Init.MemInc = DMA_MINC_ENABLE;
    dma.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    dma.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    dma.Init.Mode = DMA_NORMAL;
    dma.Init.Priority = DMA_PRIORITY_HIGH;
    HAL_DMA_Init(&dma);

    // wypelniamy bufor przykladowymi danymi
    for (i = 0; i < BUFFER_SIZE; i++)
        src_buffer[i] = 100 + i;

    //copy_cpu();
    copy_dma();

    while (1) {
    }
}
