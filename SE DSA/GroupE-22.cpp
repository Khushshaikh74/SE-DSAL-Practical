#include<iostream>
#include<algorithm> // for std::sort
using namespace std;

class Heap
{
	int n;
	int *minheap,*maxheap;
	public:
	void get();
	void displayMin(){cout<<"Minimum marks are :"<<minheap[0]<<endl;}
	void displayMax(){cout<<"Maximum marks are :"<<maxheap[0]<<endl;}
    void displaySortedMarks();
	void upAdjust(bool,int);
};

void Heap::get()
{
	cout<<"Enter number of students: "<<endl;
	cin>>n;
	int k;
	minheap=new int[n];
	maxheap=new int[n];
	cout<<"Enter marks of students: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		minheap[i]=k;
		upAdjust(0,i);
		maxheap[i]=k;
		upAdjust(1,i);
	}
}

void Heap::upAdjust(bool m,int l)
{
	int s;
	if(!m)
	{
		while(minheap[(l-1)/2]>minheap[l])
		{
			s=minheap[l];
			minheap[l]=minheap[(l-1)/2];
			minheap[(l-1)/2]=s;
			l=(l-1)/2;
			if(l==-1)
				break;
		}
	}
	else
	{
		while(maxheap[(l-1)/2]<maxheap[l])
		{
			s=maxheap[l];
			maxheap[l]=maxheap[(l-1)/2];
			maxheap[(l-1)/2]=s;
			l=(l-1)/2;
			if(l==-1)
				break;
		}
	}
}

void Heap::displaySortedMarks()
{
    int *sortedMarks = new int[n];
    for(int i = 0; i < n; i++)
    {
        sortedMarks[i] = minheap[i]; // Copying the minheap to an array
    }

    sort(sortedMarks, sortedMarks + n); // Sorting the array of marks

    cout << "Sorted marks are: ";
    for(int i = 0; i < n; i++)
    {
        cout << sortedMarks[i] << " ";
    }
    cout << endl;

    delete[] sortedMarks; // Deallocating the memory
}

int main()
{   
    int ch;
	Heap H;
    
    while (true) {
        cout << "\n-----------DSAL PRACTICAL NO :- 10----------" << endl;
        cout << "\n*MENU" << endl;
        cout << "1. Accept Information" << endl;
        cout << "2. Display Minimum Marks" << endl;
        cout << "3. Display Maximum Marks" << endl;
        cout << "4. Display Sorted Marks" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> ch;
        
        switch (ch){
            case 1:
                H.get();
                break;

            case 2:
                H.displayMin();
                break;
                
            case 3:
                H.displayMax();
                break;

            case 4:
                H.displaySortedMarks();
                break;
            
            case 5:
                cout << "\n*Exiting the program.*" << endl;
                return 0;    

            default:
                cout << "Invalid choice. Please try again." << endl;
                cout << endl;

        }
    }
}