#include <iostream>
using namespace std;

class MonitoringSystem {
public:
    string name;
    string sensors[3];
    int cost;

    MonitoringSystem() {
        name = "";
        for (int i = 0; i < 3; i++) {
            sensors[i] = "";
        }
        cost = 0;
        cout << "MonitoringSystem object created with default constructor!" << endl;
    }

    MonitoringSystem(string sys_name, string sensor1, string sensor2, string sensor3) {
        name = sys_name;
        sensors[0] = sensor1;
        sensors[1] = sensor2;
        sensors[2] = sensor3;
        cost = size(sensor1) + size(sensor2) + size(sensor3);
        cout << "MonitoringSystem object created with parameterized constructor!" << endl;
    }

    void input_sensor() {
        for (int i = 0; i < 3; i++) {
            cout << "Enter the name of the sensor " << i + 1 << " : ";
            cin >> sensors[i];
        }
    }

    void setSnsorsCost() {
        cost = size(sensors[0]) + size(sensors[1]) + size(sensors[2]);
    }

    void display() {
        cout << "Name: " << name << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Sensor " << i + 1 << ": " << sensors[i] << " ";
        }
        cout << "Cost: " << cost << endl;
    }

    ~MonitoringSystem() {
        cout << "MonitoringSystem object with name '" << name << "' has been deleted!" << endl;
    }
};

int main() {
    int number_of_systems;
    cout << "Enter the number of monitoring systems: ";
    cin >> number_of_systems;

    MonitoringSystem *systems = new MonitoringSystem[number_of_systems];

    for (int i = 0; i < number_of_systems; i++) {
        cout << endl << "Enter name for system " << i + 1 << ": " << endl;
        cin >> systems[i].name;
        systems[i].input_sensor();
        systems[i].setSnsorsCost();
    }

    cout << "Monitoring Systems: " << endl;
    for (int i = 0; i < number_of_systems; i++) {
        cout << "System " << i + 1 << ": " << endl;
        systems[i].display();
    }

    int number_of_changing_system;
    cout << endl << "Enter index of system to modify: ";
    cin >> number_of_changing_system;
    number_of_changing_system--;
    if (number_of_changing_system >= 0 && number_of_changing_system < number_of_systems) {
        cout << "Enter new name: ";
        cin >> systems[number_of_changing_system].name;
        systems[number_of_changing_system].input_sensor();
        systems[number_of_changing_system].setSnsorsCost();
    } else {
        cout << "Error... Input the right number!" << endl;
    }

    cout << "Updated Monitoring Systems: " << endl;
    for (int i = 0; i < number_of_systems; i++) {
        cout << "System " << i + 1 << ": " << endl;
        systems[i].display();
    }

    return 0;
}
