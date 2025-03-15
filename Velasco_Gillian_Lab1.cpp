#include <iostream>

using namespace std;

int myArray[30];
int numElem = 0;
int maxElem = 20;

void bubbleSort(){
    int i, j;
    bool swapped;
    for(int i = 0; i < numElem - 1; i++){
        swapped = false;
        for(j = 0; j < numElem - i -1; j++){
            if(myArray[j] > myArray[j+1]){
                swap(myArray[j], myArray[j+1]);
                swapped= true;
            }
        }
        
        if(swapped == false){
            break;
        }
    }
}

int binarySearch(int num, int lowest, int highest){
    while(lowest <= highest){
        int middle = lowest + ((highest - 1) /2);

        if(myArray[middle] == num){
            return middle;
        }
        
        if(myArray[middle] < num){
            lowest = middle + 1;
        }else{
            highest = middle - 1;
        }
    }
    return -1;
}

void traverseArray(){
    cout << "\nShowing elements in my array.\n";
    for(int i = 0; i< numElem; i++)
        cout << to_string(myArray[i]) + "|";
    }

string insertAtTheEnd(int num){
    if(numElem != maxElem){
        myArray[numElem] = num;
        numElem++;
        return "\nAn element is sucessfully inserted at the end!\n";
    }
    
    return "\nThe array is full. Please remove elements before inserting new one.\n";
}

string insertAtTheBeginning(int num){
    if(numElem != maxElem){
        for(int i = numElem; i >= 0; i--)
            myArray[i+1] = myArray[i];
        }
        
        myArray[0] = num;
        numElem++;
        return "\nAn element is sucessfully inserted at the beginning!\n";
    
    return "\nThe array is full. Please remove elements before inserting new one.\n";
}

string insertAtTheGivenPosition(int num, int ElementAfter){
    bubbleSort();
    int position = binarySearch(ElementAfter, 0, maxElem);
    if (position == -1){
        return "\nElement after which to insert not found.\n";
    }
    if (numElem == maxElem){
        return "The array if full. Please remove elements before inserting a new one.\n";
    }
    for (int i = numElem; i > position + 1; i--){
        myArray[i] = myArray [i - 1];
    }
    myArray [position + 1] = num;
    numElem ++;
    return  "\nAn element is successfully inserted at the specific position.\n";
}

string insertAtSortedArray(int num){
    if(numElem != maxElem){
        int position;
        for(int i = 0; i < numElem; i++){
            if(num < myArray[i]){
                position = i;
                break;
            }
        }
        
        for(int i = numElem; i>=position; i--){
            myArray[i+1] = myArray[i];
        }
        
        myArray[position] = num;
        numElem++;
        return "\nAn element is successfully inserted at a sorted array! \n";
    }
    
    return "\nThe array is full. Please remove elements before inserting new one. \n";
}

string deleteFromTheEnd(){
    if(numElem != 0){
        numElem--;
        return "\nAn element has been deleted from the end!\n";
    }
    return "\nThe array is underflow! Delete is not possible";
}

string deleteFromTheBeginning(){
    if(numElem != 0){
        for(int i = 0; i <= numElem; i++){
        myArray[i] = myArray[i+1];
        }
        numElem--;
        return "\nAn element has been deleted from the beginning!\n";
    }
    return "\nThe array underflow! Delete is not possible.\n";
}

string deleteFromTheGiven(int element){
    if(numElem != 0){
        int index;
        for(int i = 0; i <= numElem; i++){
            if(myArray[i] == element){
                index = i;
                break;
            }
        }
    
        for(int i = index; i <= numElem; i++){
            myArray[i] = myArray[i+1];
        }
            numElem--;
            return to_string(element) + "\nhas been deleted!\n";
        }
    
        return "\nThe array is underflow! Delete is not possible.\n";
}

int main(){
    
    cout << insertAtTheBeginning(3);
    traverseArray();
    cout << insertAtTheEnd(7);
    traverseArray();
    cout << insertAtTheEnd(9);
    traverseArray();
    cout << insertAtTheBeginning(20);
    traverseArray();
    cout << insertAtTheGivenPosition(37,7);
    traverseArray();
    cout << insertAtTheBeginning(256);
    traverseArray();
    cout << insertAtTheGivenPosition(128,9);
    traverseArray();
    cout << insertAtTheBeginning(19);
    traverseArray();
    
    cout << insertAtSortedArray(3);
    cout << insertAtSortedArray(30);
    cout << insertAtSortedArray(38);
    cout << insertAtSortedArray(19);
    traverseArray();

    cout << deleteFromTheBeginning() << endl;
        traverseArray();
    cout << deleteFromTheBeginning() << endl;
        traverseArray();
    cout << deleteFromTheEnd() << endl;
        traverseArray();
    cout << deleteFromTheEnd() << endl;
        traverseArray();
    cout << deleteFromTheGiven(7) << endl;
        traverseArray();
    cout << deleteFromTheGiven(9) << endl;
        traverseArray();

    cout << endl;
    cout << binarySearch(20, 0, numElem) << endl;
    cout << binarySearch(38, 0, numElem) << endl;

    return 0;
}
