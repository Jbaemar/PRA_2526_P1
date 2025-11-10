#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>

class ListLinked : public List<T> {

    private:
        Node<T>* first;
        int n;


    public:
        ListLinked() {
            first = nullptr;
            n = 0;
        }

        ~ListLinked() {
            Node<T>* aux=first;
            for(int i=0; i<n; i++){
                aux=aux->next;
                delete first;
                first=aux;
            }
        }

        T operator[](int pos){
            if(pos < 0 || pos >= n){
                throw std::out_of_range("Posicion no valida");
            }
            Node<T>* aux = first;
            for(int i = 0; i < pos; i++){
                aux = aux->next;
            }
            return aux->data;
        }

        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
            out << "[";
            Node<T>* aux = list.first;
            for(int i = 0; i < list.n; i++){
                out << aux->data;
                if(i < list.n - 1){
                    out << ", ";
                }
                aux = aux->next;
            }
            out << "]";
            return out;
        }

        void insert(int pos, T e) override{//inserta el elemento e en la posicion pos moviendo los elementos posteriores.
            if(pos < 0 || pos > n){
                throw std::out_of_range("Posicion no valida");
            }
            Node<T>* newNode = new Node<T>(e);
            if(pos == 0){
                newNode->next = first;
                first = newNode;
            }else{
                Node<T>* aux = first;
                for(int i = 0; i < pos - 1; i++){
                    aux = aux->next;
                }
                newNode->next = aux->next;
                aux->next = newNode;
            }
            n++;

		}

		void append(T e) override{//inserta el elemento al final
            Node<T>* post = new Node<T>(e);
            post->next = nullptr;
            if(first == nullptr){
                first = post;
                n++;
                return;
            }
            Node<T>* aux = first;
            while(aux->next != nullptr){
                aux = aux->next;
            }
            aux->next = post;
            n++;

        }
                
        void prepend(T e) override{//inserta el elemento al principio
            Node<T>* prep = new Node<T>(e);
            prep->next = first;
            first = prep;
            n++;
        }

        T remove(int pos) override{//elimina el elemento en la posicion pos y lo devuelve.
            if(pos < 0 || pos >= n){
                throw std::out_of_range("Posicion no valida");
            }
            // Caso especial: eliminar el primer nodo
            if(pos == 0){
                Node<T>* toDelete = first;
                T value = toDelete->data;
                first = first->next;
                delete toDelete;
                n--;
                return value;
            }

            // Buscar el nodo previo al que hay que eliminar
            Node<T>* prev = first;
            for(int i = 0; i < pos - 1; i++){
                prev = prev->next;
            }
            Node<T>* toDelete = prev->next;
            T value = toDelete->data;
            prev->next = toDelete->next;
            delete toDelete; // liberar memoria
            n--;
            return value;
            
        }

        T get(int pos) override{//devuelve el elemento en la posicion pos.
            if(pos < 0 || pos >= n){
                throw std::out_of_range("Posicion no valida");
            }
            Node<T>* aux=first;
            for(int i = 0; i<pos; i++){
                aux=aux->next;
            }
            return aux->data;
        }

        int search(T e) override{//busca el elemento e y devuelve su posicion o -1 si no lo encuentra.
            Node<T>* aux=first;
            int cont=0;
            while(aux != nullptr && aux->data != e){
                aux = aux->next;
                cont++;
            }
            if(aux != nullptr && aux->data == e){
                return cont;
            }else{
                return -1;
            }
        }

        bool empty() override{//devuelve true si la lista esta vacia.
            if(n==0){
                return true;
            }else{
                return false;
            }
		}

		int size() override{//devuelve el numero de elementos
            return n;
		}

        

};