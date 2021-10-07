import csv
import matplotlib.pyplot as plt
import datetime as dt

FILE = "log.csv"

time = []
humidity = []
temperature = []
light = []

with open(FILE, "r") as file:
    data = csv.reader(file)
    for row in data:
        time.append(row[0])
        humidity.append(row[2])
        temperature.append(row[1])
        light.append(row[3])

time = [dt.datetime.strptime(i, "%H:%M:%S") for i in time]

fig, ax = plt.subplots()
ax.plot(time, humidity)
ax.plot(time, temperature)
ax.plot(time, light)
plt.show()
