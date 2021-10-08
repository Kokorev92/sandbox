import csv
import matplotlib.pyplot as plt
import datetime as dt

FILE = "log.csv"

time = []
humidity = []
temperature = []
light = []

# Считываем все значения в соответствующие списки
# Списки будут иметь тип string, после мы преобразуем их в int
with open(FILE, "r") as file:
    data = csv.reader(file)
    for row in data:
        time.append(row[0])
        temperature.append(row[1])
        humidity.append(row[2])
        light.append(row[3])

# Преобразуем все списки в int
humidity = list(map(int, humidity))
temperature = list(map(int, temperature))
light = list(map(int, light))

# Преобразуем время к типу datetime
time = [dt.datetime.strptime(i, "%H:%M:%S") for i in time]

fig, ax = plt.subplots()
ax.set_title('Bathroom telemetry')
ax.set_xlabel('Time(H:M:S)')
ax.plot(time, light, label='Light')
ax.plot(time, temperature, label='Temperature (C)')
ax.plot(time, humidity, label='Humidity (%)')
ax.legend()
plt.show()