## 26/06/2018

#### Quesito 1 (10 punti)

Si scriva la parte rilevante ed autoconsistente del codice di una macro di ROOT in cui:

1. Si definiscono 2 istogrammi monodimensionali di 1000 bin in un range da 0 a 10.
2. Si riempe il primo istogramma con $10^7$ occorrenze di una variabile casuale $x$ generate esplicitamente e singolarmente e distribuite secondo una distribuzione gaussiana con $\mu=5$ e deviazione standard $\sigma=1$ (campione totale).
3. Su tali occorrenze, si simula (attraverso un criterio di reiezione di tipo "hit or miss") un’efficienza di rivelazione dipendente dalla variabile casuale $x$ secondo la forma: $\varepsilon(x)=0.1xe^{-x}$. Riempire il secondo istogramma con le occorrenze accettate (campione accettato).
4. Si effettua la divisione fra i due istogrammi per ottenere l’efficienza di rivelazione osservata, utilizzando il metodo Divide della classe degli istogrammi e inserendo l’opportuna opzione per la valutazione degli errori secondo la statistica binomiale.
5. Si disegna l’istogramma dell’ efficienza visualizzando le incertezze sui contenuti dei bin.

#### Quesito 2 (12 punti)

Si scriva la parte rilevante ed autoconsistente del codice di una macro di ROOT in cui:

1. Si definiscono 2 istogrammi monodimensionali di 500 bin in un range da 0 a 5.
2. Si riempie il primo istogramma con $10^6$ occorrenze generate esplicitamente e singolarmente secondo una distribuzione gaussiana con media $\mu=2$ e deviazione standard $\sigma=0.5$.
3. Si riempie il secondo istogramma con $10^5$ occorrenze generate esplicitamente e singolarmente secondo una distribuzione esponenziale decrescente con media $\mu=1$.
4. Si fa la somma dei due istogrammi, e si effettua il Fit dell’istogramma somma secondo una forma funzionale consistente di una gaussiana (3 parametri) e un esponenziale (2 parametri), per un totale di 5 parametri liberi.
5. Si stampa a schermo il valore dei parametri dopo il fit, con relativo errore, e il $\chi^2$ ridotto.

#### Quesito 3 (6 punti)

Si scriva la parte rilevante ed autoconsistente del codice di una macro di ROOT in cui:

1. Si definisce un istogramma monodimensionale di 100 bin in un range da 0 a 10.
2. Si riempie l'istogramma con $10^5$ occorrenze di una variabile casuale $x$ distribuita secondo la p.d.f. $f(x)=\sin(x)+x^2$ nel range [0,10], utilizzando il metodo `FillRandom(const char* f,Int_t N)` della classe di istogrammi.
