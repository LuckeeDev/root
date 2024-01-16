#include "TF1.h"
#include "TH1F.h"

void macro3() {
  TH1F* histo = new TH1F{"histo", "Histogram", 100, 0, 10};

  TF1* f = new TF1{"f", "sin(x) + x^2", 0, 10};

  histo->FillRandom("f", 1e5);

  histo->Draw();
}