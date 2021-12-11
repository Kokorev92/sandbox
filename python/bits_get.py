#!/usr/bin/python3

import sys

if len(sys.argv) > 1:
    bits = sys.argv[1]
else:
    sys.exit(-1)

try:
    num = int(bits)
except:
    print('Please enter an integer')
    sys.exit(-1)

bits_count = len(bin(num)) - 2

i = 0
while i < bits_count:
    print("Bit " + str(i) + ": " + str(bool(num & (1 << i))))
    i += 1
