#include "TF1.h"
#include "TH1F.h"
#include "TMath.h"
#include "TRandom.h"

Double_t fitFunc(Double_t* xx, Double_t* par) {
  double x = xx[0];
  return par[0] *
             TMath::Exp(-(x - par[1]) * (x - par[1]) / (2 * par[2] * par[2])) +
         par[3] * TMath::Exp(-x / par[4]);
}

void macro2() {
  gRandom->SetSeed();

  TH1F* gauss = new TH1F{"gauss", "Gaussian", 500, 0, 5};
  TH1F* exp = new TH1F{"uniform", "Uniform", 500, 0, 5};

  for (int i{}; i < 1e6; ++i) {
    auto x1 = gRandom->Gaus(2, 0.5);
    gauss->Fill(x1);

    if (i < 1e5) {
      auto x2 = gRandom->Exp(1);
      exp->Fill(x2);
    }
  }

  TF1* f = new TF1{"f", fitFunc, 0, 5, 5};
  f->SetParameter(0, 8000);
  f->SetParameter(1, 2);
  f->SetParameter(2, 0.6);
  f->SetParameter(3, 1500);
  f->SetParameter(4, 1);

  TH1F* sum = new TH1F{*gauss};
  sum->SetName("sum");
  sum->SetTitle("Sum");
  sum->Add(gauss, exp);
  sum->Fit(f, "Q");

  std::cout << "Parameter 0: " << f->GetParameter(0) << " +- "
            << f->GetParError(0) << '\n'
            << "Parameter 1: " << f->GetParameter(1) << " +- "
            << f->GetParError(1) << '\n'
            << "Parameter 2: " << f->GetParameter(2) << " +- "
            << f->GetParError(2) << '\n'
            << "Parameter 3: " << f->GetParameter(3) << " +- "
            << f->GetParError(3) << '\n'
            << "Parameter 4: " << f->GetParameter(4) << " +- "
            << f->GetParError(4) << '\n'
            << "Reduced chi square: " << f->GetChisquare() / f->GetNDF()
            << '\n';
}