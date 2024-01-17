## Uso di `FillRandom`

Si scriva la parte rilevante ed autoconsistente del codice di una macro di ROOT in cui:

1. Si definisce un istogramma monodimensionale di 100 bin in un range da 0 a 10.
2. Si riempie l'istogramma con $10^5$ occorrenze di una variabile casuale $x$ distribuita secondo la p.d.f. $f(x)=x$ nel range $[0,10]$, utilizzando il metodo `FillRandom(const char* f, Int_t N)` degli istogrammi.
