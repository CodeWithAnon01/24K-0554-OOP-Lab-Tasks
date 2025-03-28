#include <iostream>
using namespace std;

class Ticket {
protected:
    int ticketID;
    string passengerName, date, destination;
    double price;
public:
    Ticket(int id, string name, string d, string dest, double p)
        : ticketID(id), passengerName(name), date(d), destination(dest), price(p) {}
    virtual void reserve() { cout << "Ticket reserved for " << passengerName << "\n"; }
    virtual void cancel() { cout << "Ticket canceled for " << passengerName << "\n"; }
    virtual void displayTicketInfo() {
        cout << "Ticket ID: " << ticketID << "\nPassenger: " << passengerName
             << "\nDate: " << date << "\nDestination: " << destination
             << "\nPrice: " << price << "\n";
    }
};

class FlightTicket : public Ticket {
    string airlineName;
    int flightNumber;
public:
    FlightTicket(int id, string name, string d, string dest, double p, string airline, int flightNo)
        : Ticket(id, name, d, dest, p), airlineName(airline), flightNumber(flightNo) {}
    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Airline: " << airlineName << "\nFlight Number: " << flightNumber << "\n";
    }
};

class TrainTicket : public Ticket {
    int trainNumber;
    string coachType;
public:
    TrainTicket(int id, string name, string d, string dest, double p, int trainNo, string coach)
        : Ticket(id, name, d, dest, p), trainNumber(trainNo), coachType(coach) {}
    void reserve() override {
        cout << "Train ticket auto-assigned for " << passengerName << "\n";
    }
};

class BusTicket : public Ticket {
    string busCompany;
    int seatNumber;
public:
    BusTicket(int id, string name, string d, string dest, double p, string company, int seatNo)
        : Ticket(id, name, d, dest, p), busCompany(company), seatNumber(seatNo) {}
    void cancel() override {
        cout << "Last-minute refund granted for " << passengerName << "\n";
    }
};

class ConcertTicket : public Ticket {
    string artistName, venue;
public:
    ConcertTicket(int id, string name, string d, string dest, double p, string artist, string v)
        : Ticket(id, name, d, dest, p), artistName(artist), venue(v) {}
    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Artist: " << artistName << "\nVenue: " << venue << "\n";
    }
};

int main() {
    FlightTicket f1(101, "John Doe", "2025-04-10", "New York", 500.0, "Airways", 2345);
    f1.displayTicketInfo();
    f1.reserve();

    TrainTicket t1(102, "Alice Smith", "2025-04-11", "Boston", 150.0, 789, "Sleeper");
    t1.reserve();

    BusTicket b1(103, "Bob Brown", "2025-04-12", "Chicago", 50.0, "Greyhound", 12);
    b1.cancel();

    ConcertTicket c1(104, "Eve Green", "2025-04-15", "LA", 200.0, "Taylor Swift", "Stadium");
    c1.displayTicketInfo();

    return 0;
}