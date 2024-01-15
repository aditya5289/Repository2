#include "Room.h"

// Default Constructor
Room::Room() : room_id(0), room_name(""), num_seats(0), price_per_seat(0.0) {}

// Parameterized Constructor
Room::Room(int id, const std::string &name, int seats, double price)
    : room_id(id), room_name(name), num_seats(seats), price_per_seat(price) {}

// Getter methods
int Room::getRoomId() const
{
    return room_id;
}

const std::string &Room::getRoomName() const
{
    return room_name;
}

int Room::getNumSeats() const
{
    return num_seats;
}

double Room::getPricePerSeat() const
{
    return price_per_seat;
}

// Setter methods
void Room::setRoomId(int id)
{
    room_id = id;
}

void Room::setRoomName(const std::string &name)
{
    room_name = name;
}

void Room::setNumSeats(int seats)
{
    num_seats = seats;
}

void Room::setPricePerSeat(double price)
{
    price_per_seat = price;
}

// Other methods
double Room::calculateTotalAmount(int num_students) const
{
    return num_students * price_per_seat;
}

void Room::displayRoomDetails() const
{
    std::cout << "Room ID: " << room_id << ", Room Name: " << room_name << ", Seats: " << num_seats << ", Price per Seat: " << price_per_seat << std::endl;
}

std::string Room::toString() const
{
    return "Room ID: " + std::to_string(room_id) + ", Room Name: " + room_name + ", Seats: " + std::to_string(num_seats) + ", Price per Seat: " + std::to_string(price_per_seat);
}
