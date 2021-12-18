#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define NC "\e[0m"
#define CYN "\e[0;36m"

using namespace std;

int main()
{
    string rejouer;
    do
    {
        char mode;
        cout << NC"Bonjour, voici le jeux du pendu ! 2 modes s'offre a vous, le premier est un mot a deviner simple, \n le deuxieme est un mot tirer au hasard parmi 20 choix.\n\n Lequels de ces 2 modes voulez vous ? (1/2)\n";

        cin >> mode;

        if (mode == '1')
        {
            char mot[10] = {"cartable"}, lettre = {};
            bool essaie = false;
            int tentative = 10;
            int nbrlettre = strlen(mot);
            string leMot = mot;

            cout << NC"Tu as choisie le premier mode, excellent choix" << endl;
            cout << NC"c'est partie le mot est en 8 lettres bonne chance !" << endl;
            char rslt[10] = {};

            for (int i = 0; i < nbrlettre; i++)
            {
                rslt[i] = '_';
            }
            cout << rslt << endl;
            cout << NC"Entrez une lettre pour devinez le mot" << endl;

            int y = 0;

            for (int y = 0; y < tentative; y++)
            {
                cin >>lettre;

                for (int h = 0; h < strlen(rslt); h++)
                {
                    if (lettre == leMot[h])
                    {
                        rslt[h] = lettre;
                        essaie = true;
                    }
                }
                if (essaie == false)
                {
                    cout << RED"tu n'as pas trouver de lettre" << endl;
                    cout << rslt << endl;
                    cout << RED"Il te reste " << tentative - y - 1 << RED" tentatives" << endl;
                }
                if (essaie == true)
                {
                    tentative++;
                    cout << GRN"tu as trouver la lettre: " << lettre << endl;
                    cout << rslt << endl;
                    essaie = false;
                }
                if (rslt == leMot)
                {
                    cout << GRN"Tu as gagner" << endl;
                    break;
                }
                if (y + 1 >= tentative)
                {
                    cout << RED"Tu as perdu dommage" << endl;
                }
            }
        }

        else if (mode == '2')
        {

            char mot[20][30] = {{"cartable"}, {"avion"}, {"porte"}, {"rideau"}, {"ordi"}, {"table"}, {"voiture"}, {"ordinateur"}, {"telephone"}, {"fil"}, {"parking"}, {"anticonstitutionellement"}, {"france"}, {"clavier"}, {"chaise"}, {"souris"}, {"SNIR"}, {"bts"}, {"pellouse"}, {"confinement"}}, lettre = {};
            srand((unsigned int)time(0));
            int valeur = rand() % 20;
            bool essaie = false;
            int tentative = 10;

            int nbrlettre = strlen(mot[valeur]);
            string leMot = mot[valeur];

            cout << NC"Tu as choisie le deuxieme mode, excellent choix" << endl;
            cout << NC"c'est partie le mot est en " << nbrlettre << " lettres bonne chance !" << endl;
            char rslt[10] = {};

            for (int i = 0; i < nbrlettre; i++)
            {
                rslt[i] = '_';
            }
            cout << rslt << endl;
            cout << NC"Entrez une lettre pour devinez le mot" << endl;

            for (int y = 0; y < tentative; y++)
            {
                cin >> lettre;

                for (int h = 0; h < strlen(rslt); h++)
                {
                    if (lettre == leMot[h])
                    {
                        rslt[h] = lettre;
                        essaie = true;
                    }
                }
                if (essaie == false)
                {
                    cout << RED"tu n'as pas trouver de lettre" << endl;
                    cout << rslt << endl;
                    cout << RED"Il te reste " << tentative - y - 1 << RED" tentatives" << endl;
                }
                if (essaie == true)
                {
                    tentative++;
                    cout << GRN"tu as trouver la lettre: " << lettre << endl;
                    cout << rslt << endl;
                    essaie = false;
                }
                if (rslt == leMot)
                {
                    cout << GRN"Tu as gagner" << endl;
                    break;
                }
                if (y + 1 >= tentative)
                {
                    cout << RED"Tu as perdu dommage" << endl;
                }
            }
        }
        cout<<CYN"voulez vous recommencer une autre partie de pendu , oui/non ?\n";
        cin>>rejouer;
    } while (rejouer == "oui");
}