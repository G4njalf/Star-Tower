03/01
-Risolto problema sparo sulle porte, ora l unico carattere che triggera il cambio mappa è '$'
-Risolto problema alcuni nemici mal posizionati
-Problema i proiettili cancellano il carattere del box della finestra che non è '|' e ovviamente ncurses non ti specifica qual è: forse si risolve facendo in modo che i proiettili distruggono solo i caratteri dei nemici
-Problema le monete vicine spesso non le prende entrambe, io le distanzierei un pò

31/12
-Risolto problema che non salvava vita e scre del player una volta cambiata stanza
-Risolto problema che non salvava status nemici (vivi o morti) una volta uscito e rientrato in una stanza 

29/12 
-Ho messo a posto il problema che l'id veniva generato a caso
-Ho scoperto un nuovo bug presente dalle versioni vecchie: se entro in una porta digitando ripetutamente il tasto wasd per andare verso la porta, si blocca il gioco (edit:se mi fermo nel punto di trigger della porta, si blocca il gioco)

02/12
-Trovato bug su salvataggio status nemici->risolto salvando l'array delle vite dei nemici all'interno del nodo della lista dove sta la stanza dei nemici ini questione
-Sblocco porta con chiave: da ultimare (problema ad utilizzare la struct "door" all'interno di "gioco": la mappa viene stampata in "map", che è fuori da gioco.

