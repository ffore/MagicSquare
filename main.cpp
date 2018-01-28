#include <iostream>
int main(){
/*...................................................................*/
/*Creating a magic square*/
    int n;
    std::cout<<"Enter the size of a magic square: ";
    while(true){
    std::cin>>n;
        if(n%2==0){
        std::cout<<"Please enter an odd size: ";
        }
        else
        break;

    }
    int mSq[n][n];
    int mSq2[n][n];
    int mSq3[n][n];
    int mSq4[n][n];

    //Assigning zeros to the squares
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            mSq[i][j]=0;
            mSq2[i][j]=0;
            mSq3[i][j]=0;
            mSq4[i][j]=0;
        }
    }

    //Assigning magic numbers to the square
    int mNum=1;
    int a=0;
    int b=n/2;
    while(mNum<=n*n){
        if(mNum==1){
            mSq[a][b]=mNum;
            mNum++;
            a--;
            b++;
            continue;
        }
		//when column and row indices out of range (top right corner)
		if(a<0 && b>=n){
			mSq[a+2][b-1] = mNum;
			a = a+2;
			b= b-1;
			mNum++;
			a--;
			b++;
			continue;
		}
		//when row index out of range (above matrix)
       if(a<0){
		    mSq[n-1][b]=mNum;
			a=n-1;
			b=b;
            mNum++;
            a--;
            b++;
            continue;
        }
		//along right edge
        if(b>(n-1)){
            mSq[a][0]=mNum;
            a=a;
			b=0;
			a--;
			b++;
            mNum++;
			continue;
        }
        //when there is already a number placed in path of next
        if(1<=mSq[a][b] && mSq[a][b]<=n*n){
            mSq[a+2][b-1]=mNum;
            a=a+2;
            b=b-1;
            a--;
            b++;
            mNum++;
            continue;
        }
        else
			mSq[a][b]=mNum;
            a--;
            b++;
            mNum++;
            continue;
    }


//Magic square #1 (mSq4)
/*.....................................................*/
	int fourx=n-1;
	int foury=n-1;
    for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
		mSq4[i][j]=mSq[foury][fourx];
		foury=foury-1;
		}
	foury=foury+n;
	fourx=fourx-1;
	}
	//Printing Magic square #1
    std::cout<<"\n"<<"Magic Square #1 is:"<<"\n";
    for(int i=0; i<n; i++){
        std::cout<<"\n";
        for(int j=0; j<n; j++){
            std::cout<<mSq4[i][j];
            std::cout<<" ";
        }
    }
    std::cout<<"\n";

    //Row adder
    int rowSum1=0;
    std::cout<<"\n"<<"Checking the sums of every row: ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            rowSum1=rowSum1+mSq4[i][j];
        }
        std::cout<<rowSum1<<" ";
        rowSum1=0;
    }
    std::cout<<"\n";

    //Column adder
    int colSum1=0;
    std::cout<<"Checking the sums of every column: ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            colSum1=colSum1+mSq4[j][i];
        }
        std::cout<<colSum1<<" ";
        colSum1=0;
    }
    std::cout<<"\n";

    //Diagonal adders
    int diagSumA1=0;
    int jA1=0;
    for(int i=0; i<n; i++){
        diagSumA1=diagSumA1+mSq4[i][jA1];
        jA1++;
    }
    /*diagonal is misspelled int the instructions*/

    int diagSumB1=0;
    int jB1=0;
    for(int i=n-1; i>=0; i--){
        diagSumB1=diagSumB1+mSq4[i][jB1];
        jB1++;
    }
    /*diagonal is misspelled int the instructions*/
    std::cout<<"Checking the sums of every diagonal: "<<diagSumA1<<" "<<diagSumB1<<"\n";
    /*.....................................................*/

    //Magic Square #2 (mSq2)-->Flipping square1 along tL & bR diagonal
    /*.....................................................*/
    for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
		mSq2[i][j]=mSq[j][i];
		}
	}
        //Printing Magic Square #2
    std::cout<<"\n"<<"Magic Square #2 is:"<<"\n";
    for(int i=0; i<n; i++){
        std::cout<<"\n";
        for(int j=0; j<n; j++){
            std::cout<<mSq2[i][j];
            std::cout<<" ";
        }
    }
    std::cout<<"\n";

        //Row adder
    int rowSum2=0;
    std::cout<<"\n"<<"Checking the sums of every row: ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            rowSum2=rowSum2+mSq2[i][j];
        }
        std::cout<<rowSum2<<" ";
        rowSum2=0;
    }
    std::cout<<"\n";

    //Column adder
    int colSum2=0;
    std::cout<<"Checking the sums of every column: ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            colSum2=colSum2+mSq2[j][i];
        }
        std::cout<<colSum2<<" ";
        colSum2=0;
    }
    std::cout<<"\n";

    //Diagonal adders
    int diagSumA2=0;
    int jA2=0;
    for(int i=0; i<n; i++){
        diagSumA2=diagSumA2+mSq2[i][jA2];
        jA2++;
    }
    /*diagonal is misspelled int the instructions*/

    int diagSumB2=0;
    int jB2=0;
    for(int i=n-1; i>=0; i--){
        diagSumB2=diagSumB2+mSq2[i][jB2];
        jB2++;
    }
    /*diagonal is misspelled int the instructions*/
    std::cout<<"Checking the sums of every diagonal: "<<diagSumA2<<" "<<diagSumB2<<"\n";
    /*.....................................................*/


    //Printing Magic Square #3 (mSq)(already made in big while loop)
    /*.....................................................*/
    std::cout<<"\n"<<"Magic Square #3 is: "<<"\n";
    for(int i=0; i<n; i++){
        std::cout<<"\n";
        for(int j=0; j<n; j++){
            std::cout<<mSq[i][j];
            std::cout<<" ";
        }
    }
    std::cout<<"\n";

        //Row adder
    int rowSum3=0;
    std::cout<<"\n"<<"Checking the sums of every row: ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            rowSum3=rowSum3+mSq[i][j];
        }
        std::cout<<rowSum3<<" ";
        rowSum3=0;
    }
    std::cout<<"\n";

    //Column adder
    int colSum3=0;
    std::cout<<"Checking the sums of every column: ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            colSum3=colSum3+mSq[j][i];
        }
        std::cout<<colSum3<<" ";
        colSum3=0;
    }
    std::cout<<"\n";

    //Diagonal adders
    int diagSumA3=0;
    int jA3=0;
    for(int i=0; i<n; i++){
        diagSumA3=diagSumA3+mSq[i][jA3];
        jA3++;
    }
    /*diagonal is misspelled int the instructions*/

    int diagSumB3=0;
    int jB3=0;
    for(int i=n-1; i>=0; i--){
        diagSumB3=diagSumB3+mSq[i][jB3];
        jB3++;
    }
    /*diagonal is misspelled int the instructions*/
    std::cout<<"Checking the sums of every diagonal: "<<diagSumA3<<" "<<diagSumB3<<"\n";
    /*.....................................................*/




	//Making Magic Square #4 (mSq3)-->rotating and flipping
    /*.....................................................*/
	int x=n-1;
	int y=n-1;
    for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
		mSq3[i][j]=mSq[x][y];
		y=y-1;
		}
	y=y+n;
	x=x-1;
	}
	//Printing Magic Square #4
    std::cout<<"\n"<<"Magic Square #4 is:"<<"\n";
    for(int i=0; i<n; i++){
        std::cout<<"\n";
        for(int j=0; j<n; j++){
            std::cout<<mSq3[i][j];
            std::cout<<" ";
        }
    }
    std::cout<<"\n";

        //Row adder
    int rowSum4=0;
    std::cout<<"\n"<<"Checking the sums of every row: ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            rowSum4=rowSum4+mSq3[i][j];
        }
        std::cout<<rowSum4<<" ";
        rowSum4=0;
    }
    std::cout<<"\n";

    //Column adder
    int colSum4=0;
    std::cout<<"Checking the sums of every column: ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            colSum4=colSum4+mSq3[j][i];
        }
        std::cout<<colSum4<<" ";
        colSum4=0;
    }
    std::cout<<"\n";

    //Diagonal adders
    int diagSumA4=0;
    int jA4=0;
    for(int i=0; i<n; i++){
        diagSumA4=diagSumA4+mSq3[i][jA4];
        jA4++;
    }
    /*diagonal is misspelled int the instructions*/

    int diagSumB4=0;
    int jB4=0;
    for(int i=n-1; i>=0; i--){
        diagSumB4=diagSumB4+mSq3[i][jB4];
        jB4++;
    }
    /*diagonal is misspelled int the instructions*/
    std::cout<<"Checking the sums of every diagonal: "<<diagSumA4<<" "<<diagSumB4<<"\n";
    /*.....................................................*/




return 0;
}
