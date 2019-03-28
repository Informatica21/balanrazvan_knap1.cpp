#include<iostream>
using namespace std;

int x; // x=nr. obiecte
float G[100][3];

int masa = 0;

int read_data()
{
cout << "Greutatea Rucsac" << endl;
cin >> masa;
cout << "Obiecte: " << endl;
cin >> x;
for (int i = 0; i < x; i++)
{
    for (int j = 0; j < 2; j++)
    {
        cin >> G[i][j];
    }
    if (G[i][0] != 0 && G[i][1] != 0)
    {
        G[i][2] = G[i][1] / G[i][0];
    }
}
}



int sorteaza()
{
    int i,j;
    for (i=0; i<x; i++)
    {
        for (j=i+1; j<x; j++)
        {
            if (G[i][2] < G[j][2])
            {
                swap(G[i], G[j]);
            }
        }
    }
}
int verify()
{
for (int i = 0; i < x; i++)
{
    for (int j = 0; j < 3; j++)
    {
        cout<< G[i][j] << endl;
    }
}
}

int greedy()
{

    float profit = 0;
    int i = 0;
    int aux;
    while(i<=x && masa>=0)
    {
        cout << "G[i][0]: " << G[i][0] << endl;
        if(masa>=G[i][0]) {

        profit=profit+G[i][1];
        masa=masa-G[i][0];
        }
        else {

                aux= (masa*100)/G[i][0];
                profit = profit + (aux * G[i][1])/100;
                break;
                        }
    i++;
   }
cout << profit;
    }
int main()
{
    read_data();
    sorteaza();
    verify();
   greedy();

}
