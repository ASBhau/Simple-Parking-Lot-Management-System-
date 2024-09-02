#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vehicle {
public:
    string plateNumber;
    int entryTime;
    string type;
    
    Vehicle(string plateNumber, int entryTime, string type) : plateNumber(plateNumber), entryTime(entryTime), type(type) {}

    double calculateCost(int exitTime) {
        int parkedTime = exitTime - entryTime;
        if (type == "Bike") return parkedTime * 10;
        if (type == "Car") return parkedTime * 20;
        if (type == "Truck") return parkedTime * 30;
        return 0;
    }
};

class ParkingLot {
private:
    vector<Vehicle> parkedVehicles;
    int currentTime;
public:
    ParkingLot() : currentTime(0) {}

    void parkVehicle(string plateNumber, string type) {
        Vehicle vehicle(plateNumber, currentTime, type);
        parkedVehicles.push_back(vehicle);
        cout << type << " with plate number " << plateNumber << " parked at time " << currentTime << ".\n";
    }

    void removeVehicle(string plateNumber) {
        for (size_t i = 0; i < parkedVehicles.size(); ++i) {
            if (parkedVehicles[i].plateNumber == plateNumber) {
                int exitTime = currentTime;
                double cost = parkedVehicles[i].calculateCost(exitTime);
                int parkedTime = exitTime - parkedVehicles[i].entryTime;

                cout << parkedVehicles[i].type << " with plate number " << plateNumber << " removed at time " << exitTime << ".\n";
                cout << "Time parked: " << parkedTime << " units. Total cost: $" << cost << "\n";

                parkedVehicles.erase(parkedVehicles.begin() + i);
                return;
            }
        }
        cout << "Vehicle with plate number " << plateNumber << " not found.\n";
    }

    void advanceTime(int timeUnits) {
        currentTime += timeUnits;
        cout << "Time advanced by " << timeUnits << " units. Current time: " << currentTime << ".\n";
    }
};

int main() {
    ParkingLot parkingLot;
    char choice;
    string plateNumber, type;
    int timeUnits;

    while (true) {
        cout << "1. Park Bike\n2. Park Car\n3. Park Truck\n4. Remove Vehicle\n5. Advance Time\n6. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                type = "Bike";
                cout << "Enter bike plate number: ";
                cin >> plateNumber;
                parkingLot.parkVehicle(plateNumber, type);
                break;
            case '2':
                type = "Car";
                cout << "Enter car plate number: ";
                cin >> plateNumber;
                parkingLot.parkVehicle(plateNumber, type);
                break;
            case '3':
                type = "Truck";
                cout << "Enter truck plate number: ";
                cin >> plateNumber;
                parkingLot.parkVehicle(plateNumber, type);
                break;
            case '4':
                cout << "Enter vehicle plate number to remove: ";
                cin >> plateNumber;
                parkingLot.removeVehicle(plateNumber);
                break;
            case '5':
                cout << "Enter time units to advance: ";
                cin >> timeUnits;
                parkingLot.advanceTime(timeUnits);
                break;
            case '6':
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
