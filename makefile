all: server client

server: src/server.cpp
	g++ -o server src/server.cpp -pthread -std=c++11

client: src/client.cpp
	g++ -o client src/client.cpp -pthread -std=c++11
