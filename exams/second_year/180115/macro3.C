#include "TF1.h"
#include "TH1F.h"
#include "TMath.h"

Double_t fitFunc(Double_t* xx) {
  double x = xx[0];
  return TMath::Sqrt(x) + x * x;
}

void macro3() {
  TH1F* histo = new TH1F{"histo", "Histogram", 100, 0, 10};

  TF1* f = new TF1{"f", "sqrt(x) + x^2", 0, 10};

  histo->FillRandom("f", 1e7);

  histo->Draw();
}