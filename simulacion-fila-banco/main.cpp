#include<iostream>
#include<string>

using namespace std;

struct Client {
    int id;
    string nombre;
    bool prioridad;

    Client* prev;
    Client* next;

    Client(int id, string nombre, bool prioridad) : id(id), nombre(nombre), prioridad(prioridad), prev(nullptr), next(nullptr) {}
};

class Bank{
private:
    Client* head;
    Client* tail;
    Client* current;
    int client_amount = 0;

public:
    Bank() : head(nullptr), tail(nullptr), current(nullptr), client_amount(0) {}

    void addClient(string nombre, bool priority) {

        if (head == NULL) {
            Client* nuevo = new Client(0, nombre, priority);
            head = current = tail = nuevo;
        } else if (priority == true) {
            Client* nuevo = new Client(client_amount = client_amount + 1, nombre, priority);
            head->prev = nuevo;
            nuevo->next = head;
            head = nuevo;
        } else {
            Client* nuevo = new Client(client_amount = client_amount + 1, nombre, priority);
            tail->next = nuevo;
            nuevo->prev = tail;
            tail = nuevo;
        }
    }

    void attendClient() {
        if (head == NULL) {
            cout << "No hay clientes en la lista\n";
        } else {
            head = head->next;
        }
    }

    void printQueue() {
        Client* temp = head;

        cout << "\nClientes en fila: " << endl; 

        while (temp != NULL) {
            cout << "Cliente : id ( " << temp->id << " )"
                 << " , " << temp->nombre
                 << " , Prioridad: " << ((temp->prioridad == true) ? "Si" : "No")
                 << endl;
            temp = temp->next;
        }
    }

};

int main() {
    Bank bank;
    
    bank.addClient("Juan", true);
    bank.addClient("Alberto", false);
    bank.addClient("Mateo", false);
    bank.addClient("Carlos", true);
    bank.addClient("Maria", true);
    
    int opcion;

    do {
        cout << "\n==== MENU ====\n";
        cout << "1. Atender cliente\n";
        cout << "2. Mostrar clientes restantes\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                bank.attendClient();
                break;
            case 2:
                bank.printQueue();
                break;
            case 0:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida\n";
        }

    } while(opcion != 0);

    return 0;
}