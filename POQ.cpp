#include <iostream>
#include <fstream>
using namespace std;

class PQ{
	
	int front;
	int last;
	private int root;
	private int father = root;
	private int son = (father+1);
	private int min = 0;

	PQ(int size){
		int *POQ = new int[size];
		front = POQ[1];
		last = POQ[size-1];
	}
	
	void insert(int data){
		last++;
		POQ[last] = data;
		bubbleUp();
		while(front != min){
			if(father > son){
				swap(father, son);
			}
		}	
	}	

	void bubbleUp(){
		while(POQ[last] <= POQ[father] && last != root){
			POQ[father] = last/2;
			if(POQ[last] < POQ[father]){
				swap(POQ[last], POQ[father]);
				last = father;
			}
		}
	}
	
	void remove(){
		for(int i = front; i < last; i++){
			cout << POQ[i];
			POQ[i] = POQ[last];
			swap(POQ[i], POQ[last++] );
			last-=1;
		}
		print();
		bubbleDown();
	}
	
	void bubbleDown(){
		int index = front;
		int lkid = index*2;
		int rkid = (index*2)+1;
		
		int min = findMin(rkid, lkid);
		
		while(POQ[index] > POQ[min] && (index*2)+1 <= last){
			swap(POQ[index], POQ[min]);
			index = min;
			lkid = index*2;
			rkid = (index*2)+1;
			if(rkid > last)
				break;

			min = findMin(rkid, lkid);
		}
	}

	void print(){
		for(int i = 0; i < size; i++){
			cout << POQ[i];
		}
	}

	int findMin(int a, int b){
		if(a < b){
			return a;
		}
		return b;
	}

	void swap(int a, int b){
		int temp = a;
		a = b;
		b = temp;
	}//swap function`

};

int main(){
	ifstream instream;		 
	
	cout << "Enter the name of the input file: ";
	string infileName;
	cin >> infileName;
	instream.open(infileName.c_str());

	if(instream.fail()){
		cout << "File could not be opened.";
		return(0);
	}
	
		
	cout << "Enter the size of the heap: ";
	string heapSize;
	cin >> heapSize;
	
	PQ *pq = new PQ[heapSize];
	
	while(!instream.eof()) {	
			instream >> data;
			pq.insert(data);
	}
	pq.remove();
	return 0;
}
