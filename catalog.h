/*********************************************************************
** Program Filename: catalog.h
** Author: Joshua Spisak
** Date: 02/03/2023
** Description: This is the header file that contains the pre-processing, structure definitions, and function prototypes.
** Input: There is no input.
** Output: There is no output.
*********************************************************************/

#include <iostream>

#include <fstream>

#include <string>

using namespace std;

struct Wizard {

    string name;
    int id;
    string password;
    string position_title; 
    float beard_length;

};

struct Spellbook {

    string title;
    string author;
    int num_pages;
    int edition;
    int num_spells;
    float avg_success_rate;
    struct Spell *s;

};


struct Spell {

    string name;
    float success_rate;
    string effect; 

};

Wizard * create_wizards(int);
Spellbook * create_spellbooks(int);
Spell * create_spells(int);
void populate_wizard_data(Wizard *, int, ifstream &);
void populate_spellbook_data(Spellbook *, int, ifstream &);
void populate_spell_data(Spell *, int, ifstream &, int);
void delete_info(Wizard **, Spellbook **, int);
int get_wiz_file(ifstream &);
int get_spellb_file(ifstream &);
int get_id(int &);
string get_password();
int login(Wizard *, int);
void search_and_print(Wizard *, int, Spellbook *, int, ofstream &, int&);
int by_name(Wizard *, int, Spellbook *, int, int, ofstream &);
void by_pages(Wizard *, int, Spellbook *, int, int, ofstream &);
int by_effect(Wizard *, int, Spellbook *, int, int, ofstream &);
int check_death_poison(Wizard *, int, Spellbook *, int, int);
int get_print_choice();