#include "TBenchmark.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TH1F.h"
#include "TRandom.h"

void macro() {
  TH1F* h1 = new TH1F{"h1", "Histogram 1", 1000, -5, 5};
  TH1F* h2 = new TH1F{"h2", "Histogram 2", 1000, -5, 5};

  gBenchmark->Start("With loop");

  for (int j{}; j < 1e5; ++j) {
    auto x = gRandom->Gaus(0, 1);
    h1->Fill(x);
  }

  gBenchmark->Show("With loop");

  gBenchmark->Start("With FillRandom");

  h2->FillRandom("gaus", 1e5);

  gBenchmark->Show("With FillRandom");
}