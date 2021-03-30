import math

A_min = 0
A_max = 4.9
B_min = 0
B_max = 9

def get_scale_a(X_b):
  return (X_b - B_min) * ((A_max - A_min) / (B_max - B_min)) + A_min

def get_scale_b(X_a):
  return (X_a - A_min) * ((B_max- B_min)/(A_max - A_min)) + B_min

print("Value frome scale A:")
x_a = float(input())

print(get_scale_b(x_a))
