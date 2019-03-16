//---------------------------------------------------------------------------
//CREATEUR DE CHEMIN DE FER
//(c) 2007 JOEL MOLL - VINCENT VILLAIN
//C++ Builder 6.0
//Form d'insertion
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Includes
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit3.h"
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
//Variables Globales
//---------------------------------------------------------------------------

//Form
TForm3 *Form3;
//Booleens de couvertures
extern bool couv1,couv2,couv3,couv4;
//Nombre de pages du chemin de fer
extern int nbPages;
//Tableau des pages
extern TMemo *tabMemos [1000];
//Memos Couvertures
extern TMemo *memoCouv1;
extern TMemo *memoCouv2;
extern TMemo *memoCouv3;
extern TMemo *memoCouv4;
//Fonctions
extern void effaceEcran();
extern void cheminDeFer(bool fromFile);

//---------------------------------------------------------------------------
//Création de la form
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
        UpDown1->Max=500-nbPages;
        UpDown2->Max=nbPages;
}

//---------------------------------------------------------------------------
//Bouton Annuler
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
        Form3->Visible=false;
}

//---------------------------------------------------------------------------
//Bouton OK
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
        int nbPagesInsert=E_nbPages->Text.ToInt();
        if(nbPagesInsert<=0 || nbPagesInsert>UpDown1->Max)
        {
                Application->MessageBox("Nombre de pages à insérer invalide","CheminDeFer - Insertion",MB_OK | MB_ICONERROR);
                return;
        }
        int noPageInsert=E_nPage->Text.ToInt();
        if(noPageInsert<0 || noPageInsert>UpDown2->Max)
        {
                Application->MessageBox("Page référence invalide","CheminDeFer - Insertion",MB_OK | MB_ICONERROR);
                return;
        }

        TMemo *tabBackup [500];
        TMemo *memoCouv1backup=memoCouv1;
        TMemo *memoCouv2backup=memoCouv2;
        TMemo *memoCouv3backup=memoCouv3;
        TMemo *memoCouv4backup=memoCouv4;

        for(int i=0;i<500;i++)
                tabBackup[i]=tabMemos[i];

        effaceEcran();
        nbPages=nbPages+nbPagesInsert;
        cheminDeFer(false);

        int i=0;
        int index=noPageInsert;

        while(i!=index)
        {
               tabMemos[i]->Text=tabBackup[i]->Text;
               i++;
        }

        int i2=index+nbPagesInsert;

        while(tabMemos[i2]!=NULL)
        {
               tabMemos[i2]->Text=tabBackup[i]->Text;
               i++;
               i2++;
        }

        if(couv1)
                memoCouv1->Text=memoCouv1backup->Text;
        if(couv2)
                memoCouv2->Text=memoCouv2backup->Text;
        if(couv3)
                memoCouv3->Text=memoCouv3backup->Text;
        if(couv4)
                memoCouv4->Text=memoCouv4backup->Text;

        Form3->Visible=false;
}
//---------------------------------------------------------------------------
