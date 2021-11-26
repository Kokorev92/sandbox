import matplotlib.pyplot as plt
from matplotlib.widgets import Button
import pylab

time = [i for i in range(0, 5000)]
volt = []

i = 0
n = 3
period = 500


def update_graph():
    global time
    global volt
    global i
    global n
    global period
    volt.clear()
    while i < len(time):
        current = i // period
        if (current < n*2) and (current % 2 == 0):
            volt.append(1)
        else:
            volt.append(0)
        i += 1
    ax.clear()
    ax.set_title('Логика мигания светодиода' + ' N=' + str(n))
    ax.set_xlabel('Time (ms)')
    ax.plot(time, volt)
    plt.draw()


def add_clicked(event):
    global n
    global i
    i = 0
    if n >= 5:
        n = 5
    else:
        n += 1
    update_graph()


def del_clicked(event):
    global n
    global i
    i = 0
    if n <= 0:
        n = 0
    else:
        n -= 1
    update_graph()


fig, ax = plt.subplots()
update_graph()
fig.subplots_adjust(left=0.07, right=0.95, top=0.95, bottom=0.2)
axes_button_add = pylab.axes([0.7, 0.05, 0.25, 0.075])
axes_button_del = pylab.axes([0.05, 0.05, 0.25, 0.075])
button_add = Button(axes_button_add, 'Добавить')
button_del = Button(axes_button_del, 'Удалить')
button_add.on_clicked(add_clicked)
button_del.on_clicked(del_clicked)
plt.show()
