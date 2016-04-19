#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "TGraphErrors.h"
#include "TAxis.h"


	const int row=100;
	const int column=9;
	const int par=9;
	ifstream file;
	string waste;                 //to deposit unnecasary data (such as the titles)
	float a[par][column][row]=0;  //to hold the fitted values

	//arrays to hold the true values
	/*const int u1=30;
	const int u2=20;
	const int u3=40;
	const int u4=10;
	const int n=90;*/
	const int u0=12;
	const int u1=21;
	const int u2=21;
	const int u3=21;
	const int u4=21;
	const int u5=21;
	const int u6=21;
	const int u7=21;
	const int u8=21;
	//const int n=20;
	
	/*float FL[u1];
	float S39[u2];
	float S6s[u3];
	float S6c[u4];
	float x[n];*/

	float FL[u0];
	float S3[u1];
	float S4[u2];
	float S5[u3];
	float S6s[u4];
	float S6c[u5];
	float S7[u6];
	float S8[u7];
	float S9[u8];

	

string get_par2(int i)
{
	if(i == 0){return "FL";}
	if(i == 1){return "S3";}
	if(i == 2){return "S4";}
	if(i == 3){return "S5";}
	if(i == 4){return "S6s";}
	if(i == 5){return "S6c";}
	if(i == 6){return "S7";}
	if(i == 7){return "S8";}
	if(i == 8){return "S9";}
	if(i == 9){return "all";}
}

void getData()
{
	/*float jj;
	for(int i=0; i<30; i++){ jj = i; FL[i] =0.2 + jj/50;}
	for(int i=-0; i<20; i++){ jj = i; S3[i] =-0.2+ jj/50;  S9[i] =-0.2+ jj/50;}
	for(int i=0; i<40; i++){  jj = i; S6s[i] =-0.4+ jj/50;}
	for(int i=0; i<10; i++){  jj = i; S6c[i] =-0.1+ jj/50;}
	
	for(int i=0; i<90; i++)
		{
			jj = i; 
			S4[i] = -0.9+ jj/50;
			S5[i] = -0.9+ jj/50;
			S7[i] = -0.9+ jj/50;
			S8[i] = -0.9+ jj/50;
		}*/
	for(int i = 0; i < 21; i++)
	{	float jc= i;
		S3[i]= (-10 + jc)/10;
		S4[i]= (-10 + jc)/10;
		S5[i]= (-10 + jc)/10;
		S6s[i]= (-10 + jc)/10;
		S6c[i]= (-10 + jc)/10;
		S7[i]= (-10 + jc)/10;
		S8[i]= (-10 + jc)/10;
		S9[i]= (-10 + jc)/10;
	}
	
	for(int i = 0; i < 12; i++)
	{	float jk = i;
		FL[i]= (-2 + jk)/10;
	}
	
	
	
	for(int k=0; k<par; k++)      //cycles through FL, S3, S4 ...
	{	
		std::string path = "/Users/amit/Data/";
		std::string ext = ".txt";
		std::string fnam;
		
		fnam = path + get_par2(k)+ ext;
		std::cout<<fnam<<std::endl;
		file.open(fnam.c_str());
				
			//	for(int p=0; p<18; p++)  //gets rid of the titles in the data files
			//	{
			//	    file>>waste;
			//	};



					for (int i=0; i<row; i++)  //cycles through the rows
					{
					  	if(!file.eof())   //only continues if end of file marker hasn't been reached
						{
					   		 for(int j=0; j<column; j++) //cycles through the columns
							{
					   		  	if(!file.eof())
								{
					
									file>>a[k][j][i];    //stores data in the array 

					     		}

					  	 	}
						}
					}
	
				file.close();    //closes the opened data file before next one is opened
 	}

	//To check for errors 
	std::cout<< a[0][0][0]<<endl;
	std::cout<< a[0][0][1]<<endl;
	std::cout<< a[0][1][1]<<endl;

}
