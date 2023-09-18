# This code explains how to create a socket object to create a client
import socket
import threading

# AF_Inet for IPV4 and SOCK_STREAM for TCP/IP
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# write the server IP and port number
ip = "169.254.230.199" #server ip
port = 1234
client.connect((ip, port))

def receive():
    while True:
        try:
            message = client.recv(1024).decode('utf-8')
            print(message)
        except:
            print("An Error occured!")
            client.close()
            break

def write():
    while True:
        message = f'{client}:{input("")}'
        client.send(message.encode('utf-8'))

receive_thread=threading.Thread(target=receive)
receive_thread.start()

write_thread=threading.Thread(target=write)
write_thread.start()


#
# # connect to the server
# # Receive message from the server
# message = client.recv(1024)
# print(message.decode())
# # Send message to the server.
# # Note: you have to encode the message before sending
# s.send("2y 7aga".encode("utf-8"))
#
#

