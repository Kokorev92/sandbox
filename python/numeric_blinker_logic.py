import matplotlib.pyplot as plt

time = [i for i in range(0, 5000)]
volt = []

i = 0
n = 3
period = 500
while i < len(time):
    current = i // period
    if (current < n*2) and (current % 2 == 0):
        volt.append(1)
    else:
        volt.append(0)
    i += 1

fig, ax = plt.subplots()
ax.set_title('Логика мигания светодиода')
ax.set_xlabel('Time (ms)')
ax.plot(time, volt)
plt.show()
