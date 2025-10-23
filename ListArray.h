#include <iostream>
#include <ostream>
#include <stdexcept>
#include "List.h"
using namespace std;

template<typename T>
class ListArray : public List<T> {
	private:
		T* arr;//puntero al inicio del array.
		int max;//n elem maximos 
		int n;//n elementos lista
		static const int MINSIZE = 2;
		
		void resize(int new_size){//crea un nuevo array de tamano new_size, copia los elementos del array viejo y borra el array viejo.
			T* new_arr = new T[new_size];
			for (int i = 0; i < n; i++) {
				new_arr[i] = arr[i];
			}
			delete[] arr;
			arr = new_arr;
			max = new_size;
		}

	public:
		ListArray(){//constructor dinamico.
			arr = new T[MINSIZE];
			max = MINSIZE;
			n = 0;
		}


		~ListArray(){//destructor dinamico.
			delete[] arr;
		}
		
		void insert(int pos, T e) override{//inserta el elemento e en la posicion pos moviendo los elementos posteriores.
			if(pos < 0 || pos > n){
				throw out_of_range("Posicion no valida");
			}
			if(n == max){
				resize(max*2);
			}
			for(int i = n; i >pos; i--){
				arr[i] = arr[i-1];
			}
			arr[pos] = e;
			n++;
		}

		void append(T e) override{//inserta el elemento al final
			if(n == max){
				resize(max*2);
			}
			arr[n] = e;
			n++;

		}
                
		void prepend(T e) override{//inserta el elemento al principio
			if(n== max){
				resize(max*2);
			}
			for(int i = n; i > 0; i-- ){
				arr[i]=arr[i-1];
			}
			arr[0] = e;
			n++; 
		}

        T remove(int pos) override{//elimina el elemento en la posicion pos y lo devuelve.
			if(pos < 0 || pos > n-1 || n == 0){
				throw out_of_range("Posicion no valida");
			}
			T removed = arr[pos];
			for(int i = pos; i < n-1; i++){
				arr[i] = arr[i+1];
			}
			n--;
			return removed;
		}

        T get(int pos) override{//devuelve el elemento en la posicion pos.
			if(pos < 0 || pos > n-1){
				throw out_of_range("Posicion no valida");
			}
			return arr[pos];
		}

        int search(T e) override{//busca el elemento e y devuelve su posicion o -1 si no lo encuentra.
			for(int i = 0; i < n; i++){
				if(arr[i] == e){
					return i;
				}
			}
			return -1;
		}

        bool empty() override{//devuelve true si la lista esta vacia.
			return n == 0;
		}

		int size() override{//devuelve el numero de elementos
			return n;
		}
		
		T operator[](int pos){//sobrecarga el operador [] para acceder a un elemento en la posicion pos.
			if(pos < 0 || pos > n-1){
				throw out_of_range("Posicion no valida");
			}
			return arr[pos];
		}

		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){//sobrecarga del operador << para imprimir la lista entera. Se utiliza friend para acceder a los miembros privados porque es una funcion externa de ostream.
			out << "[";
			for(int i = 0; i < list.n; i++){
				out << list.arr[i];
				if(i < list.n - 1){
					out << ", ";
				}
			}
			out << "]";
			return out;

		}




};
