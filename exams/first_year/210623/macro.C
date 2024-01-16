#include "TF1.h"
#include "TGraphErrors.h"
#include "TMath.h"

Double_t fitFunction(Double_t *x, Double_t *par) {
  Double_t xx = *x;
  Double_t val = par[0] * xx * xx + par[1] * xx + par[2];
  return val;
}

void macro() {
  TGraphErrors *g = new TGraphErrors("data.txt", "%lg %lg %lg");
  g->SetTitle("Grafico;x;y");

  TF1 *f = new TF1("f", fitFunction, 0., 10., 3);
  f->SetParameters(1., 1., 1.);
  g->Fit(f, "Q");
  g->Draw();

  std::cout << "A: " << f->GetParameter(0) << "+-" << f->GetParError(0) << '\n'
            << "B: " << f->GetParameter(1) << "+-" << f->GetParError(1) << '\n'
            << "C: " << f->GetParameter(2) << "+-" << f->GetParError(2) << '\n'
            << "Reduced chi square: " << f->GetChisquare() / f->GetNDF()
            << '\n';
}