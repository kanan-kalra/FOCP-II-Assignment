//MOVIE TICKETS


#include <iostream>
#include <string>
using namespace std;

// Maximum limits
const int MAX_CUSTOMERS = 10000;  // Maximum customer IDs
const int MAX_MOVIES = 10000;     // Maximum movie IDs
const int MAX_TICKETS = 100;      // Maximum tickets per movie

// 2D array: booked[customerID][movieID] = true if booked
// This acts like a table with rows = customers, columns = movies
bool booked[MAX_CUSTOMERS][MAX_MOVIES];

// 1D array: ticketsSold[movieID] = number of tickets sold for that movie
int ticketsSold[MAX_MOVIES];

// BOOK: Customer x wants to book movie y
bool book(int x, int y) {

    // Check if already booked
    if (booked[x][y] == true) {
        return false;
    }

    // Check if sold out
    if (ticketsSold[y] >= MAX_TICKETS) {
        return false;
    }

    // Do the booking
    booked[x][y] = true;
    ticketsSold[y]++;
    return true;
}

// CANCEL: Customer x wants to cancel booking for movie y
bool cancel(int x, int y) {

    // Check if booking exists
    if (booked[x][y] == false) {
        return false;
    }

    // Cancel the booking
    booked[x][y] = false;
    ticketsSold[y]--;
    return true;
}

// IS_BOOKED: Check if customer x has booked movie y
bool isBooked(int x, int y) {
    return booked[x][y];
}

// AVAILABLE_TICKETS: How many tickets are left for movie y
int availableTickets(int y) {
    return MAX_TICKETS - ticketsSold[y];
}

int main() {

    // Initialize all arrays to 0/false
    // (global arrays are auto-initialized, but doing it manually for clarity)
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        for (int j = 0; j < MAX_MOVIES; j++) {
            booked[i][j] = false;
        }
    }
    for (int i = 0; i < MAX_MOVIES; i++) {
        ticketsSold[i] = 0;
    }

    int Q;
    cout << "Enter number of queries: ";
    cin >> Q;

    while (Q--) {
        string queryType;
        cin >> queryType;

        if (queryType == "BOOK") {
            int x, y;
            cin >> x >> y;
            if (book(x, y)) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        }
        else if (queryType == "CANCEL") {
            int x, y;
            cin >> x >> y;
            if (cancel(x, y)) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        }
        else if (queryType == "IS_BOOKED") {
            int x, y;
            cin >> x >> y;
            if (isBooked(x, y)) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        }
        else if (queryType == "AVAILABLE_TICKETS") {
            int y;
            cin >> y;
            cout << availableTickets(y) << endl;
        }
        else {
            cout << "Invalid query!" << endl;
        }
    }

    return 0;
}
