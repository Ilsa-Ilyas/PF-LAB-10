#include <stdio.h>
#include <string.h>
#define MAX_FLIGHTS 100
typedef struct {
    char flightNumber[10];
    char departureCity[50];
    char arrivalCity[50];
    char departureTime[10];
    char arrivalTime[10];
    int availableSeats;
} Flight;
Flight flights[MAX_FLIGHTS];
int flightCount = 0;
void addFlight(char *flightNumber, char *departureCity, char *arrivalCity, char *departureTime, char *arrivalTime, int availableSeats) {
    if (flightCount < MAX_FLIGHTS) {
        strcpy(flights[flightCount].flightNumber, flightNumber);
        strcpy(flights[flightCount].departureCity, departureCity);
        strcpy(flights[flightCount].arrivalCity, arrivalCity);
        strcpy(flights[flightCount].departureTime, departureTime);
        strcpy(flights[flightCount].arrivalTime, arrivalTime);
        flights[flightCount].availableSeats = availableSeats;
        flightCount++;
        printf("Flight added successfully!\n");
    } else {
        printf("Cannot add more flights. Maximum limit reached.\n");
    }
}
void bookSeat(char *flightNumber) {
    int found = 0;
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].flightNumber, flightNumber) == 0) {
            if (flights[i].availableSeats > 0) {
                flights[i].availableSeats--;
                printf("Seat booked successfully! Seats remaining: %d\n", flights[i].availableSeats);
            } else {
                printf("No seats available on this flight.\n");
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Flight not found.\n");
    }
}
void displayAvailableFlights(char *departureCity, char *arrivalCity) {
    int found = 0;
    printf("Available flights from %s to %s:\n", departureCity, arrivalCity);
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].departureCity, departureCity) == 0 && strcmp(flights[i].arrivalCity, arrivalCity) == 0) {
            printf("Flight Number: %s\n", flights[i].flightNumber);
            printf("Departure Time: %s\n", flights[i].departureTime);
            printf("Arrival Time: %s\n", flights[i].arrivalTime);
            printf("Available Seats: %d\n", flights[i].availableSeats);
            found = 1;
        }
    }
    if (!found) {
        printf("No flights available between %s and %s.\n", departureCity, arrivalCity);
    }
}
void updateFlightDetails(char *flightNumber, char *newDepartureTime, char *newArrivalTime) {
    int found = 0;
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].flightNumber, flightNumber) == 0) {
            strcpy(flights[i].departureTime, newDepartureTime);
            strcpy(flights[i].arrivalTime, newArrivalTime);
            printf("Flight details updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Flight not found.\n");
    }
}
int main() {
    addFlight("AA101", "New York", "Los Angeles", "08:00", "11:00", 10);
    addFlight("BA202", "Chicago", "Miami", "12:00", "16:00", 5);
    addFlight("CA303", "New York", "Los Angeles", "15:00", "18:00", 20);
    printf("\nBooking a seat on flight AA101:\n");
    bookSeat("AA101");
    printf("\nDisplaying available flights from New York to Los Angeles:\n");
    displayAvailableFlights("New York", "Los Angeles");
    printf("\nUpdating the schedule for flight BA202:\n");
    updateFlightDetails("BA202", "13:00", "17:00");
    printf("\nDisplaying available flights from Chicago to Miami:\n");
    displayAvailableFlights("Chicago", "Miami");
    return 0;
}