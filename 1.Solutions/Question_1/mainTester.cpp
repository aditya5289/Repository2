#include "Room.h"
#include "Room.cpp"
int main()
{
    // Create Room objects using different constructors
    Room room1;
    Room room2(101, "Meeting Room", 15, 120.0);

    // Display details using displayRoomDetails method
    std::cout << "Details of Room 1:" << std::endl;
    room1.displayRoomDetails();

    std::cout << "\nDetails of Room 2:" << std::endl;
    room2.displayRoomDetails();

    // Use setter methods to update Room details
    room1.setRoomId(102);
    room1.setRoomName("Conference Room");
    room1.setNumSeats(30);
    room1.setPricePerSeat(150.0);

    // Display updated details
    std::cout << "\nUpdated Details of Room 1:" << std::endl;
    room1.displayRoomDetails();

    return 0;
}
