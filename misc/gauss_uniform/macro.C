#include "TCanvas.h"
#include "TColor.h"
#include "TF1.h"
#include "TH1F.h"
#include "TMath.h"
#include "TRandom.h"

Double_t myFunction(Double_t* x, Double_t* par) {
  Double_t xx = x[0];
  Double_t val = par[0] * TMath::Exp(-(xx - par[0]) * (xx - par[0]) / 2. /
                                     par[2] / par[2]) +
                 par[3];
  return val;
}

void macro() {
  constexpr Int_t nGen1 = 1E6;
  constexpr Int_t nGen2 = 1E4;

  TH1F* h1 = new TH1F{"h1", "First", 500, 0., 5.};
  TH1F* h2 = new TH1F{"h2", "Second", 500, 0., 5.};

  Double_t x;
  for (Int_t i = 0; i < nGen1; ++i) {
    x = gRandom->Gaus(2.5, 0.25);
    h1->Fill(x);
  }

  for (Int_t i = 0; i < 1E4; ++i) {
    x = gRandom->Uniform(0., 5.);
    h2->Fill(x);
  }

  TH1F* sum = new TH1F{*h1};
  sum->SetName("sum");
  sum->SetTitle("Sum");
  sum->Add(h1, h2);

  TF1* f = new TF1{"f", myFunction, 0., 5., 4};
  f->SetParameters(1, 1, 1, 1);
  f->SetLineColor(kRed);
  f->SetLineWidth(1);

  TCanvas* canvas = new TCanvas{"canvas"};
  sum->Fit(f);
  sum->Draw();

  TCanvas* c = new TCanvas{"c"};
  c->Divide(1, 2);
  c->cd(1);
  h1->Draw();
  c->cd(2);
  h2->Draw();
}