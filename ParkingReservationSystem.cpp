/*
Write a program to implement Parking area reservation. The parking area has only one way out
and one-way inn; so scheduling has to be done for the arrival and departure of vehicles in the
parking area. At one time, only one vehicle can arrive or leave the area. Scheduling has to be
done on the basis of first come, first serve. Whichever vehicle comes first at the parking area will
be given the space in the parking area. Similarly, whichever vehicle requests for departure first,
will be given the space to the exit.
[Hint: Arrival of vehicle=enqueue, Departure of vehicle=dequeue]
*/

#include <iostream>
using namespace std;

int main()
{
    int choice, n, i, j, k, l, m, p, q;
    int front = -1, rear = -1;
    int arr[100], dep[100], time[100], status[100];
    int count = 0;
    cout << "Parking Area Reservation" << endl;
    cout << "1. Arrival of Vehicle" << endl;
    cout << "2. Departure of Vehicle" << endl;
    cout << "3. Exit" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Enter Vehicle Number: ";
        cin >> n;
        cout << "Enter Arrival Time: ";
        cin >> time[n];
        cout << "Enter Departure Time: ";
        cin >> dep[n];
        arr[n] = time[n];
        status[n] = 1;
        if (front == -1)
        {
            front = n;
            rear = n;
        }
        else
        {
            rear = n;
            for (i = front; i <= rear; i++)
            {
                arr[i + 1] = arr[i] + 1;
                dep[i + 1] = dep[i] + 1;
            }
        }
        break;
    case 2:
        cout << "Enter Vehicle Number: ";
        cin >> n;
        if (status[n] == 1)
        {
            for (i = n; i <= rear; i++)
            {
                arr[i] = arr[i + 1];
                dep[i] = dep[i + 1];
            }
            status[n] = 0;
        }

    }
    
}
