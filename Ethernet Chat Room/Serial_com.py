import serial

message = serial.Serial(
    port='COM6',
    baudrate=9600,
    stopbits=1,
)

# message.open()

while 1:
    print("connected")
    Data = input("Insert a message: ")
    print(Data)

    message.write(Data.encode())
    # Don't forget to send \n at the end of the message
    received_msg = message.readline()
    print(received_msg.decode())

    if received_msg.decode() == 'q':
        message.close()
        break


