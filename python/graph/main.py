import csv
import matplotlib.pyplot as plt
import matplotlib.dates as mdates
import datetime as dt

FILE = "log.csv"

time = []
humidity = []
temperature = []
light = []


# Функция для преобразования значения освещения
def light_status(current_light):
    if current_light > 200:
        return 1
    else:
        return 0


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

# Преобразуем АЦП значения освещения к двум состояниям: 1 - вкл. 0 - выкл.
light = list(map(light_status, light))

# Преобразуем время к типу datetime
time = [dt.datetime.strptime(i, "%H:%M:%S") for i in time]

fig, ax = plt.subplots()
ax.set_title('Bathroom telemetry')  # Заголовок графика
ax.set_xlabel('Time(H:M:S)')  # Подпись оси X
ax.xaxis.set_major_formatter(mdates.DateFormatter("%H:%M:%S"))  # Формат подписи меток времени по оси X

ax.plot(time, light, label='Light (on/off)', color='red')
ax.plot(time, temperature, label='Temperature (C)')
ax.plot(time, humidity, label='Humidity (%)')
ax.legend()  # Отображение легенды
plt.show()
