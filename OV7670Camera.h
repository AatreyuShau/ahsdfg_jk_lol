#ifndef OV7670CAMERA_H
#define OV7670CAMERA_H

#include <Arduino.h>
#include <Wire.h>

class OV7670Camera {
public:
    OV7670Camera(int sdaPin, int sclPin);
    
    bool begin();
    bool takePicture(uint8_t* imageBuffer, size_t bufferSize);
    bool startVideoRecording();
    bool stopVideoRecording();
    bool captureFrame(uint8_t* frameBuffer, size_t bufferSize);
    void setResolution(int width, int height);
    void setBrightness(int brightness);
    void setContrast(int contrast);

private:
    int _sdaPin;
    int _sclPin;
    int _width;
    int _height;
    int _brightness;
    int _contrast;
    
    void initCamera();
    bool writeRegister(uint8_t reg, uint8_t value);
    bool readRegister(uint8_t reg, uint8_t* value);
};

#endif // OV7670CAMERA_H
