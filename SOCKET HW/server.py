'''
author: Suzanne Nolba
version: 1.2
course: CSCE 3530
This be the server receiving any request from clients
It wil send back to the client a PONG but might drop it
'''
import random
import socket

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server.bind(('', 8008))
print('sln0098 server connected')
print('[server] : ready to accept data...')

while 1:
    seed = random.randint(0, 10)
    message, address = server.recvfrom(1024)
    if seed >= 3:
        print(f'[client] : {message}')
        server.sendto(b'PONG', address)
    else:
        print('[server] : packet dropped')