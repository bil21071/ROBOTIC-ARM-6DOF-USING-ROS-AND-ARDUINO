#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create the PCA9685 driver object
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Define servo properties
#define SERVOMIN  122 // Minimum pulse length out of 4096 (adjust if needed)
#define SERVOMAX  487 // Maximum pulse length out of 4096 (adjust if needed)
#define SERVO_CHANNEL 1 // The channel where the servo is connected

void setup() {
  Serial.begin(9600);
  Serial.println("PCA9685 Servo Driver Test");

  // Initialize the PCA9685 driver
  pwm.begin();
  
  // Set the PWM frequency to 60 Hz
  pwm.setPWMFreq(60);  
  delay(10);  // Give some time for the PCA9685 to initialize
}

void loop() {
  // Sweep the servo from minimum to maximum
  for (uint16_t pulseLength = SERVOMIN; pulseLength <= SERVOMAX; pulseLength++) {
    pwm.setPWM(SERVO_CHANNEL, 1, pulseLength);  // Set PWM on the specified channel
    delay(10); // Adjust the delay for smoother movement
  }

  // Optional: Pause in the middle for a smooth transition
  delay(500);
  
  // Sweep the servo from maximum to minimum
  for (uint16_t pulseLength = SERVOMAX; pulseLength >= SERVOMIN; pulseLength--) {
    pwm.setPWM(SERVO_CHANNEL, 1, pulseLength);  // Set PWM on the specified channel
    delay(10); // Adjust the delay for smoother movement
  }
  
  // Optional: Pause in the middle for a smooth transition
  delay(500);
}