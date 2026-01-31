 #include <iostream>
 using namespace std;

 class Node {
 public:
 	int data;
 	Node* prev;
 	Node* next;

 	Node(int value) {
     	data = value;
     	prev = NULL;
     	next = NULL;
 	}
 };

 class DoublyLinkedList {
 private:
 	Node* head;

 public:
 	DoublyLinkedList() {
     	head = NULL;
 	}

 	void insertEnd(int value) {
     	Node* newNode = new Node(value);

     	if (head == NULL) {
         	head = newNode;
         	return;
     	}

     	Node* temp = head;
  	   while (temp->next != NULL) {
         	temp = temp->next;
     	}

     	temp->next = newNode;
     	newNode->prev = temp;
 	}

 	void displayForward() {
     	Node* temp = head;
     	cout << "Forward Traversal: ";
     	while (temp != NULL) {
         	cout << temp->data << " ";
         	temp = temp->next;
     	}
     	cout << endl;
 	}

 	void displayBackward() {
     	Node* temp = head;
     	if (temp == NULL) return;

     	while (temp->next != NULL) {
      	   temp = temp->next;
     	}

     	cout << "Backward Traversal: ";
     	while (temp != NULL) {
         	cout << temp->data << " ";
         	temp = temp->prev;
     	}
     	cout << endl;
 	}
 };

 int main() {
 	DoublyLinkedList dll;

 	dll.insertEnd(10);
 	dll.insertEnd(20);
 	dll.insertEnd(30);
 	dll.insertEnd(40);

 	dll.displayForward();
 	dll.displayBackward();

 	return 0;
 }