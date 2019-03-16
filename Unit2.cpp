//---------------------------------------------------------------------------
//CREATEUR DE CHEMIN DE FER
//(c) 2007 JOEL MOLL - VINCENT VILLAIN
//C++ Builder 6.0
//Form de saisie des paramètres
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Includes
//---------------------------------------------------------------------------

#pragma hdrstop
#include <fstream.h>
#include <stdio.h>
#include <string.h>
#include <vcl.h>
#include "Unit1.h"
#include "Unit2.h"
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
//Variables Globales
//---------------------------------------------------------------------------

//Form Builder de démarrage
TForm1 *Form1;
//Booleens de couvertures
extern bool couv1,couv2,couv3,couv4;
//Fichier à lire
extern fstream ficCdf;
extern char ligne[255];
extern AnsiString titre;
//Nombre de pages du chemin de fer
extern int nbPages;
//Fonctions
extern void effaceEcran();
extern void cheminDeFer(bool fromFile);

//---------------------------------------------------------------------------
//Création de la form
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

//---------------------------------------------------------------------------
//Clic bouton de validation des paramètres
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//Test champ nombre de pages vide
if(E_nbpages->Text=="" || E_nbpages->Text.ToInt()>1000)
{
        Application->MessageBox("Veuillez préciser un nombre de pages, inférieur a 1000","CheminDeFer - Information",MB_OK | MB_ICONINFORMATION);
        return;
}

//Test champ titre vide
if(E_Titre->Text=="")
{
        Application->MessageBox("Veuillez préciser un titre","CheminDeFer - Information",MB_OK | MB_ICONINFORMATION );
        return;
}

//Init Projet
effaceEcran();

if(Form1->CB_couv1->Checked==true)
        couv1=true;
else
        couv1=false;
if(Form1->CB_couv2->Checked==true)
        couv2=true;
else
        couv2=false;
if(Form1->CB_couv3->Checked==true)
        couv3=true;
else
        couv3=false;
if(Form1->CB_couv4->Checked==true)
        couv4=true;
else
        couv4=false;

//Conversion nombre de pages : champ texte -> entier
nbPages=E_nbpages->Text.ToInt();

//Affichage de la form chemin de fer
Form1->Visible=false;
Form2->Visible=true;
Form2->Caption="Créateur de Chemin De Fer v1.1 - <nouveau projet>";
titre=E_Titre->Text;
Form2->label_Titre->Caption=titre;

cheminDeFer(false);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Form1->Visible=false;
}
//---------------------------------------------------------------------------

