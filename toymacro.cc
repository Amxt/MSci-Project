
#include "iostream"
#include "fstream"
#include "string" 
#include "Prime4.cc"
//#include "testtest_AFitKstLL_3DPdfPprimeToy.cc"
using namespace std;

double mm;
double pp[];
void toymacro(int para, Double_t nToys, Double_t nGen, Double_t mm, Double_t increment, Double_t upperBound){

	ofstream file;

	double KK[9][10];

	for(int i=0; i<9; i++){				//setup array kk[][]
		
		for(int j=0; j<10; j++){
			kk[i][j]=0;
		}
	}

	for(int i=0; i<9; i++){	
		int j= (i+1)*100;
		kk[i][0] = j; 
	}
	
	for(int i = 1; i<9; i++){
		kk[i][1] = 0.5;	
	}

	for(int i=0; i<9; i++){
		kk[i][i+1] = mm;
	}


   switch(para){

 case 1: 
    string filename="FLtest.txt";
	string parameter="FL";
   double pp[10]={100.0,mm,0,0,0,0,0,0,0,0};
   break;

 case 2: 
    string filename="S3test.txt";
	string parameter="S3";
   double pp[10]={200.0,0.5,mm,0,0,0,0,0,0,0};
   break;

 case 3: 
    string filename="S4test.txt";
	string parameter="S4";
   double pp[10]={300.0,0.5,0,mm,0,0,0,0,0,0};
   break;

 case 4: 
    string filename="S5test.txt";
	string parameter="S5";
   double pp[10]={400.0,0.5,0,0,mm,0,0,0,0,0};
   break;

 case 5: 
    string filename="S6stest.txt";
	string parameter="S6s";
   double pp[10]={500.0,0.5,0,0,0,mm,0,0,0,0};
   break;

 case 6: 
    string filename="S6ctest.txt";
	string parameter="S6c";
   double pp[10]={600.0,0.5,0,0,0,0,mm,0,0,0};
   break;

 case 7: 
    string filename="S7test.txt";
	string parameter="S7";
   double pp[10]={700.0,0.5,0,0,0,0,0,mm,0,0};
   break;

 case 8: 
    string filename="S8test.txt";
	string parameter="S8";
   double pp[10]={800.0,0.5,0,0,0,0,0,0,mm,0};
   break;

 case 9: 
    string filename="S9test.txt";
	string parameter="S9";
   double pp[10]={900.0,0.5,0.0,0.0,0.0,0.0,0.0,0.0,0.0,mm};
   break;

      
   default: cout<<"error"<<endl;
      }


   file.open(filename.c_str(),ios::app);

std::string var;
 file<<parameter<<endl;
 file<<"fitVals mean"<<"      "<<"fitVals RMS"<<"       "<<"fitErrors mean"<<"       "<<"fitErrors RMS"
     <<"       "<<"Pull mean"<<"        "<<"Pull error"<<"       "<<"Pull sigma"<<"      "
<<"Pull sigma error"<<endl<<endl;

 for(mm; mm<upperBound; mm+=increment){
   
   Prime4(file, pp[0],pp[1],pp[2],pp[3],pp[4],pp[5],pp[6],pp[7],pp[8],pp[9], nToys, nGen);

   };
file.close();
};
