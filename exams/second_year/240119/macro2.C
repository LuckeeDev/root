#include <iostream>

#include "TFile.h"
#include "TH1I.h"
#include "TRandom.h"

void macro2() {
  TH1I* histo = new TH1I{"histo", "Histogram", 5, 0, 5};

  for (int j{}; j < 1e7; ++j) {
    auto x = gRandom->Uniform(0, 1);

    if (x <= 0.05) {
      histo->Fill(0);
    } else if (x <= 0.20) {
      histo->Fill(1);
    } else if (x <= 0.35) {
      histo->Fill(2);
    } else if (x <= 0.70) {
      histo->Fill(3);
    } else {
      histo->Fill(4);
    }
  }

  double entries = histo->GetEntries();

  for (int j{}; j < 5; ++j) {
    double occurrences = histo->GetBinContent(j + 1);
    double frac = occurrences / entries;

    std::cout << "Caso " << j << ": " << frac << '\n';
  }

  TFile* file = new TFile("macro2.root", "recreate");
  histo->Write();
  file->Close();
}