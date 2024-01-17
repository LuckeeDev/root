#include "TF1.h"
#include "TH1F.h"

void macro() {
  TH1F* histo = new TH1F{"histo", "Histogram", 100, 0, 10};
  TF1* pdf = new TF1{"pdf", "x", 0, 10};

  histo->FillRandom("pdf", 1e5);

  histo->Draw();
}