#include "TCanvas.h"
#include "TF1.h"
#include "TGraphErrors.h"
#include "TMath.h"

Double_t fitFunction(Double_t *x, Double_t *par) {
  Double_t xx = x[0];
  Double_t val = par[0] * TMath::Sin(par[1] * xx);
  return val;
}

void exam4() {
  Double_t x[]{-0.75, -0.5, -0.25, 0., 0.25, 0.5, 0.75};
  Double_t y[]{3.1, 0.1, -3.2, -0.1, 2.9, 0.1, -3.2};
  Double_t y_err[]{0.2, 0.1, 0.2, 0.1, 0.2, 0.1, 0.2};
  TGraphErrors *g = new TGraphErrors(7, x, y, nullptr, y_err);

  TF1 *f = new TF1("f", fitFunction, -1., 1., 2);
  f->SetParameters(3., 6.);
  TCanvas *c = new TCanvas("c");
  g->Fit(f, "Q");
  g->Draw();

  std::cout << "par0: " << f->GetParameter(0) << "+-" << f->GetParError(0)
            << '\n'
            << "par1: " << f->GetParameter(1) << "+-" << f->GetParError(1)
            << '\n'
            << "Reduced chi square: " << f->GetChisquare() / f->GetNDF()
            << '\n';
}