#include "Server.h"

Server::Server() 
    : m_NextPlayerID(0), m_Running(true), m_Server(nullptr)
{
    if (enet_initialize() != 0) {
        std::cerr << "Failed to initialize ENet" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    ENetAddress address;
    address.host = ENET_HOST_ANY;
    address.port = SERVER_PORT;

    m_Server = enet_host_create(
        &address,
        MAX_CLIENTS,
        CHANNEL_COUNT,
        SERVER_INCOMING_BANDWIDTH,
        SERVER_OUTGOING_BANDWIDTH
    );

    if (!m_Server) {
        std::cerr << "Failed to create server" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::cout << "Server created on port " << SERVER_PORT << std::endl;
}

Server::~Server() {
    if (m_Server) {
        enet_host_destroy(m_Server);
    }
    enet_deinitialize();
}

void Server::Run() {
    ENetEvent event;
    while (m_Running) {
        while (enet_host_service(m_Server, &event, EVENT_WAIT_TIME_MS) > 0) {
            ProcessEvent(event);
        }
    }
}

void Server::ProcessEvent(ENetEvent& event) {
    switch (event.type) {
        case ENET_EVENT_TYPE_CONNECT: {
            char ip[32];
            enet_address_get_host_ip(&event.peer->address, ip, sizeof(ip));
            std::cout << "Client connected: " << ip << ":" << event.peer->address.port << std::endl;

            Player p;
            p.connectedRoomID = std::nullopt;
            p.ID = m_NextPlayerID++;
            m_ConnectedPlayers[event.peer] = p;

            break;
        }
        case ENET_EVENT_TYPE_RECEIVE: {
            HandlePacketReceive(event);
            enet_packet_destroy(event.packet);
            break;
        }
        case ENET_EVENT_TYPE_DISCONNECT: {
            char ip[32];
            enet_address_get_host_ip(&event.peer->address, ip, sizeof(ip));
            std::cout << "Client disconnected: " << ip << ":" << event.peer->address.port << std::endl;

            Player player = m_ConnectedPlayers[event.peer];
            m_ConnectedPlayers.erase(event.peer);
            if (player.connectedRoomID.has_value() && m_Rooms[player.connectedRoomID.value()].host.ID == player.ID) {
                int roomID = player.connectedRoomID.value();

                if (m_Rooms[roomID].other.has_value()) {
                    m_Rooms[roomID].host = m_Rooms[roomID].other.value();
                }
                else {
                    m_Rooms.erase(roomID);
                }
            }
            break;
        }
        default:
            break;
        }
}

void Server::HandlePacketReceive(ENetEvent& event) {
    ENetPacket* packet = event.packet;

    if (packet->dataLength >= sizeof(PacketHeader)) {
        PacketHeader* header = reinterpret_cast<PacketHeader*>(packet->data);

        switch (header->type) {
        case CREATE_ROOM: {
            std::cout << "Handling CREATE_ROOM packet" << std::endl;

            uint32_t roomID = rand() % 900000 + 100000; 
            while (m_RoomIds.find(roomID) != m_RoomIds.end()) {
                roomID = rand() % 1000000 + 100000;
            }
            m_RoomIds.insert(roomID);

            Room room;
            room.host = m_ConnectedPlayers[event.peer];
            m_ConnectedPlayers[event.peer].connectedRoomID = std::optional<int>(roomID);

            m_Rooms[roomID] = room;

            RoomPacket response;
            response.header.type = ROOM_DATA;
            response.roomID = roomID;

            ENetPacket* enetPacket = enet_packet_create(
                &response,
                sizeof(response),
                ENET_PACKET_FLAG_RELIABLE 
            );

            enet_peer_send(event.peer, 0, enetPacket);
            std::cout << "Created room with ID: " << roomID << " by player with ID: " << m_ConnectedPlayers[event.peer].ID << std::endl;
            break;
        }

        case JOIN_ROOM: {
            std::cout << "Handling JOIN_ROOM packet" << std::endl;
            RoomPacket* roomPacket = reinterpret_cast<RoomPacket*>(packet->data);
            int roomID = roomPacket->roomID;
            if (m_RoomIds.find(roomID) == m_RoomIds.end()) {
                std::cout << "Room with ID: " << roomID << " doesnt exist" << std::endl;
                break;
            }   

            Room room = m_Rooms[roomID];

            if (room.other != std::nullopt) {
                std::cout << "Place is already occupied" << std::endl;
                break;
            }
            room.other = std::optional<Player>(m_ConnectedPlayers[event.peer]);
            m_ConnectedPlayers[event.peer].connectedRoomID = roomID;

            RoomPacket response;
            response.header.type = ROOM_DATA;
            response.roomID = roomID;

            ENetPacket* enetPacket = enet_packet_create(
                &response,
                sizeof(response),
                ENET_PACKET_FLAG_RELIABLE
            );

            enet_peer_send(event.peer, 0, enetPacket);
            std::cout << "Player with ID: " << m_ConnectedPlayers[event.peer].ID << " joined room: "<< roomID << " succesfully" << std::endl;
            break;
        }

        case SEND_DATA: {
            std::cout << "Handling SEND_DATA packet" << std::endl;
            // TODO: Handle player data
            break;
        }

        default:
            std::cerr << "Unknown packet type received." << std::endl;
            break;
        }
    }
}