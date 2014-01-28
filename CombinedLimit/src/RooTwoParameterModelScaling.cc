/***************************************************************************** 
 * Project: RooFit                                                           * 
 *                                                                           * 
 * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/ 

// Your description goes here... 

#include "Riostream.h" 

#include "HiggsAnalysis/CombinedLimit/interface/RooTwoParameterModelScaling.h" 

#include <math.h> 
#include "TMath.h" 
#include "RooFormulaVar.h"
#include "RooRealVar.h"
#include "RooFit.h"

#include "TFile.h"

ClassImpUnique(RooTwoParameterModelScaling,MAGICWORDOFSOMESORT) 

RooTwoParameterModelScaling::RooTwoParameterModelScaling() : 
  P(0)
{
  initializeProfiles();
}

RooTwoParameterModelScaling::RooTwoParameterModelScaling(const char *name, 
					     const char *title,
					     RooAbsReal& _x,
					     RooAbsReal& _param1,
					     RooAbsReal& _param2,
					     RooAbsReal& _SM_shape,
					     const char * parFilename) :
   RooAbsReal(name,title),
   param1("param1","param1",this,_param1),
   param2("param2","param2",this,_param2),
   profileFilename(parFilename),
   P(0)
{ 
  initializeProfiles();
  initializeNormalization(_x,_SM_shape);
  const char* pwd = gDirectory->GetPath();
  TFile *f = TFile::Open(parFilename,"READ");  
  gDirectory->cd(pwd);
  //  readProfiles(*f);
  std::vector<double> bins_;

  const RooRealVar& rdep = dynamic_cast<const RooRealVar&>(_x);
  int N_bins=rdep.getBinning("").numBins();

  for (int i=0;i<N_bins;i++){
    if (i==0) bins_.push_back(rdep.getBinning("").binLow(i));
    bins_.push_back(rdep.getBinning("").binHigh(i));
  }
  readProfiles(bins_,*f);

  f->Close();
} 

RooTwoParameterModelScaling::
RooTwoParameterModelScaling(const RooTwoParameterModelScaling& other, 
		      const char* name) :  
  RooAbsReal(other,name),
  param1("param1",this,other.param1),
  param2("param2",this,other.param2),
  SM_integral(other.SM_integral),
  integral_basis(other.integral_basis),
  bins(other.bins),
  profileFilename(other.profileFilename),
  P(0)
{ 
  initializeProfiles();
  const char* pwd = gDirectory->GetPath();
  TFile *f = TFile::Open(profileFilename,"READ");  
  gDirectory->cd(pwd);  
  readProfiles(bins,*f);
  f->Close();
} 

void RooTwoParameterModelScaling::initializeProfiles() {
  int const N_bins=1;

  P = new TH2D*[N_bins]();
}

void RooTwoParameterModelScaling::initializeNormalization(const RooAbsReal& dep,
						    const RooAbsReal& shape) {
  const RooRealVar& rdep = dynamic_cast<const RooRealVar&>(dep);
  RooRealVar& b = const_cast<RooRealVar&>(rdep);
  
  bool bin_true=rdep.hasBinning("");
  if (!bin_true)
    cout <<"\t @@@@@@@@@@@ can't find biining! (RooTwoParameterModelScaling file)" << endl;

  int N_bins=rdep.getBinning("").numBins();

  
  RooAbsReal* integral = shape.createIntegral(RooArgSet(dep),RooArgSet());
  SM_integral = integral->getVal();
  delete integral;

  for(int i=0; i<N_bins; ++i) {

    int bin_low=rdep.getBinning("").binLow(i);
    int bin_high=rdep.getBinning("").binHigh(i);
    const string intRange="integRange";
    b.setRange((const char*)intRange.c_str(),bin_low,bin_high); //ok
    RooAbsReal* integral = shape.createIntegral(RooArgSet(rdep),RooArgSet(),(const char*)intRange.c_str());
    integral_basis.push_back(integral->getVal());

    if (i==0){
      bins.push_back(bin_low);
    }
    bins.push_back(bin_high);

    delete integral;

  }

}

void RooTwoParameterModelScaling::readProfiles(std::vector<double> bins,TDirectory& dir) const {


  int N_bins=bins.size()-1;

  std::cout << "N_bins = " << N_bins << std::endl;

  int i;
  for(i=0; i<N_bins; ++i) {
    if (P[i]) delete P[i];
    TString dkname = TString::Format("bin_content_lam_dk_%i",i+1);
    P[i] = dynamic_cast<TH2D *>(dir.Get(dkname)->Clone(dkname+"new"));
    P[i]->SetDirectory(0);

  }

}

void RooTwoParameterModelScaling::readProfiles(RooTwoParameterModelScaling const& other) {

  int N_bins=other.bins.size()-1;

  for (int i = 0; i<N_bins; ++i) {    
    TString dkname = TString::Format("bin_content_lam_dk_%i",i+1);
    P[i] = dynamic_cast<TH2D *>(other.P[i]->Clone(dkname+"new"));
    P[i]->SetDirectory(0);
  }
}

RooTwoParameterModelScaling::~RooTwoParameterModelScaling() {
  int N_bins=1;

  for(int i = 0; i<N_bins; ++i) {
    if (P[i])
      delete P[i];
  }
  delete[] P;
}

Double_t RooTwoParameterModelScaling::evaluate() const 
{ 
  
  double v1(param1), v2(param2);

  if (not P[0]) {
    TFile f(profileFilename);
  readProfiles(bins,f);
    f.Close();
  }

  if (v1 < P[0]->GetXaxis()->GetXmin())
    v1 = P[0]->GetXaxis()->GetXmin();
  if (v1 > P[0]->GetXaxis()->GetXmax())
    v1 = P[0]->GetXaxis()->GetXmax();
  if (v2 < P[0]->GetYaxis()->GetXmin())
    v2 = P[0]->GetYaxis()->GetXmin();
  if (v2 > P[0]->GetYaxis()->GetXmax())
    v2 = P[0]->GetYaxis()->GetXmax();

  double ret(0.);
  int N_bins=bins.size()-1;
  for(int i = 0; i<N_bins; i++) {
    //param1 is read from the x axis
    //param2 is read from the y axis
    ret += P[i]->Interpolate(v1,v2)*integral_basis[i];

  }
  cout << "ret/SM_integral= "<< ret<<"/"<<SM_integral<<" = "<< ret/SM_integral << endl;
  return ret/SM_integral;

}
