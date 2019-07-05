# Embedded Integer Math Benchmark

[![Build Status](https://travis-ci.org/VioletGiraffe/Integer-Benchmark-Embedded.svg?branch=master)](https://travis-ci.org/VioletGiraffe/Integer-Benchmark-Embedded)

A real-life benchmark for embedded systems (Arduino, ESP32 et. al.). Calculates N first prime numbers using simple brute force looping (no lookup tables) and measures calculation time.

This is a project for platformIO.

Tested on (with the compiler options as specified in platformio.ini - C++17, -O3). N = 2500:

* Arduino Due @ 84 MHz - 57 ms
* Espressif ESP32 @ 160 MHz - 24 ms
* Arduino Uno R3 @ 16 MHz - 6886 ms