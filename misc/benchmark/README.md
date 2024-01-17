## Benchmark

Si scriva la parte rilevante ed autoconsistente di codice di una macro di ROOT rivolto a monitorare con la classe `TBenchmark` il tempo di CPU rispettivamente impiegato per fare le due seguenti operazioni, utilizzando anche l'opportuno metodo per stampare a schermo i tempi di esecuzione:

1. Generare $10^5$ occorrenze generate esplicitamente e singolarmente di una gaussiana con media $\mu=0$ e deviazione standard $\sigma=1$, riempiendo un istogramma `h1` che si assume già opportunamente definito.
2. Generare $10^5$ occorrenze di una gaussiana `G(0,1)` con il metodo `FillRandom`, riempiendo un istogramma `h2` che si assume già opportunamente definito.
