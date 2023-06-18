# Collezione di esercizi con [ROOT](https://root.cern)

Questa repo contiene una collezione di esercizi svolti con [ROOT](https://root.cern), il framework di analisi dati utilizzato durante il corso di Laboratorio di Meccanica e Termodinamica all'Università di Bologna nell'A.A. 2022/2023.

## Indice

-   Esami
    -   [15/06/2023](exams/230615)
    -   [06/09/2022](exams/220906)
    -   [12/07/2022](exams/220712)
    -   [23/06/2021](exams/210623)
    -   [10/06/2019](exams/190610)
    -   [07/02/2019](exams/190207)
    -   [08/06/2018](exams/180608)
-   Altri esercizi
    -   [Somma di una gaussiana e un'uniforme](misc/gauss_uniform)
    -   [Hit or miss](misc/hit_or_miss)

## Istruzioni

Per eseguire le macro presenti nella repository è necessario avere ROOT installato sul proprio sistema. Possono essere eseguite spostandosi nella directory d'interesse, lanciando ROOT ed eseguendo il comando `.x macro.C`.

Per far funzionare l'intellisense di Visual Studio Code è necessario modificare il file `.vscode/c_cpp_properties.json` e indicare al posto di `~/programs/root/include` la directory in cui si trovano gli header file di ROOT sul proprio sistema.
