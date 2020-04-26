#include <output/output_device.h>
#include <Servo.h>

class Servo: public OutputDevice {
private:
    uint8_t pin;
public:
    Servo(uint16_t device_id): OutputDevice(device_id){}
    bool init(uint8_t pin);
    uint16_t position(uint16_t position);
};

bool Servo::init(uint8_t pin){
    this->pin = pin;
    myservo.attach(this->pin);
}

uint16_t Servo::position(uint16_t position){
    uint16_t op_value = map(position, 0, 1023, 0, 180);
    myservo.write(val); 
    return op_value;
}

