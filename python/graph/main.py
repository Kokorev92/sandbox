import csv
import matplotlib.pyplot as plt
import datetime as dt

FILE = "log.csv"

time = []
humidity = []
temperature = []

with open(FILE, "r") as file:
    data = csv.reader(file)
    for row in data:
        time.append(row[0])
        humidity.append(row[2])
        temperature.append(row[1]) 

time = [dt.datetime.strptime(i, "%H:%M:%S") for i in time]

plt.plot(time, humidity, time,  temperature)
plt.show()
