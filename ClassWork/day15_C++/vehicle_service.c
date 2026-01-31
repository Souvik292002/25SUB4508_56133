#include <stdio.h>
#include <stdlib.h>

/* ===============================
   Structure Definition
   =============================== */
struct node {
    int vehicleId;
    struct node *next;
};

/* Head pointer (start of service queue) */
struct node *head = NULL;

/* ===============================
   Function Declarations
   =============================== */
void addEmergencyVehicle(int id);
void addRegularVehicle(int id);
void addAfterVehicle(int afterId, int newId);
void removeVehicle(int id);
void searchVehicle(int id);
void displayQueue();

/* ===============================
   Main Function (Menu Driven)
   =============================== */
int main() {

    int choice, id, afterId;

    while (1) {
        printf("\n===============================");
        printf("\n Vehicle Service Management ");
        printf("\n===============================");
        printf("\n1. Add Emergency Vehicle");
        printf("\n2. Add Regular Vehicle");
        printf("\n3. Add Vehicle After Specific ID");
        printf("\n4. Remove Vehicle After Service");
        printf("\n5. Search Vehicle");
        printf("\n6. Display Service Queue");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter Vehicle ID (Emergency): ");
            scanf("%d", &id);
            addEmergencyVehicle(id);
            break;

        case 2:
            printf("Enter Vehicle ID (Regular): ");
            scanf("%d", &id);
            addRegularVehicle(id);
            break;

        case 3:
            printf("Enter Existing Vehicle ID: ");
            scanf("%d", &afterId);
            printf("Enter New Vehicle ID: ");
            scanf("%d", &id);
            addAfterVehicle(afterId, id);
            break;

        case 4:
            printf("Enter Vehicle ID to Remove: ");
            scanf("%d", &id);
            removeVehicle(id);
            break;

        case 5:
            printf("Enter Vehicle ID to Search: ");
            scanf("%d", &id);
            searchVehicle(id);
            break;

        case 6:
            displayQueue();
            break;

        case 7:
            printf("Exiting system...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

/* ===============================
   Add Emergency Vehicle
   (Insert at Beginning)
   =============================== */
void addEmergencyVehicle(int id) {

    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->vehicleId = id;
    newNode->next = head;
    head = newNode;

    printf("Emergency vehicle %d added.\n", id);
}

/* ===============================
   Add Regular Vehicle
   (Insert at End)
   =============================== */
void addRegularVehicle(int id) {

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->vehicleId = id;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Regular vehicle %d added.\n", id);
}

/* ===============================
   Add Vehicle After Specific ID
   =============================== */
void addAfterVehicle(int afterId, int newId) {

    struct node *temp = head;

    while (temp != NULL && temp->vehicleId != afterId) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Vehicle ID %d not found.\n", afterId);
        return;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->vehicleId = newId;
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Vehicle %d added after %d.\n", newId, afterId);
}

/* ===============================
   Remove Vehicle After Service
   =============================== */
void removeVehicle(int id) {

    struct node *temp = head;
    struct node *prev = NULL;

    if (head != NULL && head->vehicleId == id) {
        head = head->next;
        free(temp);
        printf("Vehicle %d removed.\n", id);
        return;
    }

    while (temp != NULL && temp->vehicleId != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Vehicle ID %d not found.\n", id);
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Vehicle %d removed.\n", id);
}

/* ===============================
   Search Vehicle
   =============================== */
void searchVehicle(int id) {

    struct node *temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->vehicleId == id) {
            printf("Vehicle %d found at position %d.\n", id, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Vehicle %d not found in queue.\n", id);
}

/* ===============================
   Display Service Queue
   =============================== */
void displayQueue() {

    struct node *temp = head;

    if (temp == NULL) {
        printf("Service queue is empty.\n");
        return;
    }

    printf("Current Service Queue:\n");

    while (temp != NULL) {
        printf("%d -> ", temp->vehicleId);
        temp = temp->next;
    }

    printf("NULL\n");
}
