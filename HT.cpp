#include <iostream>
using namespace std;

class ListNode{

public: 
	int data; 					//value of data
	ListNode* next; 			//pointer to next node
	
	ListNode(int d){
		data = d;
		next = NULL;
	}//constructor
};

class LinkedList {
	
	private ListNode head;
	private ListNode last;
	private int size;
	
	public LinkedList(){
		head = new ListNode(99999);
		last = head;
		size = 0;
	} //Create LinkedList
	
	public int getSize(){
		return size;
	}
	
	public void add(int d) {
		ListNode* spot = new ListNode(d);
		last->next = spot;
		last = spot;
		size++;
	}
	
	public void print(){
		ListNode spot = head.next;
		while(spot != NULL) {
			cout << spot->data << " " << endl;
			spot = spot->next;
		}
	}
};

int main(){
	int hashFunction(int d, int b){
		return (d % b);
	}//return last digit
	
	int buckets = 10;
	int data = 0;
	LinkedList[] listarray = new LinkedList[buckets];
	for(int i=0; i<buckets; i++){
		listarray[i]=new LinkedList();
	}
		
	ifstream instream;
	instream.open("HT.txt");
	
	if(instream.fail()){
		cout << "File could not be opened.";
		return(0);
	}

	while(!instream.eof()) {	
		instream >> data;
		data = inputFile.nextInt();
		int index = hashFunction(data, buckets);
		cout << "Data: " << data << "    Index: " << index << endl;
		listarray[index].add(data);
		for(int i=0; i<buckets; i++){
			listarray[i].print();
		}
	}
	
}
