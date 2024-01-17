## 12/07/2022 (`TGraphErrors`)

Si scriva la parte rilevante ed autoconsistente del codice di una macro di ROOT in cui:

1. Si definisce un grafico (classe `TGraphErrors`) atto a rappresentare le 5 coppie di misure (x,y) che dovranno essere opportunamente inserite in forma di arrays:
    - Valori in x: `{1,4,9,16,25}`;
    - Valori in y: `{10,20,30,40,50}`;
    - Errori in x: `{0.1,0.4,0.9,1.6,2.5}`;
    - Errori in y: `{0.1,0.2,0.3,0.4,0.5}`.
2. Si disegna il grafico, inserendo come titoli degli assi "Misure in x" e "Misure in y".
3. Si esegue sul grafico un fit secondo una dipendenza funzionale del tipo $f(x)= A+B \sqrt{x}$, dove $A$ e $B$ sono i parametri liberi del fit. Stampare a schermo i valori di A e B esito del fit, con rispettive incertezze, e il $\chi ^2$ ridotto.
