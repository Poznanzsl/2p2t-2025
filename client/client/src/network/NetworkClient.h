#pragma once

#include <iostream>
#include <enet/enet.h>

class NetworkClient {
public:
    NetworkClient();
    ~NetworkClient();

    bool Connect(const std::string& serverAddress, uint16_t port);
    void Disconnect();
    void SendData(const void* data, size_t dataSize);
    void ReceiveData();
private:
    ENetHost* m_Client;     
    ENetPeer* m_ServerPeer;
};