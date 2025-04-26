#include "NetworkClient.h"

//=========================================================================
//                     Config consts

namespace NetworkConfig {
    constexpr int MAX_CONNECTIONS = 1;                    // just server
    constexpr int CHANNEL_COUNT = 2;                      // send / recive
    constexpr uint32_t INCOMING_BANDWIDTH = 0; 
    constexpr uint32_t OUTGOING_BANDWIDTH = 0; 

    constexpr uint32_t CONNECT_TIMEOUT_MS = 5000;
    constexpr uint32_t DISCONNECT_TIMEOUT_MS = 3000;
    constexpr int RECEIVE_WAIT_TIME_MS = 0;
}
//=========================================================================

NetworkClient::NetworkClient()
    : m_Client(nullptr), m_ServerPeer(nullptr)
{
	if (enet_initialize() != 0) {
		std::cerr << "Failed to initialize enet" << std::endl;
		exit(1);
	}
}

NetworkClient::~NetworkClient(){
	if (m_Client) {
		enet_host_destroy(m_Client);
	}
	enet_deinitialize();
}

bool NetworkClient::Connect(const std::string& serverAddress, uint16_t port){
    m_Client = enet_host_create(
        nullptr,
        NetworkConfig::MAX_CONNECTIONS,
        NetworkConfig::CHANNEL_COUNT,
        NetworkConfig::INCOMING_BANDWIDTH,
        NetworkConfig::OUTGOING_BANDWIDTH
    );

    if (!m_Client) {
        std::cerr << "Failed to create client host" << std::endl;
        return false;
    }

    ENetAddress address;
    enet_address_set_host(&address, serverAddress.c_str());
    address.port = port;

    m_ServerPeer = enet_host_connect(m_Client, &address, NetworkConfig::CHANNEL_COUNT, 0); 
    if (!m_ServerPeer) {
        std::cout << "Failed to connect to server" << std::endl;
        return false;
    }

    ENetEvent event;
    if (enet_host_service(m_Client, &event, NetworkConfig::CONNECT_TIMEOUT_MS) > 0 && event.type == ENET_EVENT_TYPE_CONNECT) {
        std::cout << "Connected to server" << std::endl;
        return true;
    }
    else {
        if (m_ServerPeer) {
            enet_peer_reset(m_ServerPeer);
        }
        std::cout << "Connection to server failed" << std::endl;
        return false;
    }
}

void NetworkClient::Disconnect(){
    if (m_ServerPeer) {
        enet_peer_disconnect(m_ServerPeer, 0);  
        ENetEvent event;
        while (enet_host_service(m_Client, &event, NetworkConfig::DISCONNECT_TIMEOUT_MS) > 0) {
            if (event.type == ENET_EVENT_TYPE_DISCONNECT) {
                std::cout << "Disconnected from server" << std::endl;
                break;
            }
            else {
                if (event.packet) {
                    enet_packet_destroy(event.packet);
                }
            }
        }
    }
}

void NetworkClient::SendData(const void* data, size_t dataSize){
    if (m_ServerPeer) {
        ENetPacket* packet = enet_packet_create(data, dataSize, ENET_PACKET_FLAG_RELIABLE);
        enet_peer_send(m_ServerPeer, 0, packet);
        enet_host_flush(m_Client);
    }
}

void NetworkClient::ReceiveData(){
    ENetEvent event;
    while (enet_host_service(m_Client, &event, NetworkConfig::RECEIVE_WAIT_TIME_MS) > 0) {
        switch (event.type) {
            case ENET_EVENT_TYPE_RECEIVE:{
                std::cout << "Received data: " << event.packet->data << std::endl;
                enet_packet_destroy(event.packet);
                break;
            }
            case ENET_EVENT_TYPE_DISCONNECT:{
                std::cout << "Server disconnected" << std::endl;
                break;
            }
        }
    }
}
