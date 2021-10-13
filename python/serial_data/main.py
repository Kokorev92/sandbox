import sys
from PyQt5 import QtWidgets
import serial
from PyQt5.QtGui import QColor, QPalette

import main_window


class RelayGui(QtWidgets.QMainWindow, main_window.Ui_MainWindow):
    port = serial.Serial('/dev/ttyACM0', 19200)
    packet = [0x3a, 0, 0x21, 0]
    relay1 = False
    relay2 = False

    def calc_crc(self):
        i = 0
        self.packet[3] = 0
        while i < 3:
            self.packet[3] = (self.packet[3] + self.packet[i]) % 256
            i += 1

    def send_packet(self):
        self.calc_crc()
        print(self.packet)
        self.port.write(self.packet)

    def relay1_button_click(self):
        self.relay1 = not self.relay1
        palette = self.relay1_button.palette()
        if self.relay1:
            self.packet[1] |= (1 << 0)
            palette.setColor(QPalette.Button, QColor(0, 255, 0))
        else:
            self.packet[1] &= ~(1 << 0)
            palette.setColor(QPalette.Button, QColor(255, 0, 0))
        self.relay1_button.setPalette(palette)
        self.send_packet()

    def relay2_button_click(self):
        self.relay2 = not self.relay2
        palette = self.relay2_button.palette()
        if self.relay2:
            self.packet[1] |= (1 << 1)
            palette.setColor(QPalette.Button, QColor(0, 255, 0))
        else:
            self.packet[1] &= ~(1 << 1)
            palette.setColor(QPalette.Button, QColor(255, 0, 0))
        self.relay2_button.setPalette(palette)
        self.send_packet()

    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.relay1_button.clicked.connect(self.relay1_button_click)
        self.relay2_button.clicked.connect(self.relay2_button_click)
        self.send_packet()


def main():
    app = QtWidgets.QApplication(sys.argv)
    window = RelayGui()
    window.show()
    app.exec()


if __name__ == '__main__':
    main()
