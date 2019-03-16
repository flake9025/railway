//---------------------------------------------------------------------------
//CREATEUR DE CHEMIN DE FER
//(c) 2007 JOEL MOLL - VINCENT VILLAIN
//C++ Builder 6.0
//Fonctions
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Includes
//---------------------------------------------------------------------------

#pragma hdrstop
#include <fstream.h>
#include "Unit1.h"
#include "Unit7.h"
#pragma package(smart_init)

//---------------------------------------------------------------------------
//Fonction Création d'un mémo
//Paramètres :  Position en pixels à partir de la gauche
//              Position en pixels à partir du haut
//              Form sur laquelle afficher
//---------------------------------------------------------------------------
TMemo* creerMemo(int left,int top,TForm *form)
{
        TMemo *m=new TMemo(form);
        m->Parent=form;
        m->Left=left;
        m->Top=top;
        m->Width=100;
        m->Height=120;
        m->Alignment=taCenter;
        return m;
}

//---------------------------------------------------------------------------
//Fonction Création d'un label
//Paramètres :  Position à partir de la gauche
//              Position à partir du haut
//              Libellé
//              Form sur laquelle afficher
//---------------------------------------------------------------------------
TLabel* creerLabel(int left,int top,AnsiString caption,TForm *form)
{
        TLabel *l=new TLabel(form);
        l->Parent=form;
        l->Left=left;
        l->Top=top;
        l->Caption=caption;
        return l;
}

//---------------------------------------------------------------------------
//Fonction Effacer un memo
//---------------------------------------------------------------------------
void effaceMemo(TMemo *m)
{
        if(m!=NULL)
        {
                m->Visible=false;
                m=NULL;
        }
}

//---------------------------------------------------------------------------
//Fonction Effacer un label
//---------------------------------------------------------------------------
void effaceLabel(TLabel *l)
{
        if(l!=NULL)
        {
                l->Visible=false;
                l=NULL;
        }
}

//---------------------------------------------------------------------------
//Fonction lire texte Memo depuis fichier
//Paramètres :  Memo qui recevra le texte
//              Fichier à lire
//---------------------------------------------------------------------------
void lireTexteMemo(TMemo *m,fstream *f)
{
        int lignesVides=0;
        char ligne[255];
        do
        {
                (*f).getline(ligne,255);
                if(strcmp(ligne,"\r\n")==0)
                {
                        lignesVides++;
                        m->Text=m->Text+"\r\n";
                }else{
                        if(strcmp(ligne,"*%*%*")!=0)
                                m->Text=m->Text+ligne+"\r\n";
                        lignesVides=0;
                }
        }while(strcmp(ligne,"*%*%*")!=0 && lignesVides<5);
}

//---------------------------------------------------------------------------
//Fonction Création d'un mémo de couverture
//Paramètres :  Position à partir de la gauche
//              Position à partir du haut
//              Booléen de couverture active (cochée)
//              Booléen d'ouverture de projet depuis un fichier
//              Fichier à lire
//              Label associé à la couverture
//              Form sur laquelle afficher
//---------------------------------------------------------------------------
TMemo* creerMemoCouv(int left,int top,bool *active,bool *fromFile,fstream *f,TLabel *l,TForm *form)
{
        //Creation du mémo
        TMemo *m=creerMemo(left,top,form);
        //Création du label
        if(*active)
        {
                if(*fromFile)
                        lireTexteMemo(m,f);
        }else{
                m->Visible=false;
                l->Visible=false;
        }
        return m;
}

//---------------------------------------------------------------------------
//Fonction Ecrire Memo dans un fichier
//Paramètres :  Fichier de sauvegarde
//              Memo
//---------------------------------------------------------------------------
void ecrireMemo(std::ofstream *f,TMemo *m)
{
        *f<<m->Text.c_str()<<"\n";
        *f<<"*%*%*"<<"\n";
}

//---------------------------------------------------------------------------
//Fonction Ecrire booléen dans un fichier
//Paramètres :  Fichier de sauvegarde
//              Booléen
//---------------------------------------------------------------------------
void ecrireBooleen(std::ofstream *f,bool *b)
{
       if(*b)
                *f<<"1"<<"\n";
       else
                *f<<"0"<<"\n";
}

