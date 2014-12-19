#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <fstream>

using namespace std;

class Weapon
{
    /*
    Mili-Spec = 1
    Restricted = 2
    Classified = 3
    Covert = 4
    Knife = 5
    */
    public:
        int itemQuality;
        string weaponName;
        void setName(string Name)
        {
            weaponName = Name;
        }
        void setItemQuality(int Quality)
        {
            itemQuality = Quality;
        }
};

class Case
{
    int miliSpecCount;
    int restrictedCount;
    int classifiedCount;
    int covertCount;
    int knifeCount;

    public:
        Weapon miliSpec[10];
        Weapon restricted[10];
        Weapon classified[10];
        Weapon covert[10];
        Weapon KnifeList[15];

        Case(Weapon ItemsA[], int a, Weapon ItemsB[], int b, Weapon ItemsC[], int c, Weapon ItemsD[], int d, Weapon ItemsE[], int e)
        {
            miliSpecCount = a;
            restrictedCount = b;
            classifiedCount = c;
            covertCount = d;
            knifeCount = e;

            for (int x=0; x < miliSpecCount; x++)
            {
                miliSpec[x] = ItemsA[x];
            }
            for (int x=0; x < restrictedCount; x++)
            {
                restricted[x] = ItemsB[x];
            }
            for (int x=0; x < classifiedCount; x++)
            {
                classified[x] = ItemsC[x];
            }
            for (int x=0; x < covertCount; x++)
            {
                covert[x] = ItemsD[x];
            }
            for (int x=0; x < covertCount; x++)
            {
                KnifeList[x] = ItemsE[x];
            }
        }

        void getItemFromCase(Weapon &CaseDrop, int &color)
        {
            /*
            Color Values:
            Milispec 0x09
            Restricted 0x05
            Classified 0x0d
            Covert 0x0c
            Knife 0x04

            Drop rates:
            http://csgoarray.blogspot.com/2014/05/cs-go-case-chances-and-knife-drop-rate.html
            */

            /*
            CSGO Knife Skins
            01. Default
            02. Blue Steel
            03. Boreal Forest
            04. Case Hardened
            05. Crimson Web
            06. Fade
            07. Forest DDPAT
            08. Night
            09. Safari Mesh
            10. Scorched
            11. Slaughter
            12. Stained
            13. Urban Masked
            */

            int intChance;
            int statTrakChance;
            int selectedItemFromQuality;
            intChance = rand() % 1000;
            //statTrakChance = rand() % 10 + 1;
            if(intChance >=0 && intChance <= 699)//Milispec
            {
                color = 0x09;
                selectedItemFromQuality = 1;
                selectedItemFromQuality = rand() % miliSpecCount;
                CaseDrop.setItemQuality(1);
                CaseDrop.setName(miliSpec[selectedItemFromQuality].weaponName);
            }
            if(intChance >699 && intChance <= 781)//Milispec Stattrak
            {
                color = 0x09;
                selectedItemFromQuality = 1;
                selectedItemFromQuality = rand() % miliSpecCount;
                CaseDrop.setItemQuality(1);
                CaseDrop.setName(miliSpec[selectedItemFromQuality].weaponName);
                CaseDrop.setName("Stat-Trak " + CaseDrop.weaponName);
            }
            else if(intChance > 781 && intChance <= 930)//Restricted
            {
                color = 0x05;
                selectedItemFromQuality = 2;
                selectedItemFromQuality = rand() % restrictedCount;
                CaseDrop.setItemQuality(1);
                CaseDrop.setName(restricted[selectedItemFromQuality].weaponName);
            }
            else if(intChance > 930 && intChance <= 947)//Restricted Stattrak
            {
                color = 0x05;
                selectedItemFromQuality = 2;
                selectedItemFromQuality = rand() % restrictedCount;
                CaseDrop.setItemQuality(1);
                CaseDrop.setName(restricted[selectedItemFromQuality].weaponName);
                CaseDrop.setName("Stat-Trak " + CaseDrop.weaponName);
            }
            else if(intChance > 947 && intChance <= 980)//Classified
            {
                color = 0x0d;
                selectedItemFromQuality = 3;
                selectedItemFromQuality = rand() % classifiedCount;
                CaseDrop.setItemQuality(1);
                CaseDrop.setName(classified[selectedItemFromQuality].weaponName);
            }
            else if(intChance > 980 && intChance <= 983)//Classified stattrak
            {
                color = 0x0d;
                selectedItemFromQuality = 3;
                selectedItemFromQuality = rand() % classifiedCount;
                CaseDrop.setItemQuality(1);
                CaseDrop.setName(classified[selectedItemFromQuality].weaponName);
                CaseDrop.setName("Stat-Trak " + CaseDrop.weaponName);
            }
            else if(intChance > 983 && intChance <= 993)//Covert
            {
                color = 0x0c;
                selectedItemFromQuality = 4;
                selectedItemFromQuality = rand() % covertCount;
                CaseDrop.setItemQuality(1);
                CaseDrop.setName(covert[selectedItemFromQuality].weaponName);
            }
            else if(intChance > 993 && intChance <= 994)//Covert stattrak
            {
                color = 0x0c;
                selectedItemFromQuality = 4;
                selectedItemFromQuality = rand() % covertCount;
                CaseDrop.setItemQuality(1);
                CaseDrop.setName(covert[selectedItemFromQuality].weaponName);
                CaseDrop.setName("Stat-Trak " + CaseDrop.weaponName);
            }
            else if(intChance > 994 && intChance <= 999)//Knife
            {
                color = 0x04;
                selectedItemFromQuality = 5;
                selectedItemFromQuality = rand() % knifeCount;
                CaseDrop.setItemQuality(1);
                CaseDrop.setName(KnifeList[selectedItemFromQuality].weaponName);
            }
            else if(intChance > 999)//Knife stattrak
            {
                color = 0x04;
                selectedItemFromQuality = 5;
                selectedItemFromQuality = rand() % knifeCount;
                CaseDrop.setItemQuality(1);
                CaseDrop.setName(KnifeList[selectedItemFromQuality].weaponName);
                CaseDrop.setName("Stat-Trak " + CaseDrop.weaponName);
            }
        }


};

int main()
{
    const double KEY_PRICE = 2.49;
    const int
                MiliSpec = 1,
                Resticted = 2,
                Classified = 3,
                Covert = 4,
                Knife = 5;
    double seed;
    srand(time(NULL));
    seed = rand();
    srand(seed);

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = 0x07;
    int caseNum;
    double moneySpent = 0;
    Weapon CaseDrop;

    //Default Knifes
        Weapon Karambit;
        Weapon Bayonet;
        Weapon M9;
        Weapon Flip;
        Weapon Gut;
        Weapon DefaultKnifeList[] = {Karambit, Bayonet, M9, Flip, Gut};

    //Operation Phoenix Items
        //Milispec
        Weapon UMP_45_Corporal; UMP_45_Corporal.setItemQuality(MiliSpec); UMP_45_Corporal.setName("UMP-45 | Corporal");
        Weapon Negev_Terrain; Negev_Terrain.setItemQuality(MiliSpec); Negev_Terrain.setName("Negev | Terrain");
        Weapon Tec_9_Sandstorm; Tec_9_Sandstorm.setItemQuality(MiliSpec); Tec_9_Sandstorm.setName("Tec-9 | Sandstorm");
        Weapon MAG_7_Heaven_Guard; MAG_7_Heaven_Guard.setItemQuality(MiliSpec); MAG_7_Heaven_Guard.setName("MAG-7 | Heaven Guard");
        //Restricted
        Weapon MAC_10_Heat; MAC_10_Heat.setItemQuality(Resticted); MAC_10_Heat.setName("MAC-10 | Heat");
        Weapon SG_553_Pulse; SG_553_Pulse.setItemQuality(Resticted); SG_553_Pulse.setName("SG 553 | Pulse");
        Weapon FAMAS_Sergeant; FAMAS_Sergeant.setItemQuality(Resticted); FAMAS_Sergeant.setName("FAMAS | Sergeant");
        Weapon USPS_Guardian; USPS_Guardian.setItemQuality(Resticted); USPS_Guardian.setName("USP-S | Guardian");
        //Classified
        Weapon AK47_Redline; AK47_Redline.setItemQuality(Classified); AK47_Redline.setName("AK-47 | Redline");
        Weapon P90_Trigon; P90_Trigon.setItemQuality(Classified); P90_Trigon.setName("P90 | Trigon");
        Weapon Nova_Antique; Nova_Antique.setItemQuality(Classified); Nova_Antique.setName("Nova | Antique");
        //Covert
        Weapon AWP_Asiimov; AWP_Asiimov.setItemQuality(Covert); AWP_Asiimov.setName("AWP | Asiimov");
        Weapon AUG_Chameleon; AUG_Chameleon.setItemQuality(Covert); AUG_Chameleon.setName("AUG | Chameleon");
        //Knife

        //Loot List
        Weapon PhoenixMiliSpec[] = {UMP_45_Corporal, Negev_Terrain, Tec_9_Sandstorm, MAG_7_Heaven_Guard};
        Weapon PhoenixRestricted[] = { MAC_10_Heat, SG_553_Pulse, FAMAS_Sergeant, USPS_Guardian};
        Weapon PhoenixClassified[] = {AK47_Redline, P90_Trigon, Nova_Antique};
        Weapon PhoenixCovert[] = {AWP_Asiimov, AUG_Chameleon};
        //Create Case
        Case Phoenix(PhoenixMiliSpec, 4 , PhoenixRestricted, 4, PhoenixClassified, 3, PhoenixCovert, 2, DefaultKnifeList, 5);


    //Operation Breakout Items
        //Milispec
        Weapon MP7_Urban_Hazard; MP7_Urban_Hazard.setItemQuality(MiliSpec); MP7_Urban_Hazard.setName("MP7 | Urban Hazard");
        Weapon Negev_Desert_Strike; Negev_Desert_Strike.setItemQuality(MiliSpec); Negev_Desert_Strike.setName("Negev | Desert Strike");
        Weapon P2000_Ivory; P2000_Ivory.setItemQuality(MiliSpec); P2000_Ivory.setName("P2000 | Ivory");
        Weapon SSG08_Abyss; SSG08_Abyss.setItemQuality(MiliSpec); SSG08_Abyss.setName("SSG-08 | Abyss");
        Weapon UMP_45_Labyrinth; UMP_45_Labyrinth.setItemQuality(MiliSpec); UMP_45_Labyrinth.setName("UMP-45 | Labyrinth");
        //Restricted
        Weapon PP_Bizon_Osiris; PP_Bizon_Osiris.setItemQuality(Resticted); PP_Bizon_Osiris.setName("PP-Bizon | Osiris");
        Weapon CZ75_Auto_Tigris; CZ75_Auto_Tigris.setItemQuality(Resticted); CZ75_Auto_Tigris.setName("CZ75-Auto | Tigris");
        Weapon Nova_Koi; Nova_Koi.setItemQuality(Resticted); Nova_Koi.setName("Nova | Koi");
        Weapon P250_Supernova; P250_Supernova.setItemQuality(Resticted); P250_Supernova.setName("P250 | Supernova");
        //Classified
        Weapon Desert_Eagle_Conspiracy; Desert_Eagle_Conspiracy.setItemQuality(Classified); Desert_Eagle_Conspiracy.setName("Desert Eagle | Conspiracy");
        Weapon Five_SeveN_Fowl_Play; Five_SeveN_Fowl_Play.setItemQuality(Classified); Five_SeveN_Fowl_Play.setName("Five-SeveN | Fowl Play");
        Weapon Glock_18_Water_Elemental; Glock_18_Water_Elemental.setItemQuality(Classified); Glock_18_Water_Elemental.setName("Glock-18 | Water Elemental");
        //Covert
        Weapon P90_Asiimov; P90_Asiimov.setItemQuality(Covert); P90_Asiimov.setName("P90 | Asiimov");
        Weapon M4A1S_Cyrex; M4A1S_Cyrex.setItemQuality(Covert); M4A1S_Cyrex.setName("M4A1-S | Cyrex");
        //Knife
        Weapon ButterflyKnife; ButterflyKnife.setItemQuality(Knife); ButterflyKnife.setName("Butterfly Knife");
        //Loot List
        Weapon BreakoutMiliSpec[] = {MP7_Urban_Hazard, Negev_Desert_Strike, P2000_Ivory, SSG08_Abyss, UMP_45_Labyrinth};
        Weapon BreakoutRestricted[] = {PP_Bizon_Osiris, CZ75_Auto_Tigris, Nova_Koi, P250_Supernova};
        Weapon BreakoutClassified[] = {Desert_Eagle_Conspiracy, Five_SeveN_Fowl_Play, Glock_18_Water_Elemental};
        Weapon BreakoutCovert[] = {P90_Asiimov, M4A1S_Cyrex};
        Weapon BreakoutKnife[] = {ButterflyKnife};
        //Create Case
        Case Breakout(BreakoutMiliSpec, 5 , BreakoutRestricted, 4, BreakoutClassified, 3, BreakoutCovert, 2, BreakoutKnife, 1);


    ofstream weaponDrop;
    weaponDrop.open("History.txt");
    cout << "Welcome to my case opening simulator.\n";
    cout << "All items are field tested.\n";
    while(true)
    {
        cout << "Please select a case to open:\n";
        cout << "1. Operation Breakout Case\n";
        cout << "2. Operation Phoenix Case\n";
        cout << "3. Exit Case Simulator\n";
        cin >> caseNum;
        if (caseNum==1)
        {
            Breakout.getItemFromCase(CaseDrop, color);
            SetConsoleTextAttribute(console, color);
            cout << CaseDrop.weaponName << endl;
            SetConsoleTextAttribute(console, 0x07);
        }
        else if(caseNum==2)
        {
            Phoenix.getItemFromCase(CaseDrop, color);
            SetConsoleTextAttribute(console, color);
            cout << CaseDrop.weaponName << endl;
            SetConsoleTextAttribute(console, 0x07);
        }
        else if(caseNum==3)
        {
            break;
        }
        moneySpent += KEY_PRICE;
        cout << "You have spent $" << moneySpent << endl;
        weaponDrop << CaseDrop.weaponName << endl;
    }
    return 0;
}
