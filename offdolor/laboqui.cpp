#include <MPU6050.h>

MPU6050 mpu;

void setup() {
    Serial.begin(115200);
    Wire.begin();
    mpu.initialize();

    // Check if the MPU6050 is connected correctly
    if (!mpu.testConnection()) {
        Serial.println("MPU6050 connection failed!");
        while (1);  // Halt execution if sensor is not connected
    }

    // Calculate and set offsets
    mpu.calcOffsets(); // This function should internally calculate the offsets for gyro and accel
    Serial.println("Offsets calculated.");
}

void loop() {
    // Your main code here, where you can use calibrated sensor readings
    int16_t ax, ay, az;
    int16_t gx, gy, gz;
    
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    
    // Use the sensor readings
    Serial.print("a/g:\t");
    Serial.print(ax); Serial.print("\t");
    Serial.print(ay); Serial.print("\t");
    Serial.print(az); Serial.print("\t");
    Serial.print(gx); Serial.print("\t");
    Serial.print(gy); Serial.print("\t");
    Serial.println(gz);

    delay(100); // Add a delay to avoid flooding the serial output
}
