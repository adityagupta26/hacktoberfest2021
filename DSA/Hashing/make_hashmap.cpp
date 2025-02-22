#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Node{
    public:
    string key;
    T value;
    Node<T>*next;

    Node(string key, T val)
    {
        this->key=key;
        value=val;
        next=NULL;

        if(next!=NULL)
        delete next;
    }
};

template<typename T>
class Hashtable{

    //pointer pointing to array of pointers 
    Node<T>**table;
    int curr_size;
    int table_size;

    int hash(string key)
    {
        int idx=0;
        int pow=1;

        for(int i=0;i<key.length();i++)
        {
            idx+=(key[i]*pow)%table_size;
            idx=idx%table_size;
            p=(p*27)%table_size;
        }
        return idx;

    }

    void rehash()
    {
        Node<T>**oldTable=table;
        table_size=2*table_size;
        table=new Node<T>*[table_size];

        for(int i=0;i<table_size;i++)
        table[i]=NULL;
        curr_size=0;

    //shifting elements from old to new table
        for(int i=0;i<table_size;i++)
        {
            
        }
    }

    public:
    Hashtable(int ts=10)
    {
        table_size=ts;
        table=new Node<T>*[table_size];
        curr_size=0;

        for(int i=0;i<table_size;i++)
        table[i]=NULL;
    }

    void insert(string key,T value)
    {
        int idx=hash(key);

        //create linked list
        Node<T>*n=new Node<T>(key,val);
        n->next=table[idx];
        table[idx]=n;
        curr_size++;

        //rehashing
        float load_factor=curr_size/table_size;
        if(load_factor>0.7)
        rehash();
    }

    void erase(string args)
    {
    	// Creating an empty HashMap
		HashMap<String, Integer> hash_map = new HashMap<String, Integer>();
		// Mapping int values to string keys
		hash_map.put("Geeks", 10);
		hash_map.put("4", 15);
		hash_map.put("Geeks", 20);
		hash_map.put("Welcomes", 25);
		hash_map.put("You", 30);
		// Displaying the HashMap
		System.out.println("Initial Mappings are: " + hash_map);
		// Clearing the hash map using clear()
		hash_map.clear();
		// Displaying the final HashMap
		System.out.println("Finally the maps look like this: " + hash_map);
	}

    T search(string key)
    {

    }
};

int main() {
   
}
