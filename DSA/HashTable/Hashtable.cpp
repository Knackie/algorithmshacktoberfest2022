
#include <iostream>
using namespace std;

/*Record Class */
class Record
{
private:
    string name, major;
    int id, grade;
public:
    Record(string full_name, string maj, int identi, int gr);
    Record ();
    string getKey() { return name; }
    string setKey(string full_name) { name = full_name;}
    int getHashIndex(int hash_table_size);

};

Record::Record(string full_name, string maj, int identi, int gr)
{
        name = full_name;
        major = maj;
        id = identi;
        grade = gr;
}

int Record::getHashIndex(int hash_table_size)
{
    int sum = 0;
    for (int i = 0; i<name.length();i++)
    {
        sum+=name[i];
    }

    sum = sum % hash_table_size;
    return sum;
}

/* LinkedList Class */
template <class T, class K>
class LinkedListNode
{
private:
    K key;
    LinkedListNode<T, K> * next;
    T * record;

public:
    LinkedListNode(K k, T * rec) { next= NULL; key = k;  record = rec; }
    void setRecord (T * rec) { record = rec; }
    void setKey (K ke) { key = ke; }
    void printKey() {cout <<  key << endl; }
    LinkedListNode<T,K> * getNext() {return next; }
    void setNext(LinkedListNode<T,K> * ne) { next = ne; }


};

template <class T, class K>
class LinkedList
{
   private:
       LinkedListNode<T, K> * head;
       int list_size;

   public:
    LinkedList();
    bool insertNode(K key, T * record);
    bool deleteNode (K key);
    T * findRecord(K key);
    LinkedListNode<T, K> * getHead() {return head; }
    bool empty();
    int Size() {return list_size; }
    void printKeys();
    void deleteList();

};

template <class T, class K>
LinkedList<T,K>:: LinkedList()
{
    head = NULL;
    list_size = 0;

}

template <class T, class K>
bool LinkedList<T, K>:: insertNode(K key, T * record)
{
         LinkedListNode<T,K> * temp = new LinkedListNode<T,K>(key, record);

         if (head == NULL)
         {
             head = temp;
             list_size++;
             return true;
         }
         else
         {
            temp->setNext(head);
            head = temp;
            list_size++;
            return true;
         }


}

template <class T, class K>
T* LinkedList<T, K> :: findRecord(K search_key)
{

    LinkedListNode<T, K> * temp;
    temp = head;

    if (head == NULL) return NULL;
    while (temp!=NULL)
    {
        if (temp->key == search_key) return temp->record;
        else temp = temp->getNext();
    }
    return NULL;
}



template <class T, class K>
bool LinkedList<T, K> :: deleteNode(K search_key)
{
    LinkedListNode<T, K> * temp1, * temp2;
    temp1 = temp2 = head;
    if (temp1 == NULL) return false;
    while (temp1 != NULL)
    {
        if (temp1->getKey() == search_key && temp2 == temp1)
        {
            head = NULL;
            list_size--;
            return true;
        }

        if (temp1->getKey() == search_key)
        {
            temp2->setNext(temp1->getNext());
            list_size--;
            return true;
        }

        temp2 = temp1;
        temp1 = temp1->getNext();
    }
    return false;

}

template <class T, class K>
bool LinkedList<T,K>:: empty()
{
    if (head == NULL) return true;
    else return false;
}
template <class T, class K>
void LinkedList<T,K>:: printKeys()
{
   LinkedListNode<T,K> * temp;
   temp = head;
   if (temp == NULL ) return;
   else {
    while(temp!=NULL)
    {
        temp->printKey();
        temp = temp->getNext();
    }
   }
}

template <class T, class K>
void LinkedList<T,K>:: deleteList()
{
    LinkedListNode<T,K> * temp1;
    temp1 = head;
    if (head == NULL ) return;
    while (head!=NULL)
    {
        head = temp1->getNext();
        delete temp1;
        temp1 = head;
    }
}



/*HashTable Class */
template <class T, class K>
class HashTable
{
private:
    int m_size, records;
    LinkedList<T,K> * arr;

public:
    HashTable(int max_size);
    ~HashTable();
    void insertRecord(T * record);
    T * findRecord(K key);
    void eraseRecord(K key);
    int getRecords() {return records; }
    void printAll();

};

template <class T, class K>
HashTable<T,K>::HashTable(int max_size)
{
    m_size = max_size;
    arr = new LinkedList<T,K>[m_size];
    records = 0;
}

template <class T, class K>
HashTable<T,K>::~HashTable()
{
    for (int i = 0; i < m_size; i++) arr[i].deleteList();
    delete [] arr;
}


template <class T, class K>
void HashTable<T, K>:: insertRecord (T * record)
{
    K key = record->getKey();

    int index = record->getHashIndex(m_size);


    if (arr[index].insertNode(key, record)) records++;



}

template <class T, class K>
void HashTable<T, K> :: eraseRecord (K key)
{
    Record temp;
    temp.setKey(key);

    int index = temp.getHashIndex(m_size);

   if (arr[index].deleteNode(key)) records--;

}

template <class T, class K>
T * HashTable<T,K>:: findRecord(K key)
{
    Record temp;
    temp.setKey(key);

    int index = temp.getHashIndex(m_size);

   T * rec =  arr[index].findRecord(key);

   return rec;
}

template <class T, class K>
void HashTable<T, K>:: printAll()
{
    for (int i = 0; i < m_size; i++)
    {
        arr[i].printKeys();
    }
}

int main ()
{

    Record a("Jasjeet Singh", "CS", 1, 12);
    Record b("Remy Martin", "CS", 2, 12);
    Record c("John Doe", "CS", 3, 12);
    Record d("Dustin Johnson", "CS", 4, 12 );
    Record e("Allie Johnson", "CS", 5, 12);
    Record f("Martilova Putin", "CS", 6, 12);
    Record g("Ice Cube", "CS", 7, 12);
    Record h("Ben Hoga", "CS", 8, 12 );
    Record i("Xie Wou Jin", "CS", 9, 12);
    Record j("Kim Ung Choi", "CS", 10, 12);
    Record k("Benjamin Martin", "CS", 11, 12);
    Record l("Xavier Costigan", "CS", 12, 12 );

    HashTable<Record, string> table(5);

    table.insertRecord(&a);
    table.insertRecord(&b);
    table.insertRecord(&c);
    table.insertRecord(&d);
    table.insertRecord(&e);
    table.insertRecord(&f);
    table.insertRecord(&g);
    table.insertRecord(&h);
    table.insertRecord(&i);
    table.insertRecord(&j);
    table.insertRecord(&k);
    table.insertRecord(&l);

   cout <<"--------------------------"<< table.getRecords() << " added----------------------\n " << endl;

    table.printAll();


    return 0;

}
