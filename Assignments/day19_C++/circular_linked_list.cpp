

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

 class CircularLinkedList {
 private:
 	Node* head;

 public:
 	CircularLinkedList() {
     	head = NULL;
 	}

 	// Insert node at the end
 	void insertEnd(int value) {
     	Node* newNode = new Node(value);

     	if (head == NULL) {
         	head = newNode;
         	newNode->next = head;
         	return;
     	}

         Node* temp = head;
     	while (temp->next != head) {
         	temp = temp->next;
     	}

     	temp->next = newNode;
     	newNode->next = head;
 	}

 	// Display the list
 	void display() {
     	if (head == NULL) {
         	cout << "List is empty." << endl;
         	return;
     	}

     	Node* temp = head;
     	cout << "Circular Linked List: ";
     	do {
         	cout << temp->data << " ";
         	temp = temp->next;
     	} while (temp != head);
   	  cout << endl;
 	}
 };

 int main() {
 	CircularLinkedList cll;

 	cll.insertEnd(10);
 	cll.insertEnd(20);
 	cll.insertEnd(30);
 	cll.insertEnd(40);

 	cll.display();

 	return 0;
 }



