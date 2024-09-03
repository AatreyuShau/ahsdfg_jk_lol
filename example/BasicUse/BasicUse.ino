#include <OV7670Camera.h>

#define SDA_PIN 21
#define SCL_PIN 22

OV7670Camera camera(SDA_PIN, SCL_PIN);

void setup() {
    Serial.begin(115200);
    if (!camera.begin()) {
        Serial.println("Failed to initialize the camera.");
        while (true);
    }

    uint8_t imageBuffer[640 * 480]; // Adjust buffer size based on resolution

    if (camera.takePicture(imageBuffer, sizeof(imageBuffer))) {
        Serial.println("Picture taken successfully!");
        // Process the image data
    } else {
        Serial.println("Failed to take a picture.");
    }
}

void loop() {
    // Example of starting and stopping video recording
    camera.startVideoRecording();
    delay(5000); // Record for 5 seconds
    camera.stopVideoRecording();
}
