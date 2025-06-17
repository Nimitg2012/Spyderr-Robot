#include <Servo.h>

// Servos
Servo lf_femur, lf_tibia; // Left Front
Servo rf_femur, rf_tibia; // Right Front
Servo lb_femur, lb_tibia; // Left Back
Servo rb_femur, rb_tibia; // Right Back

// Calibrated angles
int lf_femur_neutral = 90;
int lf_tibia_ground = 105;

int rf_femur_neutral = 90;
int rf_tibia_ground = 95;

int lb_femur_neutral = 90;
int lb_tibia_ground = 110;

int rb_femur_neutral = 90;
int rb_tibia_ground = 100;

void centerLegs() {
  lf_femur.write(lf_femur_neutral);
  lf_tibia.write(lf_tibia_ground);

  rf_femur.write(rf_femur_neutral);
  rf_tibia.write(rf_tibia_ground);

  lb_femur.write(lb_femur_neutral);
  lb_tibia.write(lb_tibia_ground);

  rb_femur.write(rb_femur_neutral);
  rb_tibia.write(rb_tibia_ground);

  delay(500);
}

void liftLeg(Servo &tibia) {
  tibia.write(60);  // Lift tibia up (adjust 60 if needed)
  delay(300);
}

void lowerLeg(Servo &tibia, int groundAngle) {
  tibia.write(groundAngle);
  delay(300);
}

void moveFemur(Servo &femur, int angle) {
  femur.write(angle);
  delay(300);
}

void walkForward() {
  centerLegs();

  // Step 1: Lift left front leg and move forward
  liftLeg(lf_tibia);
  moveFemur(lf_femur, lf_femur_neutral - 30); // Move femur forward
  lowerLeg(lf_tibia, lf_tibia_ground);

  // Step 2: Lift right back leg and move forward
  liftLeg(rb_tibia);
  moveFemur(rb_femur, rb_femur_neutral - 30);
  lowerLeg(rb_tibia, rb_tibia_ground);

  // Step 3: Lift right front leg and move forward
  liftLeg(rf_tibia);
  moveFemur(rf_femur, rf_femur_neutral - 30);
  lowerLeg(rf_tibia, rf_tibia_ground);

  // Step 4: Lift left back leg and move forward
  liftLeg(lb_tibia);
  moveFemur(lb_femur, lb_femur_neutral - 30);
  lowerLeg(lb_tibia, lb_tibia_ground);

  centerLegs();
}

void rippleWalk() {
  centerLegs();

  // Lift and lower legs one by one for ripple effect
  liftLeg(lf_tibia);
  lowerLeg(lf_tibia, lf_tibia_ground);

  liftLeg(rf_tibia);
  lowerLeg(rf_tibia, rf_tibia_ground);

  liftLeg(lb_tibia);
  lowerLeg(lb_tibia, lb_tibia_ground);

  liftLeg(rb_tibia);
  lowerLeg(rb_tibia, rb_tibia_ground);

  centerLegs();
}

void turnLeft() {
  centerLegs();

  moveFemur(rf_femur, rf_femur_neutral - 30);
  moveFemur(lf_femur, lf_femur_neutral + 30);

  delay(500);

  centerLegs();
}

void dance() {
  centerLegs();

  for (int i = 0; i < 3; i++) {
    moveFemur(lf_femur, lf_femur_neutral - 30);
    moveFemur(rf_femur, rf_femur_neutral + 30);
    moveFemur(lb_femur, lb_femur_neutral - 30);
    moveFemur(rb_femur, rb_femur_neutral + 30);
    delay(300);

    centerLegs();
    delay(300);
  }
}

void setup() {
  Serial.begin(9600);

  lf_femur.attach(16); // D0
  lf_tibia.attach(2);  // D4

  rf_femur.attach(5);  // D1
  rf_tibia.attach(14); // D5

  lb_femur.attach(4);  // D2
  lb_tibia.attach(12); // D6

  rb_femur.attach(0);  // D3
  rb_tibia.attach(13); // D7

  centerLegs();

  Serial.println("Spider bot ready. Commands: walk, ripple, left, dance, test");
}

void loop() {
  if (Serial.available() > 0) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "walk") {
      walkForward();
    } else if (cmd == "ripple") {
      rippleWalk();
    } else if (cmd == "left") {
      turnLeft();
    } else if (cmd == "dance") {
      dance();
    } else if (cmd == "test") {
      centerLegs();
      Serial.println("Centered legs for calibration.");
    } else {
      Serial.println("Unknown command.");
    }
    centerLegs();
  }
}
