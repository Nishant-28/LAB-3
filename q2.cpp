#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

void insertionSort(int arr[], int n) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

int main() {

  int option;
  int n = 500; 
  int arr[n];

  while(true) {

    cout << "MAIN MENU (INSERTION SORT)" << endl;
    cout << "1. Ascending Data" << endl;
    cout << "2. Descending Data" << endl; 
    cout << "3. Random Data" << endl;
    cout << "4. Exit" << endl;

    cout << "Enter option: ";
    cin >> option;

    switch(option) {
      case 1: {
        // Read ascending data
        ifstream in("inAsce.dat");
        for(int i=0; i<n; i++) {
          in >> arr[i];
        }
        
        // Sort
        int comparisons = 0;
        insertionSort(arr, n);
        
        // Count comparisons
        for(int i=1; i<n; i++) {
          comparisons += i;
        }

        // Output sorted data
        ofstream out("outInsAsce.dat");
        for(int i=0; i<n; i++) {
          out << arr[i] << " ";  
        }
        out.close();

        cout << "Number of Comparisons: " << comparisons << endl;
        cout << "Scenario: Best case" << endl;
        break;
      }
      
      case 2: {
        // Read descending data
        ifstream in("inDesc.dat");
        for(int i=n-1; i>=0; i--) {
          in >> arr[i]; 
        }

        // Sort        
        int comparisons = 0;
        insertionSort(arr, n);
        
        // Count comparisons
        for(int i=1; i<n; i++) {
          comparisons += i;
        }

        // Output sorted data  
        ofstream out("outInsDesc.dat");
        for(int i=0; i<n; i++) {
          out << arr[i] << " ";
        }
        out.close();
        
        cout << "Number of Comparisons: " << comparisons << endl;
        cout << "Scenario: Worst case" << endl;        
        break;
      }
      
      case 3: {
        // Generate random data
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 99);
        for(int i=0; i<n; i++) {
          arr[i] = dis(gen);
        }

        // Sort
        int comparisons = 0;
        insertionSort(arr, n);
        
        // Count comparisons        
        for(int i=1; i<n; i++) {
          comparisons += i;
        }

        // Output sorted data
        ofstream out("outInsRand.dat");
        for(int i=0; i<n; i++) {
          out << arr[i] << " ";
        }
        out.close();

        cout << "Number of Comparisons: " << comparisons << endl;
        cout << "Scenario: Average case" << endl;        
        break; 
      }
      
      case 4:
        exit(0);
        
      default:
        cout << "Invalid option" << endl;
    }
  }

  return 0;
}
