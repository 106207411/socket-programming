# TCP Socket Programming

This repository contains two C programs, `client.c` and `server.c`, that demonstrate how to establish a TCP connection between a client and a server using sockets.

## Getting Started

**To compile the programs**

navigate to `sp/` folder and run the `build.sh` in your terminal:

```bash
./build.sh
```

**To run the server**
    
```bash
./server
```
The server is hosted at [http://127.0.0.1:8080](http://127.0.0.1:8080)

**To run the client**

```bash
./client
```
You can manually enter the message to be sent to the server from the client side. The server will echo the uppercase version of the message back to the client.

