# Progetto-Prog
PERSONAGGIO:
Ho implementato il movimento (WASD), lo sparo (frecce direzionali) e la capriola (con lo shift); per farlo ho utilizzato uno switch (fare degli switch separati non funzionava, non ho ben capito perché). Un problema è che non ci posso implementare l'attesa tra una capriola e l'altra a causa di com'è strutturato lo switch. L'altro problema è l'attesa tra uno sparo e l'altro, quando parte il proiettile non ci si può muovere, dovremmo implementare un thread di merda.
Per interagire con il resto delle entità ho fatto due funzioni che servono ad incrementare ed a diminuire la vita, funzionano solo se implemento il trigger dentro la classe del personaggio stesso. Per una questione di chiarezza e di ordine del codice ho provato ad implementarlo nella classe dei nemici e degli artefatti, ma non funziona, quindi pure questo è da sistemare.

NEMICI:
Ne ho implementati di due tipi, il primo è la bomba: è un'entità ferma che si triggera se ti trovi sopra o a distanza di una casella da lui, ho impostato un lampeggiamento che cambia colore man mano che sta per esplodere; una volta esplosa ho aggiunto un effetto di esplosione con un flash e con degli asterischi che si spargono in giro, mi manca la funzione che serve poi a cancellarli di nuovo. Il problema della bomba è sempre quello dell'attesa, si blocca tutto ed esplode. 
Il secondo nemico è un'entità che lancia bombe, essendo una sottoclasse posso riutilizzare le funzioni dell'esplosione, ma per ora ho solo implementato il suo movimento casuale; pure qua ci vuole un thread.

ARTEFATTI:
Sugli artefatti ne ho solo aggiunto uno, che se raccolto aumenta la vita del personaggio. Come detto in precedenza la funzione non va, ma se implementata della classe del giocatore poi funziona.

MAIN:
Ho principalmente utilizzato dei cicli while per far funzionare il programma, le condizioni di questi cicli sono dettate dal booleano "gameover": nel caso venga impostato a true il gioco finisce; e da un getch(): se si preme la "x" si esce manualmente dal gioco. 
Per inserire le entità nella mappa ho usato solo dei puntatori in modo tale che se il personaggio, interagendo con l'entità, la distrugge o la raccoglie, posso farla "sparire" tramite il delete del puntatore. In questo modo l'entità non è più presente nella mappa e se il personaggio dovesse passare nel punto in cui c'era prima l'artefatto o il nemico, non verrà più attivato nessun trigger.
Infine ho realizzato tramite un array e un ciclo la scritta "GAMEOVER" che si compone man mano una volta finito il gioco.
