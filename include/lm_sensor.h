#include <input_device.h>
#include <Arduino.h>

class LmSensor: public InputDevice {
private:
    uint8_t pin;
public:
    LmSensor(uint16_t device_id, uint16_t threshold, long sample_time): InputDevice(device_id, threshold, sample_rate) {};
    bool init(uint8_t pin);
    uint16_t read();
};

bool LmSensor::init(uint8_t pin){
    this->pin = pin;
}

uint16_t LmSensor::read(){
    float tempC;
    tempC= analogRead(this->pin);
    tempC = (5.0 * tempC * 100.0)/1024.0; 
 
    return(tempC);
}