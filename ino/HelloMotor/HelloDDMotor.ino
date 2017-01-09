/**
 * This program is an example of standalone use of an Arduino device driver
 * from the Luni library.  Compiled and loaded onto an Arduino, it initializes,
 * then briefly demonstrates some typical device driver calls.  In this case,
 * the DC motor device driver DDMotor is the target device.
 */

#include <LuniLib.h>

// Device Driver selection

#include <DDMotor/DDMotor.h>

DeviceDriver *selectedDevices[] = {
  new DDMotor("DCM",1),
  0};

// --------------------------------------------------------

void setup() {
  Serial.begin(115200);
  tst->countDown(5);
  tst->runSelected();
}

void loop() {
    tst->dispatchTimers();
}
