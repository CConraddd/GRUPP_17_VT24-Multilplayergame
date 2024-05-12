#ifndef CLIENT_H
#define CLIENT_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "../objects/player.h"

typedef struct {
    IPaddress ip;
    TCPsocket clientSocket;
	UDPpacket *pPacket;
    UDPsocket udpSocket;
    Player *player[4];
    int clientId;
}Client;

//TCP
Client *createClient();
int connectToServer(Client *pClient);
void closeClient(Client *pClient);

//UDP

void sendDataUDP(Client *pClient, Player *player, UDPpacket *packet, UDPsocket udpSocket);
int receiveFromServer(Client *pClient, Player *player, UDPpacket *packet, UDPsocket udpSocket);

#endif