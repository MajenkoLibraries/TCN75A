#include <TCN75A.h>

void TCN75A::begin() {
    Wire.begin();
    writeRegister(1, 0b01100000);
}

void TCN75A::begin(uint8_t addr) {
    _i2caddr = addr;
    Wire.begin();
    writeRegister(1, 0b01100000);
}

void TCN75A::writeRegister(uint8_t reg, uint8_t val) {
    Wire.beginTransmission(_i2caddr);
    Wire.write(reg);
    Wire.write(val);
    Wire.endTransmission();
}

uint16_t TCN75A::readRegister(uint8_t reg) {
    Wire.beginTransmission(_i2caddr);
    Wire.write(reg);
    Wire.endTransmission(false);
    Wire.requestFrom(_i2caddr, (uint8_t)2);
    uint8_t msb = Wire.read();
    uint8_t lsb = Wire.read();
    return (msb << 8) | lsb;
}

float TCN75A::readTemperature() {
    writeRegister(1, 0b11100001);
    uint8_t status = readRegister(1);
    while (status & 0b10000000) {
        status = readRegister(1);
    }

    int16_t rval = readRegister(0);
    rval /= 16;
    return (float)rval / 16.0;
}
