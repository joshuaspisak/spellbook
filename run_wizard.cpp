/*********************************************************************
** Program Filename: run_wizard.cpp
** Author: Joshua Spisak
** Date: 01/03/2023
** Description: This is the main program for Assignment 2. It only does things like open up the file stream objects and then uses the other functions. It also uses a loop to continue asking for input until the user quits.
** Input: Two file names for wizard and spellbook file, an id and password, a choice for what and how to display, and a file name for output. The header file is included.
** Output: Wizard info upon login, spellbook and spell data based on searching choice, basic instructions.
*********************************************************************/

#include "catalog.h"

/*********************************************************************
** Function: main
** Description: This runs the program
** Parameters: None
** Pre-Conditions: The program compiles
** Post-Conditions: The program quits
*********************************************************************/ 

int main () {

    ifstream f1;

    ifstream f2;

    ofstream f3;

    /*
     * The two files are received and checked
     */

    if(!get_wiz_file(f1) || !get_spellb_file(f2)){

        return 1;

    }

    int num_spellbooks;

    f2 >> num_spellbooks;

    int num_wizards;

    f1 >> num_wizards;

    Wizard *wizard_array = create_wizards(num_wizards);

    populate_wizard_data(wizard_array, num_wizards, f1);

    Spellbook *spellbook_array = create_spellbooks(num_spellbooks);

    populate_spellbook_data(spellbook_array, num_spellbooks, f2);

    int wizard_index = login(wizard_array, num_wizards);

    /*
     * Checks if the user info was correct and if not exits program
     */
    
    if(wizard_index == -1){

        cout << endl << "You have failed to input a correct id and password after three attempts.";

        return 1;

    }

    int not_finished = 1;

    /*
     * Repeats prompt until user quits
     */

    while(not_finished == 1){

        search_and_print(wizard_array, wizard_index, spellbook_array, num_spellbooks, f3, not_finished);
        
        f3.close();
    
    }

    delete_info(&wizard_array, &spellbook_array, num_spellbooks);

    return 0;

}