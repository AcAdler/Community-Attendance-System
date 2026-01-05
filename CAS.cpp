#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

#define SIZE 4

using namespace std;

void markAttendance(string names[], char status[]) {
    cout << "\nEnter P for Present or A for Absent\n";

    for (int S = 0; S < SIZE; S++) {
        cout << names[S] << ": ";
        cin >> status[S];
        status[S] = toupper(status[S]);

        while (status[S] != 'P' && status[S] != 'A') {
            cout << "Invalid input! Enter P or A only: ";
            cin >> status[S];
            status[S] = toupper(status[S]);
        }
    }
}

void showAttendance(string names[], char status[]) {
    cout << "\n===== ATTENDANCE LIST ========\n";

    for (int S = 0; S < SIZE; S++) {
        cout << names[S] << " - ";
        if (status[S] == 'P')
            cout << "Present\n";
        else
            cout << "Absent\n";
    }
}

void countPresent(char status[], int &present) {
    for (int S = 0; S < SIZE; S++) {
        if (status[S] == 'P') {
            present++;
        }
    }
}

int main() {
    string names[SIZE] = {
        "Alota",
        "Cabuyadao",
        "Cuesta",
        "Garcia"
    };

    char status[SIZE];
    int choice = 0;
    int present = 0;

    bool isRunning = true;
    float attendanceRate;

    do {
        cout << "\n=== COMMUNITY ATTENDANCE SYSTEM ===\n";
        cout << "1. Mark Attendance\n";
        cout << "2. Show Attendance\n";
        cout << "3. Show Summary\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            markAttendance(names, status);
        }
        else if (choice == 2) {
            showAttendance(names, status);
        }
        else if (choice == 3) {
            present = 0;
            countPresent(status, present);

            int absent = abs(SIZE - present);
            attendanceRate = (float)present / SIZE * 100;

            cout << "\nPresent: " << present << endl;
            cout << "Absent: " << absent << endl;
            cout << "Attendance Rate: " << attendanceRate << "%\n";
        }
        else if (choice == 4) {
            cout << "\nThank you!!.\n";
            isRunning = false;
        }
        else {
            cout << "\nInvalid choice.\n";
        }

    } while (isRunning);

    return 0;
}
