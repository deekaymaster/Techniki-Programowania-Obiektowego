#include <iostream>
// Definicja struktury węzła kolejki
struct Node {
	int data;
	Node* next;
	Node(int d) : data(d), next(nullptr) {} // Konstruktor węzła
};
// Definicja klasy Kolejki
class Queue {
private:
	Node* front; // Wskaźnik na początek kolejki
	Node* rear; // Wskaźnik na koniec kolejki
public:
	Queue(); // Konstruktor kolejki
	~Queue(); // Destruktor kolejki
	void enqueue(int data); // Dodawanie elementu do kolejki
	void dequeue(); // Usuwanie elementu z kolejki
	int peek(); // Podglądanie pierwszego elementu kolejki
	bool isEmpty(); // Sprawdzanie, czy kolejka jest pusta
};
// Konstruktor kolejki
Queue::Queue() : front(nullptr), rear(nullptr) {}
// Destruktor kolejki
Queue::~Queue() {
	dequeue(); // Usuwamy wszystkie elementy kolejki
}
// Dodawanie elementu do kolejki
void Queue::enqueue(int data) {
	Node* newNode = new Node(data); // Tworzymy nowy węzeł
	if (rear == nullptr) { // Jeśli kolejka jest pusta
		front = rear = newNode; // Nowy węzeł staje się zarówno początkiem, jak i końcem kolejki
	}
	else {
		rear->next = newNode; // Ustawiamy następnik ostatniego elementu kolejki na nowy węzeł
			rear = newNode; // Nowy węzeł staje się nowym końcem kolejki
	}
}
// Usuwanie elementu z kolejki
void Queue::dequeue() {
	Node* temp = front; // Zapamiętujemy wskaźnik na pierwszy element
		front = front->next; // Przesuwamy wskaźnik na początek kolejki
	delete temp; // Usuwamy poprzedni pierwszy element

	if (front == nullptr) { // Jeśli kolejka jest teraz pusta
		rear = nullptr; // Zerujemy również wskaźnik na koniec kolejki
	}
}
int main() {
	Queue myQueue;
	myQueue.enqueue(10);
	myQueue.enqueue(20);
	myQueue.enqueue(30);
	// std::cout << "Pierwszy element kolejki: " << myQueue.peek() << std::endl;
	myQueue.dequeue();
	// std::cout << "Pierwszy element kolejki po usunięciu: " << myQueue.peek() << std::endl;
	myQueue.dequeue();
	myQueue.dequeue();
	// if (myQueue.isEmpty()) {
	// std::cout << "Kolejka jest pusta.\n";
	// } else {
	// std::cout << "Kolejka nie jest pusta.\n";
	// }
	return 0;
}