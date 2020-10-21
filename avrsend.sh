#!/usr/bin/env bash
MCU=atmega32u4
BUILD_DIR=.
TARGET=handwired_dactyl_manuform_5x6_joserc87

ls /dev/tty* > /tmp/1;
echo "Reset your Pro Micro now";
while [[ -z $USB ]]; do
  sleep 1;
  ls /dev/tty* > /tmp/2;
  USB=`diff /tmp/1 /tmp/2 | grep -o '/dev/tty.*'`;
done;
echo "The devide is in $USB"
sleep 2;
echo avrdude -p $MCU -c avr109 -P $USB -U flash:w:$BUILD_DIR/$TARGET.hex
avrdude -p $MCU -c avr109 -P $USB -U flash:w:$BUILD_DIR/$TARGET.hex
