#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void outputE();
char graficaE[5][5];
void gameE();
void outputM();
char graficaM[7][7];
void gameM();
void outputH();
char graficaH[9][9];
void gameH();
void change();
char ist;

int main()
{
    char mod;
    bool uscita=true;
    char unita='9';

    system("color C");
    cout<<"____________  ___ _____ _____  ______ _____ ___________ _____ _____ _____ "<<endl;
    cout<<"| ___ \\ ___ \\/ _ \\_   _|  _  | |  ___|_   _|  _  | ___ \\_   _|_   _|  _  |"<<endl;
    cout<<"| |_/ / |_/ / /_\\ \\| | | | | | | |_    | | | | | | |_/ / | |   | | | | | |"<<endl;
    cout<<"|  __/|    /|  _  || | | | | | |  _|   | | | | | |    /  | |   | | | | | |"<<endl;
    cout<<"| |   | |\\ \\| | | || | \\ \\_/ / | |    _| |_\\ \\_/ / |\\ \\ _| |_  | | \\ \\_/ /"<<endl;
    cout<<"\\_|   \\_| \\_\\_| |_/\\_/  \\___/  \\_|    \\___/ \\___/\\_| \\_|\\___/  \\_/  \\___/ "<<endl;
    cout<<"                                                                          "<<endl;
    cout<<endl<<endl;
    Sleep(1000);
    system("cls");

    system("color 6");
    cout<<"Se si vuole leggere le istruzioni digitare Y senno' digitare qualsiasi altro tasto."<<endl;
    cin>>ist;
    if ( ist == 'Y' || ist == 'y')
    {
        do
        {
            cout<<"In questo gioco ti trovi in un prato disseminato di mine, devi cercare di pulire l'area scavando buchi nel terreno senza esplodere, una volta che pulirai una casella ti comparira' in essa a posto di una X il numero di bombe nelle caselle adiacenti, comprese le diagonali, cerca di non saltare in aria e buona fortuna."<<endl;;
            cout<<"Premere un tasto per continuare."<<endl;
            cin>>unita;
            if(unita!='9')
                uscita=false;
        }
        while(uscita);
    }
    cout<<endl<<endl<<endl;

    cout<<"Se vuoi attivare la musica premi Y altrimenti premi un altro tasto qualsiasi."<<endl;
    cin>>ist;
    if ( ist == 'Y' || ist == 'y' )
    {
        sndPlaySound("Sottofondo", SND_LOOP | SND_ASYNC);
    }
    cout<<endl<<endl<<endl;

    cout<<"E' possibile sceglere fra tre modalita' : Semplice, Media e Difficile; inserire la prima lettera della modalità con cui si vuol giocare."<<endl;
    do
    {
        cin>>mod;
        if ( mod== 'S' || mod== 's' )
        {
            gameE();
        }
        if ( mod == 'M' || mod == 'm' )
        {
            gameM();
        }
        if ( mod == 'D' || mod == 'd' )
        {
            gameH();
        }
        if ( mod != 'S' && mod != 's' && mod != 'M' && mod !='m' && mod!='D' && mod != 'd' )
        {
            cout<<"Hai sbagliato a inserire, perfavore inserire S se si vuole giocare con la modalita' semplice, M se si vuole giocare con quella media o D se si vuole giocare con quella difficile."<<endl;
        }
    }
    while( mod != 'S' && mod != 's' && mod != 'M' && mod !='m' && mod!='D' && mod != 'd' );
}

void gameE()
{
    do
    {
        if (ist=='Y'||ist=='y')
        {
        sndPlaySound("Sottofondo", SND_LOOP | SND_ASYNC);
        }
        char boo;
        int z=0;
        int xbomba=0;
        int abombe=0;
        int ybomba=0;
        int uscita=0;
        int matrice[7][7];
        int nbombe=0;

        for(int d=0;d<5;d++)
        {
            for(int k=0;k<5;k++)
            {
                graficaE[k][d]='X';
            }
        }

        for(int n=0;n<7;n++)
        {
            for(int l=0;l<7;l++)
            {
                matrice[n][l]=0;
            }
        }

        srand(time(NULL));
        nbombe=5+rand()%5;

        for(int i=0; i<nbombe; i++)
        {
            xbomba=1+rand()%5;
            ybomba=1+rand()%5;
            if(matrice[xbomba][ybomba]==0)
            {
                matrice[xbomba][ybomba]=1;
            }
            else
            {
                i--;
            }
        }

        system("cls");
        system("color E");
        outputE();

        do
        {

            z++;

            cout<<endl<<"Inserire in che riga scavare :"<<endl;
            cin>>xbomba;
            cout<<"Inserire in che colonna scavare :"<<endl;
            cin>>ybomba;

            if (matrice[xbomba][ybomba]==1)
            {
                uscita=1;
            }

            else if (matrice[xbomba][ybomba]==0)
            {
                abombe=matrice[xbomba-1][ybomba-1]+matrice[xbomba-1][ybomba]+matrice[xbomba-1][ybomba+1]+matrice[xbomba][ybomba-1]+matrice[xbomba][ybomba+1]+matrice[xbomba+1][ybomba-1]+matrice[xbomba+1][ybomba]+matrice[xbomba+1][ybomba+1];
                xbomba--;
                ybomba--;

                switch (abombe)
                {
                case 0:
                    graficaE[xbomba][ybomba]='0';
                    break;
                case 1:
                    graficaE[xbomba][ybomba]='1';
                    break;
                case 2:
                    graficaE[xbomba][ybomba]='2';
                    break;
                case 3:
                    graficaE[xbomba][ybomba]='3';
                    break;
                case 4:
                    graficaE[xbomba][ybomba]='4';
                    break;
                case 5:
                    graficaE[xbomba][ybomba]='5';
                    break;
                case 6:
                    graficaE[xbomba][ybomba]='6';
                    break;
                case 7:
                    graficaE[xbomba][ybomba]='7';
                    break;
                case 8:
                    graficaE[xbomba][ybomba]='8';
                    break;
                }
                system("cls");
                outputE();
            }
        }
        while((z<(25-nbombe)) && uscita==0);

        if (z<(25-nbombe))
        {
            system("cls");
            cout<<"HAI PERSO"<<endl;
            if(ist =='y'|| ist=='Y')
            {
                sndPlaySound("Sconfitta", SND_LOOP | SND_ASYNC);
            }
            Sleep(3000);
        }
        else if (z=(25-nbombe))
        {
            system("cls");
            cout<<"HAI VINTO"<<endl;
            if(ist=='y'||ist=='Y')
            {
                sndPlaySound("Vittoria", SND_LOOP | SND_ASYNC);
            }
            Sleep(3000);
        }

        for(int tt=0;tt<5;tt++)
        {
            for(int rr=0;rr<5;rr++)
            {
                graficaE[tt][rr]=' ';
            }
        }

        system("color C");
        for(int q=0;q<5;q++)
        {
            for(int p=0;p<5;p++)
            {
                cout<<"Vediamo insieme dove erano le bombe (le O simboleggiano le bombe)"<<endl;
                outputE();
                system("cls");
                if(matrice[q+1][p+1]==1)
                {
                    graficaE[q][p]='O';
                    cout<<"Vediamo insieme dove erano le bombe (le O simboleggiano le bombe)"<<endl;
                    outputE();
                    Sleep(1000);
                    system("cls");
                }
            }
        }
        cout<<"Vediamo insieme dove erano le bombe (le O simboleggiano le bombe)"<<endl;
        outputE();
        Sleep(3000);
        system("cls");

        cout<<"Se vuoi cambiare modalita' premi C altrimenti premi un tasto qualsiasi per rigiocare."<<endl;
        cin>>boo;
        if ( boo == 'C' || boo == 'c')
        {
            change();
        }
    }
    while(true);
}

void gameM()
{
    do
    {
        if (ist=='Y'||ist=='y')
        {
        sndPlaySound("Sottofondo", SND_LOOP | SND_ASYNC);
        }
        char boo;
        int z=0;
        int xbomba=0;
        int abombe=0;
        int ybomba=0;
        int uscita=0;
        int matrice[9][9];
        int nbombe=0;

        for(int d=0;d<7;d++)
        {
            for(int k=0;k<7;k++)
            {
                graficaM[k][d]='X';
            }
        }

        for(int n=0;n<9;n++)
        {
            for(int l=0;l<9;l++)
            {
                matrice[n][l]=0;
            }
        }

        srand(time(NULL));
        nbombe=10+rand()%10;

        for(int i=0; i<nbombe; i++)
        {
            xbomba=1+rand()%7;
            ybomba=1+rand()%7;
            if(matrice[xbomba][ybomba]==0)
            {
                matrice[xbomba][ybomba]=1;
            }
            else
            {
                i--;
            }
        }

        system("cls");
        system("color E");
        outputM();

        do
        {

            z++;

            cout<<endl<<"Inserire in che riga scavare :"<<endl;
            cin>>xbomba;
            cout<<"Inserire in che colonna scavare :"<<endl;
            cin>>ybomba;

            if (matrice[xbomba][ybomba]==1)
            {
                uscita=1;
            }

            else if (matrice[xbomba][ybomba]==0)
            {
                abombe=matrice[xbomba-1][ybomba-1]+matrice[xbomba-1][ybomba]+matrice[xbomba-1][ybomba+1]+matrice[xbomba][ybomba-1]+matrice[xbomba][ybomba+1]+matrice[xbomba+1][ybomba-1]+matrice[xbomba+1][ybomba]+matrice[xbomba+1][ybomba+1];
                xbomba--;
                ybomba--;

                switch (abombe)
                {
                case 0:
                    graficaM[xbomba][ybomba]='0';
                    break;
                case 1:
                    graficaM[xbomba][ybomba]='1';
                    break;
                case 2:
                    graficaM[xbomba][ybomba]='2';
                    break;
                case 3:
                    graficaM[xbomba][ybomba]='3';
                    break;
                case 4:
                    graficaM[xbomba][ybomba]='4';
                    break;
                case 5:
                    graficaM[xbomba][ybomba]='5';
                    break;
                case 6:
                    graficaM[xbomba][ybomba]='6';
                    break;
                case 7:
                    graficaM[xbomba][ybomba]='7';
                    break;
                case 8:
                    graficaM[xbomba][ybomba]='8';
                    break;
                }
                system("cls");
                outputM();
            }
        }
        while((z<(49-nbombe)) && uscita==0);

        if (z<(49-nbombe))
        {
            system("cls");
            cout<<"HAI PERSO"<<endl;
            if(ist =='y'|| ist=='Y')
            {
                sndPlaySound("Sconfitta", SND_LOOP | SND_ASYNC);
            }
            Sleep(3000);
        }
        else if (z=(49-nbombe))
        {
            system("cls");
            cout<<"HAI VINTO"<<endl;
            if(ist=='y'||ist=='Y')
            {
                sndPlaySound("Vittoria", SND_LOOP | SND_ASYNC);
            }
            Sleep(3000);
        }

        for(int tt=0;tt<7;tt++)
        {
            for(int rr=0;rr<7;rr++)
            {
                graficaM[tt][rr]=' ';
            }
        }

        system("color C");
        for(int q=0;q<7;q++)
        {
            for(int p=0;p<7;p++)
            {
                cout<<"Vediamo insieme dove erano le bombe (le O simboleggiano le bombe)"<<endl;
                outputM();
                system("cls");
                if(matrice[q+1][p+1]==1)
                {
                    graficaM[q][p]='O';
                    cout<<"Vediamo insieme dove erano le bombe (le O simboleggiano le bombe)"<<endl;
                    outputM();
                    Sleep(1000);
                    system("cls");
                }
            }
        }
        cout<<"Vediamo insieme dove erano le bombe (le O simboleggiano le bombe)"<<endl;
        outputM();
        Sleep(3000);
        system("cls");

        cout<<"Se vuoi cambiare modalita' premi C altrimenti premi un tasto qualsiasi per rigiocare."<<endl;
        cin>>boo;
        if ( boo == 'C' || boo == 'c')
        {
            change();
        }
    }
    while(true);
}

void gameH()
{
    do
    {
        if (ist=='Y'||ist=='y')
        {
        sndPlaySound("Sottofondo", SND_LOOP | SND_ASYNC);
        }
        char boo;
        int z=0;
        int xbomba=0;
        int abombe=0;
        int ybomba=0;
        int uscita=0;
        int matrice[11][11];
        int nbombe=0;

        for(int d=0;d<9;d++)
        {
            for(int k=0;k<9;k++)
            {
                graficaH[k][d]='X';
            }
        }

        for(int n=0;n<11;n++)
        {
            for(int l=0;l<11;l++)
            {
                matrice[n][l]=0;
            }
        }

        srand(time(NULL));
        nbombe=30+rand()%10;

        for(int i=0; i<nbombe; i++)
        {
            xbomba=1+rand()%9;
            ybomba=1+rand()%9;
            if(matrice[xbomba][ybomba]==0)
            {
                matrice[xbomba][ybomba]=1;
            }
            else
            {
                i--;
            }
        }

        system("cls");
        system("color E");
        outputH();

        do
        {

            z++;

            cout<<endl<<"Inserire in che riga scavare :"<<endl;
            cin>>xbomba;
            cout<<"Inserire in che colonna scavare :"<<endl;
            cin>>ybomba;

            if (matrice[xbomba][ybomba]==1)
            {
                uscita=1;
            }

            else if (matrice[xbomba][ybomba]==0)
            {
                abombe=matrice[xbomba-1][ybomba-1]+matrice[xbomba-1][ybomba]+matrice[xbomba-1][ybomba+1]+matrice[xbomba][ybomba-1]+matrice[xbomba][ybomba+1]+matrice[xbomba+1][ybomba-1]+matrice[xbomba+1][ybomba]+matrice[xbomba+1][ybomba+1];
                xbomba--;
                ybomba--;

                switch (abombe)
                {
                case 0:
                    graficaH[xbomba][ybomba]='0';
                    break;
                case 1:
                    graficaH[xbomba][ybomba]='1';
                    break;
                case 2:
                    graficaH[xbomba][ybomba]='2';
                    break;
                case 3:
                    graficaH[xbomba][ybomba]='3';
                    break;
                case 4:
                    graficaH[xbomba][ybomba]='4';
                    break;
                case 5:
                    graficaH[xbomba][ybomba]='5';
                    break;
                case 6:
                    graficaH[xbomba][ybomba]='6';
                    break;
                case 7:
                    graficaH[xbomba][ybomba]='7';
                    break;
                case 8:
                    graficaH[xbomba][ybomba]='8';
                    break;
                }
                system("cls");
                outputH();
            }
        }
        while((z<(81-nbombe)) && uscita==0);

        if (z<(81-nbombe))
        {
            system("cls");
            cout<<"HAI PERSO"<<endl;
            if(ist =='y'|| ist=='Y')
            {
                sndPlaySound("Sconfitta", SND_LOOP | SND_ASYNC);
            }
            Sleep(3000);
        }
        else if (z=(81-nbombe))
        {
            system("cls");
            cout<<"HAI VINTO"<<endl;
            if(ist=='y'||ist=='Y')
            {
                sndPlaySound("Vittoria", SND_LOOP | SND_ASYNC);
            }
            Sleep(3000);
        }

        for(int tt=0;tt<9;tt++)
        {
            for(int rr=0;rr<9;rr++)
            {
                graficaH[tt][rr]=' ';
            }
        }

        system("color C");
        for(int q=0;q<9;q++)
        {
            for(int p=0;p<9;p++)
            {
                cout<<"Vediamo insieme dove erano le bombe (le O simboleggiano le bombe)"<<endl;
                outputH();
                system("cls");
                if(matrice[q+1][p+1]==1)
                {
                    graficaH[q][p]='O';
                    cout<<"Vediamo insieme dove erano le bombe (le O simboleggiano le bombe)"<<endl;
                    outputH();
                    Sleep(1000);
                    system("cls");
                }
            }
        }
        cout<<"Vediamo insieme dove erano le bombe (le O simboleggiano le bombe)"<<endl;
        outputH();
        Sleep(3000);
        system("cls");

        cout<<"Se vuoi cambiare modalita' premi C altrimenti premi un tasto qualsiasi per rigiocare."<<endl;
        cin>>boo;
        if ( boo == 'C' || boo == 'c')
        {
            change();
        }
    }
    while(true);
}

void change()
{
    sndPlaySound("Sottofondo", SND_LOOP | SND_ASYNC);
    system("cls");
    char mod;
    system("color 6");
    cout<<"Hail scelto di cambiare la modalita' di gioco."<<endl<<"Inserire S se si vuole giocare con la modalita' semplice, M se si vuole giocare con quella media o D se si vuole giocare con quella difficile."<<endl;
    do
    {
        cin>>mod;
        if ( mod== 'S' || mod== 's' )
        {
            gameE();
        }
        if ( mod == 'M' || mod == 'm' )
        {
            gameM();
        }
        if ( mod == 'D' || mod == 'd' )
        {
            gameH();
        }
        if ( mod != 'S' && mod != 's' && mod != 'M' && mod !='m' && mod!='D' && mod != 'd' )
        {
            cout<<"Hai sbagliato a inserire, perfavore inserire S se si vuole giocare con la modalità semplice, M se si vuole giocare con quella media o D se si vuole giocare con quella difficile."<<endl;
        }
    }
    while( mod != 'S' && mod != 's' && mod != 'M' && mod !='m' && mod!='D' && mod != 'd' );
}

void outputE()
{
    cout<<endl;
    cout<<"   | 1 | 2 | 3 | 4 | 5"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<" 1 | "<<graficaE[0][0]<<" | "<<graficaE[0][1]<<" | "<<graficaE[0][2]<<" | "<<graficaE[0][3]<<" | "<<graficaE[0][4]<<endl;
    cout<<"-----------------------"<<endl;
    cout<<" 2 | "<<graficaE[1][0]<<" | "<<graficaE[1][1]<<" | "<<graficaE[1][2]<<" | "<<graficaE[1][3]<<" | "<<graficaE[1][4]<<endl;
    cout<<"-----------------------"<<endl;
    cout<<" 3 | "<<graficaE[2][0]<<" | "<<graficaE[2][1]<<" | "<<graficaE[2][2]<<" | "<<graficaE[2][3]<<" | "<<graficaE[2][4]<<endl;
    cout<<"-----------------------"<<endl;
    cout<<" 4 | "<<graficaE[3][0]<<" | "<<graficaE[3][1]<<" | "<<graficaE[3][2]<<" | "<<graficaE[3][3]<<" | "<<graficaE[3][4]<<endl;
    cout<<"-----------------------"<<endl;
    cout<<" 5 | "<<graficaE[4][0]<<" | "<<graficaE[4][1]<<" | "<<graficaE[4][2]<<" | "<<graficaE[4][3]<<" | "<<graficaE[4][4]<<endl;
}

void outputM()
{
    cout<<endl;
    cout<<"   | 1 | 2 | 3 | 4 | 5 | 6 | 7"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<" 1 | "<<graficaM[0][0]<<" | "<<graficaM[0][1]<<" | "<<graficaM[0][2]<<" | "<<graficaM[0][3]<<" | "<<graficaM[0][4]<<" | "<<graficaM[0][5]<<" | "<<graficaM[0][6]<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<" 2 | "<<graficaM[1][0]<<" | "<<graficaM[1][1]<<" | "<<graficaM[1][2]<<" | "<<graficaM[1][3]<<" | "<<graficaM[1][4]<<" | "<<graficaM[1][5]<<" | "<<graficaM[1][6]<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<" 3 | "<<graficaM[2][0]<<" | "<<graficaM[2][1]<<" | "<<graficaM[2][2]<<" | "<<graficaM[2][3]<<" | "<<graficaM[2][4]<<" | "<<graficaM[2][5]<<" | "<<graficaM[2][6]<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<" 4 | "<<graficaM[3][0]<<" | "<<graficaM[3][1]<<" | "<<graficaM[3][2]<<" | "<<graficaM[3][3]<<" | "<<graficaM[3][4]<<" | "<<graficaM[3][5]<<" | "<<graficaM[3][6]<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<" 5 | "<<graficaM[4][0]<<" | "<<graficaM[4][1]<<" | "<<graficaM[4][2]<<" | "<<graficaM[4][3]<<" | "<<graficaM[4][4]<<" | "<<graficaM[4][5]<<" | "<<graficaM[4][6]<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<" 6 | "<<graficaM[5][0]<<" | "<<graficaM[5][1]<<" | "<<graficaM[5][2]<<" | "<<graficaM[5][3]<<" | "<<graficaM[5][4]<<" | "<<graficaM[5][5]<<" | "<<graficaM[5][6]<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<" 7 | "<<graficaM[6][0]<<" | "<<graficaM[6][1]<<" | "<<graficaM[6][2]<<" | "<<graficaM[6][3]<<" | "<<graficaM[6][4]<<" | "<<graficaM[6][5]<<" | "<<graficaM[6][6]<<endl;
}

void outputH()
{
    cout<<endl;
    cout<<"   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<" 1 | "<<graficaH[0][0]<<" | "<<graficaH[0][1]<<" | "<<graficaH[0][2]<<" | "<<graficaH[0][3]<<" | "<<graficaH[0][4]<<" | "<<graficaH[0][5]<<" | "<<graficaH[0][6]<<" | "<<graficaH[0][7]<<" | "<<graficaH[0][8]<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<" 2 | "<<graficaH[1][0]<<" | "<<graficaH[1][1]<<" | "<<graficaH[1][2]<<" | "<<graficaH[1][3]<<" | "<<graficaH[1][4]<<" | "<<graficaH[1][5]<<" | "<<graficaH[1][6]<<" | "<<graficaH[1][7]<<" | "<<graficaH[1][8]<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<" 3 | "<<graficaH[2][0]<<" | "<<graficaH[2][1]<<" | "<<graficaH[2][2]<<" | "<<graficaH[2][3]<<" | "<<graficaH[2][4]<<" | "<<graficaH[2][5]<<" | "<<graficaH[2][6]<<" | "<<graficaH[2][7]<<" | "<<graficaH[2][8]<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<" 4 | "<<graficaH[3][0]<<" | "<<graficaH[3][1]<<" | "<<graficaH[3][2]<<" | "<<graficaH[3][3]<<" | "<<graficaH[3][4]<<" | "<<graficaH[3][5]<<" | "<<graficaH[3][6]<<" | "<<graficaH[3][7]<<" | "<<graficaH[3][8]<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<" 5 | "<<graficaH[4][0]<<" | "<<graficaH[4][1]<<" | "<<graficaH[4][2]<<" | "<<graficaH[4][3]<<" | "<<graficaH[4][4]<<" | "<<graficaH[4][5]<<" | "<<graficaH[4][6]<<" | "<<graficaH[4][7]<<" | "<<graficaH[4][8]<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<" 6 | "<<graficaH[5][0]<<" | "<<graficaH[5][1]<<" | "<<graficaH[5][2]<<" | "<<graficaH[5][3]<<" | "<<graficaH[5][4]<<" | "<<graficaH[5][5]<<" | "<<graficaH[5][6]<<" | "<<graficaH[5][7]<<" | "<<graficaH[5][8]<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<" 7 | "<<graficaH[6][0]<<" | "<<graficaH[6][1]<<" | "<<graficaH[6][2]<<" | "<<graficaH[6][3]<<" | "<<graficaH[6][4]<<" | "<<graficaH[6][5]<<" | "<<graficaH[6][6]<<" | "<<graficaH[6][7]<<" | "<<graficaH[6][8]<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<" 8 | "<<graficaH[7][0]<<" | "<<graficaH[7][1]<<" | "<<graficaH[7][2]<<" | "<<graficaH[7][3]<<" | "<<graficaH[7][4]<<" | "<<graficaH[7][5]<<" | "<<graficaH[7][6]<<" | "<<graficaH[7][7]<<" | "<<graficaH[7][8]<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<" 9 | "<<graficaH[8][0]<<" | "<<graficaH[8][1]<<" | "<<graficaH[8][2]<<" | "<<graficaH[8][3]<<" | "<<graficaH[8][4]<<" | "<<graficaH[8][5]<<" | "<<graficaH[8][6]<<" | "<<graficaH[8][7]<<" | "<<graficaH[8][8]<<endl;
}
