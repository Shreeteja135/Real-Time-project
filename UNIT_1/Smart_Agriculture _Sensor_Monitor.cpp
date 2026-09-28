#include <iostream>   // For input and output operations
#include <string>     // For using string data type
#include <vector>     // For using vector container

using namespace std;

// ==========================================================
// Class : SoilSensor
// Stores and manages soil moisture sensor information
// Demonstrates Object-Oriented Programming concepts
// ==========================================================
class SoilSensor
{
private:
    string sensorId;        // Unique ID of the sensor
    double moistureLevel;   // Current soil moisture percentage
    string timestamp;       // Time of the latest reading

public:
    // Constructor to initialize sensor details
    SoilSensor(string id, double moisture, string time)
        : sensorId(id), moistureLevel(moisture), timestamp(time) {}

    // Function to update moisture reading and timestamp
    void readSensor(double newMoisture, string newTime)
    {
        moistureLevel = newMoisture; // Update moisture value
        timestamp = newTime;         // Update reading time
    }

    // Function to display sensor information
    void displayData() const
    {
        cout << "Sensor: " << sensorId
             << " | Moisture: " << moistureLevel << "%"
             << " | Time: " << timestamp << endl;
    }
};

// ==========================================================
// Main Function
// Creates multiple soil sensors and displays readings
// ==========================================================
int main()
{
    // Vector to store multiple SoilSensor objects
    vector<SoilSensor> farmSensors;

    // Adding sensor objects to the vector
    farmSensors.emplace_back("S001", 45.2, "08:00");
    farmSensors.emplace_back("S002", 52.8, "08:00");
    farmSensors.emplace_back("S003", 38.5, "08:00");

    // Display all sensor readings
    cout << "=== Morning Sensor Readings ===" << endl;

    for (const auto &sensor : farmSensors)
    {
        sensor.displayData();
    }

    // Update first sensor reading
    farmSensors[0].readSensor(47.5, "09:00");

    // Display updated reading
    cout << "\n=== Updated Reading ===" << endl;
    farmSensors[0].displayData();

    return 0; // Program ends successfully
}
