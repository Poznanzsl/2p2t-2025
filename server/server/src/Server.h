#pragma once

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <optional>

#include "PacketData.h"
#include "enet/enet.h"

struct Player {
    std::optional<int> connectedRoomID;
    int ID;
};

struct Room {
    Player host;
    std::optional<Player> other;
};

class Server {
public:
    Server();
    ~Server();

    void Run();
private:
    void HandlePacketReceive(ENetEvent& event);
    void ProcessEvent(ENetEvent& event);
private:
    bool m_Running;
    ENetHost* m_Server;

    std::unordered_set<int> m_RoomIds;
    std::unordered_map<int, Room> m_Rooms;
    std::unordered_map<ENetPeer*, Player> m_ConnectedPlayers;
    int m_NextPlayerID;
private:
    static constexpr uint16_t SERVER_PORT = 12345;
    static constexpr int MAX_CLIENTS = 32;
    static constexpr int CHANNEL_COUNT = 2;  // send / receive
    static constexpr uint32_t SERVER_INCOMING_BANDWIDTH = 0;
    static constexpr uint32_t SERVER_OUTGOING_BANDWIDTH = 0;
    static constexpr int EVENT_WAIT_TIME_MS = 1000;
};