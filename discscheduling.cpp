#include <bits/stdc++.h>
using namespace std;

int closest(int request[], bool visited[], int head, int n)
{
    int min = INT_MIN;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int dist = abs(head - request[i]);
            if (dist < min)
            {
                min = dist;
                index = i;
            }
        }
    }
    return index;
}

void sstf(int request[], int n, int head)
{
    bool visited[n] = {false};
    sort(request, request + n); // Using C++ predefined sort function
    int totalSeek = 0;

    cout << "Seek Sequence: ";
    for (int i = 0; i < n; i++)
    {
        int minIndex = closest(request, visited, head, n);
        totalSeek += abs(head - request[minIndex]);
        visited[minIndex] = true;
        head = request[minIndex];

        // Print the serviced request (seek sequence)
        cout << request[minIndex] << " ";
    }
    cout << endl;

    cout << "Total seek time (SSTF): " << totalSeek << endl;
}

void scan(int request[], int n, int head, int direction, int size)
{
    int total = 0;
    sort(request, request + n); // Using C++ predefined sort function
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        if (request[i] > head)
        {
            index = i;
            break;
        }
    }

    if (direction == 1)
    { // Moving towards the end
        for (int i = index; i < n; i++)
        {
            total += abs(head - request[i]);
            head = request[i];
        }
        if (head != size - 1)
        {
            total += abs(head - (size - 1));
            head = size - 1;
        }
        for (int i = index - 1; i >= 0; i--)
        {
            total += abs(head - request[i]);
            head = request[i];
        }
    }
    else
    { // Moving towards the beginning
        for (int i = index - 1; i >= 0; i--)
        {
            total += abs(head - request[i]);
            head = request[i];
        }
        if (head != 0)
        {
            total += abs(head - 0);
            head = 0;
        }
        for (int i = index; i < n; i++)
        {
            total += abs(head - request[i]);
            head = request[i];
        }
    }

    cout << "Total seek time (SCAN): " << total << endl;
}

void clook(int request[], int n, int head, int direction)
{
    int total = 0;
    sort(request, request + n); // Using C++ predefined sort function
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        if (request[i] > head)
        {
            index = i;
            break;
        }
    }

    if (direction == 1)
    { // Moving towards the end
        for (int i = index; i < n; i++)
        {
            total += abs(head - request[i]);
            head = request[i];
        }
        for (int i = 0; i < index; i++)
        {
            total += abs(head - request[i]);
            head = request[i];
        }
    }
    else
    { // Moving towards the beginning
        for (int i = index - 1; i >= 0; i--)
        {
            total += abs(head - request[i]);
            head = request[i];
        }
        for (int i = n - 1; i >= index; i--)
        {
            total += abs(head - request[i]);
            head = request[i];
        }
    }

    cout << "Total seek time (C-LOOK): " << total << endl;
}

int main()
{
    int n;
    cout << "Enter number of seeks: ";
    cin >> n;

    int request[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter seek: ";
        cin >> request[i];
    }

    int head;
    cout << "Enter head position: ";
    cin >> head;

    int size;
    cout << "Enter disk size: ";
    cin >> size;

    clook(request, n, head, 1); // Example of calling C-LOOK with direction 1 (towards the end)
    sstf(request, n, head);
    return 0;
}
