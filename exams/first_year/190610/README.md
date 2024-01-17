## 10/06/2019 (`TGraphErrors`)

Si scriva la parte rilevante e autoconsistente del codice di una macro di ROOT in cui:

1. Si definisce un grafico atto a rappresentare le 7 coppie di misure (x, y) che dovranno essere opportunamente inserite in forma di arrays:
    - Valori in x: `{-0.75,-0.5,-0.25,0.,0.25,0.5,0.75}`;
    - Valori in y: `{3.1, 0.1 ,-3.2, -0.1, 2.9, 0.1,-3.2}`;
    - Errori in y: `{0.2,0.1,0.2,0.1,0.2,0.1,0.2}`.
2. Si disegna il grafico con l'opzione per visualizzare anche le barre di errore;
3. Si esegue sul grafico un fit secondo una dipendenza funzionale del tipo $f(x) = A\sin (Bx)$, dove $A$ e $B$ sono parametri liberi del fit. A tal fine istanziare un oggetto funzione `TF1` in modo opportuno.
4. Si stampano a schermo i valori dei due parametri e le relative incertezze, e il valore del $\chi ^2$ ridotto.
