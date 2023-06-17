#include "TCanvas.h"
#include "TF1.h"
#include "TH1F.h"
#include "TRandom.h"

void macro() {
  constexpr Int_t nGen = 1E7;

  TH1F *hGen = new TH1F{"hGen", "Histogram 1", 1000, 0., 5.};
  TH1F *hAcc = new TH1F{"hAcc", "Histogram 2", 1000, 0., 5.};

  TF1 *f = new TF1{"f", "x/5.", 0., 5.};

  Double_t x, xRND = 0;

  for (Int_t i = 0; i < nGen; ++i) {
    x = gRandom->Exp(1);
    hGen->Fill(x);

    xRND = gRandom->Uniform(0., 1.);

    if (xRND < f->Eval(x)) {
      hAcc->Fill(x);
    }
  }

  TH1F *hEff = new TH1F{*hGen};
  hEff->SetTitle("Observed efficiency");
  hEff->SetName("hEff");
  hEff->Divide(hAcc, hGen, 1, 1, "B");

  TCanvas *canvas = new TCanvas{"canvas"};
  hEff->Draw("E,SAME");

  TCanvas *c = new TCanvas{"c"};
  c->Divide(1, 2);
  c->cd(1);
  hGen->Draw();
  c->cd(2);
  hAcc->Draw();
}