#include <iostream>
#include <cmath>
using namespace std;

class chess
{
public: pair <int, int> pos;
        char color;
chess()
{
    pos.first = 0; pos.second = 0;
    color = 'w';
}
chess(pair <int, int> pos, char color)
{
    this -> pos.first = pos.first;
    this -> pos.second = pos.second;
    this -> color = color;
}
    bool king = false;
    bool queen = false;
    bool rook = false;
    bool bishop = false;
    bool knight = false;
    bool pawn = false;
// A - фигура, которая ходит; В - фигура, которой угрожают
bool KingThreatens (chess objB){
    if(king)
    {
        if(objB.pos.first == pos.first && abs(objB.pos.second - pos.second)==1)
            return true;
        if(objB.pos.second == pos.second && abs(objB.pos.first - pos.first)==1)
            return true;
        if(abs(objB.pos.second - pos.second)==1 && abs(objB.pos.second - pos.second)==1)
            return true;
    }
    else throw "error";
}
bool QueenThreatens (chess objB){
    if(queen)
    {
        if(objB.pos.first == pos.first || objB.pos.second == pos.second)
            return true;
        if(abs(objB.pos.second - pos.second) == abs(objB.pos.first - pos.first)||objB.pos.second == pos.first)
            return true;
    }
    else throw "error";
}
bool RookThreatens (chess objB){
        if(rook)
        {if(objB.pos.first == pos.first || objB.pos.second == pos.second)
                return true;
        }
        else throw "error";
}
bool BishopThreatens (chess objB){
    if(bishop)
    {
        if(abs(objB.pos.second - pos.second) == abs(objB.pos.first - pos.first)||objB.pos.second == pos.first)
            return true;
    }
    else throw "error";
}
bool PawnThreatens (chess objB){
    if(pawn)
    {
        if(color == 'b'){int a = pos.first; pos.first=pos.second; pos.second = a;
        a = objB.pos.first; objB.pos.first=objB.pos.second; objB.pos.second = a;}
        if(objB.pos.second - pos.second == 1)
            return true;
        if(objB.pos.second == pos.second + 1 && abs(pos.first - objB.pos.first)==1)
            return true;
    }
    else throw "error";
}
};

void Ex_1()
{
    int x, y, z;
    cout<< "Enter X: "; cin >> x;
    cout<< endl <<"Enter Y: "; cin >> y;
    cout<< endl <<"Enter Z: "; cin >> z;
    /* try {
         if((x%2!=0 || y%2!=0)&& (x!=0 && y!=0))
             throw "X and Y should be odd numbers!";
         if(x<20 && y<20)
             throw "X and Y can't be less than 20 at the same time!";
         if(x!=0 && y!=0)
             throw "X or Y must be 0!";
         if(x>0 || y>0 || z>0)
             throw "X, Y and Z must be less then 0!";
         if(x<100 && y<100 && z<100)
             throw "X, Y or Z must be more than 100!";
         if(x%5!=0 && y%5!=0 && z%5!=0)
             throw "X, Y or Z shoul be multiple of 5!";
     } catch (...) {
         cout<< "Error!"<< endl;
     }*/
    if(x%2!=0 && y%2!=0) cout<< "condition is true"<<endl;
    else cout<< "condition is false"<<endl;

    if(x<20 || y<20) cout<< "condition is true"<<endl;
    else cout<< "condition is false"<<endl;

    if(x==0 || y==0) cout<< "condition is true"<<endl;
    else cout<< "condition is false"<<endl;

    if((x%5!=0 && y%5!=0) ||(x%5!=0 && z%5!=0)|| (y%5!=0&& z%5!=0)) cout<< "condition is false"<<endl;
    else cout<< "condition is true"<<endl;

    if(x>100 || y>100 || z>100) cout<< "condition is true"<<endl;
    else cout<< "condition is false"<<endl;
}

void Ex_2 ()
{
    chess figure1, figure2;
    cout<< "Enter A: "; cin >> figure1.pos.first >> figure1.pos.second;
    cout<< endl <<"Enter B: "; cin >> figure2.pos.first>> figure2.pos.second;
    if(figure1.RookThreatens(figure2))
        cout << "Rook from 'A' threatens 'B' "<< endl;
    else cout << "Rook from 'A' doesn't threaten 'B' "<< endl;

    if(figure1.BishopThreatens(figure2))
        cout << "Bishop from 'A' threatens 'B' "<< endl;
    else cout << "Bishop from 'A' doesn't threaten 'B' "<< endl;

    if(figure1.KingThreatens(figure2))
        cout << "King from 'A' threatens 'B' "<< endl;
    else cout << "King from 'A' doesn't threaten 'B' "<< endl;

    if(figure1.QueenThreatens(figure2))
    cout << "Queen from 'A' threatens 'B' "<< endl;
    else cout << "queen from 'A' doesn't threaten 'B' "<< endl;

    if(figure1.PawnThreatens(figure2))
        cout << "Pawn from 'A' threatens 'B' "<< endl;
    else cout << "Pawn from 'A' doesn't threaten 'B' "<< endl;

}

void Ex_3()
{
    for(int i =1; i<10;i++)
    {
        cout<< i << " * " << 7<< " = "<< i * 7<< endl;
    }
    int n;
    cout << "Enter n: "; cin>> n;
    for(int i =1; i<10;i++)
    {
        cout<< i << " * " <<  n << " = "<< i * n << endl;
    }
}

void Ex_4()
{
    int res1 = 1, a, b;
    for (int i =8 ; i < 16;i++) res1*=i;
    cout << res1 << endl;
    cout << "Enter a: "; cin>> a;
    for (int i =a ; i < 21;i++) res1*=i;
    cout << endl << res1 << endl;
    cout << "Enter b: "; cin>> b;
    for (int i =1 ; i < b+1;i++) res1*=i;
    cout << endl << res1 << endl;
    cout << "Enter a: "; cin>> a;
    cout << endl <<"Enter b: "; cin>> b;
    for (int i =a ; i < b+1;i++) res1*=i;
    cout << endl << res1 << endl;
}

int main(int argc, const char * argv[]) {
    Ex_1();
    Ex_2();
    Ex_3();
    Ex_4();
    system("pause");
    return 0;
}

