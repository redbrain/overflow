# Overflow [![Build Status](https://travis-ci.org/redbrain/overflow.svg?branch=master)](https://travis-ci.org/redbrain/overflow)

Overflow is a framework for the RTSP RTP protocol.

## C/C++ Build

To compile native libraries:

```bash
$ mkdir build
$ cd build
$ cmake -DTESTS=ON ../
$ make
```

## Android Build

To compile android lib:

```bash
$ cd android/overflow
$ ./gradlew clean build
```

## TODO

* iOS build - Podfile/Carthage
* iOS Decoders - H264/MJPEG/MPEG4
* Android decoders
* Cleanup code
* PIMPL Pattern implement
* More unit-tests
* Test reconnection does libuv do this?
* RTSP->RTMP
* Python Bindings
