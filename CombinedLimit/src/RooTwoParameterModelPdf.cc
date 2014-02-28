/***************************************************************************** 
 * Project: RooFit                                                           * 
 *                                                                           * 
 * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/ 

// Your description goes here... 

#include "Riostream.h" 

#include "HiggsAnalysis/CombinedLimit/interface/RooTwoParameterModelPdf.h" 

#include <math.h> 
#include "TMath.h" 
#include "RooFormulaVar.h"
#include "RooRealVar.h"
#include "RooFit.h"

#include "TFile.h"

ClassImpUnique(RooTwoParameterModelPdf,MAGICWORDOFSOMESORT) 

RooTwoParameterModelPdf::RooTwoParameterModelPdf() : 
  P(0)
{
  initializeProfiles();
}

RooTwoParameterModelPdf::RooTwoParameterModelPdf(const char *name, 
					       const char *title, 
					       RooAbsReal& _x,
					       RooAbsReal& _param1,
					       RooAbsReal& _param2,
					       RooAbsReal& _SM_shape,
					       const char * parFilename) :
   RooAbsPdf(name,title),
   x("observable","observable",this,_x),
   param1("param1","param1",this,_param1),
   param2("param2","param2",this,_param2),
   SM_shape("SM_shape","SM_shape",this,_SM_shape),
   profileFilename(parFilename),
   P(0)
{ 
  initializeProfiles();
  initializeNormalization(std::string(""),_x,_SM_shape);
  const char* pwd = gDirectory->GetPath();
  TFile *f = TFile::Open(parFilename,"READ");  
  gDirectory->cd(pwd);

  std::vector<double> bins_;

  const RooRealVar& rdep = dynamic_cast<const RooRealVar&>(_x);
  int N_bins=rdep.getBinning("").numBins();
  
  for (int i=0;i<N_bins;i++){
    if (i==0){
      bins_.push_back(rdep.getBinning("").binLow(i));
    }
    bins_.push_back(rdep.getBinning("").binHigh(i));
  }
  readProfiles(bins_,*f);
  f->Close();
} 

RooTwoParameterModelPdf::RooTwoParameterModelPdf(const RooTwoParameterModelPdf& other, 
					       const char* name) :  
  RooAbsPdf(other,name),
  x("observable",this,other.x),
  param1("param1",this,other.param1),
  param2("param2",this,other.param2),
  SM_shape("SM_shape",this,other.SM_shape),
  integral_basis(other.integral_basis),
  bins(other.bins),
  profileFilename(other.profileFilename),
  P(0)
{ 

    std::cout << "@@@ bins.size() = " << bins.size() << std::endl;


  initializeProfiles();
  initializeBins(x.arg());
  const char* pwd = gDirectory->GetPath();
  TFile *f = TFile::Open(profileFilename,"READ");  
  gDirectory->cd(pwd);  
  readProfiles(bins,*f);
  f->Close();
} 

void RooTwoParameterModelPdf::initializeProfiles() {
  int const N_bins=20;
  P = new TH2D*[N_bins]();
}

void RooTwoParameterModelPdf::initializeBins(const RooAbsReal& dep) const {

  std::vector<double> bins;
  const RooRealVar& rdep = dynamic_cast<const RooRealVar&>(dep);
  int N_bins=rdep.getBinning("").numBins();
  for(int i=0; i<N_bins; ++i) {
    if (i==0){
      bins.push_back(rdep.getBinning("").binLow(i));
    }
    bins.push_back(rdep.getBinning("").binHigh(i));

  }
}

void RooTwoParameterModelPdf::initializeNormalization(const std::string& rName,
						     const RooAbsReal& dep,
						     const RooAbsReal& shape) const {

  std::cout << "initializeNormalization" << std::endl;

  integral_basis[rName] = std::vector<double>();

  const RooRealVar& rdep = dynamic_cast<const RooRealVar&>(dep);
  int N_bins=rdep.getBinning("").numBins();
  int i;
  for(i=0; i<N_bins; ++i) {


    Double_t bin_low=rdep.getBinning("").binLow(i);
    Double_t bin_high=rdep.getBinning("").binHigh(i);

    if (i==0){
      bins.push_back(rdep.getBinning("").binLow(i));
    }
    bins.push_back(rdep.getBinning("").binHigh(i));

    RooRealVar& b = const_cast<RooRealVar&>(rdep);

    const string intRange="integRange";

    b.setRange((const char*)intRange.c_str(),bin_low,bin_high); 
    RooAbsReal* integral = shape.createIntegral(RooArgSet(rdep),RooArgSet(),(const char*)intRange.c_str());

    integral_basis[rName].push_back(integral->getVal());

    delete integral;
  }
}

void RooTwoParameterModelPdf::readProfiles(std::vector<double> bins,TDirectory& dir) const {
  
  assert(bins.size() > 0);
  int N_bins=bins.size()-1;
  int i;
  std::cout << "012499 N_bins = " << N_bins << std::endl;
  for(i=0; i<N_bins; ++i) {
    if (P[i]) delete P[i];
    TString dkname = TString::Format("bin_content_lam_dk_%i",i+1);
    P[i] = dynamic_cast<TH2D *>(dir.Get(dkname)->Clone(dkname+"new"));
    P[i]->SetDirectory(0);
  }

}

void RooTwoParameterModelPdf::readProfiles(RooTwoParameterModelPdf const& other) {

  int N_bins=other.bins.size()-1;

  for (int i = 0; i<N_bins; ++i) {
    TString dkname = TString::Format("p%i_lambda_dkg", i);
    P[i] = dynamic_cast<TH2D *>(other.P[i]->Clone(dkname+"new"));
    P[i]->SetDirectory(0);
  }
}

RooTwoParameterModelPdf::~RooTwoParameterModelPdf() {
  int const N_bins=20;

  for(int i = 0; i<N_bins; ++i) {
    if (P[i])
      delete P[i];
  }
  delete[] P;
}

Double_t RooTwoParameterModelPdf::evaluate() const 
{ 
  // ENTER EXPRESSION IN TERMS OF VARIABLE ARGUMENTS HERE 

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

  int bin_with_x=1;
  for (int j=0;j<N_bins;j++)
    if (x<bins[j+1] && x>bins[j]) bin_with_x=j+1;

  //param1 is read from the x axis
  //param2 is read from the y axis
  ret = P[bin_with_x-1]->Interpolate(v1, v2)*SM_shape;

  if (ret < 0.) ret = 0.;
  return ret; 
}

Int_t RooTwoParameterModelPdf::
getAnalyticalIntegral(RooArgSet& allVars,RooArgSet& analVars, 
		      const char* /*rangeName*/) const {  
  if (matchArgs(allVars,analVars,x)) return 1 ;
  return 0 ;
}

Double_t RooTwoParameterModelPdf::
analyticalIntegral(Int_t code, const char* rangeName) const {  

  assert(code==1 && "invalid analytic integration code!");

  std::string rName = ( rangeName == 0 ? std::string("") : std::string(rangeName) );
  if( integral_basis.find(rName) == integral_basis.end() ) {
    initializeNormalization(rName,x.arg(),SM_shape.arg());
  }

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
  for(Int_t i=0 ; i<N_bins ; i++) {
    ret += P[i]->Interpolate(v1, v2)*integral_basis[rName][i]
      ;
  }
  //cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@--> lZ: "<<v1<<" dk: "<<v2 <<" ret: "<<ret<< endl;
  
  cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@---> integral: "<<ret<< endl;

  return ret;

}
