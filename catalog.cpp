/*********************************************************************
** Program Filename: catalog.cpp
** Author: Joshua Spisak
** Date: 02/03/2023
** Description: This is the implementation that contains all the function definitions.
** Input: The header file is included.
** Output: There is no output.
*********************************************************************/

#include "catalog.h"

/*********************************************************************
** Function: create_wizards
** Description: this dynamically creates an array of wizards
** Parameters: an integer for the number of wizards
** Pre-Conditions: the integer is inputted
** Post-Conditions: the array is created
*********************************************************************/ 

Wizard * create_wizards(int num_wizards){

    Wizard *wizard_array = new Wizard[num_wizards];

}

/*********************************************************************
** Function: create_spellbooks
** Description: this dynamically creates an array of spellbokos
** Parameters: an integer for the number of spellbooks
** Pre-Conditions: the integer is inputted
** Post-Conditions: the array is created
*********************************************************************/ 

Spellbook * create_spellbooks(int num_spellbooks){

    Spellbook *spellbook_array = new Spellbook[num_spellbooks];

}

/*********************************************************************
** Function: create_spells
** Description: dynamically creates an array of spells
** Parameters: integer for number of spells
** Pre-Conditions: integer is inputted
** Post-Conditions: array is created
*********************************************************************/ 

Spell * create_spells(int num_spells){

    Spell *spell_array = new Spell[num_spells];

}

/*********************************************************************
** Function: populate_wizard_data
** Description: this populates the wizard array with information for each member variable
** Parameters: the wizard array, an integer for number of wizards, and the input file stream
** Pre-Conditions: the stream is declared
** Post-Conditions: the wizard array is full
*********************************************************************/ 

void populate_wizard_data(Wizard *wizard_array, int num_wizards, ifstream & f1){

    for(int i = 0; i < num_wizards; i++){

        f1 >> wizard_array[i].name >> wizard_array[i].id >> wizard_array[i].password >> wizard_array[i].position_title >> wizard_array[i].beard_length;
        //cout << "Name: " << wizard_array[i].name << endl << "ID: " << wizard_array[i].id << endl << "Password: " << wizard_array[i].password << endl << "Position: " << wizard_array[i].position_title << endl << "Length: " << wizard_array[i].beard_length << endl << endl;
    
    }

}

/*********************************************************************
** Function: populate_spellbook_data
** Description: Fills the spellbook array for all member variables, also uses create_spells() function to make spell array in each spellbook and declare spell member variables
** Parameters: the spellbook array, the number of spellbooks, and the input stream
** Pre-Conditions: the stream is declared
** Post-Conditions: the spellbooks are all full and so are their spells
*********************************************************************/ 

void populate_spellbook_data(Spellbook * spellbook_array, int num_spellbooks, ifstream & f2){
    
    /*
     * Loops through spellbooks
     */
    
    for(int i = 0; i < num_spellbooks; i++){

        f2 >> spellbook_array[i].title >> spellbook_array[i].author >> spellbook_array[i].num_pages >> spellbook_array[i].edition >> spellbook_array[i].num_spells;
        //cout << "Title: " << spellbook_array[i].title << endl << "Author: " << spellbook_array[i].author << endl << "Pages: " << spellbook_array[i].num_pages << endl << "Edition: " << spellbook_array[i].edition << endl << "Spells: " << spellbook_array[i].num_spells << endl << endl;
        
        spellbook_array[i].s = create_spells(spellbook_array[i].num_spells);
        
        float temp = 0;

        /*
         * Loops through spells
         */
        
        for(int j = 0; j < spellbook_array[i].num_spells; j++){
            
            populate_spell_data(spellbook_array[i].s, spellbook_array[i].num_spells, f2, j);
            
            temp += spellbook_array[i].s[j].success_rate;
        
        }
        
        spellbook_array[i].avg_success_rate = temp / spellbook_array[i].num_spells;
        //cout << endl << "Average Success Rate: " << spellbook_array[i].avg_success_rate << endl << endl;
    
    }

}

/*********************************************************************
** Function: populate_spell_data
** Description: populates spell member variables
** Parameters: spell array, number of spells, stream, and spell index
** Pre-Conditions: the stream is declared
** Post-Conditions: the spell is populated
*********************************************************************/ 

void populate_spell_data(Spell *spell_array, int num_spells, ifstream & f2, int spell_index){
    
    f2 >> spell_array[spell_index].name >> spell_array[spell_index].success_rate >> spell_array[spell_index].effect;
    //cout << "Name: " << spell_array[spell_index].name << endl << "Success Rate: " << spell_array[spell_index].success_rate << endl << "Effect: " << spell_array[spell_index].effect << endl;

}

/*********************************************************************
** Function: delete_info
** Description: frees dynamic memory
** Parameters: pointer to wizard array, pointer to spellbook array, and integer for number of spellbooks
** Pre-Conditions: the pointers are correct
** Post-Conditions: no memory leaks
*********************************************************************/ 

void delete_info(Wizard **wizard_array, Spellbook **spellbook_array, int num_spellbooks){
    
    delete [] *wizard_array;

    /*
     * Loops through spellbooks
     */
    
    for(int i = 0; i < num_spellbooks; i++){
        
        delete [] (*spellbook_array)[i].s;
    
    }
    
    delete [] *spellbook_array;

}

/*********************************************************************
** Function: get_wiz_file
** Description: asks the user for a wizard file and opens it
** Parameters: the input stream
** Pre-Conditions: the stream is declared
** Post-Conditions: a file is opened or the program quits
*********************************************************************/ 

int get_wiz_file(ifstream & f1){
    
    cout << endl << "Enter the wizard info file name: ";
    
    string wiz_file_name;
    
    cin >> wiz_file_name;
    
    f1.open(wiz_file_name.c_str());

    /*
     * Checks if the file was opened
     */
    
    if(!f1.is_open()){
        
        cout << endl << "That is not a valid file name." << endl;
        
        return 0;
    
    }
    
    return 1;

}

/*********************************************************************
** Function: get_spellb_file
** Description: the user is asked for a spellbook file and it's opened
** Parameters: input stream
** Pre-Conditions: the stream is declared
** Post-Conditions: the file is opened or program quits
*********************************************************************/ 

int get_spellb_file(ifstream & f2){
    
    cout << endl << "Enter the spellbook info file name: ";
    
    string spellb_file_name;
    
    cin >> spellb_file_name;
    
    f2.open(spellb_file_name.c_str());
    
    /*
     * Checks if the file was opened
     */
    
    if(!f2.is_open()){
        
        cout << endl << "That is not a valid file name." << endl;
        
        return 0;
    
    }
    
    return 1;

}

/*********************************************************************
** Function: get_id
** Description: the user is prompted for their wizard id
** Parameters: an integer to keep track of times they got it wrong
** Pre-Conditions: the user can input
** Post-Conditions: the id is valid
*********************************************************************/ 

int get_id(int &one_wrong) {

    cout << endl << "Please enter your ID: ";

    string id;

    int finished = 0;

    /*
     * Ignores return character if the user hasn't gotten the info wrong yet
     */

    if(one_wrong == 0){
        
        cin.ignore();
   
    }

    /*
     * Loops until valid id is returned
     */

    while(finished == 0){
        
        getline(cin, id);

        /*
        *catches any empty strings
        */

        if(id.empty()){

            cout << endl << "Please enter only integers for your ID: ";
            
            continue;
        
        }

        /*
        *checks if each character in the input string is an int 0-9
        */
        for(int i = 0; i < id.size(); i++){
            
            if(!(id[i] > 47 && id[i] < 58)){
              
                cout << endl << "Please enter only integers for your ID: ";
               
                finished--;
               
                break;
           
            }
        
        }

        finished++;
    }

    return stoi(id);

}

/*********************************************************************
** Function: get_password
** Description: retrieves password from user
** Parameters: none
** Pre-Conditions: user can input
** Post-Conditions: password is valid or program quits
*********************************************************************/ 

string get_password(){
    
    cout << endl << "Please enter your password: ";
    
    string password;
    
    getline(cin, password);
    
    return password;

}

/*********************************************************************
** Function: login
** Description: logs the user in
** Parameters: wizard array and number of wizards
** Pre-Conditions: array is declared
** Post-Conditions: program quits or user info is shown
*********************************************************************/ 

int login(Wizard *wizard_array, int num_wizards){
    
    int one_wrong = 0;

    /*
     * Gives three tries
     */
    
    for(int i = 0; i < 3; i++){
        
        int id;
        
        id = get_id(one_wrong);
        
        string password;
        
        password = get_password();

        /*
         * Loops through all wizards and checks if there is a match
         */
        
        for(int j = 0; j < num_wizards; j++){
            
            if(id == wizard_array[j].id && password == wizard_array[j].password){
                
                cout << endl << "Welcome " << wizard_array[j].name << endl << "ID: " << wizard_array[j].id << endl << "Status: " << wizard_array[j].position_title << endl << "Beard Length: " << wizard_array[j].beard_length << endl;
                
                return j;
           
            }
        
        }
        
        cout << endl << "That is an incorrect id and password combination" << endl;
        
        one_wrong = 1;
    
    }
    
    return -1;

}

/*********************************************************************
** Function: search_and_print
** Description: asks user for search method and then performs that by using different functions
** Parameters: wizard array, spellbook array, number of spellbooks, file output stream, integer to keep track of finished or not
** Pre-Conditions: all arrays are created dynamically
** Post-Conditions: the operation the user chooses gets performed
*********************************************************************/ 

void search_and_print(Wizard *wizard_array, int wizard_index, Spellbook *spellbook_array, int num_spellbooks, ofstream &f3, int &not_finished){
    
    cout << endl << "Which option would you like to choose?" << endl << "1. Search spellbook by its name" << endl << "2. Search spellbooks by number of pages" << endl << "3. Search spells by their effect" << endl << "4. Quit" << endl << "Your Choice: ";
    
    int choice;
    
    cin >> choice;
    
    if(choice == 1){
        
        while(!by_name(wizard_array, wizard_index, spellbook_array, num_spellbooks, get_print_choice(), f3)){
        
        }
    
    }
    
    if(choice == 2){
        
        by_pages(wizard_array, wizard_index, spellbook_array, num_spellbooks, get_print_choice(), f3);
    
    }
    
    if(choice == 3){
    
        by_effect(wizard_array, wizard_index, spellbook_array, num_spellbooks, get_print_choice(), f3);
    
    }
    
    if(choice == 4){
    
        not_finished = 0;
    
    }

}

/*********************************************************************
** Function: by_name
** Description: lets the user search by name of spellbooks
** Parameters: wizard array, wizard user index, spellbook array, number of spellbooks, the choice of print to screen or file, and the output stream
** Pre-Conditions: the user has chosen to print to screen or file
** Post-Conditions: correct info is printed to correct location
*********************************************************************/ 

int by_name(Wizard *wizard_array, int wizard_index, Spellbook *spellbook_array, int num_spellbooks, int print_choice, ofstream &f3){
    
    /*
     * Opens output file
     */
    
    if(print_choice == 2){
        
        cout << endl << "Please provide desired filename: ";
        
        string file_name;
        
        cin >> file_name;
        
        f3.open(file_name.c_str(), ios::app);
    
    }
    
    cout << endl << "Enter the spellbook name: ";
    
    string spellbook_name;
   
    cin >> spellbook_name;

    /*
     * Loops through spellbooks
     */
    
    for(int i = 0; i < num_spellbooks; i++){
        
        if(spellbook_array[i].title == spellbook_name){
            
            if(check_death_poison(wizard_array, wizard_index, spellbook_array, i, spellbook_array[i].num_spells) && print_choice == 1){
                
                cout << endl << "Title: " << spellbook_array[i].title << endl << "Author: " << spellbook_array[i].author << endl << "Number of Pages: " << spellbook_array[i].num_pages << endl << "Edition: " << spellbook_array[i].edition << endl << "Number of Spells: " << spellbook_array[i].num_spells << endl << "Average Success Rate: " << spellbook_array[i].avg_success_rate << endl;
                
                for(int j = 0; j < spellbook_array[i].num_spells; j++){
                    
                    cout << endl << "Spell: " << spellbook_array[i].s[j].name << endl << "Success Rate: " << spellbook_array[i].s[j].success_rate << endl << "Effect: " << spellbook_array[i].s[j].effect << endl;
                
                }
                
                f3.close();

                return 1;
            
            }
           
            else if(check_death_poison(wizard_array, wizard_index, spellbook_array, i, spellbook_array[i].num_spells) && print_choice == 2){
                
                f3 << endl << "Title: " << spellbook_array[i].title << endl << "Author: " << spellbook_array[i].author << endl << "Number of Pages: " << spellbook_array[i].num_pages << endl << "Edition: " << spellbook_array[i].edition << endl << "Number of Spells: " << spellbook_array[i].num_spells << endl << "Average Success Rate: " << spellbook_array[i].avg_success_rate << endl;
                
                for(int j = 0; j < spellbook_array[i].num_spells; j++){
                    
                    f3 << endl << "Spell: " << spellbook_array[i].s[j].name << endl << "Success Rate: " << spellbook_array[i].s[j].success_rate << endl << "Effect: " << spellbook_array[i].s[j].effect << endl;
                
                }
                
                f3.close();

                return 1;
            
            }
            
            else{
                
                cout << endl << "You don't have access to this spellbook as a student." << endl;

                f3.close();
                
                return 0;
            
            }
        
        }
    
    }

    f3.close();
    
    return 0;

}

/*********************************************************************
** Function: by_pages
** Description: outputs spellbooks based on max pages
** Parameters: wizard array, spellbook array, wizard user index, number of spellbooks, choice of print to screen or file, and output stream
** Pre-Conditions: the user has inputted to print to file or screen
** Post-Conditions: the chosen action has been performed to screen or file
*********************************************************************/ 

void by_pages(Wizard *wizard_array, int wizard_index, Spellbook *spellbook_array, int num_spellbooks, int print_choice, ofstream &f3){
    
    /*
     * Opens output file
     */
    
    if(print_choice == 2){
        
        cout << endl << "Please provide desired filename: ";
       
        string file_name;
        
        cin >> file_name;
        
        f3.open(file_name.c_str(), ios::app);
    
    }
    
    cout << endl << "Enter the maximum number of pages: ";
    
    int max_pages;
    
    cin >> max_pages;
    
    int num_shown = 0;

    /*
     * Loops through spellbooks
     */
    
    for(int i = 0; i < num_spellbooks; i++){
        
        if((spellbook_array[i].num_pages <= max_pages) && check_death_poison(wizard_array, wizard_index, spellbook_array, i, spellbook_array[i].num_spells) && print_choice == 1){
           
            cout << endl << "Title: " << spellbook_array[i].title << endl << "Number of Pages: " << spellbook_array[i].num_pages << endl;
            
            num_shown++;
        
        }
        
        else if((spellbook_array[i].num_pages <= max_pages) && check_death_poison(wizard_array, wizard_index, spellbook_array, i, spellbook_array[i].num_spells) && print_choice == 2){
            
            f3 << endl << "Title: " << spellbook_array[i].title << endl << "Number of Pages: " << spellbook_array[i].num_pages << endl;
            
            num_shown++;
        
        }
    
    }
    
    if(num_shown == 0){
        
        cout << "The page limit you entered contains only spellbooks with death or poison effect spells, which you cannot access as a student.";
    
    }

}

/*********************************************************************
** Function: by_effect
** Description: outputs spells based on effect
** Parameters: wizard array, spellbook array, wizard user index, number of spellbooks, choice of print to screen or file, and output stream
** Pre-Conditions: the user has inputted to print to file or screen
** Post-Conditions: the chosen action has been performed to screen or file
*********************************************************************/ 


int by_effect(Wizard *wizard_array, int wizard_index, Spellbook *spellbook_array, int num_spellbooks, int print_choice, ofstream &f3){
    
    /*
     * Opens output file
     */
    
    if(print_choice == 2){
        
        cout << endl << "Please provide desired filename: ";
        
        string file_name;
        
        cin >> file_name;
        
        f3.open(file_name.c_str(), ios::app);
    
    }
    
    cout << endl << "Enter the spell effect: ";
    
    string spell_effect;
    
    cin >> spell_effect;
    
    if((wizard_array[wizard_index].position_title == "Student") && ((spell_effect == "death") || (spell_effect == "poison"))){
        
        cout << endl << "You don't have access to death or posion spells as a student." << endl;
        
        return 0;
    
    }
    
    /*
     * Loops through spellbooks
     */

    for(int i = 0; i < num_spellbooks; i++){
        
        for(int j = 0; j < spellbook_array[i].num_spells; j++){
            
            if(spellbook_array[i].s[j].effect == spell_effect && print_choice == 1){
                
                cout << endl << spell_effect << " " << spellbook_array[i].s[j].name << endl;
            
            }
            
            else if(spellbook_array[i].s[j].effect == spell_effect && print_choice == 2){
                
                f3 << endl << spell_effect << " " << spellbook_array[i].s[j].name << endl;
            
            }
       
        }
    
    }

}

/*********************************************************************
** Function: check_death_poison
** Description: checks if the spellbook has poison or death spells
** Parameters: wizard array, spellbook array, wizard user index, spellbook index, and number of spells
** Pre-Conditions: a spellbook index is given
** Post-Conditions: a 0 or 1 is returned
*********************************************************************/ 


int check_death_poison(Wizard *wizard_array, int wizard_index, Spellbook *spellbook_array, int spellbook_index, int num_spells){
    
    for(int i = 0; i < num_spells; i++){
        
        if(wizard_array[wizard_index].position_title == "Student" && (spellbook_array[spellbook_index].s[i].effect == "death" || spellbook_array[spellbook_index].s[i].effect == "poison")){
           
            return 0;
        
        }
    
    }
    
    return 1;

}

/*********************************************************************
** Function: get_print_choice
** Description: gets input for print to screen or file
** Parameters: none
** Pre-Conditions: the user can input
** Post-Conditions: a string for choice is returned
*********************************************************************/ 

int get_print_choice(){
    
    cout << endl << "How would you like the information displayed?" << endl;
    
    cout << "1. Print to screen (Press 1)" << endl;
    
    cout << "2. Print to file (Press 2)" << endl;
    
    cout << "Your Choice: ";
   
    int print_choice;
    
    cin >> print_choice;
    
    return print_choice;

} 

