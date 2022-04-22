#include <iostream>
#include <vector>
#include <string>

using namespace std;

class  PhoneDirectory {
private :
    string first_name , last_name ;
    int phone_number ;
public:

    //default constructor
    PhoneDirectory();

    //parametrized constructor
    PhoneDirectory (string fname , string lname , int phone){
        first_name = fname ;
        last_name = lname ;
        phone_number = phone ;
    }

    // destructor
    ~PhoneDirectory (){}

    //setter for first name
    void setFirstName(string f) {
      first_name = f;
    }

    //getter for first name
    string getFirstName() {
      return first_name;
    }

    //setter for last name
    void setLasttName(string l) {
      last_name = l;
    }

    //getter for last name
    string getLastName() {
      return last_name;
    }

    //setter for phone number
    void setPhoneNumber(int p){
      phone_number = p ;
    }

    //getter for phone number
    int getPhoneNumber (){
      return phone_number ;
    }

     // overloading < operator
      bool operator <(PhoneDirectory & p1) {
         if(first_name < p1.first_name) {
            return true;
         }
      }
      // overloading > operator
      bool operator >(PhoneDirectory & p2) {
         if(first_name > p2.first_name) {
            return true;
         }
      }
};
    //insertion sort
    void insertionSort (vector<PhoneDirectory> &d ){
        for (int i = 1 ; i < d.size() ; i++){
            PhoneDirectory temp = d[i];
            int j ;
            for (j = i ; j > 0 && temp < d[j - 1] ; j-- ){
                d[j]= d[j-1];
            }
            d[j] = temp ;
        }

    }
    //selection sort
    void selectionSort (vector<PhoneDirectory> &d ){
        for (int i = 0 ; i< d.size()-1 ; i++){
            int j , least ;
            for (j = i +1 , least = i  ;j <d.size() ;j++ ){
                if (d[j]< d[least]){
                    least = j ;
                }
            }
            swap (d[least],d[i]);
        }
    }
    //shell sort
    void shellSort (vector<PhoneDirectory> &d ){
        for (int List = d.size()/2 ; List >0 ; List = List/2 ) {
            for (int i = List ; i < d.size() ; i ++ ){
                PhoneDirectory temp = d[i];
                int j ;
                for ( j = i ; j >= List && d [j - List ]> temp ; j= j-List ){
                    d[j]= d[j-List];
                }
                d[j]=temp;

            }
        }
    }

    void sorting_technique (int choice  ,vector< PhoneDirectory>& directory){

        switch(choice)
        {
                  case 1:
                      {
                            insertionSort(directory);
                      }

                    break;

                  case 2:
                      {
                                selectionSort(directory);
                      }
                    break;

                  case 3:
                      {
                                shellSort(directory);
                      }

                    break;

                  default:
                  {
                      cout << "invalid sorting technique "<< endl;
                      cout << "Enter the required sorting technique again: ";
                      cin >> choice ;


                  }
        }
    }

    void addingEntry (vector<PhoneDirectory>& directory){
        string first , last ;
        int pNumber;
         cout << "Enter the first name:";
         cin >> first ;
         cout << "Enter the last name:";
         cin >> last ;
         cout << "Enter the phone number:";
         cin >> pNumber ;

         //object from phone directory
         PhoneDirectory newEntry(first ,last,pNumber);
         //adding new entry to the directory
         directory.push_back(newEntry);


    }

    void printingVector (vector<PhoneDirectory>& directory){
        int size = directory.size();
        for (int i = 0 ; i <size ; i++){
            cout << "First name:"<<directory[i].getFirstName() << endl;
            cout << "Last name:"<<directory[i].getLastName() << endl;
            cout << "Phone number:"<< directory[i].getPhoneNumber() << endl;
        }
    }



int main()

{
    vector <PhoneDirectory> directory ;

    int choice;
    bool x = true;
    while ( x != false)
    {
        cout << "Phone directory" <<endl;
        cout << " 1. Add an entry to the directory" << endl ;
        cout << " 2. Look up a phone number" << endl ;
        cout << " 3. Look up by first name"<< endl ;
        cout << " 4. Delete an entry from the directory"<< endl ;
        cout << " 5. List All entries in phone directory"<< endl ;
        cout << " 6. Exit form this program"<< endl ;

        cout << "Enter your choice: " << endl ;
        cin >> choice;

        switch (choice)
        {

            case 1:
            {
             // add an entry
             addingEntry (directory);
            }
            break;

            case 2:
            {
                // looking up an entry by phone number
                int phonee  ;
                cout << "Enter the phone number: ";
                cin >> phonee ;

                for (int i =0 ; i <directory.size();i++){
                    // check if the entered phone number is equal to a phone number in the directory
                    if (directory[i].getPhoneNumber()== phonee){
                        cout << "First name:"<<directory[i].getFirstName() << endl;
                        cout << "Last name:"<<directory[i].getLastName() << endl;
                        cout << "Phone number:"<< directory[i].getPhoneNumber() << endl;
                    }

                    else {
                        cout << "Not found "<<endl ;
                    }

                }

            }
            break;

            case 3:
            {
                //looking up an entry by first name
                string firstn ;
                cout << "Enter the first name: ";
                cin >> firstn ;
                for (int i = 0 ; i < directory.size() ; i++){
                        //check if the entered first name is equal to a first name in the directory
                        if (directory[i].getFirstName() == firstn ){
                            cout << "First name:"<<directory[i].getFirstName() << endl;
                            cout << "Last name:"<<directory[i].getLastName() << endl;
                            cout << "Phone number:"<< directory[i].getPhoneNumber() << endl;
                        }

                        else {
                            cout << "Not found " << endl;
                        }



                  }
            }
            break;

            case 4:
            {
                // deleting an entry by first name
                int choice2;

                cout << "Enter the required sorting technique: "<<endl;
                cout << "1-insertion sort " << endl ;
                cout << "2-selection sort" << endl ;
                cout << "3-shell sort " <<endl ;
                cin >> choice2;
                sorting_technique(choice2,directory);

                string first ;
                cout << "Enter the first name: ";
                cin >> first ;
                for (int i = 0 ; i <directory.size() ; i++){
                        //check if the entered first name is equal to a first name in the directory
                        if (directory[i].getFirstName() == first ){
                            //deleting an entry
                           directory.erase(directory.begin()+i);
                        }
               }

            }

            break;


            case 5:
            {
                // listing the directory
                int choice3 ;
                cout << "Enter the required sorting technique: " <<endl;
                cout << "1-insertion sort " << endl ;
                cout << "2-selection sort" << endl ;
                cout << "3-shell sort " <<endl ;
                cin >> choice3 ;
                sorting_technique(choice3 ,directory);
                printingVector (directory);

            }
            break;

            case 6: {
            cout << "End of Program "<< endl;
            x= false;
            }
            break;

            default:{
            cout << "invalid Choice"<< endl;
            cout << "Choose again"<< endl;
            cin >> choice;
            break;
                    }

         }
    }


}

















