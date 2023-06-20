[![author](https://img.shields.io/badge/author-lauradefaria-purple.svg)](https://github.com/lauradefaria)

# Remote_Chat
It consists of the implementation of two programs in C/C++ for the composition of a remote chat service: a server application and another client. The server application will receive connections from clients and replicate every message collected from a client to all connected clients. The client application will connect to a server, and multiple instances of the server can receive and send messages to/from all clients connected to the server. The implementation will use the C/C++ socket library and concurrent programming (PThreads).

---

## Table of Contents
- [Sockets & Threads](#sockets-&-threads)
- [Setup](#setup)
- [Clone](#clone)
- [Author](#author)

---    
## Sockets & Threads

- **Socket programming** is a way of connecting two nodes on a network to communicate with each other. One socket(node) listens on a particular port at an IP, while the other socket reaches out to the other to form a connection. The server forms the listener socket while the client reaches out to the server.
- **Pthreads** is an execution model that exists independently from a programming language, as well as a parallel execution model. It allows a program to control multiple different flows of work that overlap in time. Each flow of work is referred to as a thread, and creation and control over these flows is achieved by making calls to the POSIX Threads API.

---    
## Setup

To compile, use the command below in this folder:
```shell
$make
```
To run the server:
```shell
$./server PORTA NOME_DA_SALA
```
To run the client:
```shell
$./client IP_SERVIDOR PORTA NOME_DO_CLIENTE
```
    
---    
## Clone

- Clone this repo to your local machine using
    > https://github.com/lauradefaria/Remote_Chat.git

---
## Author

|<a href="https://www.linkedin.com/in/lauradefaria/" target="_blank">**Laura de Faria Maranhão Ayres**</a> |
|:-----------------------------------------------------------------------------------------:|
|                   <img src="imgs/laura.jpg" width="200px"> </img>                            |           
|               <a href="http://github.com/lauradefaria" target="_blank">`github.com/lauradefaria`</a>      | 
