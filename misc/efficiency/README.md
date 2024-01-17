## Efficienza

Si scriva la parte rilevante ed autoconsistente del codice di una macro di ROOT in cui:

1. Si definiscono 2 istogrammi monodimensionali di 100 bin in un range da 0 a 10.
2. Si riempie il primo istogramma con $10^5$ occorrenze di una variabile casuale $x$ generate esplicitamente e singolarmente e distribuite secondo una distribuzione gaussiana con media $\mu=5$ e deviazione standard $\sigma=1$ (campione totale).
3. Su tali occorrenze, si simula (attraverso un criterio di reiezione di tipo "hit or miss") un'efficienza di rivelazione dipendente dalla variabile casuale $x$ secondo la forma:

    - $\varepsilon(x)=0.3$ per $0\leq x\leq 3$
    - $\varepsilon(x)=0.7$ per $x \geq 3$

    Riempire il secondo istogramma con le occorrenze accettate (campione accettato).

4. Si effettua la divisione fra i due istogrammi per ottenere l'efficienza di rivelazione osservata, utilizzando il metodo `Divide` della classe degli istogrammi e inserendo l'opportuna opzione per la valutazione degli errori secondo la statistica binomiale.
5. Si disegnano i tre istogrammi (campione totale, campione accettato, efficienza) su un'unica canvas divisa in tre pad.
