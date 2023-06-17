#include "TCanvas.h"
#include "TF1.h"
#include "TGraphErrors.h"

void exam2() {
  Double_t x[]{1, 2, 3, 4, 5};
  Double_t y[]{3, 9, 19, 33, 51};
  Double_t y_err[]{0.1, 0.4, 0.9, 1.6, 2.5};

  TGraphErrors* g = new TGraphErrors(5, x, y, nullptr, y_err);

  TCanvas* c = new TCanvas("c");
  g->Draw();
  TF1* f = new TF1("f", "[0] * x * x + [1]");
  f->SetParameters(1, 1);
  g->Fit(f);
}