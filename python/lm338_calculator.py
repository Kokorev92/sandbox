import matplotlib
import matplotlib.pyplot as plt

R1 = 240
R2 = range(0, 2500, 1)

Vo = []

for r2 in R2:
    Vo.append(1.25 * (1 + r2 / R1))

plt.plot(Vo, R2)
plt.show()
