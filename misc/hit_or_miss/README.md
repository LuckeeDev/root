# Criterio hit or miss

Si scriva una macro in cui:

1. Si definiscono 2 istogrammi monodimensionali di 1000 bin tra 0. e 5.;
2. Si riempie il primo con $10^7$ occorrenze di una variabile x generata esplicitamente e singolarmente (`gRandom`) e distribuita secondo una esponenziale decrescente con media 1.
3. Su tali occorrenze si simula (hit or miss) un'efficienza dipendente da x secondo $\epsilon (x) = x/5$. Riempire il secondo istogramma con le occorrenze accettate.
4. Si effettua la divisione fra i due istogrammi per ottenre l'efficienza di rivelazione osservata, utilizzando il metodo `Divide` e inserendo l'opportuna opzione per la valutazione degli errori secondo la statistica binomiale.
5. Si disegna l'istogramma dell'efficienza visualizzando le incertezze sui contenuti dei bin.
