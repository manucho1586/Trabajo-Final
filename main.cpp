//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "display.h"

static void userInterfaceDisplayInit();

int main()
{
    userInterfaceDisplayInit();
    while(true)
    {

    }
}

static void userInterfaceDisplayInit()
{
    displayInit( DISPLAY_TYPE_LCD_HD44780, DISPLAY_CONNECTION_I2C_PCF8574_IO_EXPANDER);
    //displayModeWrite( DISPLAY_MODE_CHAR );
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "Temperature:" );

    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "Gas:" );
    
    displayCharPositionWrite ( 0,2 );
    displayStringWrite( "Alarm:" );
}
