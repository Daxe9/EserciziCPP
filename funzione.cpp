/*
Il programma permette di fare tre operazioni diverse selezionabili con un menu:
a - il programma trova il maggiore di N numeri inseriti dall'utente
b - il programma trova il minimo comune multiplo tra due numeri inseriti dall'utente
c - il programma stampa tutti i numeri primi da 2 a N (N è un numero maggiore di 2 scelto dall'utente)
d - il programma esegue la moltiplicazione di due numeri attraverso le somme
e- il programma esegue l'elevamento a potenza attraverso la funzione precedente
f - il programma converte in binario un numero decimale N inserito dall'utente (N positivo)
g - il programma converte in decimale un numero N inserito dall'utente (il numero N deve essere composto solo da 1 e 0)

Sviluppare il programma utilizzando le funzioni, e in particolare:
- una funzione che stampi io menù e ritorni la scelta dell'utente
- una funzione che controlli che il numero inserito dall'utente sia maggiore di una certa soglia
- una funzione che ritorni il numero maggiore tra DUE numeri inseriti
- una funzione che utilizzi la precedente per trovare il massimo tra N numeri inseriti
- una funzione che trovi il mcm tra due numeri passati come parametro
- una funzione che ritorni true o false a seconda se il numero passato come parametro è primo o no
- una funzione che stampa tutti i numeri primi fino a N (passato come parametro)
- una funzione che ritorni la conversione binaria di un numero decimale passato come parametro
- una funzione che ritorni la conversione decimale di un numero binario passato come parametro
AGGIUNTA: è possibile riscrivere le ultime due funzioni in modo da convertire da decimale ad una qualsiasi altra base (Passata come parametro) e viceversa?
*/
#include <iostream>
#include <cmath>
using namespace std;

void printMenu() {
    cout << "a - trova il maggiore di N numeri inseriti dall'utente\n";
    cout << "b - trova il minimo comune multiplo tra due numeri inseriti dall'utente\n";
    cout << "c - stampa tutti i numeri primi da 2 a N (N è un numero maggiore di 2 scelto dall'utente)\n";
    cout << "d - moltiplica due numeri attraverso le somme\n";
    cout << "e - eleva un numero a potenza attraverso la funzione precedente\n";
    cout << "f - converte in binario un numero decimale N inserito dall'utente (N positivo)\n";
    cout << "g - converte in decimale un numero N inserito dall'utente (il numero N deve essere composto solo da 1 e 0)\n";
    cout << "Inserisci il carattere identificativo\n";
}


int findTheMaxNumber() {
    int max = 0;
    int number;
    cout << "Inserisci il numero di interi da controllare: ";
    cin >> number;
    
    if (number < 0) {
        cout << "Il numero deve essere positivo\n";
        cin >> number;    
    }
    for (int i = 0; i < number; i++) {
        int temp;
        cout << "Inserisci il numero " << i + 1 << ": ";
        cin >> temp;
        if (temp > max) {
            max = temp;
        }
    }
    return max;
}

int findLeastCommonMultipler() {
    int a, b;
    cout << "Inserisci il primo numero: ";
    cin >> a;
    cout << "Inserisci il secondo numero: ";
    cin >> b;
    int mcm = 1;
    for (int i = 1; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0) {
            mcm = i;
            break;
        }
    }
    return mcm;
} 

int convertToBinary(int number) {
    int binary = 0;
    int i = 0;
    while (number > 0) {
        binary += number % 2 * pow(10, i);
        number /= 2;
        i++;
    }
    return binary;
}

int convertToDecimal(int binary) {
    int decimale = 0;
    int i = 0;
    while (binary > 0) {
        decimale += binary % 10 * pow(2, i);
        binary /= 10;
        i++;
    }
    return decimale;
}

void findPrimeNumber(int n) {
    int count = 0;
    for (int i = 2; i <= n; i++) {
        bool isPrime = true;
        for(int j = 2; j < i; ++j) {
            if(i % j == 0) {
                isPrime = false;
            }
        }
        if(isPrime) {
            cout << i << " ";
        }
    }
}

int multiplication(int a, int b) {
    int sum = 0;
    for (int i = 0; i < b; i++) {
        sum += a;
    }
    return sum; 
}

bool validateBinaryNumber(int n) {
    bool valid = true;
    while (n > 0 && valid) {
        if(n % 10 > 1) {
            valid = false;
        }
        n /= 10;
    }

    return valid;
}

int power(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++) {
        result = multiplication(result, a);
    }
    return result;
}

int main() {
    char c;
    int n1, n2;
    do {
        printMenu();
        cin >> c;
        switch (c) {
            case 'a':
                cout << "a:\n";
                cout << findTheMaxNumber() << endl;
                break;
            case 'b':
                cout << "b:\n";
                cout << findLeastCommonMultipler() << endl;
                break;
            case 'c':
                cout << "Inserisci un numero maggiore di 2: ";
                cin >> n1;
                findPrimeNumber(n1);
                cout << "c:\n";
                break;
            case 'd':
                cout << "d:\n";
                cout << "Inserisci un numero: ";
                cin >> n1;
                cout << "Inserisci un'altro numero: ";
                cin >> n2;
                cout << multiplication(n1, n2) << endl;
                break;
            case 'e':
                cout << "e:\n";
                cout << "Inserisci un numero: ";
                cin >> n1;
                if(n1 < 0) {
                    cout << "Errore, inserisci un numero positivo: ";
                    cin >> n1;
                }
                cout << "Inserisci un'altro numero: ";
                cin >> n2;
                if(n2 < 0) {
                    cout << "Errore, inserisci un numero positivo: ";
                    cin >> n1;
                }
                cout << power(n1, n2) << endl;
                break;
            case 'f':
                cout << "f:\n";
                cout << "Inserisci un numero decimale: ";
                cin >> n1;
                cout << convertToBinary(n1) << endl;
                break;
            case 'g':
                cout << "g:\n";
                cout << "Inserisci un numero binario: ";
                cin >> n1;
                while (!validateBinaryNumber(n1)) {
                    cout << "Errore, inserisci un numero binario: ";
                    cin >> n1;
                }
                cout << convertToDecimal(n1) << endl;
                break;
            case 'x':
                cout << "Uscita.\n";
                break;
            default:
                cout << "carattere non valido\n";
                break;
        }
    }while(c != 'x' && c != 'X');
    return 0;
}