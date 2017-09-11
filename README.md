# affinity [![Build Status](https://travis-ci.org/ckilimci/affinity.svg?branch=master)](https://travis-ci.org/ckilimci/affinity)

Set the affinity of the process thread to a specific CPU core

To Compile:
```sh
gcc -Wall affinity-cmd.c -o affinity-cmd
gcc -Wall affinity-fork.c -o affinity-fork
```

This package may need to install **build-essential** and **kernel-headers**. Additionally, **raspberrypi-kernel-headers** for Raspberry Pi.
