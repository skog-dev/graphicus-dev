
#include <iostream>

#define VECTEUR_H

template <class E>
class Vector
{
public:
    Vector(int c = 2);
    ~Vector();
    
    int getCapacity();
    int getSize();
    
    void doubleSize();
    void purge();
    
    bool isEmpty();
    
    void copyList(E **element, E **list);
    void printTo(std::ostream &s);
    
    E *getElement(int index);
    E *removeElement(int index);
    bool addElement(E *element);

    E operator[](int index);
    bool operator+=(E *element);

    friend std::ostream& operator<<(std::ostream &s, Vector<E> &vector) {
        vector.printTo(s);
        return s;
    }

    friend std::ofstream& operator<<(std::ofstream &s, Vector<E> &vector) {
        vector.printTo(s);
        return s;
    }

    friend std::ostringstream& operator<<(std::ostringstream &s, Vector<E> &vector) {
        vector.printTo(s);
        return s;
    }


    friend std::istream& operator>>(std::istream &s, Vector<E> &vector) {
        for (int i = 0; i < vector.capacity; i++) {
            E *element;
            s >> element;
            vector.addElement(element);
        }
        return s;
    }

    friend std::ifstream& operator>>(std::ifstream &s, Vector<E> &vector) {
        for (int i = 0; i < vector.capacity; i++) {
            E *element;
            s >> element;
            vector.addElement(element);
        }
        return s;
    }

    friend std::istringstream& operator>>(std::istringstream &s, Vector<E> &vector) {
        for (int i = 0; i < vector.capacity; i++) {
            E *element;
            s >> element;
            vector.addElement(element);
        }
        return s;
    }

    void operator++(); 
    void operator--();

private:
    E **list;
    int size;
    int capacity;
    int current = 0;
};

template <class E>
Vector<E>::Vector(int c)
{
    capacity = c;
    size = 0;

    list = new E *[capacity];
    for (int i = 0; i < capacity; i++) { list[i] = nullptr; }
}

template <class E>
Vector<E>::~Vector() { delete list; }

template <class E>
int Vector<E>::getCapacity() { return capacity; }

template <class E>
int Vector<E>::getSize() { return size; }

template <class E>
void Vector<E>::doubleSize()
{
    E **temp_list = new E *[capacity * 2];

    copyList(list, temp_list);

    capacity *= 2;

    delete list;
    list = temp_list;
    
}

template <class E>
void Vector<E>::purge()
{
    for (int i = 0; i < capacity; i++) { list[i] = nullptr; }
    size = 0;
}

template <class E>
bool Vector<E>::isEmpty()
{
    for (int i = 0; i < capacity; i++) {

        if (list[i] != nullptr) { return false; }

    }

    return true;
}

template <class E>
void Vector<E>::copyList(E **source, E **destination)
{
    
    for (int i = 0; i < capacity; i++) { 
        destination[i] = source[i];
    }

    destination = source;
}

template <class E>
void Vector<E>::printTo(std::ostream &s)
{
    for (int i = 0; i < capacity; i++)
    {
        if (list[i] != nullptr) { s << *list[i] << std::endl; }
        else { s << "null" << std::endl; }
    }
}

template <class E>
E *Vector<E>::getElement(int index)
{
    if (list[index] == nullptr || index < 0 || index > capacity - 1) { return nullptr; }
    return list[index];
}

template <class E>
E *Vector<E>::removeElement(int index)
{
    if (index < 0 || index > capacity - 1) { return nullptr; }

    E *element = list[index];

    list[index] = nullptr;

    E **temp_list = new E *[capacity];

    int cnt = 0;

    for (int i = 0; i < capacity; i++)
    {
        if (list[i] == nullptr) { continue; }

        temp_list[cnt] = list[i];
        cnt++;
    }

    copyList(temp_list, list);

    size--;

    return element;
}

template <class E>
bool Vector<E>::addElement(E *element)
{
    if (size == capacity) { doubleSize(); }

    list[size] = element;
    size++;

    return true;
}

template <class E>
E Vector<E>::operator[](int index)
{
    if (list[index] == nullptr || index < 0 || index > capacity - 1) { new E; }
    return *list[index];
}

template <class E>
bool Vector<E>::operator+=(E *element)
{
    if (size == capacity) { doubleSize(); }

    list[size] = element;
    size++;

    return true;
}

template <class E>
void Vector<E>::operator++() { if (current < capacity) current++; }

template <class E>
void Vector<E>::operator--() { if (current > 0)current--; }

