#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    int id;
    string title;
    string status;
    int time;
public:
    Book(int id, string name) {
        this->id = id;
        this->title = title;
        this->status = "avaible";
        this->time = 0;
    }

    void showBook() {
        cout << "[" << id << "] " << title << " (" << status << ")";
        if (status == "issude") {
            cout << " - due in " << time << " days";
        }
    }


    bool recive() {
        if (status == "avaible") {
            status = "recived";
            return true;
        }
        return false;
    }

    bool issue(int time_to_read) {
        if (status == "avaible" or status == "recived") {
            status = "issued";
            time = time_to_read;
            return true;
        }
        return false;
    }

    void reduceTime(int left_time) {
        if (status == "issued") {
            time-= left_time;
            if (time < 0) {
                time = 0;
            }
        }
    }

    void littleTime() {
        if (time <= 2) {
            cout << "[" << id << "] " << title << " (" << status << ")";
            cout << "You have only " << time << " days tp bring book back";
        }
    }
};

class Library {
private:
    vector<Book> books;
public:
    void addBook(Book book) {
        if (size(books)>=15){
            cout << "Library id full" << endl;
        } else {
            books.push_back(book);
        }
    }
    void reciveBook(){

        };


};

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
    int number_of_exercises;
    cout << "Enter number of exercise"<<endl;
    cin >> number_of_exercises;
    if (number_of_exercises == 1) {
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
        } if (number_of_exercises == 2) {
            








        } else {
            cout << "Error... out of range";
        }
    }
    return 0;
}
