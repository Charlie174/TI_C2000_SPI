//
// Included Files
//
#include "cpu.h"
#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "gpio.h"
#include "sci.h"
#include "spi.h"
#include "string.h"
#include "interrupt.h"
// #include <cstdint>
#define SPI_DATA_LENGTH 10

uint16_t delayCount;            // Number (0-9) to scale the LED frequency

//
// Function Prototypes
//
// __interrupt void INT_sw_XINT_ISR(void);
// __interrupt void INT_mySCIA_RX_ISR(void);
// __interrupt void INT_mySPIS_RX_ISR(void);

uint16_t rxStatus = 0U;
char *msg; 
// uint16_t rDataA[2];


//
// Main
//
// uint16_t sData = 15;                  // Send data. Worked 
// char sData = 'M';                  // Send data. Worked
// char rData;                  // Send data. Worked
// char sData[] = "I Miss YOU...";                  // Send data. 
uint16_t sData[];                  // Send data. 
uint8_t s = 0;                  // Send data. 
uint16_t rData = 0;                  // Send data. 
// int8_t rData = 0;                  // Send data. 

// int len = sizeof(sData);
char rxData[] = "I got the msg...";
// char rData[];
char *tx;
char *rx;



// uint16_t sData[SPI_DATA_LENGTH];  // Data buffer to send

// void initSPIdata(void) {
//     uint16_t i;
//     for (i = 0; i < SPI_DATA_LENGTH; i++) {
//         sData[i] = 0xA0 + i;  // Example: Fill with pattern 0xA0, 0xA1, ..., 0xA9
//     }
// }


// void sendSPIdata(void) {
//     uint16_t i;
//     for (i = 0; i < SPI_DATA_LENGTH; i++) {
//         SPI_writeDataNonBlocking(mySPIS_BASE, sData[i]);
//         DEVICE_DELAY_US(10);  // Small delay may be needed between transfers
//     }
// }


//
// Main
//
void main(void)
{
    //
    // CPU Initialization
    //
    Device_init();
    // Interrupt_initModule();
    // Interrupt_initVectorTable();

    //
    // Configure GPIO pins
    //
    Device_initGPIO();

    //
    // Initialize the SCI and Timer Modules
    //
    Board_init();

    // GPIO_setPadConfig(27, GPIO_PIN_SPIB_PTE);
    // GPIO_setPadConfig(cs1, GPIO_PIN_SPIA_PTE);

    EINT;
    ERTM;
    initSPIdata();
    //
    // Send starting message.
    //
    // msg = "\r\n\n\nHello My World! Happy to see you.\0";
    // SCI_writeCharArray(mySCIA_BASE, (uint16_t*)msg, 38);


    for(;;)
        {
            // SCI_enableInterrupt(mySCIA_BASE, SCI_INT_RXRDY_BRKDT);
            // msg = "\r\n1\0";
            // DEVICE_DELAY_US(500000);
            // SCI_writeCharArray(mySCIA_BASE, (uint16_t*)msg, 4);
            // sendSPIdata();
            // SCI_enableInterrupt(mySCIA_BASE, SCI_INT_RXFF);

            // int cs = GPIO_readPin(27);

            // if (cs == 0){
            //     msg = "\r\n4\0";
            //     SCI_writeCharArray(mySCIA_BASE, (uint16_t*)msg, 4);

            //     SPI_writeDataNonBlocking(mySPIS_BASE, sData);
            //     DEVICE_DELAY_US(10);
            //     rData[i] = SPI_readDataBlockingFIFO(mySPIS_BASE);     //not wok for same in and same out.
            //     SCI_writeCharNonBlocking(mySCIA_BASE, rData[i]);

            // }

            // DEVICE_DELAY_US(10);

            // msg = "\r\n4\0";
            // SCI_writeCharArray(mySCIA_BASE, (uint16_t*)msg, 4);

            // SPI_writeDataNonBlocking(mySPIS_BASE, sData);
            // DEVICE_DELAY_US(10);
            // rData = SPI_readDataNonBlocking(mySPIS_BASE);
            // SPI_writeDataNonBlocking(mySPIS_BASE, sData);
            // if (rData == 9)

            // rData = SPI_readDataBlockingFIFO(mySPIS_BASE);
            // SCI_writeCharNonBlocking(mySCIA_BASE, rData);



       
            // rxStatus = SCI_getRxStatus(mySCIA_BASE);
            // if((rxStatus & SCI_RXSTATUS_ERROR) != 0)
            // {
            //     //
            //     // If Execution stops here there is some error
            //     // Analyze SCI_getRxStatus() API return value
            //     //
            //     ESTOP0;
            // }
            
        }
}


// __interrupt void INT_mySCIA_RX_ISR(void){
//     msg = "\r\nInterrupt Happened.\0";
//     SCI_writeCharArray(mySCIA_BASE, (uint16_t*)msg, 21);
//     int x = 1;
//     while (x < 4){
//         msg = "\r\nHi\0";
//         SCI_writeCharArray(mySCIA_BASE, (uint16_t*)msg, 5);
//         DEVICE_DELAY_US(500000);
//         x++;
//     }
//     SCI_resetRxFIFO(mySCIA_BASE);

//     DEVICE_DELAY_US(100000);
//     Interrupt_clearACKGroup(INT_mySCIA_RX_INTERRUPT_ACK_GROUP);
// }



// __interrupt void INT_sw_XINT_ISR(void){
//     int x = 0;
//     while (x < 6){
//         GPIO_writePin(led, 1);
//         DEVICE_DELAY_US(100000);
//         GPIO_writePin(led, 0);
//         DEVICE_DELAY_US(100000);
//         x++;
//     }
//     // DEVICE_DELAY_US(1000000);


//     SPI_writeDataNonBlocking(mySPIM_BASE, sData);
//     SPI_writeDataNonBlocking(mySPIS_BASE, s);
//     rData = SPI_readDataBlockingFIFO(mySPIS_BASE);
//     SCI_writeCharNonBlocking(mySCIA_BASE, rData);

//     // GPIO_writePin(cs1, 0);
//     // DEVICE_DELAY_US(10);         // delay is must for reset the buffer and run the next input minimum 10us
//     // int i = 0;
//     // for(i = 0; i < len; i++){
//     //     SPI_writeDataNonBlocking(mySPIM_BASE, sData[i]);
//     //     DEVICE_DELAY_US(10);         // delay is must for reset the buffer and run the next input minimum 10us

//     //     // rData[i] = SPI_readDataNonBlocking(mySPIS_BASE);   //Worked But captured bit wrong 
//         // rData[i] = SPI_readDataBlockingFIFO(mySPIS_BASE);     //not wok for same in and same out.
//         // SCI_writeCharNonBlocking(mySCIA_BASE, rData[i]);
//     //     SCI_writeCharNonBlocking(mySCIA_BASE, (char)(rData[i] & 0xFF));

//     //     // DEVICE_DELAY_US(10);         // delay is must for reset the buffer and run the next input minimum 10us
//     // }
//     // DEVICE_DELAY_US(10);         // delay is must for reset the buffer and run the next input minimum 8us
//     // GPIO_writePin(cs1, 1);

//     Interrupt_clearACKGroup(INT_sw_XINT_INTERRUPT_ACK_GROUP);
//     // SysCtl_resetDevice();

// }



// __interrupt void INT_mySPIS_RX_ISR(void){
//     msg = "\r\n\n\nHello My World! Happy to see you.\0";
//     SCI_writeCharArray(mySCIA_BASE, (uint16_t*)msg, 38);
    
//     // int i = 0;
//     // for(i = 0; i < 16; i++){
//     //     // SPI_writDataNonBlocking(mySPIM_BASE, 0);
//     //     // DEVICE_DELAY_US(10)e;         // delay is must for reset the buffer and run the next input minimum 10us

//     //     // SPI_writeDataNonBlocking(mySPIS_BASE, 5);
//     //     // SPI_pollingFIFOTransaction(mySPIS_BASE, 16, (uint16_t*)tx , (uint16_t*)rx, 8, 10);       //Not workking 
//     //     // DEVICE_DELAY_US(10);         // delay is must for reset the buffer and run the next input minimum 10us
        
//     //     // rData[i] = SPI_readDataNonBlocking(mySPIS_BASE);   //Worked But captured bit wrong because doesn't wait fully and capture.
//     //     rData[i] = SPI_readDataBlockingFIFO(mySPIS_BASE);     //not wok for same in and same out.
//     //     // SCI_writeCharNonBlocking(mySCIA_BASE, rData[i]);
//     //     // DEVICE_DELAY_US(10);         // delay is must for reset the buffer and run the next input minimum 10us
//     // }
// }


// __interrupt void INT_mySPIS_TX_ISR(void){
//     msg = "\r\n\n\nHello My World! Happy to see you.\0";
//     SCI_writeCharArray(mySCIA_BASE, (uint16_t*)msg, 38);
// }

//
// End of File
//
