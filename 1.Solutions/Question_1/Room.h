#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

class Room
{
private:
    int room_id;
    std::string room_name;
    int num_seats;
    double price_per_seat;

public:
    // Constructors
    Room();
    Room(int id, const std::string &name, int seats, double price);

    // Getter methods
    int getRoomId() const;
    std::string getRoomName();
    int getNumSeats() const;
    double getPricePerSeat() const;

    // Setter methods
    void setRoomId(int id);
    void setRoomName(const std::string &name);
    void setNumSeats(int seats);
    void setPricePerSeat(double price);

    // Other methods
    double calculateTotalAmount(int num_students) const;
    void displayRoomDetails() const;
    std::string toString() const;
};

#endif // ROOM_H
