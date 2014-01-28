// -*- mode: c++ -*-

#ifndef ROOATGCPROCESSSCALING
#define ROOATGCPROCESSSCALING

#include "RooRealProxy.h"
#include "RooAbsPdf.h"
#include "TProfile2D.h"
#include "TH2D.h"
#include "TString.h"
  
class RooTwoParameterModelScaling : public RooAbsReal {
public:
  
  RooTwoParameterModelScaling ();
  RooTwoParameterModelScaling (const char * name, const char * title,
			 RooAbsReal& _x, RooAbsReal& _param1,
			 RooAbsReal& _param2,
			 RooAbsReal& _SM_shape,
			 const char * parFilename);
  RooTwoParameterModelScaling (const RooTwoParameterModelScaling& other, const char * name);
  virtual TObject * clone(const char * newname) const { 
    return new RooTwoParameterModelScaling(*this, newname);
    }
  
  virtual ~RooTwoParameterModelScaling ();  
  
  void readProfiles(std::vector<double> bins,TDirectory& dir) const ;


  TString getProfileFilename() const { return profileFilename; }
  
protected:
  
  //  RooRealProxy x;
  //  const RooAbsReal& x;
  RooRealProxy param1;
  RooRealProxy param2;
  
  double SM_integral;
  std::vector<double> integral_basis;
  //here:
  std::vector<double> bins;

  TString profileFilename;
  
  TH2D ** P; //!
  
  void initializeProfiles();
  void initializeNormalization(const RooAbsReal& dep,
			       const RooAbsReal& shape);
  void readProfiles(RooTwoParameterModelScaling const& other);
  
  virtual double evaluate() const ;
  
private:
  
  ClassDef(RooTwoParameterModelScaling, 5) 
};

#endif
