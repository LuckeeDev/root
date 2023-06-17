#include <iostream>

#include "TH1D.h"
#include "TRandom.h"

void macro() {
  TH1D *h = new TH1D("h", "Histogram", 1000, -1., 1.);

  Double_t x;
  for (Int_t i = 0; i < 1E6; ++i) {
    x = gRandom->Gaus(0., 1.);
    h->Fill(x);
  }

  std::cout << "Histogram mean: " << h->GetMean() << "+-" << h->GetMeanError()
            << '\n'
            << "Histogram RMS: " << h->GetRMS() << "+-" << h->GetRMSError()
            << '\n'
            << "Underflow: " << h->GetBinContent(0) << '\n'
            << "Overflow: " << h->GetBinContent(1001) << '\n';
}