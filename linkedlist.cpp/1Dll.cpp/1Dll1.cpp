//array stored in heap memmory in contigious locations
//like for example in char array
char arr[]={'a','b','c'};
// let say arr is stored at 1000
// then address of arr[0]=1000, arr[1]=1001, arr[2]=1002 (sizeof(char)=1)

/*similarly int arr[]={1,2,3};
let say arr is stored at 2000
then address of arr[0]=2000, arr[1]=2004, arr[2]=2008 (sizeof(int)=4)

the elements are stored in contigious locations in heap memory.

Why can't we increase or decrease the size of array?
//eg: int arr[3]={1,2,3};
//arr[3]=4; //error

why can't the size of array be changed
ChatGPT said:
ChatGPT
The size of an array in C++ cannot be changed because arrays are allocated in contiguous memory during their initialization, 
and the memory size is fixed at the time of allocation.


but in linked list, the elements are stored in heap memory but not in contigious locations.
//eg: 1->2->3->4->5
//address of 1=1000, 2=2000, 3=3000, 4=4000, 5=5000
we can increase or decrease the size of linked list..why?
In a linked list, the elements are stored in memory locations that are not necessarily contiguous.

real life application of linked list:
1.browser 
  like in a browser u search for something and then u click on a link and then u click on another link and then u click on another link in the same tab.
  and also u can go back to the previous page by clicking on the back button.
    so the links u clicked are stored in a linked list.
    and when u click on the back button, the previous link is displayed.

2. undo operation in text editor.
    like u type something and then u delete something and then u type something else and then u delete something else.
    so the operations u did are stored in a linked list.
    and when u click on the undo button, the previous operation is displayed.

3. music player
    like u play a song and then u play another song and then u play another song.
    so the songs u played are stored in a linked list.
    and when u click on the previous button, the previous song is played.*/

// int x=2;
// int* p=&x;
// cout<<p; //address of x
// cout<<*p; //value of x
/*like u can't directly store the address of vaiable in an array.
Thereby we use pointers to store the address of a variable.

in linkedlist, for an element we store the value and the address of the next element.
//eg: 1->2->3->4->5
we have to use a self defined data type to store the value and the address of the next element.*/


// struct Node{
//   int data;
//   Node* next;
//   Node(data1,next1){
//     data=data1;
//     next=next1;
//   }
//   //we use constructor here
//   //construction helps in initialisation of the elements of the object.
  
  
// };
// int main(){
//     vector<int>arr={1,2,3,4,5,6};
//     Node* y=new Node(arr[0], nullptr);//new keyword points to the memory location of the element
//     cout<<y;//prints the address of the element
//     cout<<y->data;//prints the value of the element
//     cout<<y->next;//prints the address of the next element

//     Node y=Node(arr[0], nullptr);//here we are creating an object of the class Node.
//     cout<<y.data;//prints the value of the element
//     cout<<y.next;//prints the address of the next element
//     return 0;

    
// }

// we can also write like this:
// #include <iostream>
// #include <vector>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;

     
//     Node(int data1, Node* next1) {
//         data = data1;
//         next = next1;
//     } //constructor  Node* y = new Node(data,address of next element);
//     Node(int data1){
//       data=data1;
//       next=nullptr;
//     } //constructor Node* y = new Node(data);


// }

// int main() {
//     vector<int> arr = {1, 2, 3, 4, 5, 6};

//     Node* y = Node(arr[0]); 


//     cout << y << endl;

//     return 0;
// }
// //here we have two constructors.what we did is constructor overloading.
// //constructor overloading allows us to initialise objects in multiple ways depending on the situation.
// //constructor overloading is a concept in c++ where we can have more than one constructor in a class.
// //the constructors should have the same name but different parameters.

// Node(int data1, Node* next1) {
//     data = data1;
//     next = next1;
// }
// This constructor is useful when you want to initialize both the data and next pointer explicitly. 
// It's handy when you're creating a linked list and know what the next node should be (or want to set it to nullptr explicitly).

// Node(int data1) {
//     data = data1;
//     next = nullptr;
// }
// This constructor simplifies initialization when you only have a data value and want to default next to nullptr. 
// It's especially useful when you're creating a single node without immediately linking it to others.

// //we can also use class Node instead of struct Node.
// //the only difference between class and struct is that the members of a class are private by default and the members of a struct are public by default.
// //so we can use class instead of struct.

// Memory Space:
// Let’s talk about assuming the data stored is integer. Another main difference between an array and a linked list is the memory used. In the case of an array, we are storing integers that consume 4 Bytes for every int, whereas in a linked list, we are storing data and a pointer at every node, so the memory used up will depend on the configuration of the system.

// 32 Bit System	    64 Bit System
// Int - 4 Bytes	     Int - 4 Bytes //for one int value, if one more another int value is added, it will consume 8 Bytes
// Pointer - 4 Bytes	Pointer - 8 Bytes
// Overall - 8 Bytes	Overall - 12 Bytes
// Therefore, in the case of a 64 Bit system, it occupies or consumes more space than a 32 Bit system.

// //convert array to linkedlist
// //in array problms, u can be asked to return the array.
// //but u can't return the whole linked list. u can return the head element of the linked list.

// /*reason:
// An array is stored in contiguous blocks of memory. When you return an array from a function, you're essentially returning a pointer to the start of this memory block.
// int* createArray() {
//     static int arr[] = {1, 2, 3};
//     return arr; // Returning the starting address of the array
// }
// Since arrays are contiguous, indexing (arr[i]) is straightforward, and returning the pointer effectively gives access to the whole array.

// You cannot "return the whole linked list" because the list is not stored as a single, contiguous block like an array. Instead, the list is represented by the head pointer, 
// which serves as the entry point to the list.
// eg: 
//     Node* createLinkedList() {
//     Node* head= new Node(1);
//     head->next=new Node(2);
//     head->next->next=new Node(3);
//     return head;}*/

#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node*next1){
        data=data1;
        next=next1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }

};
//function to create ll
Node* convertarr2ll(vector<int>arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i]);
        mover->next=temp;
        mover=temp;//or mover=mover->next;
        //why this step coz we have to move the mover to the next element.
        //if we don't move the mover to the next element, then the next element will be added to the first element.
        
    }
    return head;
}
//created ll

//length of linked list
int lengthofll(Node* head){
    Node* mover=head;
    int count=0;
    while(mover!=nullptr){
        count++;
        mover=mover->next;
    }
    return count;
}

//checking if an element is present in the linked list
bool check(Node* head,int val){
    Node* mover=head;
    while(mover!=nullptr){
        if(mover->data==val){
            return true;
        }
    }
    return false;
}




int main(){
    vector<int>arr={1,2,3,4,5,6};
    Node* head=convertarr2ll(arr);

    //traversal of linked list
    Node*k=head;
    while(k!=nullptr){
        cout<<k->data<<" ";
        k=k->next;
    }
    //output 1 2 3 4 5 6

    int len=lengthofll(head);
    cout<<len;//output 6

    //checking if an element is present in the linked list
    int key;
    cin>>key;
    bool ans=check(head,key);
    cout<<ans;





    

}



