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
// #include <cstdint>


uint16_t delayCount;            // Number (0-9) to scale the LED frequency

//
// Function Prototypes
//
__interrupt void INT_sw_XINT_ISR(void);
__interrupt void INT_mySCIA_RX_ISR(void);
__interrupt void INT_mySPIS_RX_ISR(void);

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
// uint16_t sData[] = {1,2,3,4,5,6,7,8,9,0};                  // Send data. 
uint16_t sData[] = {255,254,253,252,251,250,240,230,220,600};                  // Send data. 
// uint8_t sData = 9;                  // Send data. 
uint8_t s = 7;                  // Send data. 
// uint8_t rData;                  // Send data. 
uint8_t rData[10];                  // Send data. 
// uint8_t r;                  // Send data. 

int len = sizeof(sData);
char rxData[10] = "Done.....";
// char rData[];
char *tx;
char *rx;

int m = 1;



//
// Main
//
void main(void)
{
    //
    // CPU Initialization
    //
    Device_init();
    Interrupt_initModule();
    Interrupt_initVectorTable();

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


    SPI_resetRxFIFO(mySPIS_BASE);
    SPI_resetTxFIFO(mySPIS_BASE);

    //
    // Send starting message.
    //
    msg = "\r\n\n\nHello My World! Happy to see you.\0";
    SCI_writeCharArray(mySCIA_BASE, (uint16_t*)msg, 38);


    for(;;)
        {
            SPI_reset(mySPIS_BASE);
            SCI_enableInterrupt(mySCIA_BASE, SCI_INT_RXRDY_BRKDT);
            msg = "\r\n1\0";
            DEVICE_DELAY_US(500000);
            SCI_writeCharArray(mySCIA_BASE, (uint16_t*)msg, 4);

            // SCI_enableInterrupt(mySCIA_BASE, SCI_INT_RXFF);

            // int cs = GPIO_readPin(27);
            // int i = 0;
            // SPI_writeDataNonBlocking(mySPIM_BASE, sData[i]);

            // int i = 0;
            // for (i = 0; i < len; i++) {
            //     SPI_writeDataNonBlocking(mySPIM_BASE, sData[i]);
            //     SPI_writeDataNonBlocking(mySPIS_BASE, s);
            //     DEVICE_DELAY_US(10); // delay is must for reset the buffer and run
            //                         // the next input minimum 10us

            //     // rData[i] = SPI_readDataNonBlocking(mySPIS_BASE);   //Worked But
            //     // captured bit wrong
            //     rData = SPI_readDataBlockingFIFO(mySPIS_BASE); // not wok for same in and same out.
            //     SCI_writeCharNonBlocking(mySCIA_BASE, rData);
            //     // SCI_writeCharNonBlocking(mySCIA_BASE, (char)(rData[i] & 0xFF));

            //     DEVICE_DELAY_US(10); // delay is must for reset the buffer and run
            //                        // the next input minimum 10us
            // }

            rxStatus = SCI_getRxStatus(mySCIA_BASE);
            if((rxStatus & SCI_RXSTATUS_ERROR) != 0)
            {
                //
                // If Execution stops here there is some error
                // Analyze SCI_getRxStatus() API return value
                //
                ESTOP0;
            }
            
        }
}


__interrupt void INT_mySCIA_RX_ISR(void){
    msg = "\r\nInterrupt Happened.\0";
    SCI_writeCharArray(mySCIA_BASE, (uint16_t*)msg, 21);
    int x = 1;
    while (x < 4){
        msg = "\r\nHi\0";
        SCI_writeCharArray(mySCIA_BASE, (uint16_t*)msg, 5);
        DEVICE_DELAY_US(500000);
        x++;
    }

    int i;
    for(i = 0; i < 30; i++){
        GPIO_writePin(led, 1);
        // char x = rData[i];
        SCI_writeCharBlockingFIFO(mySCIA_BASE, rData[i]);
        DEVICE_DELAY_US(10000);
    }

    GPIO_writePin(led, 0);

    // SCI_clearInterruptStatus(mySCIA_BASE,1);

    SCI_resetRxFIFO(mySCIA_BASE);

    DEVICE_DELAY_US(100000);
    Interrupt_clearACKGroup(INT_mySCIA_RX_INTERRUPT_ACK_GROUP);
}



__interrupt void INT_sw_XINT_ISR(void){
    int x = 0;
    while (x < 6){
        GPIO_writePin(led, 1);
        DEVICE_DELAY_US(100000);
        GPIO_writePin(led, 0);
        DEVICE_DELAY_US(100000);
        x++;
    }
    // DEVICE_DELAY_US(1000000);


    // SPI_writeDataNonBlocking(mySPIM_BASE, sData);
    // SPI_writeDataNonBlocking(mySPIS_BASE, s);
    // rData = SPI_readDataBlockingFIFO(mySPIS_BASE);
    // SCI_writeCharNonBlocking(mySCIA_BASE, rData);

    // char data = rData;
    // SCI_writeCharNonBlocking(mySCIA_BASE, data);

    // GPIO_writePin(cs1, 0);
    // DEVICE_DELAY_US(10);         // delay is must for reset the buffer and run the next input minimum 10us
    int i = 0;
    for(i = 0; i < len; i++){
        // SPI_writeDataNonBlocking(mySPIM_BASE, sData[i]);
        SPI_writeDataNonBlocking(mySPIS_BASE, s);
        DEVICE_DELAY_US(10);         // delay is must for reset the buffer and run the next input minimum 10us

        // rData[i] = SPI_readDataNonBlocking(mySPIS_BASE);   //Worked But captured bit wrong 
        rData[i] = SPI_readDataBlockingFIFO(mySPIS_BASE);     //not wok for same in and same out.
        SCI_writeCharNonBlocking(mySCIA_BASE, rData[i]);
        // SCI_writeCharNonBlocking(mySCIA_BASE, (char)(rData[i] & 0xFF));

        DEVICE_DELAY_US(10);         // delay is must for reset the buffer and run the next input minimum 10us
    }
    // DEVICE_DELAY_US(10);         // delay is must for reset the buffer and run the next input minimum 8us
    // GPIO_writePin(cs1, 1);

    Interrupt_clearACKGroup(INT_sw_XINT_INTERRUPT_ACK_GROUP);
    // SysCtl_resetDevice();

}


// interrupt happen as we are using c2000 as slave
// SO we can have a functions here to run 
__interrupt void INT_mySPIS_RX_ISR(void){
    // msg = "\r\nS_RX\0";
    // SCI_writeCharArray(mySCIA_BASE, (uint16_t*)msg, 6);

    
    // uint8_t r[30] = {0};
    m++;
    // SCI_writeCharBlockingFIFO(mySCIA_BASE, m);
    int i;
    // SPI_resetRxFIFO(mySPIS_BASE);

    for (i = 0; i < 10; ++i) {
        // SPI_writeDataNonBlocking(mySPIM_BASE, sData[i]);
        // SPI_writeDataNonBlocking(mySPIS_BASE, rxData[i]);
        // SPI_writeDataBlockingFIFO(mySPIS_BASE, rxData[i]);
        // SPI_writeDataNonBlocking(mySPIS_BASE, s);
        // DEVICE_DELAY_US(10); // delay is must for reset the buffer and run
                            // the next input minimum 10us

        // rData[i] = SPI_readDataNonBlocking(mySPIS_BASE);   //Worked But captured bit wrong
        SPI_writeDataBlockingFIFO(mySPIS_BASE, m);
        // DEVICE_DELAY_US(2); // delay is must for reset the buffer and run
        rData[i] = SPI_readDataBlockingFIFO(mySPIS_BASE); // not wok for same in and same out.

        // r[i] = SPI_readDataBlockingFIFO(mySPIS_BASE); // not wok for same in and same out.
        // rData[i] = r[i];
        DEVICE_DELAY_US(10); // delay is must for reset the buffer and run
        // SCI_writeCharNonBlocking(mySCIA_BASE, rData[i]);
        // SCI_writeCharNonBlocking(mySCIA_BASE, (char)(rData[i] & 0xFF));

        // DEVICE_DELAY_US(10); // delay is must for reset the buffer and run the next input minimum 10us
    }



    SCI_writeCharNonBlocking(mySCIA_BASE, 'r');
    
    SPI_clearInterruptStatus(mySPIS_BASE, SPI_INT_RXFF);
    SPI_resetTxFIFO(mySPIS_BASE);
    SPI_resetRxFIFO(mySPIS_BASE);
    Interrupt_clearACKGroup(INT_mySPIS_RX_INTERRUPT_ACK_GROUP);
}


__interrupt void INT_mySPIS_TX_ISR(void){
    msg = "\r\nS_TX\0";
    SCI_writeCharArray(mySCIA_BASE, (uint16_t*)msg, 7);


    SPI_resetTxFIFO(mySPIS_BASE);
    Interrupt_clearACKGroup(INT_mySPIS_TX_INTERRUPT_ACK_GROUP);
}

//
