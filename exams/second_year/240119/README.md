## 19/01/2024

#### Quesito 1 (Istogrammi e `TList`)

**Importante**: in tutti i punti del quesito, sfruttare quanto più possibile la possibilità di scrivere il codice in forma di cicli.

Si scriva la parte rilevante e autoconsistente del codice di una macro di ROOT in cui:

1. Si definiscono in un ciclo 4 istogrammi monodimensionali di tipo `TH1D`, aventi 1000 bin in un range da 0 a 10, e con nomi root `{"histo0","histo1","histo2","histo3"}`, attraverso un array di puntatori di tipo `TH1*` e successiva allocazione dinamica degli oggetti.
2. Si impostano i titoli dell'asse $x$ e $y$ rispettivamente a "x variable" e "entries".
3. Si riempie ciascuno degli istogrammi con $10^6$ occorrenze di una variabile casuale generata _esplicitamente e singolarmente_ (i.e. attraverso `gRandom`) secondo delle distribuzioni gaussiane con media, rispettivamente, pari a $\mu=\{2.5,4.5,6.5,8.6\}$ e deviazione standard $\sigma$ pari al 10\% della media corrispondente.
4. Si inseriscono i quattro istogrammi in un oggetto contenitore di tipo `TList`.
5. Successivamente, sempre utilizzando un ciclo, si disegnano su una `TCanvas` divisa in 4 pad i quattro istogrammi recuperandoli dalla `TList`, e si stampano a schermo media e RMS con relative incertezze.

#### Quesito 2 (Categorie)

Si scriva la parte rilevante e autoconsistente del codice di una macro di ROOT in cui:

1. Si definisce un istogramma monodimensionale di 5 bin in un range da 0 a 5, finalizzato a visualizzare il numero di conteggi osservati nelle categorie che contraddistinguono la popolazione di cui a punto successivo.
2. Si genera una popolazione di $N=10^7$ elementi appartenenti a 5 categorie distinte, con rispettive probabilità di occorrenza:

    - Caso 0: 5\%
    - Caso 1: 15\%
    - Caso 2: 15\%
    - Caso 3: 35\%
    - Caso 4: 30\%

    e si riempie l'istogramma con le occorrenze osservate nei diversi casi.

3. Si stampano a schermo _le frazioni_ di popolazione osservate nei cinque bin dell'istogramma, utilizzando i metodi espliciti degli istogrammi per estrarre il numero di ingressi dell'istogramma e il contenuto dei bin.
4. Si salva l'istogramma su un file ROOT.

#### Quesito 3 (PDF definita a tratti)

Si scriva la parte rilevante e autoconsistente del codice di una macro di ROOT in cui:

1. Si definisce un istogramma monodimensionale di 100 bin in un range da 0 a 5.
2. Si riempie l'istogramma con $10^6$ occorrenze di una variabile casuale $x$ distribuita secondo la p.d.f.:

    - $f(x)=0.2$ per $0\leq x < 1$
    - $f(x)=x/5$ per $1\leq x <5$

    nel range $[0,5]$, utilizzando il metodo `FillRandom(const char* f, Int_t N)` della classe degli istogrammi.

3. Monitorare il tempo di esecuzione del punto 2. attraverso la funzionalità `TBenchmark`.
