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
		
		void resize(int new_size){
			T* new_arr = new T[new_size];
			for (int i = 0; i < n; i++) {
				new_arr[i] = arr[i];
			}
			delete[] arr;
			arr = new_arr;
			max = new_size + 5;
		}

	public:
		ListArray(){
			arr = new T[MINSIZE];
			max = MINSIZE;
			n = 0;
		}


		~ListArray(){
			delete[] arr;
		}
		
		void insert(int pos, T e) override{
			if(pos < 0 || pos > n-1){
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

		void append(T e) override{
			if(n == max){
				resize(max*2);
			}
			arr[n] = e;
			n++;

		}
                
		void prepend(T e) override{
			if(n== max){
				resize(max*2);
			}
			for(int i = n; i > 0; i-- ){
				arr[i]=arr[i-1];
			}
			arr[0] = e;
		}

        T remove(int pos) override{
			if(pos < 0 || pos > n-1){
				throw out_of_range("Posicion no valida");
			}
			T removed = arr[pos];
			for(int i = pos; i < n-1; i++){
				arr[i] = arr[i+1];
			}
			n--;
			return removed;
		}

        T get(int pos) override{
			if(pos < 0 || pos > n-1){
				throw out_of_range("Posicion no valida");
			}
			return arr[pos];
		}

        int search(T e) override{
			for(int i = 0; i < n; i++){
				if(arr[i] == e){
					return i;
				}
			}
			return -1;
		}

        bool empty() override{
			return n == 0;
		}

		int size() override{
			return n;
		}
		
		T operator[](int pos){
			if(pos < 0 || pos > n-1){
				throw out_of_range("Posicion no valida");
			}
			return arr[pos];
		}

		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
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
