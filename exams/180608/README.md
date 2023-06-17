# Consegna

Si scriva la parte rilevante ed autoconsistente del codice di una macro di ROOT in cui:

1. Si definisce un istogramma unidimensionale (classe `TH1D`) con 1000 bin, in un range da -1. a 1.;
2. In un ciclo lo si riempie con $10^6$ occorrenze di una variabile casuale, estratte da una distribuzione gaussiana con media 0 e deviazione standard 1 (attraverso l'opportuno metodo della classe `TRandom`);
3. Al termine del ciclo si stampano a schermo:
    - La media e la RMS dell'istogramma, con i loro errori;
    - Il contenuto dei bin di underflow e overflow (occorrenze fuori range). Dire anche se ci si aspetta che questi ultimi (underflow e overflow) siano diversi da 0, motivando la risposta.

## Risposta

È corretto aspettarsi che i bin di underflow e overflow siano diversi da 0. Il motivo risiede nel fatto che l'intervallo $[-1, 1]$ contiene solo il $68.2%$ delle occorrenze di una gaussiana con $\mu = 0$ e $\sigma = 1$. Di conseguenza, ci si può aspettare che circa il $15.9%$ delle occorrenze cada in underflow e il $15.9%$ cada in overflow.
