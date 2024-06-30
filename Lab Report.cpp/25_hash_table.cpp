#include<iostream>
using namespace std;

class HashTable{
    struct Node{
        string key;
        int value;
        Node* next;

        Node(string key, int value){
            this->key=key;
            this->value=value;
            next=nullptr;
        }
    };

    static const int SIZE=5;
    Node* dataMap[SIZE];

    int hash(string key){
        int hash=0;
        for(int i=0;i<key.length();i++){
            int asciiValue = int(key[i]);
            hash=(hash+asciiValue*23)%SIZE;
        }
        return hash;
    }

    public:
    void printtable(){
        for(int i=0;i<SIZE;i++){
            cout<<i<<":"<<endl;
            if(dataMap[i]){
                Node* temp=dataMap[i];
                while(temp != nullptr){
                    cout<<"  {"<<temp->key<<" , "<<temp->value<<"}"<<endl;
                    temp=temp->next;
                }
            }
        }
    }

    void set(string key,int value){
        int index = hash(key);
        Node* newNode=new Node(key,value);

        if(dataMap[index]==nullptr){
            dataMap[index]=newNode;
        }
        else{
            Node* temp=dataMap[index];
            while(temp->next != nullptr){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }

    int get(string key){
        int index=hash(key);
        Node* temp=dataMap[index];
        
        while(temp != nullptr){
            if(temp->key==key){
                return temp->value;
            }
        }
        return 0;
    }
};

int main(){
    HashTable* ht = new HashTable();

    ht->set("Ashik",19);
    ht->set("Miskatul",1);
    ht->set("Sohan",13);
    ht->set("Sadia",00);
    ht->set("Swapnomoy",32);
    ht->set("Indra",00);
    ht->set("Khalid",33);
    ht->set("Nusrat",8);

    ht->printtable();
    cout<<"\nCheck Get Function:\nAshik "<<ht->get("Miskatul");
}