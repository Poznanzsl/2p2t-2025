#include <iostream>

#include "enet/enet.h"


//=========================================================================
//                              Config consts

namespace Config {
    constexpr uint16_t SERVER_PORT = 12345;
    constexpr int MAX_CLIENTS = 32;
    constexpr int CHANNEL_COUNT = 2;                       // send / recive
    constexpr uint32_t SERVER_INCOMING_BANDWIDTH = 0;
    constexpr uint32_t SERVER_OUTGOING_BANDWIDTH = 0;
    constexpr int EVENT_WAIT_TIME_MS = 1000;
}
//=========================================================================

int main() {
    enet_initialize();

    ENetAddress address;
    address.host = ENET_HOST_ANY; 
    address.port = Config::SERVER_PORT;        

    ENetHost* server = enet_host_create(
        &address, 
        Config::MAX_CLIENTS, 
        Config::CHANNEL_COUNT, 
        Config::SERVER_INCOMING_BANDWIDTH, 
        Config::SERVER_OUTGOING_BANDWIDTH
    );

    if (!server) {
        std::cerr << "Failed to create server" << std::endl;
        return EXIT_FAILURE;
    } 
    else {
        std::cout << "Created server" << std::endl;
    }

    ENetEvent event;
    bool running = true;
    while (running) {
        while (enet_host_service(server, &event, Config::EVENT_WAIT_TIME_MS) > 0) {
            switch (event.type) {
                case ENET_EVENT_TYPE_CONNECT: {
                    char ip[32];
                    enet_address_get_host_ip(&event.peer->address, ip, sizeof(ip));
                    std::cout << "Client connected: " << ip << " : " << event.peer->address.port << std::endl;

                    const char* message = "Test txet from server";
                    ENetPacket* packet = enet_packet_create(message, strlen(message) + 1, ENET_PACKET_FLAG_RELIABLE);
                    enet_peer_send(event.peer, 0, packet);
                    enet_host_flush(server);
                    break;
                }

                case ENET_EVENT_TYPE_RECEIVE: {
                    char ip[32];
                    enet_address_get_host_ip(&event.peer->address, ip, sizeof(ip));
                    std::cout << "Packet received: "
                        << (char*)event.packet->data
                        << "\tFrom: " << ip << " : " << event.peer->address.port << std::endl;
                    enet_packet_destroy(event.packet);
                    break;
                }

                case ENET_EVENT_TYPE_DISCONNECT: {
                    char ip[32];
                    enet_address_get_host_ip(&event.peer->address, ip, sizeof(ip));
                    std::cout << "Client disconnected: " << ip << " : " << event.peer->address.port << std::endl;
                    break;
                }
            }
        }
    }

    enet_host_destroy(server);
    enet_deinitialize();
}