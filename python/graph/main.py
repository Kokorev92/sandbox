import csv
import matplotlib.pyplot as plt
import matplotlib.dates as mdates
import datetime as dt
import argparse, sys

time = []
humidity = []
temperature = []
light = []

parser = argparse.ArgumentParser()
parser.add_argument('-f', '--file')

arguments = parser.parse_args(sys.argv[1:])
if arguments.file is None:
    print("No file path!")
    exit(-1)


# Функция для преобразования значения освещения
def light_status(current_light):
    current_light = int(current_light)
    if current_light > 200:
        return 1
    else:
        return 0


# Считываем все значения в соответствующие списки
# Списки будут иметь тип string, после мы преобразуем их в int
with open(arguments.file, "r") as file:
    data = csv.reader(file)
    for row in data:
        time.append(row[0])
        temperature.append(row[1])
        humidity.append(row[2])
        light.append(row[3])

# Преобразуем температуру и влажность в int
humidity = list(map(int, humidity))
temperature = list(map(int, temperature))

# Преобразуем АЦП значения освещения к двум состояниям: 1 - вкл. 0 - выкл.
light = list(map(light_status, light))

# Преобразуем время к типу datetime
time = [dt.datetime.strptime(i, "%H:%M:%S") for i in time]

fig, ax = plt.subplots()
ax.set_title('Bathroom telemetry')  # Заголовок графика
ax.set_xlabel('Time(H:M:S)')  # Подпись оси X
ax.xaxis.set_major_formatter(mdates.DateFormatter("%H:%M:%S"))  # Формат подписи меток времени по оси X

ax.plot(time, light, label='Light (on/off)', color='green')
ax.plot(time, temperature, label='Temperature (C)')
ax.plot(time, humidity, label='Humidity (%)')
ax.legend()  # Отображение легенды

peaks = []
i = 0
while i < len(light) - 1:
    if light[i] != light[i + 1]:
        peaks.append(i)
    i += 1

if light[0] == 1:
    peaks.insert(0, 0)
if light[len(light) - 1] == 1:
    peaks.append(len(light) - 1)

i = 0
while i < len(peaks):
    ax.axvspan(time[peaks[i]], time[peaks[i + 1]], color='red', alpha=0.2)
    i += 2

plt.show()
