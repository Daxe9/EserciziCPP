#include <random>
#include <iostream>
#include <vector>

void printMenu() {
  std::cout << "a - inserisce N numeri in un array (senza utilizzare funzioni)\n"; 
  std::cout << "b - stampi l'array (senza utilizzare funzioni)\n"; 
  std::cout << "c - ordini l'array attraverso il Bubble Sort utilizzando una funzione che SCAMBIA DUE VARIABILI\n"; 
  std::cout << "Inserisci il tuo commando: ";
}

void swap(int *a, int *b) {
	int k = *a;
	*a = *b;
	*b = k;
}

void bubbleSort(std::vector<int> &vec) {
	bool swapped;
	do {
		swapped = false;
		for(int i = 0; i < vec.size() - 1; ++i) {
			if (vec.at(i) > vec.at(i+1))	 {
				swapped = true;
				swap(&vec.at(i), &vec.at(i+1));
			}	
		}
	}while(swapped);
}

int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    std::vector<int> vec;
    char c;
		int N;
   
    do {
        printMenu();
				std::cin >> c;
				switch(c) {
					case 'a':
					case 'A':
						std::cout << "Quanti numeri vuoi nell'array: ";
						std::cin >> N;
						vec.clear();
						vec.reserve(N);
						for(int i = 0; i < N; ++i) {
							vec.push_back(dist(mt));
						}
						std::cout << "Array filled.\n";
						break;
					case 'b':
					case 'B':
						for(int &i : vec) {
							std::cout << i << " ";
						}
						std::cout << "\n";
						break;
					case 'c':
					case 'C':
						std::cout << "Bubble sort:\n";
						bubbleSort(vec);
						break;
					case 'x':
					case 'X':
						std::cout << "Uscita.\n";
						break;
					default:
						std::cout << "Invalid\n";
				}
    }while(c != 'x' && c != 'X');
    return 0;
}
