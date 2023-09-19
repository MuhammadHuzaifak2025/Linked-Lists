#include <iostream>
using namespace std;

// Define a class for a node in the linked list
class Node 
{
	public:
		int data;
    	Node* next;
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
    if (currentPosition < position - 1) {
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
    static bool search(int key, Node* head) 
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

    // Reverse the linked list
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
	
	    // The new head is the previous node (which was the last node in the original list)
	    head=previous;
	    cout<<"List has been reversed."<<endl;
	    return head;
	}
	
	Node* concatenate(Node* node1, Node* node2)
	{
		if (!node1) // Usecase for when first list is empty
		{
	        return node2; 
	    }
	    
	    Node* current = node1; //curent points at node1
	    
	    while (current->next!=NULL) //until curent->next reaches the end
	    {
	    	current=current->next; //current traverses
		}
	    
	    current->next=node2; //current points at node2 //tail of node1 points at head of node2
	    
	    node2=NULL; //node2 is rendered NULL to lead it empty so that node1 has node1 and node2
	    
	    return node1; 
}

int main() 
{
    Node* head = NULL; // Initialize an empty head List called head
    Node* node1 = NULL; // Initialize an empty head List called node1
    Node* node2 = NULL; // Initialize an empty head List called node2
    int position;
    int choice;        
    while (true) //Infinite loop
	{
        cout << "Your head List right now is: ";
        displayList(head);
        cout << "What do you want to do with this head List?" << endl;
        cout << "1: Insert at the beginning." << endl;
        cout << "2: Insert at the end." << endl;
        cout << "3: Insert at a specified space." << endl;
        cout << "4: Display Linked List." << endl;
        cout << "5: Delete Node." << endl;
        cout << "6: Search for a value." << endl;
        cout << "7: Reverse the linked list." << endl;
        cout << "8: Concatenate Lists" << endl;
        cout << "9: Insert Beginning List 1" << endl;
        cout << "10: Insert Beginning List 2" << endl;
        cout << "11: Display List 1" << endl;
        cout << "12: Display List 2" << endl;
        cout << "13: Display Concatenated List" << endl;
        cout << "14: Exit." << endl;
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
                reverse(head);
                cout << "Linked List has been reversed." << endl;
                cout << "Linked List has been reversed." << endl;
    			displayList(head); // Display the reversed list
                break;
            
            case 8:
	                 // Concatenate Lists
	                node1 = concatenate(node1, node2);
	                node2 = NULL;
	                cout << "Lists concatenated." << endl;
	                break;
				
			case 9:
					 // Insert at beginning of First Node
	                int data2;
	                cout << "Enter Data to insert at the Beginning: ";
	                cin >> data;
	                node1 = insertAtBeginning(node1, data);
	                break;
	                
	        case 10:
	            	  // Insert at beginning of First Node
	                int data3;
	                cout << "Enter Data to insert at the Beginning: ";
	                cin >> data;
	                node2 = insertAtBeginning(node2, data);
	                break;    
				
	        case 11:
	                // Display List 1
	                cout << "List 1: ";
	                displayList(node1);
	                break;
	
	        case 12:
	                // Display List 2
	                cout << "List 2: ";
	                displayList(node2);
	                break;
	
	        case 13:
	                // Display Concatenated List
	                cout << "Concatenated List: ";
	                displayList(node1);
	                break;
	                
            case 14:
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
