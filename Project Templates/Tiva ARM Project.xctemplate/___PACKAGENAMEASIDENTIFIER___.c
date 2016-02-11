//
//  ___PACKAGENAME___
//  ___FILENAME___
//
//  Created by ___FULLUSERNAME___ on ___DATE___.
//___COPYRIGHT___
//
// Example to demonstrate minimal TivaWare setup
//

// ___FILEBASENAMEASIDENTIFIER___

#include "tm4c123gh6pm.h"
#include "driverlib/sysctl.h"

// Function Prototypes

void initPortF(void);
void waitForSwitchPressed(void);
void waitForSwitchReleased(void);
void setLedRed(void);
void unsetLedRed(void);
void setLedBlue(void);
void unsetLedBlue(void);
void toggleLedGreen(void);
void unsetLedGreen(void);

// Main Function: entry point of this project

int main(void)
{
    
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    
    initPortF();
    
    while(1) {
        waitForSwitchPressed();
        setLedBlue();
        waitForSwitchReleased();
        unsetLedBlue();
        waitForSwitchPressed();
        setLedRed();
        waitForSwitchReleased();
        unsetLedRed();
    }
    
}

// Function Definitions

void initPortF(void)
{
    SYSCTL_RCGC2_R |= 0x00000020;       // 1) F clock
    SysCtlDelay(10000);                 // delay to allow clock to stabilize
    GPIO_PORTF_AMSEL_R &= 0x00;         // 2) disable analog function
    GPIO_PORTF_PCTL_R &= 0x00000000;    // 3) GPIO clear bit PCTL
    GPIO_PORTF_DIR_R &= ~0x10;          // 4.1) PF4 input,
    GPIO_PORTF_DIR_R |= 0x0E;           // 4.2) PF3,2,1 output
    GPIO_PORTF_AFSEL_R &= 0x00;         // 5) no alternate function
    GPIO_PORTF_PUR_R |= 0x10;           // 6) enable pullup resistor on PF4
    GPIO_PORTF_DEN_R |= 0x1E;           // 7) enable digital pins PF4-PF1
    GPIO_PORTF_DATA_R &= ~0x1A;         // Clear PF1, PF3 and PF4
}

#define MAX_DELAY 25000

void waitForSwitchPressed(void)
{
    int delay = MAX_DELAY;
    while (GPIO_PORTF_DATA_R & 0x10) {
        if (delay == MAX_DELAY) {
            toggleLedGreen();
        }
        SysCtlDelay(50);
        --delay;
        if (delay == 0) {
            delay = MAX_DELAY;
        }
    }
    unsetLedGreen();
}

void waitForSwitchReleased(void)
{
    while (!(GPIO_PORTF_DATA_R & 0x10)) {
    }
}

void setLedRed(void)
{
    GPIO_PORTF_DATA_R |= 0x02;
}

void unsetLedRed(void)
{
    GPIO_PORTF_DATA_R &= ~0x02;
}

void setLedBlue(void)
{
    GPIO_PORTF_DATA_R |= 0x04;
}

void unsetLedBlue(void)
{
    GPIO_PORTF_DATA_R &= ~0x04;
}

void unsetLedGreen(void)
{
    GPIO_PORTF_DATA_R &= ~0x08;
}

void toggleLedGreen(void)
{
    GPIO_PORTF_DATA_R ^= 0x08;
}
