# Consegna

Si scriva la parte rilevante e autoconsistente del codice di una macro di ROOT in cui:

1. Si definisce un istogramma unidimensionale con 1000 bin, in un range da 0. a 10.;
2. In un ciclo si riempie l'istogramma con $10 ^ 7$ occorrenze di una variabile casuale estratta da una distribuzione gaussiana con media $\mu = 5$ e $\sigma = 1$;
3. Al termine del ciclo si esegue il fit dell'istogramma con una funzione gaussiana esplicitamente definita attraverso un `TF1` (tre parametri liberi: ampiezza, media e deviazione standard) e si stampano a schermo:
   a. La media e la RMS dell'istogramma risultante con le rispettive incertezze;
   b. Il valore dei tre parametri della funzione dopo il fit, con rispettive incertezze, e il $\chi ^ 2$ ridotto del fit.
