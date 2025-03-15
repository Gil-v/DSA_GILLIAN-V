#include <iostream>
using namespace std;

typedef struct Node {
    string songName;
    string artistName;
    Node* link;
} Node;

Node* createNode(string song, string artist);

void traverse(Node* head) {
    if (head == NULL) {
        cout << "The list is empty." << endl; //comment
        return;
    }

    Node* temp = head;
    cout << "\nMy Playlist: \n" << endl;
    do {
        cout << temp->songName << " by " << temp->artistName << " -> ";
        temp = temp->link;
    } while (temp != head);

    cout << "(Back to start)" << endl;
}

Node* createNode(string song, string artist) {
    Node* newNode = new Node;
    newNode->songName = song;
    newNode->artistName = artist;
    newNode->link = newNode;
    return newNode;
}

Node* insertAtEnd(string song, string artist, Node* head) {
    if (head == NULL) {
        head = createNode(song, artist);
        cout << "A new node has been inserted at the end (as the first node)." << endl;
        return head;
    }

    Node* temp = head;
    while (temp->link != head) {
        temp = temp->link;
    }

    Node* newNode = createNode(song, artist);
    temp->link = newNode;  
    newNode->link = head;  

    cout << "A new node has been inserted at the end. \n" << endl;
    return head;
}

Node* insertAtBeginning(string song, string artist, Node* head) {
    Node* newNode = createNode(song, artist);

    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
   
    while (temp->link != head) {
        temp = temp->link;
    }

    temp->link = newNode;
    newNode->link = head;  

    cout << "A new node has been inserted at the beginning. \n" << endl;
    return newNode;  
}

string insertAfter(string afterSong, string song, string artist, Node* head) {
    if (head == NULL) {
        return "No songs in the playlist.";
    }

    Node* temp = head;
    do {
        if (temp->songName == afterSong) {
            Node* newNode = createNode(song, artist);
            newNode->link = temp->link;
            temp->link = newNode;
            return "A new node has been added after " + afterSong;
        }
        temp = temp->link;
    } while (temp != head);

    return "Song not found to insert after.";
}

string deleteAtEnd(Node* head) {
    if (head == NULL) {
        return "The linked list is empty.";
    }

    Node* temp = head;
    if (temp->link == head) {
        delete temp;
        return "The last node (head) has been deleted.";
    }

    while (temp->link->link != head) {
        temp = temp->link;
    }

    Node* lastNode = temp->link;
    temp->link = head;
    delete lastNode;

    return "A node has been deleted from the end.";
}

Node* deleteFromBeginning(Node* head) {
    if (head == NULL) {
        cout << "The linked list is empty." << endl;
        return NULL;
    }

    if (head->link == head) {
        delete head;
        return NULL;
    }

    Node* temp = head;
    while (temp->link != head) {  
        temp = temp->link;
    }

    Node* oldHead = head;
    head = head->link;
    temp->link = head;  
    delete oldHead;
    return head;
}

Node* deleteFromGivenNode(string givenNode, Node* head) {
    if (head == NULL) {
        cout << "The linked list is empty." << endl;
        return NULL;
    }

    Node* temp = head;
    if (head->songName == givenNode) {
        head = deleteFromBeginning(head);
        return head;
    }

    while (temp->link != head && temp->link->songName != givenNode) {
        temp = temp->link;
    }

    if (temp->link == head) {
        cout << "No such song found." << endl;
        return head;
    }

    Node* nodeToDelete = temp->link;
    temp->link = temp->link->link;  
    delete nodeToDelete;

    cout << "The song '" << givenNode << "' has been deleted." << endl;
    return head;
}

int main() {
    Node* head = createNode("Sanctuary by Joji", "Joji");
    head = insertAtEnd("Next to You by Chris Brown", "Chris Brown", head);
    head = insertAtEnd("Rock with You by Michael Jackson", "Michael Jackson", head);
    head = insertAtEnd("Airplanes by JHIN", "JHIN", head);

    head = insertAtBeginning("Hayaan mo Sila by Ex Batallion & Flow G.", "Ex Batallion & Flow G.", head);
    head = insertAtBeginning("BonFire by James Reid", "James Reid", head);
    head = insertAtBeginning("Kaya Pala by Patch Quiwa", "Patch Quiwa", head);
    head = insertAtBeginning("Heavenmade by JHIN", "JHIN", head);

    cout << insertAfter("Blue Butterflies by JHIN", "Estranghero by Cup of Joe", "Cup of Joe", head) << endl;
    cout << insertAfter("Estranghero by Cup of Joe", "Patutunguhan by Cup of Joe", "Cup of Joe", head) << endl;
    cout << insertAfter("Patutunguhan by Cup of Joe", "Ikaw At Ako by TJ Monterde", "TJ Monterde", head) << endl;

    cout << deleteAtEnd(head) <<endl;
    head = deleteFromBeginning(head);
    head = deleteFromGivenNode("Simula Pa Nung Una by Patch Quiwa", head);
   
    traverse(head);

    return 0;
    
}
