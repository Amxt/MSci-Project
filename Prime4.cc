// RConfigure.h is needed for TTFFONTDIR
#include "RConfigure.h"
#include "test_AFitKstLL_2DPdfToy.cc"
#include "iostream"
#include "fstream"
#include "string" 


void getstuff(TH1F &num1, TH1F &num2, TH1F &num3, ofstream &file){

	Double_t pmean1, perror1, psigma1, pserror1;

	pmean1 = num1.GetFunction("gaus")->GetParameter(1);
	perror1 = num1.GetFunction("gaus")->GetParError(1);
	psigma1 = num1.GetFunction("gaus")->GetParameter(2);
	pserror1 = num1.GetFunction("gaus")->GetParError(2);

	Double_t emean1, eerror1;
	emean1 = num2.GetMean();
	eerror1 = num2.GetRMS();

	Double_t smean1, smerror1;
	smean1 = num3.GetMean();
	smerror1 = num3.GetRMS();

 file<<smean1<<"          "<<smerror1<<"          "<<emean1<<"          "
      <<eerror1<<"          "<<pmean1<<"          "<<perror1<<"          "
      <<psigma1<<"          "<<pserror1<<"          "<<mm<<endl;
	
}

void Prime4(ofstream &file, int VAL,Double_t F_L, Double_t S_3,Double_t S_4,Double_t S_5,Double_t S_6s,Double_t S_6c,Double_t S_7,Double_t S_8,Double_t S_9,  Double_t nToys,  Double_t nGen) {
	
  cout << "Basic macro to test the 3D pdf for the K*mumu angular correlation in terms of helicity angles: P' variant" << endl;
	
  gStyle->SetOptFit(1);

  //Double_t nToys = 2;
  //Double_t nGen  = 100;

  RooRealVar cosThetaL("cosThetaL", "cosThetaL", -1.0, 1.0);
  RooRealVar cosThetaK("cosThetaK", "cosThetaK", -1.0, 1.0);
  RooRealVar phi("phi", "phi", -TMath::Pi(), TMath::Pi());

  Double_t sLimit = 4.0;
  RooRealVar FL("FL",   "FL",  F_L, -0.2, 1.2);
  RooRealVar S3("S3",   "S3",  S_3, -sLimit, sLimit);
  RooRealVar S4("S4",   "S4",  S_4, -sLimit, sLimit);
  RooRealVar S5("S5",   "S5",  S_5, -sLimit, sLimit);
  RooRealVar S6s("S6s", "S6s", S_6s, -sLimit, sLimit);
  RooRealVar S6c("S6c", "S6c", S_6c, -sLimit, sLimit);
  RooRealVar S7("S7",   "S7",  S_7, -sLimit, sLimit);
  RooRealVar S8("S8",   "S8",  S_8, -sLimit, sLimit);
  RooRealVar S9("S9",   "S9",  S_9, -sLimit, sLimit);

  // FL=0.1;
  //FL.setConstant();
  //S6s.setConstant();
  //S6c.setConstant();
  //S9.setConstant();

  AFitBtoSLL3DPprimePdf my3Dpdf("my3Dpdf", "angular correlation", cosThetaL, cosThetaK, phi, FL, S3, S4, S5, S6s, S6c, S7, S8, S9);

  // Fitted distributions
  TH1F h_FL("h_FL",   "fitted values of F_{L}",  100, FL.getMin(),  FL.getMax());
  TH1F h_S3("h_S3",   "fitted values of S_{3}",  100, S3.getMin(),  S3.getMax());
  TH1F h_S4("h_S4",   "fitted values of S_{4}",  100, S4.getMin(),  S4.getMax());
  TH1F h_S5("h_S5",   "fitted values of S_{5}",  100, S5.getMin(),  S5.getMax());
  TH1F h_S6s("h_S6s", "fitted values of S_{6s}",  100, S6s.getMin(),  S6s.getMax());
  TH1F h_S6c("h_S6c", "fitted values of S_{6c}",  100, S6c.getMin(),  S6c.getMax());
  TH1F h_S7("h_S7",   "fitted values of S_{7}",  100, S7.getMin(),  S7.getMax());
  TH1F h_S8("h_S8",   "fitted values of S_{8}",  100, S8.getMin(),  S8.getMax());
  TH1F h_S9("h_S9",   "fitted values of S_{9}",  100, S9.getMin(),  S9.getMax());

  // Fitted errors
  TH1F h_eFL("h_eFL",   "errors of F_{L}",   100, 0.0, 0.25);
  TH1F h_eS3("h_eS3",   "errors of S_{3}",   100, 0.0, 0.25);
  TH1F h_eS4("h_eS4",   "errors of S_{4}",  100, 0.0, 0.7);
  TH1F h_eS5("h_eS5",   "errors of S_{5}",  100, 0.0, 0.4);
  TH1F h_eS6s("h_eS6s", "errors of S_{6s}",  100, 0.0, 0.25);
  TH1F h_eS6c("h_eS6c", "errors of S_{6c}",  100, 0.0, 0.25);
  TH1F h_eS7("h_eS7",   "errors of S_{7}",  100, 0.0, 0.4);
  TH1F h_eS8("h_eS8",   "errors of S_{8}",  100, 0.0, 0.7);
  TH1F h_eS9("h_eS9",   "errors of S_{9}",  100, 0.0, 0.25);

  // Pulls
  TH1F h_pFL("h_pFL",   "pull values of F_{L}",  100, -5.0, 5.0);
  TH1F h_pS3("h_pS3",   "pull values of S_{3}",  100, -5.0, 5.0);
  TH1F h_pS4("h_pS4",   "pulls values of S_{4}",  100, -5.0, 5.0);
  TH1F h_pS5("h_pS5",   "pulls values of S_{5}",  100, -5.0, 5.0);
  TH1F h_pS6s("h_pS6s", "pulls values of S_{6s}",  100, -5.0, 5.0);
  TH1F h_pS6c("h_pS6c", "pulls values of S_{6c}",  100, -5.0, 5.0);
  TH1F h_pS7("h_pS7",   "pulls values of S_{7}",  100, -5.0, 5.0);
  TH1F h_pS8("h_pS8",   "pulls values of S_{8}",  100, -5.0, 5.0);
  TH1F h_pS9("h_pS9",   "pulls values of S_{9}",  100, -5.0, 5.0);

  // store the fitted parameters in a tree.
  TTree tree("tree", "Fit Results");

  for(int i=0; i < nToys ; i++) {
    // set the initial values for generation
    FL   = F_L;
    S3   = S_3;
    S4   = S_4;
    S5   = S_5;
    S6s  = S_6s;
    S6c  = S_6c;
    S7   = S_7;
    S8   = S_8;
    S9   = S_9;

    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "Toy Iteration Number: " << i << endl;
    RooDataSet * data = my3Dpdf.generate(RooArgSet(cosThetaL, cosThetaK, phi), gRandom->Poisson(nGen));
    RooFitResult * r = (RooFitResult*)my3Dpdf.fitTo(*data, RooFit::FitOptions("etrh"), RooFit::NumCPU(2));

    const RooArgList & pars = r->floatParsFinal();
    RooRealVar * fittedFL = (RooRealVar*)pars.find("FL");
    RooRealVar * fittedS3 = (RooRealVar*)pars.find("S3");
    RooRealVar * fittedS4 = (RooRealVar*)pars.find("S4");
    RooRealVar * fittedS5 = (RooRealVar*)pars.find("S5");
    RooRealVar * fittedS6s = (RooRealVar*)pars.find("S6s");
    RooRealVar * fittedS6c = (RooRealVar*)pars.find("S6c");
    RooRealVar * fittedS7 = (RooRealVar*)pars.find("S7");
    RooRealVar * fittedS8 = (RooRealVar*)pars.find("S8");
    RooRealVar * fittedS9 = (RooRealVar*)pars.find("S9");

    if(fittedFL) h_FL.Fill(fittedFL->getVal());
    if(fittedS3) h_S3.Fill(fittedS3->getVal());
    if(fittedS4) h_S4.Fill(fittedS4->getVal());
    if(fittedS5) h_S5.Fill(fittedS5->getVal());
    if(fittedS6s) h_S6s.Fill(fittedS6s->getVal());
    if(fittedS6c) h_S6c.Fill(fittedS6c->getVal());
    if(fittedS7) h_S7.Fill(fittedS7->getVal());
    if(fittedS8) h_S8.Fill(fittedS8->getVal());
    if(fittedS9) h_S9.Fill(fittedS9->getVal());

    if(fittedFL) h_eFL.Fill(fittedFL->getError());
    if(fittedS3) h_eS3.Fill(fittedS3->getError());
    if(fittedS4) h_eS4.Fill(fittedS4->getError());
    if(fittedS5) h_eS5.Fill(fittedS5->getError());
    if(fittedS6s) h_eS6s.Fill(fittedS6s->getError());
    if(fittedS6c) h_eS6c.Fill(fittedS6c->getError());
    if(fittedS7) h_eS7.Fill(fittedS7->getError());
    if(fittedS8) h_eS8.Fill(fittedS8->getError());
    if(fittedS9) h_eS9.Fill(fittedS9->getError());

    computePull(h_pFL, fittedFL,   F_L);
    computePull(h_pS3, fittedS3,   S_3);
    computePull(h_pS4, fittedS4,   S_4);
    computePull(h_pS5, fittedS5,   S_5);
    computePull(h_pS6s, fittedS6s, S_6s);
    computePull(h_pS6c, fittedS6c, S_6c);
    computePull(h_pS7, fittedS7,   S_7);
    computePull(h_pS8, fittedS8,   S_8);
    computePull(h_pS9, fittedS9,   S_9);
  }

 
  TCanvas can("can", "", 900,1200);
  can.Divide(3,3);
  can.cd(1);
  h_FL.Draw();							//better way to do this? (use array?)

  can.cd(2);
  h_S3.Draw();

  can.cd(3);
  h_S4.Draw();

  can.cd(4);
  h_S5.Draw();

  can.cd(5);
  h_S6s.Draw();

  can.cd(6);
  h_S6c.Draw();

  can.cd(7);
  h_S7.Draw();

  can.cd(8);
  h_S8.Draw();

  can.cd(9);
  h_S9.Draw();

  can.Print("kstmumu_3DPprimeToy_fitVals.pdf");

  can.cd(1);
  h_eFL.Draw();

  can.cd(2);
  h_eS3.Draw();

  can.cd(3);
  h_eS4.Draw();

  can.cd(4);
  h_eS5.Draw();

  can.cd(5);
  h_eS6s.Draw();

  can.cd(6);
  h_eS6c.Draw();

  can.cd(7);
  h_eS7.Draw();

  can.cd(8);
  h_eS8.Draw();

  can.cd(9);
  h_eS9.Draw();

  can.Print("kstmumu_3DPprimeToy_fitErrors.pdf");

  can.cd(1);
  h_pFL.Fit("gaus");

  can.cd(2);
  h_pS3.Fit("gaus");

  can.cd(3);
  h_pS4.Fit("gaus");

  can.cd(4);
  h_pS5.Fit("gaus");

  can.cd(5);
  h_pS6s.Fit("gaus");

  can.cd(6);
  h_pS6c.Fit("gaus");

  can.cd(7);
  h_pS7.Fit("gaus");

  can.cd(8);
  h_pS8.Fit("gaus");

  can.cd(9);
  h_pS9.Fit("gaus");

  
 
switch(VAL){

  case 100:
  getstuff(h_pFL,h_eFL,h_FL,file);
	      break;
 case 200:
  getstuff(h_pS3,h_eS3,h_S3,file);
	      break;
  case 300:
  getstuff(h_pS4,h_eS4,h_S4,file);
	      break;
  case 400:
  getstuff(h_pS5,h_eS5,h_S5,file);
	      break;
  case 500:
  getstuff(h_pS6s,h_eS6s,h_S6s,file);
	      break;
  case 600:
  getstuff(h_pS6c,h_eS6c,h_S6c,file);
	      break;
  case 700:
  getstuff(h_pS7,h_eS7,h_S7,file);
	      break;
  case 800:
  getstuff(h_pS8,h_eS8,h_S8,file);
	      break;
  case 900:
  getstuff(h_pS9,h_eS9,h_S9,file);
	      break;
  default:
	      cout<<"error"<<endl;
	      };
 

  can.Print("kstmumu_3DPprimeToy_pulls.pdf");

  TFile f("kstmumu.root", "RECREATE");
  f.cd();
  h_FL.Write();
  h_S3.Write();
  h_S4.Write();
  h_S5.Write();
  h_S6s.Write();
  h_S6c.Write();
  h_S7.Write();
  h_S8.Write();
  h_S9.Write();

  h_eFL.Write();
  h_eS3.Write();
  h_eS4.Write();
  h_eS5.Write();
  h_eS6s.Write();
  h_eS6c.Write();
  h_eS7.Write();
  h_eS8.Write();
  h_eS9.Write();

  h_pFL.Write();
  h_pS3.Write();
  h_pS4.Write();
  h_pS5.Write();
  h_pS6s.Write();
  h_pS6c.Write();
  h_pS7.Write();
  h_pS8.Write();
  h_pS9.Write();


}
