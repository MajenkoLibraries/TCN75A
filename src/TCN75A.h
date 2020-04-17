#ifndef _TCN75A_H
#define _TCN75A_H

#include <Arduino.h>
#include <Wire.h>

#define TCN75A_ADDRESS 0x48

class TCN75A {
    private:
        uint8_t _i2caddr;

    public:
        TCN75A() : _i2caddr(TCN75A_ADDRESS) {}
        TCN75A(uint8_t addr) : _i2caddr(addr) {}

        void begin();
        void begin(uint8_t addr);
        void writeRegister(uint8_t reg, uint8_t val);
        uint16_t readRegister(uint8_t reg);
        float readTemperature();
};

#endif
