## 07/02/2019 (`TGraphErrors`)

Si scriva la parte rilevante e autoconsistente del codice di una macro di ROOT in cui:

1. Si definisce un grafico (class `TGraphErrors`) atto a rappresentare le 5 coppie di misure (x, y) che dovranno essere opportunamente inserite in forma di arrays:
    - Valori in x: `{1,2,3,4,5}`;
    - Valori in y: `{3,9,19,33,51}`;
    - Errori in y: `{0.1,0.4,0.9,1.6,2.5}`.
2. Si disegna il graifco;
3. Si esegue sul grafico un fit secondo una dipendenza funzionale del tipo $f(x) = Ax^2 + B$, dove $A$ e $B$ sono parametri liberi del fit.
