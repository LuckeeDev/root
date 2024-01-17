#include "TH1F.h"
#include "TRandom.h"

void macro1() {
  gRandom->SetSeed();

  TH1F* h_gen = new TH1F{"h_gen", "Histogram 1", 1000, 0., 5.};
  h_gen->Sumw2();
  TH1F* h_acc = new TH1F{"h_acc", "Histogram 2", 1000, 0., 5.};
  h_acc->Sumw2();

  for (int j{}; j < 1e7; ++j) {
    auto x = gRandom->Exp(1);
    h_gen->Fill(x);

    auto y = gRandom->Uniform(0, 1);
    if (y < x / 5) {
      h_acc->Fill(x);
    }
  }

  TH1F* h_eff = new TH1F(*h_acc);
  h_eff->SetName("h_eff");
  h_eff->SetTitle("Efficiency");
  h_eff->Divide(h_acc, h_gen, 1, 1, "B");
  h_eff->Draw("E");
}