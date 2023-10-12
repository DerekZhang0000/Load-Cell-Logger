import serial
import csv
import keyboard
from datetime import datetime

# use the port that the Arduino is connected to
port_name = 'COM3'
serial_conn = serial.Serial(port_name, 57600)
csv_file_name = f"load_cell_data_{datetime.now().date()}.csv"

exit = False
logging = True

def toggle_log():
    global logging
    logging = (logging == False)
    print(f"Logging: {logging}")
keyboard.on_press_key("t", lambda _: toggle_log())

def quit():
    global exit, logging
    exit = True
    logging = False
    print("Quitting...")
keyboard.on_press_key("q", lambda _: quit())

with open(csv_file_name, 'w', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(["Timestamp", "Load Value (kg)"])
    print(f"Logging to {csv_file_name}...")

    while True:
        if exit == True:
            break
        line = serial_conn.readline().decode('utf-8').strip()
        if line[:4] != 'read':
            continue
        load_value = float(line.split(':')[1].strip())
        timestamp = datetime.now().strftime("%H:%M:%S")
        if logging:
            writer.writerow([timestamp, load_value])
            print(f"Logged: {timestamp}, {load_value} g")
serial_conn.close()