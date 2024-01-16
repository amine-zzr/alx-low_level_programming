#!/bin/bash
wget -P .. https://raw.githubusercontent.com/amine-zzr/alx-low_level_programming/master/0x18-dynamic_libraries/libinject.so
export LD_PRELOAD="../libinject.so"
