#include <iostream>
using namespace std;

// Define a class for a node in the linked list
class Node 
{
	public:
		int data;
    	Node* next;
    	
    	Node()
    	{
    		data=0;
    		next=NULL;
		}
};

// Creating Node
Node* createNode(int data) 
{
    Node* newNode = new Node; //Initializing a Node
    newNode->data = data; //Node points to Data
    newNode->next = NULL; //Node now points to the next position, which is initialized as NULL
    return newNode;
}

// Inserting Node At Beginning
Node* insertAtBeginning(Node* linked, int data) 
{
    Node* newNode = createNode(data); //Node is created with an initial data, and points to a NULL position
    newNode->next = linked;
    return newNode;
}

// Inserting Nodes at Any Position
Node* insertAtPosition(Node* head, int data, int position) 
{
    if (position < 1) //there is no position lesser than 1
	{
        cout << "Invalid position." << endl;
        return head;
    }

    if (position == 1 || head == NULL) // If the position is 1 or the list is empty, insert at the beginning
	{
        Node* newNode = createNode(data); //New Node created
        newNode->next = head; //
        return newNode;
    }

    Node* current = head;
    int currentPosition = 1;

    while (currentPosition < position - 1 && current->next != NULL) // Traverse the list to find the node immediately before the desired position
	{
        current = current->next;
        currentPosition++;
    }

    // Check if the position is valid
    if (currentPosition < position - 1) 
	{
        cout << "Position is out of bounds." << endl;
        return head;
    }

    // Create a new node with the data
    Node* newNode = createNode(data);

    // Insert the new node at the specified position
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

// Inserting Nodes At End
Node* insertAtEnd(Node* head, int data) 
{
    Node* newNode = createNode(data);

    if (head == NULL) 
	{
        return newNode; // If the list is empty, the new node becomes the head
    }

    Node* current = head;
    while (current->next != NULL) 
	{
        current = current->next; //Current Node will now point to next node
    }
    current->next = newNode;
    return head;
}

// Deleting Nodes
Node* deleteNode(Node* head, int data) 
{
    if (head == NULL) 
	{
        return NULL; // If the list is empty, nothing to delete
    }

    if (head->data == data) //if the head node pointing at data has the same data as the same input given
	{
        Node* temp = head; //New node created to store head's data
        head = head->next; //head can now point towards the next space in the List
        delete temp;//The temp node is deleted
        return head;
    }

    Node* current = head; //Current Node created to store head's data
    while (current->next != NULL && current->next->data != data) //checks if there is another node and if the data is the same as the input data
	{
        current = current->next; //Current Node will now point to next node
    }

    if (current->next != NULL) //if the next node is not the end
	{
        Node* temp = current->next; //New node created to store next node's data
        current->next = current->next->next; //Next node skipped by adjusting Current Node
        delete temp;
    }

    return head;
}

// Deleting Node at head
Node* deleteHeadNode(Node* head, int data) 
{
    if (head != NULL) //if head is not at end
	{
	    Node* temp = head; //Create a temporary pointer
	    head = head->next; //Update the head to the next node
	    delete temp; //Delete the old head node
	} 
	else //No head node (No list)
	{    
	    cout << "List is empty. No head node to delete." << endl;
	}

}

Node* listBubbleSort(Node* head) 
{
    if (!head || !head->next) //if head doesn't exist or has only one element
	{
        return head; 
    }

    bool swapped; //created swapped bool just like in normal bubble sort
    Node* current; //current Node created
    Node* last = NULL; //last node created which has no value

    do 
	{
        swapped = false; //intitialized with false to implement sorting
        current = head; //current has head
        while (current->next != last)  //until current's next pointer is at last
		{
            if (current->data > current->next->data) //if the current data is smaller than the right most data
			{
                // Swap nodes
                int temp = current->data; //do the same thing as in normal sorting //temp will have the current data
                current->data = current->next->data; //current data will now have the next data
                current->next->data = temp; //next data will have the temp data
                
                if (current == head)
                {
                	head->data= temp;
				}
				swapped = true;
            }
            current = current->next; //current traverses
        }
        last = current; //last will have the current data
    } while (swapped); //until swapped is false //until all the data is sorted

    return head;
}

// Display head List
void displayList(Node* head) 
{
    Node* current = head; 
    while (current != NULL) //until current pointer points to a NULL space, meaning no data, (List doesn't exist there)
	{
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Search for a value in the linked list
bool search(int key, Node* head) 
{
    Node* temp = head;
    while (temp != NULL) 
	{
        if (temp->data == key) 
		{
            cout << "Match Found." <<endl;
            return true;
        }
        temp = temp->next;
    }
    cout << "Match Not Found." <<endl;
    return false;
}

Node* reverse(Node* head) 
{
    Node* current = head;
    Node* next = NULL;
    Node* previous = NULL;

    while (current != NULL) 
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    head = previous;

    cout << "List has been reversed." << endl;
    return head;
}

bool searchPosition(int position, Node* head) 
{
    if (position < 1) 
    {
        cout << "Invalid position." << endl;
        return false; // Return false to indicate position error
    }
    
    if (head == NULL) 
    {
        cout << "List is empty." << endl;
        return false; // Return false to indicate an empty list
    }
    
    Node* current = head;
    int currentPosition = 1;
    
    while (currentPosition < position && current != NULL) //until current position is at position we want and current pointre is not at end
    {
        current = current->next; //current traverses
        currentPosition++; //Current Position increments
    }

    if (currentPosition == position && current != NULL) //if current position is at position we want and current is at end
    {
        cout << "Item at position " << position << ": " << current->data << endl; //print out the position's data
        return true;
    }

    cout << "Position is out of bounds." << endl;
    return false;
}

int main() 
{
    Node* head = NULL; // Initialize an empty head List called head
    int position;
    int choice;        
    while (true) //Infinite loop
	{
        cout << "Your Singly List right now is: ";
        displayList(head);
        cout << "What do you want to do with this head List?" << endl;
        cout << "1: Insert at the beginning." << endl;
        cout << "2: Insert at the end." << endl;
        cout << "3: Insert at a specified space." << endl;
        cout << "4: Display Linked List." << endl;
        cout << "5: Delete Node." << endl;
        cout << "6: Search for a value." << endl;
        cout << "7: Reverse the linked list." << endl;
        cout << "8: Delete Head Node." << endl;
        cout << "9: Sort in Ascending Order." << endl;
        cout << "10: Exit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1: 
            	//Insertion At Beginning
                int data;
                cout << "Enter Data to insert at the Beginning: ";
                cin >> data;
                head = insertAtBeginning(head, data);
                break;
            
            case 2: 
            	//Insertion At End
                cout << "Enter Data to insert at the End: ";
                cin >> data;
                head = insertAtEnd(head, data);
                break;
            
            case 3: 
            	//Insertion At Specified Space
                cout << "Enter Data to insert: ";
                cin >> data;
                cout <<"Enter the Position at which to insert: ";
                cin >>position;
                head = insertAtPosition(head, data, position);
                break;
            case 4:
                cout << "head List: ";
                displayList(head);
                break;
                
            case 5: 
            	//Data Deletion
                cout << "Enter Data to delete: ";
                cin >> data;
                head = deleteNode(head, data);
                break;
            
            case 6:
                // Search for a value
                cout << "Enter value to search: ";
                cin >> data;
                search(data, head);
                break;
            
            case 7:
                // Reverse the linked list
                head=reverse(head);
                cout << "Linked List has been reversed." << endl;
                cout << "Linked List has been reversed." << endl;
    			displayList(head); // Display the reversed list
                break;
            
            case 8: 
            	//Head Node Deletion
                deleteHeadNode(head, data);
                break;
            
            case 9:
            	//Linked List Bubble Sort
                cout << "Linked list after sorting is:" << endl;
                head = listBubbleSort(head);
                displayList(head);
                break;

            
            case 10:
                // Delete the entire linked list to free memory
                while (head != NULL) 
                {
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                }
                // Exit Program
            default:
                cout << "Invalid Choice."<<endl<<"Please try again." << endl;
        }
    }

}

