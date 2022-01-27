#include "gpio.h"
#include <lgpio.h>

Gpio::Gpio(QObject *parent) : QObject(parent)
{
    m_handle = lgGpiochipOpen(0);
    int initial_state = 0;
    for(int pin : LEDS)
        lgGpioClaimOutput(m_handle, LFLAGS, pin, initial_state); // anfangszustand der LEDS festlegen
}

Gpio::~Gpio()
{
    int state = 0;
    for(int pin : LEDS)
        lgGpioWrite(m_handle, pin, state); // LEDS ausschalten (Destructor)
    lgGpiochipClose(m_handle);
}

void Gpio::set(int pin,bool value)
{
    lgGpioWrite(m_handle, pin, value); // Blinklicht
}

void Gpio::set(unsigned int pattern)    //Lauflicht
{
    int n = 0;
    bool value;
    unsigned int check = 0b0001;
    for(auto pin : LEDS)
    {
        value = check & pattern>>n;
        lgGpioWrite(m_handle, pin, value);
        n++;
    }
}
