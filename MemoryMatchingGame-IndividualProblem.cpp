#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void shuffle(int start[]);
int row1, colm1, row2, colm2, cards[4][4], i=0, starCount=16;
int start[16]={1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8};


int main(){

    shuffle(start); //Shuffle fn.
	srand((unsigned)time(NULL)); //fill board

	for (int r=0; r<4; r++){
		for (int c=0; c<4; c++){
			cards[r][c] = start[i];
			i=i+1;
		}
	}

	/*for (int r=0; r<4; r++)
	{
		for (int c=0; c<4; c++)
		{
			cout<<cards[r][c];
		}
		cout<<endl;
	}*/

    //display board
    cout << "\t1\t2\t3\t4\n";
    cout << "  " ;
    for (int i=0; i<=8; i++){
        cout << "----";
    }
    cout << endl;

    for (int r=0; r<4; r++){
        cout << r+1 << " |\t ";
        for (int c=0; c<4; c++){
            cout << "*\t";
        }
        cout << endl << endl;
    }
    cout << endl;

    do {
        //Getting the two numbers from the user
        cout << "Enter first number's row and column: " << endl;
        cin  >> row1 >> colm1;
        cout << endl << "Enter second number's row and column: " << endl;
        cin  >> row2 >> colm2;

        row1--; colm1--; row2--; colm2--;
        cout << "\t1\t2\t3\t4\n";
        cout << "  " ;
        for (int i=0; i<=8; i++){
            cout << "----";
        }
        cout << endl;

        for (int r=0; r<4; r++){
            cout << r+1 << " |\t ";
            for (int c=0; c<4; c++){
                if ((r==row1) && (c==colm1)){
                    cout << cards[row1][colm1] << "\t";
                }
                else if ((r==row2) && (c==colm2)){
                    cout << cards[row2][colm2] << "\t";
                }
                else
                    cout << "*\t";
            }
            cout << endl << endl;
        }
        cout << endl;

        //Goes to a new page.
        for (i=0; i<20; ++i){
            cout << endl;
        }

        cout << "\t1\t2\t3\t4\n";
        cout << "  " ;
        for (int i=0; i<=8; i++){
            cout << "----";
        }
        cout << endl;

        for (int r=0; r<4; r++){
            cout << r+1 << " |\t ";
            for (int c=0; c<4; c++){
                if (((r==row1) && (c==colm1)) && ((cards[row1][colm1] == cards[row2][colm2])) ){
                    cout << cards[row1][colm1] << "\t";
                    starCount--;
                }
                else if (((r==row2) && (c==colm2)) && ((cards[row1][colm1] == cards[row2][colm2]))){
                    cout << cards[row2][colm2] << "\t";
                    starCount--;
                }
                else
                    cout << "*\t";
            }
            cout << endl << endl;
        }
        cout << endl;

    }
    while (starCount>0);
    return 0;
}


//Shuffle function
void shuffle(int start[])
{
	for (int s=0; s<=20; s++)
	{
		for (int x=0; x<16; x++)
		{
			srand((unsigned)time(NULL));
			int i=rand()%16+1;
			int temp=start[x];
			start[x]=start[i];
			start[i]=temp;
		}
	}
}
