#include <iostream>
#include<string>
#include<unordered_set>


using namespace std;

unordered_set <string> permutation_Set ;



void RecPermute(string soFar, string rest)
{
        if (rest == "") // No more characters
            permutation_Set.insert (soFar); //insert elements into unordered set
        else // Still more chars
        // For each remaining char
        for ( int i = 0; i < rest.length(); i++)
            {
                string next = soFar + rest[i]; // Glue next char
                string remaining = rest.substr(0, i)+ rest.substr(i+1);
                RecPermute(next, remaining);
            }

}
// "wrapper" function
void ListPermutations(string String) {
        RecPermute("",String );
        //printing unique combinations formed from the characters of the string
        for (auto it = permutation_Set.begin(); it != permutation_Set.end(); it++)
            {
                cout << *it << endl;

            }

}

int main()
{
        string String;
        cout << "Enter a string: " ;
        cin >> String;
        ListPermutations (String);

}
