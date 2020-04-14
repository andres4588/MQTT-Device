
class LmSensor: public InputDevice {
private:
    uint8_t pin;
public:
    IrSensor(uint16_t device_id, uint16_t threshold, long sample_time): InputDevice(device_id, threshold, sample_rate) {};
    bool init(uint8_t pin);
    uint16_t read();
};

bool LmSensor::init(uint8_t pin){
    this->pin = pin;
    this->read_timer = millis();
}

uint16_t DhSensor::read(){
    return AnalogRead(this->pin);
}