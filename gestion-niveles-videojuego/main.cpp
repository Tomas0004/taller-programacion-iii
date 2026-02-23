#include <iostream>
#include <string>

using namespace std;


struct Level {
    int numero;
    string nombre;
    string dificultad;

    Level* next;
    Level* prev;

    Level(int num, string nom, string dif) {
        numero = num;
        nombre = nom;
        dificultad = dif;
        next = NULL;
        prev = NULL;
    }
};


class Game {
private:
    Level* head;
    Level* tail;
    Level* current;

public:
    Game() {
        head = tail = current = NULL;
    }

    void addLevel(int num, string nom, string dif) {
        Level* nuevo = new Level(num, nom, dif);

        if (head == NULL) {
            head = tail = current = nuevo;
        } else {
            tail->next = nuevo;
            nuevo->prev = tail;
            tail = nuevo;
        }
    }

    void nextLevel() {
        if (current != NULL && current->next != NULL) {
            current = current->next;
            cout << "Ahora estas en: " << current->nombre << endl;
        } else {
            cout << "No hay siguiente nivel.\n";
        }
    }

    void previousLevel() {
        if (current != NULL && current->prev != NULL) {
            current = current->prev;
            cout << "Ahora estas en: " << current->nombre << endl;
        } else {
            cout << "No hay nivel anterior.\n";
        }
    }

    void printLevels() {
        Level* temp = head;

        while (temp != NULL) {
            cout << "Nivel " << temp->numero
                 << " | " << temp->nombre
                 << " | Dificultad: " << temp->dificultad
                 << endl;
            temp = temp->next;
        }
    }

    void showCurrent() {
        if (current != NULL) {
            cout << "\nNivel actual:\n";
            cout << "Nivel " << current->numero
                 << " | " << current->nombre
                 << " | Dificultad: " << current->dificultad
                 << endl;
        }
    }

    Level getLast() {
        Level* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        return *temp;
    }
};

class Presenter {
public:
    Game juego;

    Presenter(Game juego) {
        this->juego = juego;
    };

    void addLevel () {
        cout << "\nEscriba el nombre del nivel: ";
        string name;

        getline(cin, name);
        getline(cin, name);

        cout << "\nEscoja la dificultad del nivel:\n";
        cout << "1. Facil\n";
        cout << "2. Media\n";
        cout << "3. Dificil\n";
        cout << "0. Cancelar\n";

        int opcion;

        while (true) {
            cin >> opcion;
            switch (opcion) {
                case 1:
                    juego.addLevel(juego.getLast().numero + 1, name, "Facil");
                    return;
                
                case 2:
                    juego.addLevel(juego.getLast().numero + 1, name, "Media");
                    return;

                case 3:
                    juego.addLevel(juego.getLast().numero + 1, name, "Dificil");
                    return;
                
                case 0:
                    cout << "Cancelando...\n";
                    return;

                default:
                    cout << "Opcion invalida\n";
            }
        }
    }

};


int main() {
    Game juego;
    
    juego.addLevel(1, "Bosque Inicial", "Facil");
    juego.addLevel(2, "Cueva Oscura", "Media");
    juego.addLevel(3, "Castillo Final", "Dificil");
    
    Presenter presenter(juego); 
    int opcion;

    do {
        cout << "\n==== MENU ====\n";
        cout << "1. Siguiente nivel\n";
        cout << "2. Nivel anterior\n";
        cout << "3. Mostrar todos los niveles\n";
        cout << "4. Mostrar nivel actual\n";
        cout << "5. Añadir nivel\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                juego.nextLevel();
                break;
            case 2:
                juego.previousLevel();
                break;
            case 3:
                juego.printLevels();
                break;
            case 4:
                juego.showCurrent();
                break;
            case 5:
                presenter.addLevel();
                break;
            case 0:
                cout << "Saliendo del juego...\n";
                break;
            default:
                cout << "Opcion invalida\n";
        }

    } while(opcion != 0);

    return 0;
}