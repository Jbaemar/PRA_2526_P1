#include <ostream>
template <typename T>

class Node {
    public:
        T data;
        Node<T>* next;

        Node(T data, Node<T>* next=nullptr){
            this->data = data;
            this->next = next;
        }

        friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){//sobrecarga del operador << para imprimir el nodo.
            out << node.data;
            return out;
        }
    
};