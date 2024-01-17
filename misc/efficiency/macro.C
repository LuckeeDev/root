#include "TCanvas.h"
#include "TH1F.h"
#include "TRandom.h"

double efficiency(double x) {
  if (0 <= x && x <= 3) {
    return 0.3;
  } else {
    return 0.7;
  }
}

void macro() {
  gRandom->SetSeed();

  TH1F* hgen = new TH1F{"hgen", "Campione totale", 100, 0, 10};
  hgen->Sumw2();
  TH1F* hacc = new TH1F{"hacc", "Campione accettato", 100, 0, 10};
  hacc->Sumw2();

  for (int j{}; j < 1e5; ++j) {
    auto x = gRandom->Gaus(5, 1);
    hgen->Fill(x);

    auto y = gRandom->Uniform(0, 1);
    if (y < efficiency(x)) {
      hacc->Fill(x);
    }
  }

  TH1F* heff = new TH1F{*hgen};
  heff->SetName("heff");
  heff->SetTitle("Efficienza");
  heff->Divide(hacc, hgen, 1, 1, "B");

  TCanvas* canvas = new TCanvas();
  canvas->Divide(2, 2);
  canvas->cd(1);
  hgen->Draw();
  canvas->cd(2);
  hacc->Draw();
  canvas->cd(3);
  heff->Draw();
}