#!/usr/bin/python3

import sys
from prettytable import PrettyTable

if len(sys.argv) > 1:
    try:
        num = int(sys.argv[1])
    except:
        print('Please enter an integer')
        sys.exit(-1)
else:
    sys.exit(-1)

output_table = PrettyTable()
output_table.add_column("Bit", ["State"])

bits_count = len(bin(num)) - 2

for i in reversed(range(bits_count)):
    output_table.add_column(str(i), [str(1 if bool(num & (1 << i)) else 0)])

print(output_table)
