#include <iostream>

// Definicja struktury węzła kolejki
struct Node {
	int data;
	int priority; // Priorytet elementu
	Node* next;
	Node(int d, int p) : data(d), priority(p), next(nullptr) {} // Konstruktor węzła
};

// Definicja klasy Kolejki
class Queue {
private:
	Node* front; // Wskaźnik na początek kolejki
	Node* rear; // Wskaźnik na koniec kolejki
public:
	Queue(); // Konstruktor kolejki
	~Queue(); // Destruktor kolejki
	void enqueue(int data, int priority); // Dodawanie elementu do kolejki
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
void Queue::enqueue(int data, int priority) {
	Node* newNode = new Node(data, priority); // Tworzymy nowy węzeł z danymi i priorytetem
	if (front == nullptr) { // Jeśli kolejka jest pusta
		front = rear = newNode; // Nowy węzeł staje się zarówno początkiem, jak i końcem kolejki
	}
	else {
		// Sprawdzamy priorytety i dodajemy w odpowiedniej kolejności
		if (priority < front->priority) { // Jeśli nowy element ma niższy priorytet niż pierwszy element kolejki
			newNode->next = front; // Nowy element staje się nowym początkiem kolejki
			front = newNode;
		}
		else {
			Node* temp = front;
			while (temp->next != nullptr && temp->next->priority <= priority) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
			if (temp == rear) // Aktualizujemy rear, jeśli nowy węzeł jest dodany na końcu
				rear = newNode;
		}
	}
}

// Usuwanie elementu z kolejki
void Queue::dequeue() {
	if (front == nullptr) // Jeśli kolejka jest pusta, nie ma co usuwać
		return;

	Node* temp = front; // Zapamiętujemy wskaźnik na pierwszy element
	front = front->next; // Przesuwamy wskaźnik na początek kolejki
	delete temp; // Usuwamy poprzedni pierwszy element

	if (front == nullptr) // Jeśli kolejka jest teraz pusta
		rear = nullptr; // Zerujemy również wskaźnik na koniec kolejki
}

// Funkcja podglądania pierwszego elementu kolejki
int Queue::peek() {
	if (isEmpty()) {
		std::cerr << "Kolejka jest pusta." << std::endl;
		return -1; // Zwracamy wartość oznaczającą błąd
	}
	return front->data;
}

// Funkcja sprawdzająca, czy kolejka jest pusta
bool Queue::isEmpty() {
	return front == nullptr;
}

int main() {
	Queue myQueue;
	myQueue.enqueue(10, 2); // Dodanie elementu o danych 10 i priorytecie 2
	myQueue.enqueue(20, 1); // Dodanie elementu o danych 20 i priorytecie 1
	myQueue.enqueue(30, 3); // Dodanie elementu o danych 30 i priorytecie 3

	std::cout << "Pierwszy element kolejki: " << myQueue.peek() << std::endl;

	myQueue.dequeue(); // Usunięcie elementu o najwyższym priorytecie

	std::cout << "Pierwszy element kolejki po usunięciu: " << myQueue.peek() << std::endl;

	myQueue.dequeue();
	myQueue.dequeue();

	if (myQueue.isEmpty()) {
		std::cout << "Kolejka jest pusta.\n";
	}
	else {
		std::cout << "Kolejka nie jest pusta.\n";
	}

	return 0;
}
