#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
class Vector {
private:
    T* storage;
    unsigned int cap;
    unsigned int sz;
public:
    Vector() {
        cap = 5;
        storage = new T[cap];
        sz = 0;
    }
    Vector(unsigned int c) {
        cap = c;
        storage = new T[cap];
        sz = 0;
    }
    ~Vector() {
        delete [] storage;
    }
    unsigned int size() const {
        return sz;
    }

    bool empty() const {
        return sz == 0;
    }

    unsigned int capacity() const {
        return cap;
    }

    void push_back(T elem) {
        resize();
        storage[sz] = elem;
        sz++;
    }

    void pop_back() {
      assert(!empty());
      sz--;
    }

    const T& front() const {
        assert(!empty());
        return storage[0];
    }

    T& front() {
        assert(!empty());
        return storage[0];
    }

    const T& back() const {
        assert(!empty());
        return storage[sz-1];
    }

    T& back() {
        assert(!empty());
        return storage[sz-1];
    }

    const T& at(unsigned int pos) const {
        assert(pos < sz);
        return storage[pos];
    }

    T& at(unsigned int pos) {
        assert(pos < sz);
        return storage[pos];
    }

    const T& operator[](unsigned int pos) const {
        return storage[pos];
    }

    T& operator[](unsigned int pos) {
        return storage[pos];
    }

    void shrink_to_fit() {
        if (sz == cap) return;
        T* newStorage = new T[sz];
        for(unsigned int i = 0; i < sz; i++) {
            newStorage[i] = storage[i];
        }
        delete [] storage;
        storage = newStorage;
        cap = sz;
    }

    void removepos(unsigned int pos) {
        assert(pos < sz);
        for(unsigned int i = pos; i < sz-1; i++) {
            storage[i] = storage[i+1];
        }
        sz--;
    }

    void erase (unsigned int from, unsigned int to){
      assert((from <= to) && (to <= sz));

        unsigned int x = to - from;
        for (unsigned int i = from; i < sz - x; i++) {
            storage[i] = storage[i + x];
        }
        sz = sz-x;
        
    }

    void clear() {
        sz = 0;
    }

    bool contains(const T &elem) const{
         assert(!empty ());

         int x=0;
         for (unsigned int i=0; i< sz; i++){
            if (storage[i]== elem){
                x++;
            }
         }
         return x>=1;
        }

    int find (const T &elem) const{
         assert (!empty ());
         int x;
         for (unsigned int i=0; i<sz;i++){
               if (storage[i]==elem){
                return i;
               }
         }
         
         return -1;
    }
    
    void removevalue(const T &elem){
        assert (!empty());

        for (unsigned int i=0; i<sz;i++){
            if (storage[i]==elem){
                for (unsigned int j=i; j<sz-1;j++){
                    storage[j]=storage[j+1];
                }
                sz--;
                return;
            }
            
        }
    }

    void replace(const T &oldval,const T &newval){
        assert(contains(oldval));
        assert(!empty());

        for (unsigned int i=0; i<sz;i++){
            if (storage[i]==oldval){
                storage[i]=newval;
                return;
            }
        }
    }

    void removevalue_all(const T &elem){
        assert (!empty());

        for (unsigned int i=0; i<sz;i++){
            if (storage[i]==elem){
                storage[i]= storage[i+1];

                for (unsigned int j=i; j<sz-1;j++){
                    storage[j]=storage[j+1];
                }
                sz--;
                i--;
            }
            
        }
    }
    
void replace_all(const T &oldval,const T &newval){
        assert(contains(oldval));
        assert(!empty());

        for (unsigned int i=0; i<sz;i++){
            if (storage[i]==oldval){
                storage[i]=newval;
                i--;
            }
        }
    }


private:
    void resize() {
        if (sz == cap) {
            unsigned int newCapacity = cap * 1.5;
            T* newStorage = new T[newCapacity];
            for(unsigned int i = 0; i < sz; i++) {
                newStorage[i] = storage[i];
            }
            delete [] storage;
            storage = newStorage;
            cap = newCapacity;
        }
    }
public:
    void print() const {
        cout << "{";
        for(unsigned int i = 0; i < sz; i++) {
            cout << storage[i] << " ";
        }
        cout << "}" << endl;
    }

};


int main() {
    Vector<int> v(4532);
    for(int i = 0; i < 11; i++) {
    v.push_back(i * 10);
    v.push_back(i * 10);
}
    v.print();
    cout << v.front() << endl;
    cout << v.back() << endl;
    cout << v.at(5) << endl;
     
    v.back() = 200;
    v.at(5) = 10000;
    v.print();
    v.removepos(5);
    v.print();
    v.erase(2, 4);
     v.print(); 
    cout << v.contains(200) << endl; 
    //v.clear();
    cout << v.find(30) << endl;
    //v.removevalue(60);
    //v.replace(30,100);
    //v.removevalue_all(30);
     v.replace_all(90,100);
    v.print();

        
    v[4533] = 10;



    return 0;    
}

