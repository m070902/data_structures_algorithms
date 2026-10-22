#include <iostream>

using namespace std;

// El objetivo en este ejercicio es el de crear una linked list funcional,
// la cual ha de permitir introducir información al principio, al final
// y en medio, así como borrarla de la misma manera. Todo esto se llevará
// a cabo empleando funciones que funcionarán a nivel de memoria usando
// punteros, así como una clase nodo que almacenará la información y la
// dirección del siguiente término del array.

class node{
    public:
        int value;
        node* next_node;
};

class linked_list{
    node *ptr;
    node **start_pointer = &ptr;

    public:
    void add_beginning(int new_node_value){
        node* ptr;
        ptr = new node;
        ptr->value = new_node_value;
        ptr->next_node = *start_pointer;
        *start_pointer = ptr;
    }
    void add_end(int new_node_value){
        node *new_ptr, **ptr;
        new_ptr = new node;
        new_ptr->value = new_node_value;
        new_ptr->next_node = NULL;

        ptr = start_pointer;

        if ((*ptr) == NULL){
            *ptr = new_ptr;
        }
        else{
            while ((*ptr)->next_node != NULL) {
                (*ptr) = (*ptr)->next_node;
            }

            (*ptr)->next_node = new_ptr;
        }

    }
    void add_in_position(int new_node_value, int position_to_insert){
        node *new_ptr, *ptr_aux_1, *ptr_aux_2;
        new_ptr = new node;
        new_ptr->value = new_node_value;

        ptr_aux_1 = *start_pointer;
        ptr_aux_2 = (*start_pointer)->next_node;

        if (position_to_insert == 1){
            new_ptr->next_node = ptr_aux_1;
            (*start_pointer) = new_ptr;
        }
        else{
            int i = 2;
            while (i < position_to_insert){
                ptr_aux_1 = ptr_aux_2;
                ptr_aux_2 = ptr_aux_2->next_node;
                i++;
            }
        }

        new_ptr->next_node = ptr_aux_2;
        ptr_aux_1->next_node = new_ptr;
    }

    void delete_first(){
        (*start_pointer) = (*start_pointer)->next_node;
    }
    void delete_last(){
        node *ptr_aux_1, *ptr_aux_2;

        ptr_aux_1 = *start_pointer;

        if (ptr_aux_1 == NULL){
            cout << "This linked-list is empty." << endl;
        }
        else{

            ptr_aux_2 = (*start_pointer)->next_node;

            while (ptr_aux_2->next_node != NULL) {
                ptr_aux_1 = ptr_aux_2;
                ptr_aux_2 = ptr_aux_2->next_node;
            }

            ptr_aux_1->next_node = NULL;
        }
    }
    void delete_in_position(int position_to_delete){
        node *ptr_aux_1, *ptr_aux_2;

        ptr_aux_1 = *start_pointer;
        ptr_aux_2 = (*start_pointer)->next_node;

        int i = 1;
        if (position_to_delete == 1){
            *start_pointer = ptr_aux_2;
        }
        else{
            while (i < position_to_delete){
                ptr_aux_1 = ptr_aux_2;
                ptr_aux_2 = ptr_aux_2->next_node;
                i++;
            }

            ptr_aux_1->next_node = ptr_aux_2->next_node;
        }

    }

    void print_linked_list(){
        node* ptr;
        ptr = *start_pointer;
        while (ptr != NULL){
            cout << ptr->value << endl;
            ptr = ptr->next_node;
        }
    }


};


int main(){
    linked_list prueba;

    prueba.add_end(4);
    prueba.add_end(3);

    prueba.add_beginning(2);
    prueba.add_beginning(6);

    prueba.add_in_position(7, 3);
    prueba.add_in_position(7, 1);
    prueba.add_in_position(7, 5);

    prueba.delete_first();
    prueba.delete_last();

    prueba.delete_in_position(2);

    prueba.print_linked_list();

    return 0;
}