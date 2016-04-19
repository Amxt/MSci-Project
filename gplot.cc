#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <sstream>
#include "TGraphErrors.h"
#include "TAxis.h"
#include <stdlib.h>

//global variables
std::string getPath = "/Users/amit/Data2/";                     //Set path to get files
std::string savePath = "/Users/amit/GPlotGraphs/";	 	  //Set directory to save files in (must already exist)
std::string saveRootPath = "ROOT/";		    //Set additional directory to save .root files (e.g "ROOT/" will save in savePath + ROOT/

const int ro=25;
const int colum=14;
const int pa=14;
const int LL=100;

string get_par(int i);
string get_gr(int i);

//main
int gplot(std::string typ = "all", std::string PP = "all", std::string gr = "all") 
{	
	system("clear"); 
	if(typ == "all" && PP == "all" && gr == "all")
	{
		do
		{
			std::cout<<"Please type in one of the following options :\n\n" << "event  =  Plot event graphs\n" 
				 << "toy  =  Plot toy graphs\n" << "all  =  Plot both event and toy graphs\n\n";
			
			std::cin>>typ;
			if(typ == ".q" || typ == ".Q" || typ == "quit" || typ == "exit"){std::cout<<"End of gplot\n\n";return 0;}	
			
			if(typ != "all" && typ != "event" && typ != "toy"){system("clear"); std::cout<<"Invalid entry, try again\n";}

		}while(typ != "all" && typ != "event" && typ != "toy");
		
		system("clear");
		
		do
		{
			std::cout<<"Plot ";
			if(typ == "all"){std::cout<< typ << " event and toy graphs for...\n";}
			else{std::cout<<typ<<" graphs for...\n";}

			std::cout<<"Please type in one of the following options :\n\n";
			for(int i=0; i<10; i++){std::cout<< get_par(i)<<" =  Plot "<<get_par(i)<<" graphs only\n";}
			std::cout<<"\n\n";
				

			std::cin>>PP;
			if(PP == ".q" || PP == ".Q" || PP == "quit" || PP == "exit"){std::cout<<"End of gplot\n\n";return 0;}
			
			if(PP!="FL" && PP!="S3" && PP!="S4" && PP!="S5" && PP!="S6s" && PP!="S6c" && 
			PP!="S7" && PP!="S8" && PP!="S9" && PP!="all"){system("clear"); std::cout<<"Invalid entry, try again\n";}

		}while(PP!="FL" && PP!="S3" && PP!="S4" && PP!="S5" && PP!="S6s" && PP!="S6c" && 
			PP!="S7" && PP!="S8" && PP!="S9" && PP!="all");

		system("clear");

		do   
		{	
			std::cout<<"Plot ";
			if(typ == "all"){std::cout<<typ<<" event and toy graphs for "<<PP<<"..."<<std::endl;}
			else{std::cout<<typ<<" graphs for "<<PP<<"...\n";}
			
			std::cout<<"Please type in one of the following options :\n\n";
			for(int i=0; i<6; i++){std::cout<< get_gr(i)<<" =  Plot "<<get_gr(i)<<" graphs\n";}
			std::cout<<"\n\n";
				
			std::cin>>gr;
			if(gr == ".q" || gr == ".Q" || gr == "quit" || gr == "exit"){std::cout<<"End of gplot\n\n";return 0;}
			
			if(gr != "all" && gr != "fitvals" && gr != "fiterror" && gr != "pullmean" && gr != "pullsigma" && gr != "pmvps")
			{system("clear"); std::cout<<"Invalid entry, try again\n";}

		}while(gr != "all" && gr != "fitvals" && gr != "fiterror" && gr != "pullmean" && gr != "pullsigma" && gr != "pmvps");
		system("clear");
	}
	

	if(typ == "all" || typ == "event")  //event graphs
	{
		if (PP == "all") //if no parameter entered
		{
			std::cout<<"\n\n---------------Event graphs---------------\n";
			
			for(int i=0; i<9; i++){EventGraph P(get_par(i) ,gr);}			
		}
		else if(PP=="FL" || PP=="S3" || PP=="S4" || PP=="S5" || PP=="S6s" || PP=="S6c" || 
			PP=="S7" || PP=="S8" || PP=="S9") {EventGraph PA(PP ,gr); PP = "done";}
	}


	if(typ == "all" || typ == "toy")  //toy graphs
	{
		if (PP == "all") //if no parameter entered
		{	
			std::cout<<"\n----------------Toy graphs----------------\n";
			ToyGraphs FLt(get_par(0) ,gr); 	  //forloop doesnt work
			ToyGraphs FLt(get_par(1) ,gr);
			ToyGraphs FLt(get_par(2) ,gr);
			ToyGraphs FLt(get_par(3) ,gr);
			ToyGraphs FLt(get_par(4) ,gr);
			ToyGraphs FLt(get_par(5) ,gr);
			ToyGraphs FLt(get_par(6) ,gr);
			ToyGraphs FLt(get_par(7) ,gr);
			ToyGraphs FLt(get_par(8) ,gr);
		}
		else if(PP=="FL" || PP=="S3" || PP=="S4" || PP=="S5" || PP=="S6s" || PP=="S6c" || 
			PP=="S7" || PP=="S8" || PP=="S9") {ToyGraphs PAt(PP ,gr); PP = "done";}
	}


		if( typ != "all" && typ != "toy" && typ != "event" ) //if invalid parameter
		{
			std::cout<<"Invalid parameter\n"; 
			std::cout<<"\nEnter: gplot(\"type\",\"Parameter\",\"Graph\")\n";
			std::cout<<"type = all, event, toy\n";		
			std::cout<<"Parameter = all, ";
			for(int i = 0; i<9; i++){ std::cout<< get_par(i)<< ", "; }
			std::cout<<"\nGraph = all, ";
			for(int i=0; i<5; i++){std::cout<<get_gr(i)<<", ";}
			std::cout<<"\n\n";

			return 0;
		}
	//	for(int i=0; i<9; i++)
		//{
	//		PreGraph FLt(get_par(0) ,gr); 
	//	}	

	std::cout<<"\nEnd of gplot\n\n";
	return 0;
}

string get_par(int i)
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

string get_gr(int i)
{
	if(i == 0){return "fitvals";}
	if(i == 1){return "fit error";}
	if(i == 2){return "pullmean";}
	if(i == 3){return "pullsigma";}
	if(i == 4){return "pmvps";}
	if(i == 5){return "all";}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Base
{	
	private:
		
	protected:
		std::string name;
		int type;
		int row;
		int column;
 		int par;
		float a[pa][colum][ro];
		float x[LL];
		int n;
		std::string para;
		int FcolNum;
		int ScolNum;
		std::string ttl;
		std::string graphTitle;	
		
		void set_file_title();
		void set_columns(int fcol1, int fcol2);
		void get_data();
		void plot();
		void clear_data();
		void draw_graph(TGraphErrors *myGraph);
		void set_axis_title(TGraphErrors *a);
		void make_graphs(std::string p, std::string gr);
		virtual std::string get_data_file_name(int i);
		virtual std::string set_graph_title(int i);
		virtual void set_x_axis();
		virtual void set_can_vars(int &b, int &c);

	
	public:

};

virtual std::string Base::get_data_file_name(int i){}
virtual std::string Base::set_graph_title(int i){}
virtual Base::set_x_axis(){}
virtual void Base::set_can_vars(int &b, int &c){}


//------------------------------------------------------------------------------------------------------------------------
void Base::make_graphs(std::string p, std::string gr)
{
	std::cout<<std::endl<<para<<std::endl;
	clear_data();
	get_data();

	int t=0;
	
	if(gr == "all")    //plots all graphs
	{	
		t=1;	
		for(int i=0; i<7; i+=2) { set_columns(i,i+1);  plot();}   
		set_columns(4,6);
		plot(); 
	}
	else     //plots graphs specified in parameter
	{
		if(gr == "fitvals") { set_columns(0,1); plot(); t=1;} 
		if(gr == "fiterror") { set_columns(2,3); plot(); t=1;} 
		if(gr == "pullmean") { set_columns(4,5); plot(); t=1;} 
		if(gr == "pullsigma") { set_columns(6,7); plot(); t=1;} 	
		if(gr == "pmvps") { set_columns(4,6); plot(); t=1;} 
	}
	
	if(t==0 && para=="FL")  //for incorrect parameters
	{
		std::cout<<"Enter up to two of the following as a parameter: " <<std::endl;
		std::cout<<"\"fitvals\" , \"fiterror\" , \"pullmean\" , \"pullsigma\" , \"pmvps\"" <<std::endl<<std::endl;
		std::cout<<"Or leave empty to plot all graphs"<<std::endl;
		break;
	}
}
void Base::set_file_title(std::string st)
{
	std::string tm;

	if(ScolNum-FcolNum==1) //to set file name for all except PMvPS (FcolNum is repeated for PMvPS so it needs a condition to identify)
	{	
		switch(FcolNum)
		{
			case 0: 
				tm="FITVALS";
				break;	
			case 2: 
				tm="FITERROR";
				break;	
			case 4: 
				tm="PULLMEAN";
				break;	
			case 6: 
				tm="PULLSIGMA";
				break;	
		
			default: std::cout<<"error2"<<endl;	
		}
	}
	else {tm="PMVPS";} //to set file name for PMvPS 
	
	ttl= para + "-" + st + tm;
}


void Base::set_columns(int fcol1, int fcol2)
{
	FcolNum = fcol1;
	ScolNum = fcol2;
}


void Base::get_data()
{
	std::string filename;
	std::ifstream file;
	
	std::string waste;       //to deposit unnecasary data (such as the titles)
	
	for(int k=0; k<par; k++)      //cycles through event numbers ...
	{	
		filename = get_data_file_name(k);

		file.open(filename.c_str());      //opens ifstream
		if(file.is_open())
		{
						
		//	for(int p=0; p<18; p++)     //gets rid of the titles in the data files
		//	{
		//	    file>>waste;
		//	};

			for (int i=0; i<row; i++)      //cycles through the rows
			{
				if(!file.eof())      //only continues if end of file marker hasn't been reached
				{
					for(int j=0; j<column; j++)    //cycles through the columns
					{
						if(!file.eof())
						{
							file>>a[k][j][i];    //stores data in the array 

						}

					}
				}
			}
		
			
		}
	
		file.close();    //closes the opened data file before next one is opened
 	}
}


void Base::set_axis_title(TGraphErrors *a) //to set the axis titles
{	
	std::string yname; //to hold y-axis title
	std::string xname; //to hold x-axis title
	
	switch(FcolNum) //to set the y-axis title depending on the data
	{
		case 0: 
			yname="Fit Value";
			break;	
		case 2: 
			yname="Fit Error";
			break;	
		case 4: 
			yname="Pull Mean";
			break;	
		case 6: 
			yname="Pull Sigma";
			break;		
		
		default: std::cout<<"error3";	
	}

	if((ScolNum-FcolNum)==2){xname="Pull Sigma";}
	else if(type == 2){xname="True Value";}  //to set x-axis for PMvPS
	else{xname = "Number Of Toys";}
	
	//sets the axis titles
	a->GetYaxis()->SetTitle(yname.c_str());
	a->GetXaxis()->SetTitle(xname.c_str());
	a->GetXaxis()->CenterTitle();
	a->GetYaxis()->CenterTitle();
	a->Draw("A*"); 
}

void Base::plot()
{	
	set_x_axis();
		
	TGraphErrors **myGraphss = new TGraphErrors* [11];

	if(ScolNum==(FcolNum+1)) //for all except PMvPS
	{		
		for(int i=0;i<11;i++)
		{
			myGraphss[i] = new TGraphErrors(n,x,a[i][FcolNum],0,a[i][ScolNum]);		
		}		
	}
	else //for PMvPS
	{
		for(int i=0;i<11;i++)
		{
			myGraphss[i] = new TGraphErrors(n,a[i][ScolNum],a[i][FcolNum],a[i][ScolNum+1],a[i][FcolNum+1]);		
		}
	}
	
	int b, c;
	TCanvas can("can", "", 900,1200);
	can.Divide(3,4);
	set_can_vars(b, c);	
	
	for(int i=0; i<b; i++)
	{
		can.cd(i + 1);
		int j = i + c;	  
		set_axis_title(myGraphss[j]); 
		set_graph_title(i);
		draw_graph(myGraphss[j]);		
	} 
	
	
	set_file_title(name);

	ttl1 = savePath + ttl + ".pdf";
	ttl2 = savePath + saveRootPath + ttl + ".root";
	can.Print(ttl1.c_str());

	TFile f(ttl2.c_str(), "RECREATE");
	f.cd();

	for(int i=0; i<10; i++)	{myGraphss[i]->Write();}    //save graphs

	delete[] myGraphss;
}


void Base::clear_data()  //sets a[][][] to 0
{
	for(int k=0; k<par; k++)
	{
		for (int i=0; i<row; i++)
		{ 
			for(int j=0; j<column; j++)
			{
				a[k][j][i]=0;
			}
		}
	}
}


void Base::draw_graph(TGraphErrors *myGraph)
{	
	float XMa, XMi, YMa, YMi, Z=0.0 , N=1.0;    //to draw lines on graphs
			
	XMa = myGraph->GetXaxis()->GetXmax();     //get the min/max axis values
	XMi = myGraph->GetXaxis()->GetXmin();
	YMa = myGraph->GetYaxis()->GetXmax();
	YMi = myGraph->GetYaxis()->GetXmin();

	myGraph->Draw("A*");     
	myGraph->SetTitle(graphTitle.c_str());	  			
			
	if(FcolNum != 2)   //no lines on fiterror graphs
	{
		if(FcolNum == 0){TLine *line = new TLine(XMi, XMi, XMa, XMa);}    //fitvals
		if(FcolNum == 4 && ScolNum != 6){TLine *line = new TLine(XMi, Z, XMa, Z);}  //pullmean
		if(FcolNum == 6){TLine *line = new TLine(XMi, N, XMa, N);}   //pullsigma
		if(FcolNum == 4 && ScolNum == 6)  //PMvPS
		{
			TLine *line1 = new TLine(N, YMi, N, YMa);   //x=1 line
			line1->Draw("");
			TLine *line = new TLine(XMi, Z, XMa, Z);  //y=0 line
		}
		line->Draw("");	   
	}		
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class EventGraph : public Base
{
	private:
		virtual std::string get_data_file_name(int i);
		virtual std::string set_graph_title(int i);
		virtual void set_x_axis();
		virtual void set_can_vars(int &b, int &c);

	public:
		EventGraph (std::string p, std::string gr);
		~EventGraph();
};

EventGraph::EventGraph(std::string p, std::string gr)
{	
	name = "e";
	type=2;
	para=p;
	row=21;
	par=10;
	column=10;

	make_graphs(p, gr);
}

EventGraph::~EventGraph()
{}

//-----------------------------------------------------------------------------------------------------------------------------
virtual void EventGraph::set_can_vars(int &b, int &c)
{
	b=10;
	c=0;
}

virtual void EventGraph::set_x_axis()
{
	if(para=="S3" || para=="S6s"){ n = 11; float hu = -0.5;}   //adjustment to their limited range
	else if(para=="FL"){ n = 10; float hu = 0.1;}		    //n = size of x axis i.e x[n];
	else{ n = 21; float hu = -1.0; }			    //hu = x-axis start point
					
	for(int i=0; i<n; i++){ float j = i; x[i] = hu + j/10;}
}


virtual std::string EventGraph::set_graph_title(int i)
{
	std::ostringstream ss;    
	ss << i + 1 <<"00 Events";
	graphTitle = ss.str();
}


virtual std::string EventGraph::get_data_file_name(int i)
{
	std::ostringstream ss;      //to convert int i into string
	ss<<getPath<<para<<"-"<<i+1<<"00.txt";		
	return ss.str();
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ToyGraphs : public Base
{	
	private:
		virtual std::string get_data_file_name(int i);
		virtual std::string set_graph_title(int i);
		virtual void set_x_axis();
		virtual void set_can_vars(int &b, int &c);

	public:
		ToyGraphs();
		ToyGraphs(std::string p, std::string gr);
};


ToyGraphs::ToyGraphs(std::string p, std::string gr)
{	
	name = "t";
	type=3;
	para=p;
	row=21;
	par=11;
	column=10;

	make_graphs(p, gr);
}

//----------------------------------------------------------------------------------------------------------------------------
virtual void ToyGraphs::set_can_vars(int &b, int &c)
{
	if(para == "S3"){b = 4; c = 5;}
	if(para == "FL"){b = 6; c = 5;}
	if(para == "FL"){b = 6; c = 5;}
	if(para == "FL"){b = 6; c = 5;}
	if(para == "S6s" || para == "S3"){b = 5; c = 3;}  //b = number of graphs to be produced
	else if(para == "FL"){b = 6; c = 5;}		  //c = graphss[] offset amount 
	else{b = 11; c = 0;}				  //(e.g FL graphs only valid from graphss[5] to graphss[11])
}

virtual void ToyGraphs::set_x_axis()
{
	n = 14;
	for(int i=0; i<n; i++){ x[i]=(i+1)*10; }
}

virtual std::string ToyGraphs::get_data_file_name(int i)
{
	std::ostringstream ss;      //to convert int i into string
	std::string ext;
	switch(i)
	{
		
		ext = (i+1)*10;
	/*	case 0:
			ext = "n_10.txt";
			break;			
		case 1:
			ext = "n_8.txt";
			break;
		case 2:
			ext = "n_6.txt";
			break;
		case 3:
			ext = "n_4.txt";
			break;			
		case 4:
			ext = "n_2.txt";
			break;
		case 5:
			ext = "n0.txt";
			break;
		case 6:
			ext = "n2.txt";
			break;
		case 7:
			ext = "n4.txt";
			break;
		case 8:
			ext = "n6.txt";
			break;		
		case 9:
			ext = "n8.txt";
			break;
		case 10:
			ext = "n10.txt";
			break;
			
		default: cout<<"error6"<<endl;
		}	
*/
	ss<<getPath<<"A-"<<para<<"-t"<<ext<<"-e300";	
	
	return ss.str();
}

virtual std::string ToyGraphs::set_graph_title(int i)  //incomplete
{
	std::ostringstream ss;    //to set the graph titles
	std::string tm;
	
	if(para == "FL"){ i += 5; }
	if(para == "S3" || para == "S6s"){ i += 3; }
	
	if(i==0){tm = "-1.0";}
	if(i==1){tm = "-0.8";}
	if(i==2){tm = "-0.6";}
	if(i==3){tm = "-0.4";}
	if(i==4){tm = "-0.2";}
	if(i==5){tm = "0.0";}
	if(i==6){tm = "0.2";}
	if(i==7){tm = "0.4";}
	if(i==8){tm = "0.6";}
	if(i==9){tm = "0.8";}
	if(i==10){tm = "1.0";} 

	ss << "True Value = "  << tm;
	graphTitle = ss.str();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
class PreGraph : public Base
{
	private:
		virtual std::string get_data_file_name(int i);
		virtual std::string set_graph_title(int i);
		virtual void set_x_axis();
		virtual void set_can_vars(int &b, int &c);

	public:
		PreGraph (std::string p, std::string gr);
		~PreGraph();
};



PreGraph::PreGraph(std::string p, std::string gr)
{	
	name = "p";
	type=4;
	para=p;
	row=100;
	par=9;
	column=9;
        
	make_graphs(p, gr);
}


virtual std::string PreGraph::get_data_file_name(int i)
{
	std::ostringstream ss;      //to convert int i into string
	ss<<getPath<<get_par(i)<<"2.txt";		
	return ss.str();
}


virtual std::string PreGraph::set_graph_title(int i)
{
	std::ostringstream ss;    
	ss << get_par(i);
	graphTitle = ss.str();
}


virtual void PreGraph::set_x_axis()
{
	if(para=="S3" || para=="S9" ){ n = 20; float hu = -0.2;}   //adjustment to their limited range
	if(para=="S6s"){ n = 40; float hu = -0.4;}
	if(para=="S6c"){ n = 10; float hu = -0.1;}
	else if(para=="FL"){ n = 30; float hu = 0.2;}		    //n = size of x axis i.e x[n];
	else{ n = 90; float hu = -0.9; }			    //hu = x-axis start point
					
	for(int i=0; i<n; i++){ float j = i; x[i] = hu + j/50;}
}

virtual void PreGraph::set_can_vars(int &b, int &c)
{
	b = 9; c = 0;  
}

PreGraph::~PreGraph()
{}
*/