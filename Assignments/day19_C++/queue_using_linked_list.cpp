 #include <iostream>
 using namespace std;

 class Node {
 public:
 	int data;
 	Node* next;

 	Node(int value) {
     	data = value;
     	next = NULL;
 	}
 };

 class Queue {
 private:
 	Node* front;
 	Node* rear;

 public:
 	Queue() {
     	front = rear = NULL;
 	}

 	// Enqueue operation
 	void enqueue(int value) {
     	Node* newNode = new Node(value);

     	if (rear == NULL) {
         	front = rear = newNode;
         	return;
     	}

     	rear->next = newNode;
  	   rear = newNode;
 	}

 	// Dequeue operation
 	void dequeue() {
     	if (front == NULL) {
         	cout << "Queue is empty. Cannot dequeue." << endl;
         	return;
     	}

     	Node* temp = front;
     	front = front->next;

     	if (front == NULL) {
         	rear = NULL;
     	}

     	delete temp;
 	}

 	// Display queue
 	void display() {
     	if (front == NULL) {
         	cout << "Queue is empty." << endl;
         	return;
     	}

     	Node* temp = front;
     	cout << "Queue elements: ";
     	while (temp != NULL) {
         	cout << temp->data << " ";
         	temp = temp->next;
     	}
     	cout << endl;
 	}
 };

 int main() {
 	Queue q;

 	q.enqueue(10);
 	q.enqueue(20);
 	q.enqueue(30);

 	q.display();

 	q.dequeue();
 	q.display();

 	return 0;
 }