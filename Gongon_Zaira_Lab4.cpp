#include <iostream>
using namespace std;

struct Song {
    string title;
    int priority; 
};

Song karaoke_queue[10]; 
int front = -1;
int rear = -1;
int max_queue = 10;

bool isFull() {
    return (rear + 1) % max_queue == front;
}

bool isEmpty() {
    return front == -1;
}

void displayrearandfront() {
    cout << "Front: " << front << ", Rear: " << rear << endl;
}

string enqueue(string title, int priority) {
    if (isFull()) {
        return "The queue is full. Try again later!";
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % max_queue;
    }

    karaoke_queue[rear] = {title, priority};

    for (int i = front; i != rear; i = (i + 1) % max_queue) {
        int i2 = (i + 1) % max_queue;
        if (karaoke_queue[i].priority < karaoke_queue[i2].priority) {
            swap(karaoke_queue[i], karaoke_queue[i2]);
        }
    }

    displayrearandfront();
    return "A new song has been added to the queue!";
}

string dequeue() {
    if (isEmpty()) {
        return "There is no song in the queue. Try adding first!";
    }

    string song = karaoke_queue[front].title;

    if (front == rear) { 
        front = rear = -1;
    } else {
        front = (front + 1) % max_queue;
    }

    displayrearandfront();
    return song;
}

int main() {
    cout << enqueue("Zero Pressure", 2) << endl;
    cout << enqueue("Out Of My Head", 5) << endl; 
    cout << enqueue("Secrets", 1) << endl;
    cout << enqueue("Blink Twice", 3) << endl;
    cout << enqueue("Cherry On Top", 4) << endl;
    
    cout << dequeue() << " playing: " << endl;
    cout << dequeue() << " playing: " << endl;
    
    cout << enqueue("Your Song", 7) << endl;
    cout << enqueue("Malay Ko", 10) << endl; 
    
    cout << dequeue() << " playing: " << endl;
    
    cout << enqueue("Multo", 6) << endl;
    cout << enqueue("Always", 8) << endl;
    cout << enqueue("Ang Pitong Gatang", 9) << endl;
    
    cout << dequeue() << " playing: " << endl;
    cout << dequeue() << " playing: " << endl;
    cout << dequeue() << " playing: " << endl;

    return 0;
}