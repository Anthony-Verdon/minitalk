# minitalk 

## a little server to talk

This project is part of the second circle of the 42 common core. The goal is to create a communication between a server and clients using the function `signal`. You will find the subject of the project into the repository. My grade : 125/100.

## How to use it

1. Clone it `git clone git@github.com:AnthonyVerdon-42Projects/minitalk.git`.
2. Compile it `make`. You can also use `make bonus` to compile a server which support Unicode Characters and send back a signal to the client after each message.
3. run the server : `./server`. It will write it PID and wait for message.
4. If you want to send a message to the server, use the client : `./client [PID_SERVER] [MESSAGE]`

## How does it work ?

There is multiples signals, and you probably know some of them :

| Signal | What is it |
| ------ | ---------- |
| SIGINT | CTRL + C   |
| SIGSEGV | Segfault  |
| SIGKILL | kill the process |
| ... | ... |

But there is also signal that only the user can send, using the function `kill` : SIGUSR1 and SIGUSR2. It's with them that the client can send a message to the server, sending message on binary code : each message is send letter by letter, and each letter is send using binary code (SIGUSR1 corresponding to 0 and SIGUSR2 to 1).

## Possible optimization

In order to not flood the server, the client send a signal and wait thanks to the function `usleep`, but it can be a bit long for large message. A way to optimize would be to make the server send a signal to the client after each bit it received.

## Find a bug ?

If you find an undefined behaviour (crash, leaks, ...), please submit an issue or contact me
