#include <iostream>
#include<string>
#include<unordered_set>


using namespace std;

unordered_set <string> permutation_Set ;



void RecPermute(string soFar, string rest)
{
        if (rest == "") // No more characters
            permutation_Set.insert (soFar); //add elements to set
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
void ListPermutations(string s) {
        RecPermute("", s);
        for (auto it = permutation_Set.begin(); it != permutation_Set.end(); it++)
            {
                cout << *it << endl;

            }

}

int main()
{
        string x;
        cout << "Enter a word: " ;
        cin >> x;
        ListPermutations (x);

}
