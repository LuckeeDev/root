## Efficienza

Si scriva la parte rilevante ed autoconsistente del codice di una macro di ROOT in cui:

1. Si definiscono 2 istogrammi monodimensionali di 100 bin in un range da 0 a 10.
2. Si riempie il primo istogramma con $10^5$ occorrenze di una variabile casuale $x$ generate esplicitamente e singolarmente e distribuite secondo una distribuzione gaussiana con media $\mu=5$ e deviazione standard $\sigma=1$ (campione totale).
3. Su tali occorrenze, si simula (attraverso un criterio di reiezione di tipo "hit or miss")
