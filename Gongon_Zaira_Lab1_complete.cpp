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
        for(j = 0; j < numElem - i - 1; j ++){
            if(myArray[j] > myArray[j + 1]){
                swap(myArray[j], myArray[j + 1]);
                swapped = true;
            }
        }
    
        if(swapped == false){
            break;
        }
    }
}

void traverseArray(){
    cout << "Showing elements in my array! \n";
    for(int i = 0; i < numElem; i++){
        cout << to_string(myArray[i]) + " | ";
    }
    cout << "\n";
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



string insertAtTheEnd(int num){
    if(numElem != maxElem){
        myArray[numElem] = num;
        numElem++;
        return "An element is successfully inserted at the end! \n";
    }
    return "The array is full. Please remove elements before inserting new one. \n";
}

string insertAtTheBeginning(int num){
    if(numElem != maxElem){
        for(int i = numElem; i >= 0; i--){
            myArray[i + 1] = myArray[i];
        }
        myArray[0] = num;
        numElem++;
        return "An element is successfully inserted at the beginning! \n";
    }
    return "The array is full. Please remove elements before inserting new one. \n";
}

string insertAtTheGivenPosition(int num, int ElementAfter){
    if(numElem != maxElem){
        int position = binarySearch (ElementAfter, 0, numElem);
        /* for(int i = 0; i <= maxElem; i++){
            if(myArray[i] == ElementAfter){
                position = i;
                break;
            }
        } */
        
        for(int i = numElem; i>=position; i--){
            myArray[i+1] = myArray[i];
        }
        myArray[position + 1] = num;
        numElem++;
        return "An element is successfully inserted at the given position! \n";
    }
    return "The array is full. Please remove elements before inserting new one. \n";
}

string insertAtSortedArray(int num){
    if(numElem != maxElem){
        bubbleSort();
        int position;
        for(int i = 0; i < numElem; i++){
            if(num < myArray[i]){
                position = i;
                break;
            }
        }
        
        for(int i = numElem; i >= position; i--){
            myArray[i + 1] = myArray[i];
        }
        
        myArray[position] = num;
        numElem++;
        return "An element is succesfully inserted in a sorted aray! \n";
    }
    
    return "The array is full. Please remove elements before inserting new one. \n";
}

string deleteFromTheEnd(){
    if(numElem != 0){
        numElem--;
        return "An element has been deleted from the end! \n";
    }
    return "The array is underflow! Delete is not possible. \n";
}

string deleteFromTheBeginning(){
    if(numElem != 0){
        for(int i = 0; i <= numElem; i++){
            myArray[i] = myArray[i+1];
        }
        numElem--;
        return "An element has been deleted from the beginning! \n";
    }
    return "The array is underflow! Delete is not possible. \n";
}

string deleteFromGivenElement(int element){
    if(numElem != 0){
        int index = binarySearch (element, 0, numElem);
        /* for(int i = 0; i <= numElem; i++){
            if(myArray[i] == element){
                index = i;
                break;
            }
        } */
        
        for(int i = index; i <= numElem; i++){
            myArray[i] = myArray[i+1];
        }
        numElem--;
        return to_string(element) + " has been deleted!";
    }
    return "The array is underflow! Delete is not possible. \n";
}

int main() {
    
    cout << insertAtTheBeginning(3);
    cout << insertAtTheEnd(7);
    cout << insertAtTheEnd(9);
    cout << insertAtTheBeginning(20);
    cout << insertAtTheGivenPosition(38,7);
    cout << insertAtTheBeginning(256);
    cout << insertAtTheGivenPosition(128,9);
    cout << insertAtTheBeginning(19);
    
    traverseArray();
    cout << endl;
    
    cout << insertAtSortedArray(1);
    cout << insertAtSortedArray(54);
    cout << insertAtSortedArray(86);
    cout << insertAtSortedArray(94);

    
    traverseArray();
    bubbleSort();
    cout << endl;
    
    cout << deleteFromTheBeginning();
    traverseArray();
    cout << endl;
    cout << deleteFromTheBeginning();
    traverseArray();
    cout << endl;
    cout << deleteFromTheEnd();
    traverseArray();
    cout << endl;
    cout << deleteFromTheEnd();
    traverseArray();
    cout << endl;
    cout << deleteFromGivenElement(7);
    traverseArray();
    cout << endl;
    cout << deleteFromGivenElement(54);
    traverseArray();
    cout << endl;
    
    
    cout << binarySearch(9, 0, numElem);
    cout << endl;
    cout << binarySearch(7, 0, numElem);
    cout << endl;
    traverseArray();
    return 0;
}

