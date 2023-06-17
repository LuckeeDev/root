#include "TCanvas.h"
#include "TF1.h"
#include "TH1F.h"
#include "TMath.h"
#include "TRandom.h"

Double_t fitFunction(Double_t *x, Double_t *par) {
  Double_t xx = *x;
  Double_t val = par[0] * TMath::Exp(-(xx - par[1]) * (xx - par[1]) / 2. /
                                     par[2] / par[2]);
  return val;
}

void exam1() {
  TH1F *h = new TH1F("h", "Histogram", 1000, 0., 10.);

  Double_t x;
  for (Int_t i = 0; i < 1E7; ++i) {
    x = gRandom->Gaus(5., 1.);
    h->Fill(x);
  }

  TF1 *f = new TF1("f", fitFunction, 0., 10., 3);
  f->SetParameters(1, 1, 1);
  // Q disables console output
  h->Fit(f, "Q");

  Double_t hMean = h->GetMean();
  Double_t hMeanErr = h->GetMeanError();
  Double_t hRMS = h->GetRMS();
  Double_t hRMSErr = h->GetRMSError();
  Double_t par0 = f->GetParameter(0);
  Double_t par0Err = f->GetParError(0);
  Double_t par1 = f->GetParameter(1);
  Double_t par1Err = f->GetParError(1);
  Double_t par2 = f->GetParameter(2);
  Double_t par2Err = f->GetParError(2);
  Double_t chiSquare = f->GetChisquare();
  Double_t NDOF = f->GetNDF();

  std::cout << "Histogram mean: " << hMean << "+-" << hMeanErr << '\n'
            << "Histogram RMS: " << hRMS << "+-" << hRMSErr << '\n'
            << "par0: " << par0 << "+-" << par0Err << '\n'
            << "par1: " << par1 << "+-" << par1Err << '\n'
            << "par2: " << par2 << "+-" << par2Err << '\n'
            << "Reduced chi square: " << chiSquare / NDOF << '\n';
}