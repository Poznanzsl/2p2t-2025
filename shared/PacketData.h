#pragma once

#pragma pack(push, 1)
enum PacketType : uint32_t{ 
	CREATE_ROOM,
	JOIN_ROOM,
	SEND_DATA,
	ROOM_DATA,
};

struct PacketHeader {
	PacketType type;
};

struct RoomPacket {
	PacketHeader header;
	uint32_t roomID;
};
#pragma pack(pop)