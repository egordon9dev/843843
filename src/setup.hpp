#ifndef SETUP_H
#define SETUP_H
#include "MotorSaver.hpp"
#include "main.h"
#include "pid.hpp"
#define TICKS_TO_DEG 0.4
extern pros::Motor mtr5, mtr6, mtr7, mtr8, mtr9, mtr10, mtr13, mtr12;
extern MotorSaver dlSaver, drSaver, drfbSaver, clawSaver, flySaver, intakeSaver;
extern pros::Controller ctlr;
extern pros::ADIPotentiometer* drfbPot;
extern pros::ADIPotentiometer* clawPot;
extern pros::ADILineSensor* ballSens;
extern const int drfbMinPos, drfbMaxPos, drfbPos0, drfbPos1, drfbPos2, drfbMinClaw, claw180, clawPos0, clawPos1, drfb18Max;
extern const int ctlrIdxLeft, ctlrIdxUp, ctlrIdxRight, ctlrIdxDown, ctlrIdxY, ctlrIdxX, ctlrIdxA, ctlrIdxB, ctlrIdxL1, ctlrIdxL2, ctlrIdxR1, ctlrIdxR2;
extern const int BIL, MIL;
extern const int dblClickTime;
extern const double PI;
extern const double ticksPerInch;
enum class IntakeState { ALL, FRONT, NONE };
int clamp(int n, int min, int max);
double clamp(double n, double min, double max);

//------- Misc ----------
// returns prevClicks, curClicks, DblClicks
bool** getAllClicks();
void printAllClicks(int line, bool** allClicks);
void printPidValues();
void stopMotors();
Point polarToRect(double mag, double angle);
int millis();

// -------- Drive --------
void setDR(int n);
void setDL(int n);
double getDR();
double getDL();
int getDLVoltage();
int getDRVoltage();
void printDrivePidValues();
void printDriveEncoders();
void runMotorTest();

//----------- Intake ------
void intakeNone();
void intakeFront();
void intakeAll();
void setIntake(IntakeState is);
int getBallSens();
bool isBallIn();

//----------- DRFB functions ---------
void setDrfb(int n);
void setDrfbParams(bool auton);
int getDrfb();
int getDrfbEncoder();
bool pidDrfb(double pos, int wait);
void pidDrfb();
//---------- Claw functions --------
void setClaw(int n);
double getClaw();
bool pidClaw(double a, int wait);
void pidClaw();
//--------- Flywheel functions --------
void setFlywheel(int n);
double getFlywheel();
bool pidFlywheel();
bool pidFlywheel(double speed);
bool pidFlywheel(double speed, int wait);
void setupAuton();
void setupOpCtrl();
#endif
