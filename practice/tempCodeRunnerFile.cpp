void pop(){
    Node* temp;
    temp==Top;
    if(isEmpty())
    cout<<"Stack is Empty\n";
    else if(Head==Top){
        Top=NULL;
        Head=NULL;
        delete temp;
    }
    else{
        Top->prev->next=NULL;
        Top=temp->prev;
        delete temp;
    }
}
void printStack(){
    Node* temp=Head;
    while(temp !=NULL){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
void stackSize(){
    int sz=0;
    Node *temp=Head;
    while(temp!=NULL){