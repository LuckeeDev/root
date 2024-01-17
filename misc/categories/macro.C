#include <iostream>

#include "TH1I.h"
#include "TRandom.h"

void macro() {
  TH1I* histo = new TH1I{"histo", "Categories", 4, 0, 4};

  for (int j{}; j < 1e6; ++j) {
    auto x = gRandom->Uniform(0, 1);

    if (x <= 0.6) {
      histo->Fill(0);
    } else if (x <= 0.9) {
      histo->Fill(1);
    } else if (x <= 0.99) {
      histo->Fill(2);
    } else {
      histo->Fill(3);
    }
  }

  for (int j{}; j < 4; ++j) {
    std::cout << "Case " << j << " occurrences: " << histo->GetBinContent(j + 1)
              << " +- " << histo->GetBinError(j + 1) << '\n';
  };
}