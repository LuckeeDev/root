#include "TH1F.h"
#include "TMath.h"
#include "TRandom.h"

void macro1() {
  gRandom->SetSeed();

  TH1F* histo1 = new TH1F{"histo1", "Histogram 1", 1000, 0, 10};
  histo1->Sumw2();
  TH1F* histo2 = new TH1F{"histo2", "Histogram 2", 1000, 0, 10};
  histo2->Sumw2();

  for (int j{}; j < 1e7; ++j) {
    auto x = gRandom->Gaus(5, 1);
    histo1->Fill(x);

    auto y = gRandom->Uniform(0, 1);
    if (y < 0.1 * x * TMath::Exp(-x)) {
      histo2->Fill(x);
    }
  }

  TH1F* histo_division = new TH1F{*histo2};
  histo_division->SetName("histo_division");
  histo_division->SetTitle("Division");
  histo_division->Divide(histo2, histo1);
  histo_division->Draw("E");
}