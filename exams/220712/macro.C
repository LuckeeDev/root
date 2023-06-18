#include "TF1.h"
#include "TGraphErrors.h"
#include "TMath.h"

Double_t fitFunction(Double_t *x, Double_t *par) {
  Double_t xx = *x;
  Double_t val = par[0] + par[1] * TMath::Sqrt(xx);
  return val;
}

void macro() {
  Double_t x[]{1, 4, 9, 16, 25};
  Double_t y[]{10, 20, 30, 40, 50};
  Double_t x_err[]{0.1, 0.4, 0.9, 1.6, 2.5};
  Double_t y_err[]{0.1, 0.2, 0.3, 0.4, 0.5};

  TGraphErrors *g = new TGraphErrors(5, x, y, x_err, y_err);
  g->SetTitle("Grafico;Misure in x;Misure in y");

  TF1 *f = new TF1("f", fitFunction, 0, 30, 2);
  f->SetParameters(1., 1.);
  g->Fit(f, "Q");
  g->Draw();

  std::cout << "A: " << f->GetParameter(0) << "+-" << f->GetParError(0) << '\n'
            << "B: " << f->GetParameter(1) << "+-" << f->GetParError(1) << '\n'
            << "Reduced chi square: " << f->GetChisquare() / f->GetNDF()
            << '\n';
}