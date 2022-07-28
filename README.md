# Progetto-Prog

LE DIMENSIONI DELLA STANZA SONO 80 COLONNE X 24 RIGHE

LOG:
280722:
- sostituita lista doppia con albero binario (il player ha quindi 3 possibilita andare a sinistra, a destra, o indietro se possibile)
  una volta interrotta l esecuzione viene stampato il numero delle stanze diverse visitate (counter) e a che profondita dell albero ci si trovava al momento
  (profondita)
  NOTA: l'ho chiamata head ma non è la testa dell albero, è dove mi trovo al momento

LOG:
260722:
- visita delle stanze ora funziona
- 4 layout

LOG:
030522:
- testata la generazione della mappa tramite lista bidirezionale (da adeguare all albero)
- aggiunta divisione tra porte di entrata e in uscita
- prima versione di visita e generazione della lista e conseguente stampa della stanza con layout randomico (0/1)
- punto 3 è megabuggato forse va messa la funzione magica che cancella tutto a riga 44 di map.hpp



DA FARE:
- aggiungere identificativo stanze (int) es. se chiedo di stampare stanza n.7 se ho la stanza n.7 la stampa
- aggiungere layout(oppure implementare algoritmo wave function collapse) , adeguare layouts ad avere 2 porte di uscita
- differenziare le 2 porte di uscita perche una manda a sinistra l altra a destra, la porta di entrata rimanda sempre al genitore del nodo
- tracciamento di entità, artefatti, condizione delle porte (direttamente sulla lista?)
- collisioni?
