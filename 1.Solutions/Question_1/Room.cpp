#include "Room.h"

Room::Room() : room_id(0), num_seats(0), price_per_seat(0.0) {}

Room::Room(int id, const std::string &name, int seats, double price)
    : room_id(id), room_name(name), num_seats(seats), price_per_seat(price) {}

int Room::getRoomId() const
{
    return room_id;
}

std::string Room::getRoomName()
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

double Room::calculateTotalAmount(int num_students) const
{
    return num_students >= num_seats ? num_students * price_per_seat : 0.0;
}

void Room::displayRoomDetails() const
{
    std::cout << toString() << std::endl;
}

std::string Room::toString() const
{
    return "  Room ID: " + std::to_string(room_id) + "\n" +
           "  Room Name: " + room_name + "\n" +
           "  Number of Seats: " + std::to_string(num_seats) + "\n" +
           "  Price per Seat: " + " Rs." + std::to_string(price_per_seat);
}