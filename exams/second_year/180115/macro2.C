#include "TF1.h"
#include "TH1F.h"
#include "TMath.h"
#include "TRandom.h"

Double_t fitFunc(Double_t* x, Double_t* par) {
  double xx = x[0];
  double y = par[0] * TMath::Exp(-(xx - par[1]) * (xx - par[1]) /
                                 (2 * par[2] * par[2])) +
             par[3];
  return y;
}

void macro2() {
  gRandom->SetSeed();

  TH1F* histo1 = new TH1F{"histo1", "Histogram 1", 500, 0, 5};
  TH1F* histo2 = new TH1F{"histo2", "Histogram 2", 500, 0, 5};

  for (int i{}; i < 1e6; ++i) {
    auto x1 = gRandom->Gaus(2.5, 0.25);
    histo1->Fill(x1);

    if (i < 1e4) {
      auto x2 = gRandom->Uniform(0, 5);
      histo2->Fill(x2);
    }
  }

  TF1* f = new TF1{"f", fitFunc, 0, 5, 4};
  f->SetParameter(0, 16000);
  f->SetParameter(1, 2.5);
  f->SetParameter(2, 0.25);
  f->SetParameter(3, 20);

  TH1F* sum = new TH1F{*histo1};
  sum->SetName("sum");
  sum->SetTitle("Sum");
  sum->Add(histo1, histo2);

  sum->Fit(f, "Q");
  std::cout << "Parameter 0: " << f->GetParameter(0) << " +- "
            << f->GetParError(0) << '\n'
            << "Parameter 1: " << f->GetParameter(1) << " +- "
            << f->GetParError(1) << '\n'
            << "Parameter 2: " << f->GetParameter(2) << " +- "
            << f->GetParError(2) << '\n'
            << "Parameter 3: " << f->GetParameter(3) << " +- "
            << f->GetParError(3) << '\n'
            << "Reduced chi square: " << f->GetChisquare() / f->GetNDF()
            << '\n';
}