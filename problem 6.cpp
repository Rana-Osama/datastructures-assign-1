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
    PhoneDirectory(){}

    //parametrized constructor
    PhoneDirectory (string firstName , string lastName , int phoneNo){
        first_name = firstName ;
        last_name = lastName ;
        phone_number = phoneNo ;
    }

    // destructor
    ~PhoneDirectory (){}

    //setter for first name
    void setFirstName(string firstName) {
      first_name = firstName;
    }

    //getter for first name
    string getFirstName() {
      return first_name;
    }

    //setter for last name
    void setLastName(string lastName) {
      last_name = lastName;
    }

    //getter for last name
    string getLastName() {
      return last_name;
    }

    //setter for phone number
    void setPhoneNumber(int phoneNum){
      phone_number = phoneNum ;
    }

    //getter for phone number
    int getPhoneNumber (){
      return phone_number ;
    }

     // overloading < operator
      bool operator <(PhoneDirectory & phone_directory1) {
         if(first_name < phone_directory1.first_name) {
            return true;
         }
         else {
            return false ;
         }
      }
      // overloading > operator
      bool operator >(PhoneDirectory & phone_directory2) {
         if(first_name > phone_directory2.first_name) {
            return true;
         }
         else {
            return false ;
         }
      }
};
    // Function to sort the vector using insertion sort by first name
    void insertionSort (vector<PhoneDirectory> &directory1 ){
        for (int i = 1 ; i < directory1.size() ; i++){
            PhoneDirectory temp = directory1[i];
            int j ;
            // Move elements of that are greater than temp to one position ahead of their current position
            for (j = i ; j > 0 && temp < directory1[j - 1] ; j-- ){
                directory1[j]= directory1[j-1];
            }
            //placing in correct position
            directory1[j] = temp ;
        }

    }
    // Function to sort the vector using selection sort by first name
    void selectionSort (vector<PhoneDirectory> &directory2 ){
        for (int i = 0 ; i< directory2.size()-1 ; i++){
            // Find the minimum element in unsorted array
            int j , least ;
            for (j = i +1 , least = i  ;j <directory2.size() ;j++ ){
                //check if the the current element is less than the least
                if (directory2[j]< directory2[least]){
                    least = j ;
                }
            }
            //placing in correct position
            swap (directory2[least],directory2[i]);
        }
    }
    // Function to sort the vector using shell sort by first name
    void shellSort (vector<PhoneDirectory> &directory3 ){
        //Split the vector into sub-vectors
        for (int List = directory3.size()/2 ; List >0 ; List = List/2 ) {
            //gap insertion sort for sub-vectors
            for (int i = List ; i < directory3.size() ; i ++ ){
                PhoneDirectory temp = directory3[i];
                int j ;
                //shifting sorted sub-vectors yo the correct position
                for ( j = i ; j >= List && directory3 [j - List ]> temp ; j= j-List ){
                    directory3[j]= directory3[j-List];
                }
                //placing in correct position
                directory3[j]=temp;

            }
        }
    }
    //function to choose the required sorting technique
    void sorting_technique (int choice  ,vector< PhoneDirectory>& directory4){
        //input validation (check if the input is not equal to 1,2 and 3 )
         while (choice!= 1 && choice != 2 && choice != 3)
                  {
                      cout << "invalid sorting technique "<< endl;
                      cout << "Enter the required sorting technique again: ";
                      cin >> choice ;


                  }
        switch(choice)
        {
                  case 1:
                      {
                            insertionSort(directory4);
                      }

                    break;

                  case 2:
                      {
                                selectionSort(directory4);
                      }
                    break;

                  case 3:
                      {
                                shellSort(directory4);
                      }

                    break;

        }
    }
    //function to add an entry to the directory
    void addingEntry (vector<PhoneDirectory>& directory5){
         string first , last ;
         int phoneNumber;
         cout << "Enter the first name:";
         cin >> first ;
         cout << "Enter the last name:";
         cin >> last ;
         cout << "Enter the phone number:";
         cin >> phoneNumber ;

         //object from phone directory
         PhoneDirectory newEntry(first ,last,phoneNumber);
         //adding new entry to the directory
         directory5.push_back(newEntry);


    }
    //function to print the directory
    void printingVector (vector<PhoneDirectory>& directory6){
        int size = directory6.size();
        for (int i = 0 ; i <size ; i++){
            cout << "First name:"<<directory6[i].getFirstName() << endl;
            cout << "Last name:"<<directory6[i].getLastName() << endl;
            cout << "Phone number:"<< directory6[i].getPhoneNumber() << endl;
            cout << "---------------------------------"<<endl ;
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
         //input validation (check if the input is not equal to 1,2,3,4,5 and 6 )
        while (choice!= 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 ){
                            cout << "invalid Choice"<< endl;
                            cout << "Choose again"<< endl;
                            cin >> choice;
                                }

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
                int phone  ;
                cout << "Enter the phone number: ";
                cin >> phone ;
                bool found = false ;
                for (int i =0 ; i <directory.size();i++){
                    // check if the entered phone number is equal to a phone number in the directory
                    if (directory[i].getPhoneNumber()== phone){
                        cout << "First name:"<<directory[i].getFirstName() << endl;
                        cout << "Last name:"<<directory[i].getLastName() << endl;
                        cout << "Phone number:"<< directory[i].getPhoneNumber() << endl;
                        cout <<"--------------------------------" << endl;
                        found = true ;

                    }


                }
                //check if the loop reached the end without finding matching element
                    if (found == false) {
                            cout << "Not found " << endl;
                        }

            }
            break;

            case 3:
            {
                //looking up an entry by first name
                string firstName ;
                int i ;
                cout << "Enter the first name: ";
                cin >> firstName ;
                bool found = false ;
                for ( i = 0 ; i < directory.size() ; i++){
                        //check if the entered first name is equal to a first name in the directory
                         if (directory[i].getFirstName() == firstName ){
                            cout << "First name:"<<directory[i].getFirstName() << endl;
                            cout << "Last name:"<<directory[i].getLastName() << endl;
                            cout << "Phone number:"<< directory[i].getPhoneNumber() << endl;
                            cout <<"--------------------------------" << endl;
                            found = true;


                        }


                  }
                   //check if the loop reached the end without finding matching element
                        if (found == false ) {
                            cout << "Not found " << endl;
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

                string firstName ;
                cout << "Enter the first name: ";
                cin >> firstName ;
                for (int i = 0 ; i <directory.size() ; i++){
                        //check if the entered first name is equal to a first name in the directory
                        if (directory[i].getFirstName() == firstName ){
                            //deleting an entry
                           directory.erase(directory.begin()+i);
                           cout << "The required element deleted "<<endl;
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
         }
    }
}

















