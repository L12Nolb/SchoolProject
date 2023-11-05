'''
author: Suzanne Nolba
version: 1.4
course: CSCE 3530
This file will be our client sending PING to a designed Server
It will also get a response from the server
'''
import socket


for i in range(10):
    client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    client.settimeout(1)
    addresse = (socket.gethostbyname(socket.gethostname()), 8008)
    client.sendto(b'PING', addresse)
    try:
        response, server = client.recvfrom(1024)
        print('{:^2} : sent PING... received {}'.format(i+1, response))
    except socket.timeout:
        print('{:^2} : sent PING... Timed Out'.format(i+1))