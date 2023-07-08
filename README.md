# Datastructures-assign-1


#Problem 4 

The given function ListPermutations below prints all the permutations of a given string. It is required to
modify this function so that it only prints unique strings. The current function will do exhaustive
recursion to calculate all permutations. So, if the given string has duplicate characters, the output will
have duplicate words. For example, if it is given the string “Makka”, it will print “Mkkaa” four times. Try
this function and see how it works.

It is required to change the code so that it only prints unique combinations formed from the characters
of the string. So for the above mentioned example, it should print “Mkkaa” once.

Hint. To solve this, all what you need is storing each new word you form. Before printing a new word or
storing it, check if it is not already stored. You will need an array, a vector or a set to store the words
formed so far.

#########################################################################################
 
#Problem 6 

Write a program that handles an address book program, to process the following functions
(1) First, write a class called PhoneDirectory. Add a first name, last name and phone number entry
as a private.

(2) The main program uses a simple text-based interface to give the user access to the directory. In
a while loop, the program presents the user with a menu of options:

      1. Add an entry to the directory
      
      2. Look up a phone number
      
      3. Look up by first name
      
      4. Delete an entry from the directory
      
      5. List All entries in phone directory
      
      6. Exit form this program
      
(3) Delete an entry by first name.

(4) List the directory in alphabetical order by first name. 

(5) Use at least 3 sorting techniques for points 3 & 4, to perform time analysis on these different
algorithms. 

(6) Lookup an entry by first name.

(7) Lookup an entry by phone number. 

