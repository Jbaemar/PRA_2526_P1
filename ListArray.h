#include <iostream>
#include <ostream>
#include "List.h"
using namespace std;

template<typename T>
class ArrayList : public List<T> {
	private:
		T* arr;//puntero al inicio del array.
		int max;//n elem maximos 
		int n;//n elementos lista
		static const int MINSIZE = 2;
		
		void resize(int new_size){
			
		
		}

	public:
		ListArray(){


		}
		
		~ListArray(){


		}

		void insert(int pos, T e) override{


		}

		void append(T e) override{


		}
                
		void prepend(T e) override{



		}

                T remove(int pos) override{



		}

                T get(int pos) override{



		}

                int search(T e) override{



		}

                bool empty() override{



		}

                int size() override{



		}
		
		T operator[](int pos){


		}

		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){


		}	
	




};
