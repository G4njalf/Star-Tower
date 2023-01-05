29/12 
-Ho messo a posto il problema che l'id veniva generato a caso
-Ho scoperto un nuovo bug presente dalle versioni vecchie: se entro in una porta digitando ripetutamente il tasto wasd per andare verso la porta, si blocca il gioco (edit:se mi fermo nel punto di trigger della porta, si blocca il gioco)

31/12
-Risolto problema che non salvava vita e scre del player una volta cambiata stanza
-Risolto problema che non salvava status nemici (vivi o morti) una volta uscito e rientrato in una stanza

02/02
-ho trovato un nuovo bug: per come avevo strutturato gli array che salvano lo status, nel momento in cui mi viene generata una nuova stanza il cui id e layout sono uguali a quello di una stanza in cui sono già stato, nella nuova stanza copia i dati della stanza vecchia.
 ho trovato una soluzione: salvare l'array non in map, ma nel nodo relativo alla stanza: in questo modo tutte le stanze hanno un array di lunghezza 2, in cui ci sono salvati la vita di tutti i nemici. 
 problema: non so perché, ma non funziona

05/01
-Ultimata key con apertura porte: per aprire la porta bisogna prima prendere la chiave e poi avvicinarsi alla porta (ovviamente questo solo quando la si apre per la prima volta)
-Messo un muro che, nella prima mappa in cui si spawna, sbarra la porta per tornare indietro. DITEMI SE PER VOI VA BENE.