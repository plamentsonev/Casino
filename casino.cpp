#include <iostream>
#include <string> 
#include <cstdlib> 
#include <ctime>
using namespace std;
 
void drawLine(int n, char symbol);
void rules();
 
int main()
{
    string playerName;
    int amount; 
    int bettingAmount; 
    int guess;
    int dice; 
    char choice;
 
    srand(time(0)); 

    drawLine(60,'_');
    cout << "\n\n\n\t\tCASINO GAME\n\n\n\n";
    drawLine(60,'_');
 
    cout << "\n\nVuvedete imeto si: ";
    getline(cin, playerName );
 
    cout << "\n\nVuvedete vashata suma : $";
    cin >> amount;
    
    do
    {
        system("cls");
        rules();
        cout << "\n\nVashite pari sa $ " << amount << "\n";
		
		// zaloga na igracha
        do
        {
            cout << playerName <<", Vuvedete zalog: $";
            cin >> bettingAmount;
            
            if(bettingAmount > amount) {
			
                cout << "Zaloga  vi e po golqm ot vashiq balans \n"
                       <<"\nVuvedete zaloga otnovo\n "; }
                       
        } while(bettingAmount > amount);
 
		// chislata na igracha
        do
        {
            cout << "Vuvedete chislo ot 1 do 10 :";
            cin >> guess;
            
            if(guess <= 0 || guess > 10) {
			
                cout << "Chisloto trqbva da e ot  1 do 10!\n"
                    <<"\nVuvedete otnovo\n "; }
        } while(guess <= 0 || guess > 10);
 
        dice = rand()%10 + 1; // sudurja generiranoto chislo
    
        if(dice == guess)
        {
            cout << "\n\nVie spechelihte! Rs." << bettingAmount * 10;
            amount = amount + (bettingAmount * 10);
        }
        
        else
        {
            cout << "Vie zagubihte $ "<< bettingAmount <<"\n";
            amount = amount - bettingAmount;
        }
 
        cout << "\nPechelivshoto chislo e : " << dice <<"\n";
        cout << "\n"<<playerName<<", Imate $ " << amount << "\n";
        if(amount == 0)
        {
            cout << "Nqmate poveche pari  ";
            break;
        }
        
        cout << "\n\n-->Iskate li da igraete otnovo (y/n)? ";		
        cin >> choice;
    }   while(choice =='Y'|| choice=='y');
    
    cout << "\n\n\n";
    drawLine(70,'=');
    cout << "\n\nBlagodarq vi che igrahte. Vashiq balans e $ " << amount << "\n\n";
    drawLine(70,'=');
 
    return 0;
}
 
void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        cout << symbol;
    cout << "\n" ;
}
 
void rules()
{
    system("cls");
    cout << "\n\n";
    drawLine(80,'-');
    
    cout << "\t\tPravila na igrata\n";
    
    drawLine(80,'-');
    
    cout << "\t1. Izberete chislo mejdu 1 i 10\n";
    cout << "\t2. Ako uluchite pechelite 10 puti po zaloga si\n";
    cout << "\t3. Ako ne uluchite chisloto gubite zaloga si\n\n";
    
    drawLine(80,'-');
}

