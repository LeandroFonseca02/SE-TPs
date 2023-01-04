#!/usr/bin/env python3
########################################################################
# Filename    : UltrasonicRanging.py
# Description : Get distance via UltrasonicRanging sensor
# auther      : www.freenove.com
# modification: 2019/12/28
########################################################################
import RPi.GPIO as GPIO
import time

trigPin = 23
echoPin = 24
ledPin = 17
buzzerPin = 27
MAX_DISTANCE = 220  # define the maximum measuring distance, unit: cm
timeOut = MAX_DISTANCE * 60  # calculate timeout according to the maximum measuring distance


def pulseIn(pin, level, timeOut):  # obtain pulse time of a pin under timeOut
    t0 = time.time()
    while (GPIO.input(pin) != level):
        if ((time.time() - t0) > timeOut * 0.000001):
            return 0;
    t0 = time.time()
    while (GPIO.input(pin) == level):
        if ((time.time() - t0) > timeOut * 0.000001):
            return 0;
    pulseTime = (time.time() - t0) * 1000000
    return pulseTime


def getSonar():  # get the measurement results of ultrasonic module,with unit: cm
    GPIO.output(trigPin, GPIO.HIGH)  # make trigPin output 10us HIGH level
    time.sleep(0.00001)  # 10us
    GPIO.output(trigPin, GPIO.LOW)  # make trigPin output LOW level
    pingTime = pulseIn(echoPin, GPIO.HIGH, timeOut)  # read plus time of echoPin
    distance = pingTime * 340.0 / 2.0 / 10000.0  # calculate distance with sound speed 340m/s
    return distance


def setup():
    GPIO.setmode(GPIO.BCM)  # use PHYSICAL GPIO Numbering
    GPIO.setup(trigPin, GPIO.OUT)  # set trigPin to OUTPUT mode
    GPIO.setup(echoPin, GPIO.IN)  # set echoPin to INPUT mode
    GPIO.setup(ledPin, GPIO.OUT)
    GPIO.setup(buzzerPin, GPIO.OUT)
    GPIO.output(buzzerPin, GPIO.LOW)
    GPIO.output(ledPin, GPIO.LOW)

def activateBuzzer(delay, delay2):
    GPIO.output(buzzerPin, GPIO.HIGH)
    GPIO.output(ledPin, GPIO.HIGH)
    time.sleep(delay)
    GPIO.output(buzzerPin, GPIO.LOW)
    GPIO.output(ledPin, GPIO.LOW)
    time.sleep(delay2)

def sensorDistance(distance):
    if distance < 30 and distance >= 20:
        activateBuzzer(0.25,0.25)
    elif distance < 20 and distance >= 10:
        activateBuzzer(0.12,0.12)
    elif distance < 10 and distance > 5:
        activateBuzzer(0.05,0.05)
    elif distance < 5:
        activateBuzzer(1,0)
        GPIO.output(buzzerPin, GPIO.LOW)
        GPIO.output(ledPin, GPIO.LOW)

def loop():
    while (True):
        distance = getSonar()  # get distance
        print("The distance is : %.2f cm" % (distance))
        sensorDistance(distance)


if __name__ == '__main__':  # Program entrance
    print('Program is starting...')
    setup()
    try:
        loop()
    except KeyboardInterrupt:  # Press ctrl-c to end the program.
        GPIO.cleanup()  # release GPIO resource
