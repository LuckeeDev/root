#include "TH1F.h"
#include "TRandom.h"

void macro1() {
  gRandom->SetSeed();

  TH1F* histo1 = new TH1F{"histo1", "Histogram 1", 1000, 0., 5.};
  TH1F* histo2 = new TH1F{"histo2", "Histogram 2", 1000, 0., 5.};

  for (int j{}; j < 1e7; ++j) {
    auto x = gRandom->Exp(1);
    histo1->Fill(x);

    auto y = gRandom->Uniform(0, 1);
    if (y < x / 5) {
      histo2->Fill(x);
    }
  }

  TH1F* histo_eff = new TH1F(*histo2);
  histo_eff->SetName("histo_eff");
  histo_eff->SetTitle("Efficiency");
  histo_eff->Divide(histo2, histo1, 1, 1, "B");
  histo_eff->Draw("E");
}