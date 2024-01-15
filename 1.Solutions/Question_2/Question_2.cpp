// Question_2.cpp

#include <iostream>
#include <limits>
#include "Room.cpp"

void clearInputBuffer()
{
    std::cin.clear();
    while (std::cin.get() != '\n')
        continue;
}

int main()
{
    try
    {
        const int num_rooms = 10;
        Room rooms[num_rooms];

        // Create 10 rooms
        for (int i = 0; i < num_rooms; ++i)
        {
            Room room;
            room.setRoomId(i + 1);
            std::cout << "Enter details for Room " << i + 1 << ":" << std::endl;

            // Perform input validation for room name
            do
            {
                std::cout << "Room Name: ";
                std::cin >> std::ws; // consume any leading whitespaces
                std::string roomName;
                std::getline(std::cin, roomName);
                room.setRoomName(roomName);
                if (room.getRoomName().empty())
                {
                    std::cout << "Invalid input. Room name cannot be empty." << std::endl;
                    clearInputBuffer();
                }
            } while (room.getRoomName().empty());

            // Perform input validation for number of seats and price per seat
            int numSeats;
            do
            {
                std::cout << "Number of Seats: ";
                std::cin >> numSeats;
                if (std::cin.fail() || numSeats <= 0)
                {
                    std::cout << "Invalid input. Please enter a positive integer for the number of seats." << std::endl;
                    clearInputBuffer();
                }
            } while (numSeats <= 0);
            room.setNumSeats(numSeats);

            double pricePerSeat;
            do
            {
                std::cout << "Price per Seat (in Rs.): ";
                std::cin >> pricePerSeat;
                if (std::cin.fail() || pricePerSeat <= 0)
                {
                    std::cout << "Invalid input. Please enter a positive number for the price per seat." << std::endl;
                    clearInputBuffer();
                }
            } while (pricePerSeat <= 0);
            room.setPricePerSeat(pricePerSeat);

            rooms[i] = room;
        }

        // Accept the number of students and display eligible rooms
        int num_students;
        do
        {
            std::cout << "Enter the number of students: ";
            std::cin >> num_students;
            if (std::cin.fail() || num_students <= 0)
            {
                std::cout << "Invalid input. Please enter a positive integer for the number of students." << std::endl;
                clearInputBuffer();
            }
        } while (num_students <= 0);

        std::cout << "Rooms with a capacity greater than or equal to " << num_students << " students:" << std::endl;
        double totalAmount = 0.0;
        for (const Room &room : rooms)
        {
            if (room.getNumSeats() >= num_students)
            {
                room.displayRoomDetails();
                totalAmount += room.calculateTotalAmount(num_students);
            }
        }
        std::cout << "Total Amount: " << totalAmount << " Rs." << std::endl;

        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
