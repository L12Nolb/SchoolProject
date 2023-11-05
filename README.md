# SchoolProject

## Introduction

	The goal of this assignment was to create a client/server program that will
	send PING and PONG back and forth. The UDP format will be used.
	The server will sometimes drop the packet or not send any response
	to the client.
	
## Requirements

	The programs will use the libraries:
	- random
	- socket
	
	This program does not require any line arguments since the host name and port
	number are hardcoded.

## Execution
	
	1. The server has to execute first in order for the program to work.
	
	```bash
	> python server.py
	server connected
	[server] : ready to accept data...
	```
	
	2. Then we will run the client on a separate terminal. it will start sending PING
	and receiving PONG/Timed out.
	
	```bash
	> python client.py
	1  : sent PING... received b'PONG'
	2  : sent PING... Timed Out
	[...]
	```	

### FAQ
	
	Q: I get an error while executing the server.py? Is it normal?
	
	A: The port number might be used by another process. Kill it then re-run server.py
