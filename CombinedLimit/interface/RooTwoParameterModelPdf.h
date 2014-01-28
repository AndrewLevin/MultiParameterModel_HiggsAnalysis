// -*- mode: c++ -*-

#ifndef ROOATGCSEMIANALYTICPDF
#define ROOATGCSEMIANALYTICPDF

#include "RooRealProxy.h"
#include "RooAbsPdf.h"
#include "TProfile2D.h"
#include "TString.h"
  
class RooTwoParameterModelPdf : public RooAbsPdf {
public:
  
  RooTwoParameterModelPdf ();
  RooTwoParameterModelPdf (const char * name, const char * title,
			  RooAbsReal& _x, 
			  RooAbsReal& _param1, 
			  RooAbsReal& _param2,
			  RooAbsReal& _SM_shape,
			  const char * parFilename);
  RooTwoParameterModelPdf (const RooTwoParameterModelPdf& other, const char * name);
  virtual TObject * clone(const char * newname) const { 
    return new RooTwoParameterModelPdf(*this, newname);
    }
  
  virtual ~RooTwoParameterModelPdf ();
  
  Int_t getAnalyticalIntegral(RooArgSet& allVars, 
			    RooArgSet& analVars, 
			    const char* rangeName = 0) const;

  Double_t analyticalIntegral(Int_t code, const char* rangeName = 0) const;
  void readProfiles(std::vector<double> bins,TDirectory& dir) const ;

  TString getProfileFilename() const { return profileFilename; }
  
protected:
  
  RooRealProxy x;
  RooRealProxy param1;
  RooRealProxy param2;
  RooRealProxy SM_shape;
  
  mutable std::map<std::string,std::vector<double> > integral_basis;

  mutable std::vector<double> bins; // imporatant to be mutable!!!



  TString profileFilename;
  
  TH2D ** P; //!
  
  void initializeProfiles();
  void initializeBins(const RooAbsReal& shape) const;
  void initializeNormalization(const std::string& rName,
			       const RooAbsReal& dep,
			       const RooAbsReal& shape) const;
  
  void readProfiles(RooTwoParameterModelPdf const& other);

  virtual double evaluate() const ;
  
private:
  
  ClassDef(RooTwoParameterModelPdf, 4) 
};

#endif
