## 23/06/2021

Si scriva la parte rilevante e autoconsistente del codice di una macro di ROOT in cui:

1. Si definisce un grafico (classe `TGraphErrors`) atto a rappresentare le 10 coppie di misure (x,y) e l'incertezza sui valori in y che sono, nell'ordine (x,y,dy), salvati nelle tre colonne del file di testo denominato `data.txt` come segue:
    ```txt
    1	6	0.6
    2	17	1.7
    3	34	3.4
    4	57	5.7
    5	86	8.6
    6	121	12.1
    7	162	16.2
    8	209	20.9
    9	262	26.2
    10	321	32.1
    ```
2. Si disegna il grafico, inserendo i nomi degli assi;
3. Si esegue sul grafico un fit secondo una dipendenza funzionale del tipo $Ax^2 + Bx + C$, dove $A$, $B$ e $C$ sono parametri liberi del fit. Si stampi a schermo il valore dei parametri dopo il fit con le relative incertezze e il $\chi ^2$ ridotto.
